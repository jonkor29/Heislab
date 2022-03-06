#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Order.h"

typedef struct Node {
    Order order;
    struct Node* next;
} Node; 

void append(Node** p_head, Order new_order);
void delete_all_orders(Node** p_head);
void delete_orders(Node** p_head, Floor current_floor);
int contains_order(Node** p_head, Order current_order);
void print_list(Node* node);
