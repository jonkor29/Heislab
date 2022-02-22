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
