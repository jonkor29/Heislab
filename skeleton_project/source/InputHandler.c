#include "InputHandler.h"
#include "driver/elevio.h"

InputFSM get_input() {
    
    Order order;

    for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                
                if (btnPressed) {
                    order.floor = (Floor)f;
                    switch (b)
                    {
                    case BUTTON_HALL_UP:
                        order.type = UP;
                        break;
                    case BUTTON_HALL_DOWN:
                        order.type = DOWN;
                        break;
                    case BUTTON_CAB:
                        order.type = CAB;
                        break;
                    default:
                        order.type = NONE;
                        break;
                    }
                }
            }
        }

    InputFSM input_FSM = { .floorSensor = elevio_floorSensor(), .stopButton = elevio_stopButton(), .obstruction = elevio_obstruction(), .order = order };
    return input_FSM;
}
