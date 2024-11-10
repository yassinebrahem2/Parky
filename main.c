#include <stdio.h>
#include <string.h>
#include "parking.h"



void main() {


    Parking parking;
    strcpy(parking.ID, "123");
    parking.numberOfSpots = 10;
    strcpy(parking.address, "adres");
    strcpy(parking.municipality, "munic");
    parking.price = 100;
    strcpy( parking.agentCIN, "idagent69");
    parking.hasElectricCharger = 1;
    parking.vehicules[0] = 1;
    parking.vehicules[1] = 1;
    parking.vehicules[2] = 1;
    parking.vehicules[3] = 1;

    printParking(parking);
    //int userInput;
    //getParking(&parking);
    //printParking(p);
    addParking("parking.txt", parking);

}

