#pragma once
#include "driver/elevio.h"
//kun bruke an av dem, helst den fra elevio
//kan tas med i raporrten
/*

typedef enum {
    UP      = 0,
    DOWN    = 1,
    CAB     = 2
} OrderType;

Hadde vi gjort det på denne måten måtte vi castet, f.eks: elevio_buttonLamp(f, (ButtonType)order.type, 0);
eller: 
*/

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