#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Order.h"

typedef struct Node {
    Order order;
    struct Node* next; //here we must use struct keyword, because we have not yet told the compiler the name of the struct is Node (happens at the next line)
} Node;

//add Node to end of list
void append(Node** p_head, Order new_order);
//deletes all the nodes in the LinkedList
void delete_all(Node** p_head);
// Deletes the orders in the linkedlist that matches the floor. 
void delete_floor(Node** p_head, Floor current_floor);

int contains_order(Node** p_head, Order current_order);

void print_list(Node* node);