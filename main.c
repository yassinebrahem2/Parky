#include <stdio.h>
#include <string.h>
#include "parking.h"



void main() {
    int n;
    Parking parking;
    char *dir = "Parking.txt";
    strcpy(parking.ID, "123");
    parking.numberOfSpots = 10;
    strcpy(parking.address, "adres");
    strcpy(parking.municipality, "munic");
    parking.price = 6969;
    strcpy( parking.agentCIN, "idagent69");
    parking.hasElectricCharger = 1;
    parking.vehicules[0] = 1;
    parking.vehicules[1] = 1;
    parking.vehicules[2] = 1;
    parking.vehicules[3] = 1;

    //int userInput;
    getParkingNumber(dir, &n);
    printf("\n\n%d\n\n", n);

    //addParking(dir, parking);
    // printParkings(dir);
    //deleteParking(dir, "3");
    //modifyParking(dir, parking);
    //sortParking(dir);
    createSortFile(dir);

}

