#pragma once
#include "Order.h"

//the purpose of this class is simply to pass all incoming input to the FSM

typedef struct InputFSM {    
    int floorSensor;
    int stopButton;
    int obstruction;
    Order order;
} InputFSM;

InputFSM get_input();