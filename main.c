#include <stdio.h>
#include <string.h>
#include "parking.h"



void main() {
    int n;
    Parking parking;
    Agent agent;
    char *dir = "Parking.txt";
    strcpy(parking.ID, "123");
    parking.numberOfSpots = 10;
    strcpy(parking.address, "adres");
    strcpy(parking.municipality, "munic");
    parking.price = 10;
    strcpy( parking.agentCIN, "idagent");
    parking.hasElectricCharger = 1;
    parking.vehicules[0] = 1;
    parking.vehicules[1] = 1;
    parking.vehicules[2] = 1;
    parking.vehicules[3] = 1;

    //int userInput;
    // getParkingNumber(dir, &n);
    // printf("\n\n%d\n\n", n);

    //addParking(dir, parking);
    // printParkings(dir);
    //deleteParking(dir, "3C3");
    //modifyParking(dir, parking);
    //sortParking(dir, priceInRange, 1);
    //filterbyHasElectricCharger(dir, 1);
    //createSortFile(dir);
    //sprintf("FILTERING...\n");
    //filterByPrice(dir, 10, 100);
    //filterByText(dir, "1234", 0);
    
    scanAgent("Agent.txt", &agent);
    printf("\n%s\n", agent.cin);
    printAgent("filteredAgent.txt", agent);


}

