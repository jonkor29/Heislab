/**
 * @file
 * @brief Order struct to store order given by Floor and ButtonType
 */
#pragma once
#include "driver/elevio.h"

typedef enum {
    FIRST_FLOOR = 0,
    SECOND_FLOOR = 1,
    THIRD_FLOOR = 2,
    FOURTH_FLOOR = 3
} Floor;

typedef struct {
    ButtonType type; 
    Floor floor; 
} Order;