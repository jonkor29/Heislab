#pragma once

#include "driver/elevio.h"

typedef enum { 
    UP      = 0,
    DOWN    = 1,
    CAB     = 2
} OrderType;

typedef enum {
    FIRST_FLOOR = 1,
    SECOND_FLOOR = 2,
    THIRD_FLOOR = 3,
    FOURTH_FLOOR = 4
} Floor;

typedef struct
{
    OrderType type; 
    Floor floor; 
} Order;