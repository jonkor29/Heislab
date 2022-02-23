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


void delete_all(Node** p_head) {
    Node* head = *p_head;
    while(head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    *p_head = NULL; // setter den faktiske head-pointeren lik NULL
}

//alternativ implementasjon, kortere men kanskje mindre lesbar, jobber direkte på den faktiske head pointeren
//begge er testet og ser ut til å virke fint, mer litt mer testing skader ikke. Kanksje fint med en display-list funksjon.
/*

void delete_all(Node** p_head) {
    while(*p_head != NULL) {
        Node* temp = *p_head; //temp mp kanskje utenfor
        *p_head = (*p_head)->next;
        free(temp);
        temp = NULL;
    }
}

*/
