#include "FiniteStateMachine.h"

#include "driver/elevio.h"
#include "Order.h"
#include "LinkedList.h"

void init_FSM() {
    elevio_motorDirection(DIRN_DOWN);
    while(elevio_floorSensor() == -1) { 

    }
    elevio_motorDirection(DIRN_STOP);
}

 



//main loop
void run_elevator() {
    init_FSM();
    State current_state = IDLE;
    Node* head = NULL;
    Order current_order;
    //update_current_order
    for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                
                if (btnPressed) {
                    current_order.floor = (Floor)f;
                    switch (b)
                    {
                    case BUTTON_HALL_UP:
                        current_order.type = UP;
                        break;
                    case BUTTON_HALL_DOWN:
                        current_order.type = DOWN;
                        break;
                    case BUTTON_CAB:
                        current_order.type = CAB;
                        break;
                    }
                }
            }
        }


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
