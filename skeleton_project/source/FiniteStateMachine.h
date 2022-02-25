#pragma once

#include "driver/elevio.h"
#include "Order.h"
#include "LinkedList.h"

//tanke: kan lage en buttonAndSensorPoller klasse som poller alt og returnerer en struct InputFSM som input til FSM
//Denne kan ha medlemsvariabler for alle de nødvendige knappene
//denne klassen tar inn input fra polleren og setter alle outputs. 