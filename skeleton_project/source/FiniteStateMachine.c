#include "FiniteStateMachine.h"
#include "driver/elevio.h"
#include "Order.h"
#include <time.h>

void init_FSM() {
    
    elevio_motorDirection(DIRN_DOWN);
    while(elevio_floorSensor() == -1) { 

    }
    elevio_motorDirection(DIRN_STOP);
}

void look_for_and_add_order(Node** p_head) {
    for(int f = 0; f < N_FLOORS; f++) 
    {
        for(int b = 0; b < N_BUTTONS; b++)
        {
            int btnPressed = elevio_callButton(f, b);
            
            if (btnPressed) 
            {
                Order new_order;
                new_order.floor = (Floor)f; //this cast may be problematic
                
                switch (b)
                {
                case BUTTON_HALL_UP:
                    new_order.type = UP;
                    break;
                case BUTTON_HALL_DOWN:
                    new_order.type = DOWN;
                    break;
                case BUTTON_CAB:
                    new_order.type = CAB;
                    break;
                }

                if (!contains_order(p_head, new_order)) 
                {
                    append(p_head, new_order);
                } 
            }
        }
    }
}

/*
suggestion to split up look_for_and_add_order

update_order(Order* current_order);

if (!contains_order(p_head, current_order)) 
    {
        append(p_head, current_order);
    }

*/



//main loop
void run_elevator() {
    State state = IDLE;
    Node* head = NULL;
    Order current_order;
    Floor current_floor;
    //update_current_order

    init_FSM();

    while (1) {  
        //kanskje denne if-statementen kan flyttes til inni hver state for raskere oppdatering?
        if (elevio_floorSensor() != -1) 
        {
            current_floor = (Floor)(elevio_floorSensor());
        }
          
        switch (state) 
        {
        case IDLE:
            //elevio_motorDirection(DIRN_STOP);
            while (state == IDLE)
            {
                look_for_and_add_order(&head);
                if (head != NULL) 
                {
                    //update_current_order(&head, &current_order);
                    current_order = (*head).order;
                    if (current_order.floor < current_floor){
                        state = MOVING_DOWN;
                    } 
                    else if(current_order.floor > current_floor){
                        state = MOVING_UP;
                    }
                    else if(current_order.floor == current_floor){
                        state = DOORS_OPEN;
                    }
                }               
            }
            break;
        
        case MOVING_DOWN:
            elevio_motorDirection(DIRN_DOWN);
 
            while (state == MOVING_DOWN) 
            {   
                look_for_and_add_order(&head);
                int floor_sensor_reading = elevio_floorSensor();
                if (floor_sensor_reading != -1) 
                {    
                    elevio_floorIndicator(floor_sensor_reading);
                    current_floor = (Floor)(floor_sensor_reading);
  
                    Order down_order = {DOWN, current_floor};
                    Order cab_order = {CAB, current_floor}; 
                    
                    if (current_order.floor == floor_sensor_reading || contains_order(&head, down_order) || contains_order(&head, cab_order)) 
                    {
                        state = DOORS_OPEN;
                            
                    } 
                } 
            } 
            
            

            break;
        
        case MOVING_UP:
            elevio_motorDirection(DIRN_UP);
 
            while (state == MOVING_UP) 
            {   
                look_for_and_add_order(&head);
                int floor_sensor_reading = elevio_floorSensor();
                if (floor_sensor_reading != -1) 
                {    
                    elevio_floorIndicator(floor_sensor_reading);
                    current_floor = (Floor)(floor_sensor_reading);
  
                    Order up_order = {UP, current_floor};
                    Order cab_order = {CAB, current_floor}; 
                    
                    if (current_order.floor == floor_sensor_reading || contains_order(&head, up_order) || contains_order(&head, cab_order)) 
                    {
                        state = DOORS_OPEN;
                            
                    } 
                } 
            }

            
            break;

        case DOORS_OPEN:
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);                               
            delete_floor(&head, current_floor);
 
            time_t start, end;
            start = clock();
            while (state == DOORS_OPEN)
            {
                look_for_and_add_order(&head);

                end = clock();
                int time_elapsed = (end-start)/CLOCKS_PER_SEC;
                
                if (time_elapsed >= 3) 
                {
                    state = IDLE;  
                }
            }
            
            elevio_doorOpenLamp(0);

            break;
        
        
        default:
            break;
        }
    }
    delete_all(&head);
}
