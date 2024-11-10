
#include "parking.h"




void getParkingNumber(char dir[], int* n) {
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

void print() {
    printf("HelloWorld!");
}
/*
void getParking(Parking *parking) {
    int i;
    printf("INPUT:");
    scanf("%s", &parking->ID);
    scanf("%d", &parking->numberOfSpots);
    scanf("%s", parking->address);
    scanf("%s", parking->municipality);
    scanf("%f", &parking->price);
    scanf("%d", &parking->agentCIN);
    scanf("%d", &parking->hasElectricCharger);
    for (i = 0; i < 4; i++) {
        scanf("%d", &parking->vehicules[i]);
    }
}
*/

void printParking(Parking parking) {
    int n, i = 0;
    strcpy(parking.ID, "123");
    parking.numberOfSpots = 10;
    strcpy(parking.address, "adres");
    strcpy(parking.address, "munic");
    parking.price = 100;
    strcpy( parking.agentCIN, "idagent69");
    parking.hasElectricCharger = 1;
    parking.vehicules[0] = 1;
    parking.vehicules[1] = 1;
    parking.vehicules[2] = 1;
    parking.vehicules[3] = 1;
/*

    if (vehiculeCode[0] == "1") {
        parking.vehicules[n] = "Voiture";
        n++;
    }
    if (vehiculeCode[1] == "1") {
        parking.vehicules[n] = "Camion";
        n++;
    }
    if (vehiculeCode[2] == "1") {
        parking.vehicules[n] = "Moto";
        n++;
    }
    if (vehiculeCode[3] == "1") {
        parking.vehicules[n] = "Velo";
        n++;
    }
    printf("ID: %s\nNSpots: %d\nAddress: %s\nMunic: %s\nPrice: %f\nAgent: %s\nElect: %d\n",
        parking.ID, parking.numberOfSpots,
        parking.address, parking.municipality,
        parking.price, parking.agentCIN,
        parking.hasElectricCharger);
    printf("Vehicules: \n");
    for (i = 0; i < n; i++) {
        printf("  %d\n", parking.vehicules[i]);
    }

  "%s %d %s %s %f %s %d %d\n"*/
}
/*
char *getVehiculesCode(char *vehicules[4]) {
    int i, voiture, camion, moto, velo;
    voiture = camion = moto = velo = 0;
    for(i = 0; i < 4; i++) {
        if (vehicules[i] == "Voiture") {
            voiture = 1;
        }
        if (vehicules[i] == "Camion") {
            camion = 1;
        }
        if (vehicules[i] == "Moto") {
            moto = 1;
        }
        if (vehicules[i] == "Velo") {
            velo = 1;
        }
    }
    char *code = (char *)calloc(5, sizeof(char)); // 4 digits + 1 for null terminator
    if (code == NULL) {
        return NULL; // Handle allocation failure
    }

    sprintf(code, "%d%d%d%d", voiture, camion, moto, velo);
    return code;
}
*/

void addParking(char dir[], Parking newParking) {
    FILE* parkingFile = fopen(dir, "a");

    fprintf(parkingFile, "%s %d %s %s %f %s %d %d\n",
            newParking.ID, newParking.numberOfSpots,
            newParking.address, newParking.municipality,
            newParking.price, newParking.agentCIN,
            *newParking.vehicules, newParking.hasElectricCharger
            );
    fclose(parkingFile);
}
/*
void deleteParking(int IDparking) {
    FILE* parkingFile1 = fopen("parking1.txt", "w");
    FILE* parkingFile = fopen("parking.txt", "r");
    Parking currentParking;
    while(fscanf(parkingFile, "%c %d %c %c %f %d %c %d\n",
        &currentParking.ID, &currentParking.numberOfSpots,
        currentParking.address, currentParking.municipality,
        &currentParking.price, &currentParking.agentCIN,
        currentParking.vehicules, &currentParking.hasElectricCharger
        ) != EOF) {
            if (*currentParking.ID != IDparking) {
                addParking("parking1.txt", currentParking);
            }
        }
    fclose(parkingFile1);
    fclose(parkingFile);
    rename("parking1.txt", "parking.txt");
}

void modifyParking(Parking modifiedParking) {
    FILE* parkingFile1 = fopen("parking1.txt", "w");
    FILE* parkingFile = fopen("parking.txt", "r");
    Parking currentParking;
    while(fscanf(parkingFile, "%c %d %c %c %f %d %c %d",
        &currentParking.ID, &currentParking.numberOfSpots,
        currentParking.address, currentParking.municipality,
        &currentParking.price, &currentParking.agentCIN,
        currentParking.vehicules, &currentParking.hasElectricCharger
        ) != EOF) {
            if (currentParking.ID != modifiedParking.ID) {
                addParking("parking1.txt", currentParking);
            } else {
                addParking("parking1.txt", modifiedParking);
            }
        }
    fclose(parkingFile1);
    fclose(parkingFile);
    rename("parking1.txt", "parking.txt");
}
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

