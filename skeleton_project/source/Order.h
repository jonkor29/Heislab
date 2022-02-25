#pragma once

#include "driver/elevio.h"

typedef enum {
    UP      = 0,
    DOWN    = 1,
    CAB     = 2
} OrderType;

typedef enum {
    FIRST_FLOOR = 0,
    SECOND_FLOOR = 1,
    THIRD_FLOOR = 2,
    FOURTH_FLOOR = 3
} Floor;

typedef struct
{
    OrderType type; 
    Floor floor; 
} Order;