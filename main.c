#include <stdio.h>
#include <string.h>
#include "parking.h"



void main() {
    int n;
    Parking parking;
    Parking parking1;
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

    strcpy(parking1.ID, "10");
    parking1.numberOfSpots = 10;
    strcpy(parking1.address, "adres");
    strcpy(parking1.municipality, "munic");
    parking1.price = 6969;
    strcpy( parking1.agentCIN, "idagent69");
    parking1.hasElectricCharger = 1;
    parking1.vehicules[0] = 1;
    parking1.vehicules[1] = 1;
    parking1.vehicules[2] = 1;
    parking1.vehicules[3] = 1;

    //int userInput;
    //getParkingNumber(dir, &n);
    printf("\n\n%d\n\n", n);

    displayParking(parking);
    displayParking(parking1);
    printf("\n\n\n");
    swapParking(&parking, &parking1);
    displayParking(parking);
    displayParking(parking1);
    //addParking(dir, parking);
    // printParkings(dir);
    //deleteParking(dir, "3");
    //modifyParking(dir, parking);
    //sortParking(dir);

    //createSortFile(dir);

}

