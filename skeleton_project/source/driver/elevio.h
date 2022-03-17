/**
 * @file elevio.h
 * @brief A library for communicating with the elevator.
 */
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

/**
 * @brief Initializes communication with the elevator.
 */
void elevio_init(void);

/**
 * @brief Runs the elevator in the direction corresponding to @p dirn. 
 * The motor keeps going until the function is called again telling it stop or change @p dirn.
 * 
 * @param[in] dirn  instance of MotorDirection enum specifying which direction the motor should run.
 */
void elevio_motorDirection(MotorDirection dirn);

/**
 * @brief Turns on/off lamp of a certain button given @p floor, @p button and @p value (0/1).   
 * 
 * @param[in] floor The floor on which to switch the light.
 * 
 * @param[in] button What button to switch the light of.
 * 
 * @param[in] value Specifies whether to turn the light on or off.
 */
void elevio_buttonLamp(int floor, ButtonType button, int value);

/**
 * @brief Turns on the floor indicator lamp on @p floor. Automatically turns off floor indicator lamp on previous floor.
 * 
 * @param[in] floor The floor on which to turn on the light.
 */
void elevio_floorIndicator(int floor);

/**
 * @brief Turns on/off the doorOpenLamp depending on @p value.
 * 
 * @param[in] value If @c 1 turn on light, if @c 0 turn of lamp.
 */
void elevio_doorOpenLamp(int value);

/**
 * @brief Turns on/off stop lamp given @p value.
 * 
 * @param[in] value If @c 1 turn on light, if @c 0 turn of lamp.
 */
void elevio_stopLamp(int value);

/**
 * @brief Polls button specified by @p floor and @p button.
 * 
 * @param[in] floor The @p floor on which to poll the @p button.
 * 
 * @param[in] button The @p button to poll on @p floor.
 * 
 * @return @c 1 if the @p button at @p floor is being pressed, @c 0 otherwise. 
 */
int elevio_callButton(int floor, ButtonType button);

/**
 * @brief Polls floorsensor.
 * 
 * @return Floor number, with the first floor indexed at @c 0. If not at a floor, returns @c -1.
 */
int elevio_floorSensor(void);

/**
 * @brief Polls stopbutton.
 * 
 * @return @c 1 if the stop button is being pressed, @c 0 otherwise. 
 */
int elevio_stopButton(void);

/**
 * @brief Polls obstruction switch.
 * 
 * @return @c 1 if obstruction switch is active, @c 0 otherwise. 
 */
int elevio_obstruction(void);

