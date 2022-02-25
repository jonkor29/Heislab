#include "FiniteStateMachine.h"

#include "driver/elevio.h"
#include "Order.h"
#include "LinkedList.h"

void init() {
    elevio_motorDirection(DIRN_DOWN);
    while(elevio_floorSensor() == -1) { 

    }
}