#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Order.h"
#include "LinkedList.h"

int main(){
    // elevio_init();

    Order down_from_floor_4 = {DOWN, 4};
    


    //  - - - - - EXAMPLE PROGRAM - - - - -
    /*
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(DIRN_UP);

    while(1){
        int floor = elevio_floorSensor();
        printf("floor: %d \n",floor);

        if(floor == 0){
            elevio_motorDirection(DIRN_UP);
        }

        if(floor == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
        }


        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    */

    //testing, attention please
    Order myOrder = {DOWN, 2};
    Order myOrder2 = {UP, 2};
    Order myOrder3 = {CAB, 3};

    Node* g_head = NULL;
    
    append(&g_head, myOrder);
    append(&g_head, myOrder2);
    append(&g_head, myOrder3);


    //printf("g_head: %d", g_head); 
    printf("Ordretype: %d \n", down_from_floor_4.type);
    //printf("g_head: %d", g_head);
    printf("\n\n\nBEFORE DELETION\n\n\n");
    printf("g_head->order.type: %d\n", g_head->order.type);
    printf("g_head: %p \n", (void*) g_head);

    //delete_all(&g_head);

    printf("\n\n\nAFTER DELETION - :)\n\n\n");
    printf("g_head: %p \n", (void*) g_head);

    //
    
    delete_order(&g_head, 3);
    

    printf("g_head->order.type: %d\n", g_head->order.type);
    printf("g_head: %p \n", (void*) g_head);

    delete_order(&g_head,2);
    
    /*

    elevio_motorDirection(DIRN_UP);

    while (1)
    {    
        if(elevio_floorSensor() == myOrder2.floor && myOrder2.type == UP) {
            elevio_motorDirection(DIRN_STOP);
            elevio_doorOpenLamp(1);
            break;
        }
    }
    
    */
    
    
    /*
    
    //to avoid memory leak error
    for (int i = 0; i < 3; i++)
    {
        Node* temp = g_head;
        g_head = g_head->next;
        free(temp);
    }
    
    */
    return 0;
}