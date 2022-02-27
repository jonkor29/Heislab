#pragma once

#include "LinkedList.h"


//tanke: kan lage en buttonAndSensorPoller klasse som poller alt og returnerer en struct InputFSM som input til FSM
//Denne kan ha medlemsvariabler for alle de nødvendige knappene
//denne klassen tar inn input fra polleren og setter alle outputs.

typedef enum {
    IDLE = 0,
    MOVING_DOWN = 1,
    MOVING_UP = 2,
    DOORS_OPEN = 3
} State;

void init_FSM();
void look_for_order(Node** p_head); //take in pointer to list, and use list funcs to add new order if btn pressed and order not already in list
void run_elevator();