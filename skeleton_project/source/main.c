#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "Order.h"
#include "LinkedList.h"
#include "FiniteStateMachine.h"

int main(){
    
    elevio_init();
    run_elevator();

    return 0;
}