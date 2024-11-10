
#include "parking.h"


void getParkingNumber(char *dir, int* n) {
    Parking parking;
    FILE* file = fopen(dir, "r");
    while (fscanf(file, "%s %d %s %s %f %s %d %d\n",
    parking.ID, &parking.numberOfSpots,
    parking.address, parking.municipality,
    &parking.price, parking.agentCIN,
    parking.vehicules, &parking.hasElectricCharger) != EOF) {
        *n += 1;
    }
}

void getParking(Parking *parking) {
    int i;
    printf("INPUT:");
    scanf("%s", parking->ID);
    scanf("%d", &parking->numberOfSpots);
    scanf("%s", parking->address);
    scanf("%s", parking->municipality);
    scanf("%f", &parking->price);
    scanf("%s", parking->agentCIN);
    scanf("%d", &parking->hasElectricCharger);
    for (i = 0; i < 4; i++) {
        scanf("%d", &parking->vehicules[i]);
    }
}

void printParking(Parking parking) {
    int n, i;
    char vehiculeNames[4][10] = {"Voiture", "Camion", "Moto", "Velo"};
    
    printf("ID: %s\nNSpots: %d\nAddress: %s\nMunic: %s\nPrice: %f\nAgent: %s\nElect: %d\n",
        parking.ID, parking.numberOfSpots,
        parking.address, parking.municipality,
        parking.price, parking.agentCIN,
        parking.hasElectricCharger);
    printf("Vehicules: \n");
    for (i = 0; i < 5; i++) {
        if (parking.vehicules[i] == 1) {
            printf("  %s\n", vehiculeNames[i]);
        }
    }
}

void addParking(char *dir, Parking newParking) {
    FILE* parkingFile = fopen(dir, "a");

    fprintf(parkingFile, "%s %d %s %s %f %s %d%d%d%d %d\n",
            newParking.ID, newParking.numberOfSpots,
            newParking.address, newParking.municipality,
            newParking.price, newParking.agentCIN,
            newParking.vehicules[0], newParking.vehicules[1],
            newParking.vehicules[2], newParking.vehicules[3],
            newParking.hasElectricCharger
            );
    fclose(parkingFile);
}

void printParkings(char *dir) {
    int i;
    Parking parking;
    char vehiculeCode[4];
    FILE* parkingFile = fopen(dir, "r");

    while (fscanf(parkingFile, "%s %d %s %s %f %s %s %d\n",
        parking.ID, &parking.numberOfSpots,
        parking.address, parking.municipality,
        &parking.price, parking.agentCIN,
        vehiculeCode, &parking.hasElectricCharger) != EOF) {
        printf("VEHICULE CODE:%s\n", vehiculeCode);
        getVehicules(parking.vehicules, vehiculeCode);
        printParking(parking);
    }
    fclose(parkingFile);
}

void getVehicules(int vehicules[4], char vehiculeCode[4]) {
    int i;
    for (int i = 0; i < 4; i++) {
        vehicules[i] = vehiculeCode[i] - '0';
    }
}
void deleteParking(char *dir, char IDparking[8]) {
    Parking parking;
    char vehiculeCode[4];
    FILE* parkingFile = fopen(dir, "r");
    while(fscanf(parkingFile, "%s %d %s %s %f %s %s %d\n",
        parking.ID, &parking.numberOfSpots,
        parking.address, parking.municipality,
        &parking.price, parking.agentCIN,
        vehiculeCode, &parking.hasElectricCharger) != EOF) {
            if (strcmp(parking.ID, IDparking) != 0) {
                getVehicules(parking.vehicules, vehiculeCode);
                addParking("temp.txt", parking);
            }
    }
    fclose(parkingFile);
    remove(dir);
    rename("temp.txt", dir);
}

void modifyParking(char *dir, Parking modifiedParking) {
    FILE* parkingFile = fopen(dir, "r");
    Parking parking;
    char vehiculeCode[4];
    while(fscanf(parkingFile, "%s %d %s %s %f %s %s %d\n",
        parking.ID, &parking.numberOfSpots,
        parking.address, parking.municipality,
        &parking.price, parking.agentCIN,
        vehiculeCode, &parking.hasElectricCharger) != EOF) {
            getVehicules(parking.vehicules, vehiculeCode);
            if (strcmp(parking.ID, modifiedParking.ID) != 0) {
                addParking("temp.txt", parking);
            } else {
                addParking("temp.txt", modifiedParking);
            }
        }
    fclose(parkingFile);
    remove(dir);
    rename("temp.txt", dir);
}
/*
void sortParking(char attribute) {
    int n, i, j;
    Parking currentParking;
    Parking selectedParking;
    getParkingNumber("parkingList.txt", &n);
    FILE* parkingList1 = fopen("parkingList1.txt", "w");
    for(i = 0; i < n; i++) {
        FILE* parkingList = fopen("parkingList.txt", "r");
        for(j = 0; j < n; j++) {
            fscanf(parkingList, "%c %d %c %c %f %d %c %d\n",
            &currentParking.ID, &currentParking.numberOfSpots,
            currentParking.address, currentParking.municipality,
            &currentParking.price, &currentParking.agentCIN,
            currentParking.vehicules, &currentParking.hasElectricCharger);
        }
    }
}
*/

