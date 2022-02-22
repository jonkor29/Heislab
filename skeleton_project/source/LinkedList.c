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
};