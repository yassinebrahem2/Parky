
#include "parking.h"


int getParkingNumber(char *dir, int* n) {
    Parking parking;
    FILE* parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1; // Or handle the error appropriately
    }
    while (scanParking(parkingFile, &parking) != EOF) {
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
    printf("DELETING...");
    while(scanParking(parkingFile, &parking) != EOF) {
            if (strcmp(parking.ID, IDparking) != 0) {
                addParking("temp.txt", parking);
            }
    }
    printf("DONE...");
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

void sortParking(char *dir, char attribute) {
    int n, i, j, sorted = 0;
    Parking parking1;
    Parking parking2;
    char vehiculeCode1[4], vehiculeCode2[4];
    getParkingNumber(dir, &n);
    createSortFile(dir);

    while(!sorted) {
        sorted = 1;
        FILE* parkingFile = fopen(dir, "r");
        for(j = 0; j < n; j++) {
            fscanf(parkingFile, "%s %d %s %s %f %s %s %d\n",
                parking1.ID, &parking1.numberOfSpots,
                parking1.address, parking1.municipality,
                &parking1.price, parking1.agentCIN,
                vehiculeCode1, &parking1.hasElectricCharger);
            
            fscanf(parkingFile, "%s %d %s %s %f %s %s %d\n",
                parking2.ID, &parking2.numberOfSpots,
                parking2.address, parking2.municipality,
                &parking2.price, parking2.agentCIN,
                vehiculeCode2, &parking2.hasElectricCharger);
            
        }
    }
}

void createSortFile(char *dir) {
    char ch;
    FILE *sortedFile = fopen("sorted.txt", "w");
    FILE *parkingFile = fopen(dir, "r");
    while ((ch = fgetc(parkingFile)) != EOF) {
        fputc(ch, sortedFile);
    }
    fclose(parkingFile);
    fclose(sortedFile);
}

int scanParking(FILE *parkingFile, Parking *parking) {
    char vehiculeCode[4];
    char vehiculeNames[4][20] = {"Voiture", "Camion", "Moto", "Velo"};
    int val = fscanf(parkingFile, "%s %d %s %s %f %s %s %d\n",
    parking->ID, &parking->numberOfSpots,
    parking->address, parking->municipality,
    &parking->price, parking->agentCIN,
    vehiculeCode, &parking->hasElectricCharger);
    if (val > 0) {
        getVehicules(parking->vehicules, vehiculeCode);
    }
    return val;

}