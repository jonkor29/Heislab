#pragma once

#include "driver/elevio.h"

typedef enum { 
    UP      = 0,
    DOWN    = 1,
    CAB     = 2
} OrderType;

typedef struct
{
    OrderType type; 
    int floor; 
} Order;