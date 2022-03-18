#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Order.h"
#include "LinkedList.h"
#include "FiniteStateMachine.h"
#include <errno.h>
#include <string.h>


int main(){
    
    //elevio_init(); //spoor studass: hvorfor staar det at denne ikke blir aapnet
    /*
    while(1){

        
        run_elevator();
        void (*run_elevator_pointer)  = &run_elevator;
        if(run_elevator_pointer==NULL){
             printf("Value of errno: %d , %s.", errno, strerror(errno));
        }

    }
    */
    //run_elevator();

    Order myOrder1 = {BUTTON_HALL_DOWN, SECOND_FLOOR};
    Order myOrder2 = {BUTTON_HALL_UP, SECOND_FLOOR};
    Order myOrder3 = {BUTTON_CAB, THIRD_FLOOR};
    Order myOrder4 = {BUTTON_HALL_DOWN, SECOND_FLOOR};
    Order myOrder5 = {BUTTON_HALL_UP, THIRD_FLOOR};
    Order myOrder6 = {BUTTON_CAB, SECOND_FLOOR};
    Node* p_head = NULL;
    /*
    while(!elevio_stopButton()) {
        look_for_and_add_order(&p_head);
        update_order_lights(&p_head);
    }
    delete_all_orders(&p_head);
    */

    printf("---Test for append---\np_head contains:"); //gjort 
    append(&p_head, myOrder1);
    append(&p_head, myOrder2);
    append(&p_head, myOrder3);
    print_list(p_head);
    printf(".\n");

    printf("---Test for delete_orders at second floor---\np_head contains:"); //gjort
    delete_orders(&p_head,SECOND_FLOOR);
    print_list(p_head);
    printf(".\n");

    printf("---Border case, deleting orders at an empty floor---\np_head contains:"); //gjort 
    delete_orders(&p_head,SECOND_FLOOR);
    print_list(p_head);
    printf(".\n");

    append(&p_head, myOrder4);
    append(&p_head, myOrder5);
    append(&p_head, myOrder6);

    printf("---Appended three new orders---\np_head contains:");  // trenger ikke å vise fram
    print_list(p_head);
    printf(".\n");

    printf("---Test for contains_order---\np_head contains:");
    print_list(p_head);
    printf("\n");
    printf("Does p_head contain myOrder2; %d .\n", contains_order(&p_head, myOrder2));
    printf("Does p_head contain myOrder5; %d .\n", contains_order(&p_head, myOrder5));
    printf(".\n");

    printf("---Test for delete_all_orders---\np_head contains:"); //gjort
    delete_all_orders(&p_head);
    print_list(p_head);
    printf(".\n");

    printf("---Border case, using delete_orders on an empty linkedlist---\np_head contains:"); //gjort
    delete_orders(&p_head,SECOND_FLOOR);
    delete_orders(&p_head,FIRST_FLOOR);
    print_list(p_head);
    printf(".\n");

    printf("---Border case, using delete_all_orders on an empty linkedlist---\np_head contains:"); //gjort 
    delete_all_orders(&p_head);
    print_list(p_head);
    printf(".\n");

    printf("---Border case, adding 2 simular orders---\np_head contains:"); // gjort 
    append(&p_head, myOrder1);
    append(&p_head, myOrder1);
    print_list(p_head);
    printf(".\n");


    delete_all_orders(&p_head);


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

    Node* p_head = NULL;


    printf("\n\n\nlook_for_order():\n\n\n");

    append(&p_head, myOrder);
    append(&p_head, myOrder2);
    append(&p_head, myOrder3);

    update_current_order(&p_head,&test_update_funk); // denne finnes ikke lengre
    append(&p_head, test_update_funk);

    print_list(p_head);

    printf("Before:\n"); 
    print_list(p_head);

    while(1) {
        look_for_and_add_order(&p
_head);
        if (elevio_stopButton()) 
        {
            break;
        }
    }
    
    printf("\nAfter:\n"); print_list(p_head); printf("\n\n\n");
    
    append(&p_head, myOrder4);
    append(&p_head, myOrder5);
    append(&p_head, myOrder6);


    //printf("p_head: %d", p_head); 
    //printf("p_head: %d", p_head);
    printf("\n\n\nBEFORE DELETION\n\n\n");
    printf("p_head->order.type: %d\n", p_head->order.type);
    printf("p_head: %p \n", (void*) p_head);

    print_list(p_head);

    if (contains_order(&p_head, myOrder6) && contains_order(&p_head, myOrder)) {
        printf("contains order 6 and 1");
    }
    printf("contains_order(&p_head, myOrder7): %d", contains_order(&p_head, myOrder7));

    //delete_all(&p_head);

    printf("\n\n\nAFTER DELETION - :)\n\n\n");

    delete_floor(&p_head, SECOND_FLOOR);
    
    print_list(p_head);


    printf("p_head->order.type: %d\n", p_head->order.type);
    printf("p_head: %p \n", (void*) p_head);

    
    
    delete_orders(&p_head,SECOND_FLOOR);
    delete_all(&p_head);

    print_list(p_head);


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
        Node* temp = p
_head;
        p
_head = p
_head->next;
        free(temp);
    }
    
    */

    return 0;
}