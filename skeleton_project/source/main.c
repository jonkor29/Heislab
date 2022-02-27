#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Order.h"
#include "LinkedList.h"
#include "FiniteStateMachine.h"

int main(){
    elevio_init(); //spør studass: hvorfor står det at denne ikke blir åpnet?

    run_elevator();

    //printf("floorSensor(): %d", elevio_floorSensor());    


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

    /* 
    
    - - - -  - - - - - - -TESTCODE BELOW - - - - - - - - -  - -

    Order myOrder = {DOWN, SECOND_FLOOR};
    Order myOrder2 = {UP, SECOND_FLOOR};
    Order myOrder3 = {CAB, THIRD_FLOOR};
    Order myOrder4 = {DOWN, SECOND_FLOOR};
    Order myOrder5 = {UP, THIRD_FLOOR};
    Order myOrder6 = {CAB, SECOND_FLOOR};
    Order myOrder7 = {CAB, FOURTH_FLOOR};
    Order test_update_funk;

    Node* g_head = NULL;


    printf("\n\n\nlook_for_order():\n\n\n");

    append(&g_head, myOrder);
    append(&g_head, myOrder2);
    append(&g_head, myOrder3);

    update_current_order(&g_head,&test_update_funk);
    append(&g_head, test_update_funk);

    print_list(g_head);

    printf("Before:\n"); 
    print_list(g_head);

    while(1) {
        look_for_and_add_order(&g_head);
        if (elevio_stopButton()) 
        {
            break;
        }
    }
    
    printf("\nAfter:\n"); print_list(g_head); printf("\n\n\n");
    
    append(&g_head, myOrder4);
    append(&g_head, myOrder5);
    append(&g_head, myOrder6);


    //printf("g_head: %d", g_head); 
    //printf("g_head: %d", g_head);
    printf("\n\n\nBEFORE DELETION\n\n\n");
    printf("g_head->order.type: %d\n", g_head->order.type);
    printf("g_head: %p \n", (void*) g_head);

    print_list(g_head);

    if (contains_order(&g_head, myOrder6) && contains_order(&g_head, myOrder)) {
        printf("contains order 6 and 1");
    }
    printf("contains_order(&g_head, myOrder7): %d", contains_order(&g_head, myOrder7));

    //delete_all(&g_head);

    printf("\n\n\nAFTER DELETION - :)\n\n\n");

    delete_floor(&g_head, SECOND_FLOOR);
    
    print_list(g_head);


    printf("g_head->order.type: %d\n", g_head->order.type);
    printf("g_head: %p \n", (void*) g_head);

    
    
    //delete_order(&g_head,3);
    delete_all(&g_head);

    print_list(g_head);


    - - - -  - - - - - - -TESTCODE ABOVE - - - - - - - - -  - -

    */

    
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