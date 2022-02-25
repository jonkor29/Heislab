#pragma once



//tanke: kan lage en buttonAndSensorPoller klasse som poller alt og returnerer en struct InputFSM som input til FSM
//Denne kan ha medlemsvariabler for alle de nødvendige knappene
//denne klassen tar inn input fra polleren og setter alle outputs.

typedef enum {
    IDLE = 0,
    MOVING_DOWN = 1,
    MOVING_UP = 2,
    DOORS_OPEN = 3
} State;

void init();