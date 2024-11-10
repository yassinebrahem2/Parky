
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

void printParkings(char dir[]) {
    int i;
    Parking parking;
    char vehiculeCode[4];
    FILE* parkingFile = fopen(dir, "r");

    while (fscanf(parkingFile, "%s %d %s %s %f %s %s %d\n",
        parking.ID, &parking.numberOfSpots,
        parking.address, parking.municipality,
        &parking.price, parking.agentCIN,
        vehiculeCode, &parking.hasElectricCharger) != EOF) {
        getVehicules(parking.vehicules, vehiculeCode);
        printParking(parking);
    }
    fclose(parkingFile);
}

void getVehicules(int vehicules[4], char vehiculeCode[4]) {
    int i;
    for(i = 0; i < 4; i++) {
        if (strcmp(&vehiculeCode[i], "1") == 0) {
            vehicules[i] = 1;
        }
    }
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

