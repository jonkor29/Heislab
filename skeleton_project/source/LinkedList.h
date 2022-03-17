/**
 * @file LinkedList.h
 * @author Arvin.D and Jonas.K (jonask/arvind@stud.ntnu.no)
 * @brief A simple library for doing operations on a linkedlist containing  rders .
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Order.h"

typedef struct Node {
    Order order;
    struct Node* next;
} Node; 

/**
 * @brief Append a @p new_order to the linkedlist which head pointer is @p p_head.
 * 
 * @param[in, out] p_head   Head pointer to the linkedlist.
 * @param[in] new_order     The order we are adding to the linkedlist.
 */
void append(Node** p_head, Order new_order);

/**
 * @brief Deletes all orders in the linkedlist where @p p_head is pointing to the head
 * 
 * @param[in,out] p_head    Head pointer to the linkedlist.
 */
void delete_all_orders(Node** p_head);

/**
 * @brief Delets all orders where the member variable floor is equal to @p current_floor in the linkedlist where @p p_head is the head pointer.
 * Delets all the orders containing @p current_floor in the linkedlist where @p p_head is the head pointer.  

 * @param[in, out] p_head   Head pointer to the linkedlist.
 * @param[in] current_floor Current floor from floor_sensor(), delets the ordering containing this floor.
 */
void delete_orders(Node** p_head, Floor current_floor);

/**
 * @brief Checks if @p current_order is in the linkedlist, or not. Where @p p_head is the head pointer.
 * 
 * @param[in] p_head        Head pointer to the linkedlist.
 * @param[in] current_order Checking if this orer is in the linkedlist or not.
 * 
 * @return @c 1 if @p current_order is in the linkedlist, or @c 0 otherwise. 
 */
int contains_order(Node** p_head, Order current_order);

/**
 * @brief Prints out all the orders in the linkedlist where @p node is the head. Used for debugging. 
 * 
 * @param[in] node  The head of the linkedlist. 
 */
void print_list(Node* node);
