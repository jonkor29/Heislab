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
//Lights up lamp of certain button. value = 0/1, ButtonType is wether the button is inside or outside the elevator. And floor is in range [0, 3]
void elevio_buttonLamp(int floor, ButtonType button, int value);
//Probably lights up floor indicator lamp
void elevio_floorIndicator(int floor);
// When value is bigger then 0. the lamp turns on
void elevio_doorOpenLamp(int value);
// When value is bigger then 0. the lamp turns on
void elevio_stopLamp(int value);

//Polls button specified by floor and buttontype. Return 1/0
int elevio_callButton(int floor, ButtonType button);
//This polls the floorsensor. Returns -1 if between floors. Otherwise returns the floor number between [0, 3].
int elevio_floorSensor(void);
//Polls stupbutton. Return 0/1
int elevio_stopButton(void);
//Polls obstruction button. Returns 0/1
int elevio_obstruction(void);

