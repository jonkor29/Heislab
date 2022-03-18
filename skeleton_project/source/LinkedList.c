/**
 * @file
 * @brief Implementation file for Linkedlist library.
 */

#include "LinkedList.h"

//Dropper p-prefiks foran ord som head, p_last og next fordi det er godt kjent for programmerere at disse er pekere. Dette for å unngå forvirring.
void append(Node** pp_head, Order new_order) {
    Node* p_new_node = (Node*) malloc(sizeof(Node)); //allocate new node
    Node* p_last = *pp_head; //set p_last equal to head
    
    p_new_node->order = new_order; //load the new order into the new node
    p_new_node->p_next = NULL; //the new node wil be the p_last node (we're appending)

    if (*pp_head == NULL) {
        *pp_head = p_new_node; //if the list was empty, set head to point to teh new node
        return;
    }

    while(p_last->p_next != NULL) { //find the p_last node, and set p_last 
        p_last = p_last->p_next;
    }

    p_last->p_next = p_new_node; //make the node that was p_last now point to the new node

    return;
}
//temp, head, p_prev
void delete_all_orders(Node** pp_head) {
    Node* p_head = *pp_head;
    while(p_head != NULL) {
        Node* p_temp = p_head;
        p_head = p_head->p_next;
        free(p_temp);
        p_temp = NULL;
    }
    *pp_head = NULL; // setter den faktiske p_head-pointeren lik NULL
}

void delete_orders(Node** pp_head, Floor current_floor) {
    Node* p_temp = *pp_head;
    Node* p_prev;
    
    while(p_temp != NULL && p_temp->order.floor == current_floor) {
        *pp_head = p_temp->p_next;
        free(p_temp);
        p_temp = *pp_head;
    }

    while (p_temp != NULL) {   
        while(p_temp != NULL && p_temp->order.floor != current_floor) {
            p_prev = p_temp;
            p_temp = p_temp->p_next;
        }

        if(p_temp == NULL) {
            return;
        }

        p_prev->p_next = p_temp->p_next;
        free(p_temp);
        p_temp = p_prev->p_next;    
    }

    return;
}

int contains_order(Node** pp_head, Order current_order) {
    
    Node* p_temp = *pp_head;
    Node* p_prev;
    
    while(p_temp != NULL && (p_temp->order.floor != current_order.floor || p_temp->order.type != current_order.type)) {
        p_prev = p_temp;
        p_temp = p_temp->p_next;
    }

    if(p_temp == NULL) {
        return 0;
    }

    if (p_temp->order.floor == current_order.floor && p_temp->order.type == current_order.type) {
        return 1;
    }  

    return 0;
}

void print_list(Node* p_node) {
    printf("[");
    while(p_node != NULL) {
        printf(" (type: %d, floor: %d) ,", p_node->order.type, p_node->order.floor);
        p_node = p_node->p_next;
    }
    printf("]");
}


