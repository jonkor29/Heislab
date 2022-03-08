#include "LinkedList.h"

//Dropper p-prefiks foran ord som head, last og next fordi det er godt kjent for programmerere at disse er pekere. Dette for å unngå forvirring.
void append(Node** p_head, Order new_order) {
    Node* p_new_node = (Node*) malloc(sizeof(Node)); //allocate new node
    Node* last = *p_head; //set last equal to head
    
    p_new_node->order = new_order; //load the new order into the new node
    p_new_node->next = NULL; //the new node wil be the last node (we're appending)

    if (*p_head == NULL) {
        *p_head = p_new_node; //if the list was empty, set head to point to teh new node
        return;
    }

    while(last->next != NULL) { //find the last node, and set last 
        last = last->next;
    }

    last->next = p_new_node; //make the node that was last now point to the new node

    return;
}

void delete_all_orders(Node** p_head) {
    Node* head = *p_head;
    while(head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    *p_head = NULL; // setter den faktiske head-pointeren lik NULL
}

void delete_orders(Node** p_head, Floor current_floor) {
    Node* temp = *p_head;
    Node* prev;
    
    while(temp != NULL && temp->order.floor == current_floor) {
        *p_head= temp->next;
        free(temp);
        temp = *p_head;
    }

    while (temp != NULL) {   
        while(temp != NULL && temp->order.floor!=current_floor) {
            prev=temp;
            temp=temp->next;
        }

        if(temp == NULL) {
            return;
        }

        prev->next=temp->next;
        free(temp);
        temp= prev->next;    
    }

    return;
}

int contains_order(Node** p_head, Order current_order) {
    
    Node* temp = *p_head;
    Node* prev;
    
    while(temp != NULL && (temp->order.floor!=current_order.floor || temp->order.type != current_order.type)) {
        prev=temp;
        temp=temp->next;
    }

    if(temp == NULL) {
        return 0;
    }

    if (temp->order.floor==current_order.floor && temp->order.type == current_order.type) {
        return 1;
    }  

    return 0;
}

void print_list(Node* node) {
    printf("[");
    while(node != NULL) {
        printf(" (type: %d, floor: %d) ,", node->order.type, node->order.floor);
        node = node->next;
    }
    printf("]");
}


