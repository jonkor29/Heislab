#include "FiniteStateMachine.h"
#include "driver/elevio.h"
#include "Order.h"

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
    init_FSM();
    State current_state = IDLE;
    Node* head = NULL;
    Order current_order;
    //update_current_order

    while (1) {

        switch (current_state)
        {
        case IDLE:
            break;
        
        case MOVING_DOWN:
            break;
        
        case MOVING_UP:
            break;

        case DOORS_OPEN:
            break;
        
        
        default:
            break;
        }

    }
}
