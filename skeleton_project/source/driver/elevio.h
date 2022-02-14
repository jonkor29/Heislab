#pragma once


#define N_FLOORS 4

typedef enum { 
    DIRN_DOWN   = -1,
    DIRN_STOP   = 0,
    DIRN_UP     = 1
} MotorDirection;


#define N_BUTTONS 3

typedef enum { 
    BUTTON_HALL_UP      = 0,
    BUTTON_HALL_DOWN    = 1,
    BUTTON_CAB          = 2
} ButtonType;

//INIT
void elevio_init(void);

//MOTOR
//This function runs the elevator up/down/stops it based on MotorDirection
void elevio_motorDirection(MotorDirection dirn);

// - - - LAMPS - - -
//Lights up lamp at a certain floor. We assume value is 0/1 and ButtonType is wether the button is inside or outside the elevator
void elevio_buttonLamp(int floor, ButtonType button, int value);
//TEST this func! Probably lights up floor indicator lamp
void elevio_floorIndicator(int floor);
void elevio_doorOpenLamp(int value);
void elevio_stopLamp(int value);

//Unclear how this works... How will we get input from buttons? Polling?
int elevio_callButton(int floor, ButtonType button);
//
int elevio_floorSensor(void);
int elevio_stopButton(void);
int elevio_obstruction(void);

