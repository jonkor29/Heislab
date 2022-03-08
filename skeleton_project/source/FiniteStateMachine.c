#include "FiniteStateMachine.h"
#include "driver/elevio.h"
#include "Order.h"
#include <time.h>

void init_FSM() {
    elevio_doorOpenLamp(0);
    elevio_motorDirection(DIRN_DOWN);
    while(elevio_floorSensor() == -1) { 

    }
    elevio_motorDirection(DIRN_STOP);
}

void look_for_and_add_order(Node** p_head) {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {
            int btnPressed = elevio_callButton(f, b);

            if (btnPressed) {
                Order new_order;
                new_order.floor = (Floor)f; //Is this cast problematic? Not readable?
                new_order.type = (ButtonType)b;
                
                
                /*

                switch (b) //this may be replaced by a single line if we cast b from int to ButtonType, readability?
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

                */
            
                

                if (!contains_order(p_head, new_order)) {
                    append(p_head, new_order);
                } 
            }
        }
    }
}

void update_order_lights(Node** p_head) {
    for(int f = 0; f < N_FLOORS; f++) {
        for(int b = 0; b < N_BUTTONS; b++) {            
            Order order;
            order.floor = (Floor)f; //this cast may be problematic
            order.type = (ButtonType)b; //what is more readable, this or switch-case?
            
            if (contains_order(p_head, order)) {
                elevio_buttonLamp(f, order.type, 1);                
            } else {
                elevio_buttonLamp(f, order.type, 0);
            }
        }
    }
}

void run_elevator() {
    State state = IDLE;
    Node* head = NULL;
    Order current_order;
    Floor current_floor;
    State prev_state = IDLE;

    update_order_lights(&head);    
    init_FSM();
    

    while (1) {  
        //kanskje denne if-statementen kan flyttes til inni hver state for raskere oppdatering?
        if (elevio_floorSensor() != -1) {
            current_floor = (Floor)(elevio_floorSensor());
        }

        switch (state) {
        case IDLE:

            while (state == IDLE) {
                
                look_for_and_add_order(&head);
                update_order_lights(&head);

                if (head != NULL) {
                    current_order = (*head).order;
                    if (current_order.floor < current_floor) {
                        state = MOVING_DOWN;
                    } else if(current_order.floor > current_floor) {
                        state = MOVING_UP;
                    } else if(current_order.floor == current_floor) {
                        state = DOORS_OPEN;
                
                        switch (prev_state) {
                        case MOVING_DOWN:
                            state = MOVING_UP;
                            break;
                        case MOVING_UP:
                            state = MOVING_DOWN;
                            break;
                        case DOORS_OPEN:
                            state = DOORS_OPEN;
                            break;
                        default:
                            break;
                        }
                    }
                }  
                if (elevio_stopButton()) {
                    state = EMERGENCY_STOP;
                }        
            }
            break;
        
        case MOVING_DOWN:
            elevio_motorDirection(DIRN_DOWN);
 
            while (state == MOVING_DOWN) {   
                look_for_and_add_order(&head);
                update_order_lights(&head);

                int floor_sensor_reading = elevio_floorSensor();
                if (floor_sensor_reading != -1) {    
                    prev_state = MOVING_DOWN;
                    elevio_floorIndicator(floor_sensor_reading);
                    current_floor = (Floor)(floor_sensor_reading);
  
                    Order down_order = {BUTTON_HALL_DOWN, current_floor};
                    Order cab_order = {BUTTON_CAB, current_floor}; 
                    
                    if (current_order.floor == floor_sensor_reading || contains_order(&head, down_order) || contains_order(&head, cab_order)) {
                        state = DOORS_OPEN;     
                    } 
                } 
                if (elevio_stopButton()) {
                    state = EMERGENCY_STOP;
                } 
            } 
            break;
        
        case MOVING_UP:
            elevio_motorDirection(DIRN_UP);
 
            while (state == MOVING_UP) {   
                look_for_and_add_order(&head);
                update_order_lights(&head);

                int floor_sensor_reading = elevio_floorSensor(); //hva er best her? sample en gang eller flere?
                if (floor_sensor_reading != -1) {
                    prev_state = MOVING_UP;    
                    elevio_floorIndicator(floor_sensor_reading);
                    current_floor = (Floor)(floor_sensor_reading);
  
                    Order up_order = {BUTTON_HALL_UP, current_floor};
                    Order cab_order = {BUTTON_CAB, current_floor}; 
                    
                    if (current_order.floor == floor_sensor_reading || contains_order(&head, up_order) || contains_order(&head, cab_order)) {
                        state = DOORS_OPEN;     
                    } 
                } 
                if (elevio_stopButton()) {
                    state =  EMERGENCY_STOP;
                }  
            }
            break; 

        case DOORS_OPEN:
            prev_state = DOORS_OPEN;
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);                               
            delete_orders(&head, current_floor);
            update_order_lights(&head);
 
            time_t start, end;
            start = time(NULL);
            while (state == DOORS_OPEN) {
                look_for_and_add_order(&head);
                update_order_lights(&head);
                
                if (elevio_stopButton()) {
                    state = EMERGENCY_STOP;
                    start = time(NULL);
                }

                if (elevio_obstruction()) {
                    start = time(NULL);
                }
 
                end = time(NULL);
                double time_elapsed = (end-start);
                
                if (time_elapsed >= 3) {
                    state = IDLE;
                }

            }

            elevio_doorOpenLamp(0);
            break;

        case EMERGENCY_STOP:
            elevio_motorDirection(DIRN_STOP);
            delete_all_orders(&head); 
            elevio_stopLamp(1);

            if(elevio_floorSensor() != -1) {
                elevio_doorOpenLamp(1);
                state = DOORS_OPEN; 
            } 
            else if(elevio_floorSensor() == -1) {
                elevio_doorOpenLamp(0);
                state = IDLE;
            }
            
            while(elevio_stopButton()){
                
            }

            elevio_stopLamp(0);
            break; 

        default:
            break;
        }
    }
    delete_all_orders(&head);
    update_order_lights(&head);
}