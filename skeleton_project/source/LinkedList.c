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


void delete_order(Node** p_head, int current_floor){
    /*

    int cases = 0;
    Node* number_of_cases= *p_head;
    while(number_of_cases != NULL){
        if (number_of_cases->order.floor== current_floor){
            cases++; 
        }
        number_of_cases= number_of_cases->next;
    }

    Node* head= *p_head;
    Node* previous = NULL;

    if(head != NULL && head->order.floor== current_floor){
        *p_head= head->next;
        free(head);
        head = *p_head;
    }

    while(head != NULL && head->order.floor!= current_floor){
        previous= head;
        head= head->next;
    }

    if(head !=NULL && head->order.floor==current_floor){
        previous->next= head->next;
        head->next= NULL;
        free(head);
    }
    
    */
    
    // Alternativ versjon.
   
    while (1)
    {
        Node* temp = *p_head;
        Node* prev;
        while (1)
        {
            if(temp != NULL && temp->order.floor== current_floor)  //if the list is not empty and the first item 
                {
                *p_head= temp->next;
                free(temp);
                temp = NULL;
                break;
                }
            
            while(temp!= NULL && temp->order.floor!=current_floor)
            {
                prev=temp;
                temp=temp->next;
            }
            
            if(temp != NULL && temp->order.floor== current_floor)
            {
                prev->next=temp->next;
                free(temp);
                temp= NULL;
                break;
            }
            if(temp == NULL) 
            {
                return;    
            }
        }
        
    }
    return;
    
    
    // Alternativ versjon, slutt.
}