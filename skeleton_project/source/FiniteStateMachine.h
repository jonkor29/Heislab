/**
 * @file
 * @brief Finite state machine library to enable and run the elevator FSM.
 */
#pragma once
#include "LinkedList.h"

typedef enum {
    IDLE = 0,
    MOVING_DOWN = 1,
    MOVING_UP = 2,
    DOORS_OPEN = 3,
    EMERGENCY_STOP = 4
} State;

/**
 * @brief Initializes the FSM by running the elevator down to the nearest floor.
 */
void init_FSM();

/**
 * @brief Polls all buttons and adds orders to the linked list, if they're not already present.
 * 
 * @param[in, out] pp_head pointer to the head of the list
 */
void look_for_and_add_order(Node** pp_head);

/**
 * @brief Updates order lights for all orders in the list to which @p pp_head points.
 * 
 * @param[in, out] pp_head pointer to the head of the list
 */
void update_order_lights(Node** pp_head);

/**
 * @brief Runs the elevator.
 */
void run_elevator();
