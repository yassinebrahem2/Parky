
#include "parking.h"


int getParkingNumber(char *dir, int* n) {
    Parking parking;
    FILE* parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (scanParking(parkingFile, &parking) != EOF) {
        *n += 1;
    }
    fclose(parkingFile);
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

void displayParking(Parking parking) {
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

void addParking(char *dir, Parking parking) {
    FILE *parkingFile = fopen(dir, "a");
    printParking(parkingFile, parking);
    fclose(parkingFile);
}

void printParking(FILE *parkingFile, Parking parking) {
    fprintf(parkingFile, "%s %d %s %s %f %s %d%d%d%d %d\n",
            parking.ID, parking.numberOfSpots,
            parking.address, parking.municipality,
            parking.price, parking.agentCIN,
            parking.vehicules[0], parking.vehicules[1],
            parking.vehicules[2], parking.vehicules[3],
            parking.hasElectricCharger
            );
}

void displayParkings(char *dir) {
    int i;
    Parking parking;
    char vehiculeCode[4];
    FILE* parkingFile = fopen(dir, "r");

    while (fscanf(parkingFile, "%s %d %s %s %f %s %s %d\n",
        parking.ID, &parking.numberOfSpots,
        parking.address, parking.municipality,
        &parking.price, parking.agentCIN,
        vehiculeCode, &parking.hasElectricCharger) != EOF) {
        displayParking(parking);
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
    FILE *parkingFile = fopen(dir, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    while(scanParking(parkingFile, &parking) != EOF) {
            if (strcmp(parking.ID, IDparking) != 0) {
                printParking(tempFile, parking);
            }
    }
    fclose(tempFile);
    fclose(parkingFile);
    remove(dir);
    rename("temp.txt", dir);
}

void modifyParking(char *dir, Parking modifiedParking) {
    FILE* parkingFile = fopen(dir, "r");
    FILE* tempFile = fopen("temp.txt", "w");
    Parking parking;
    char vehiculeCode[4];
    while(fscanf(parkingFile, "%s %d %s %s %f %s %s %d\n",
        parking.ID, &parking.numberOfSpots,
        parking.address, parking.municipality,
        &parking.price, parking.agentCIN,
        vehiculeCode, &parking.hasElectricCharger) != EOF) {
            getVehicules(parking.vehicules, vehiculeCode);
            if (strcmp(parking.ID, modifiedParking.ID) != 0) {
                printParking(tempFile, parking);
            } else {
                printParking(tempFile, modifiedParking);
            }
        }
    fclose(parkingFile);
    fclose(tempFile);
    remove(dir);
    rename("temp.txt", dir);
}

int price(Parking parking1, Parking parking2) {
    return parking1.price > parking2.price;
}

void sortParking(char *dir, int (*compare)(Parking, Parking)) {
    int n, i, j, sorted = 0;
    Parking parking1;
    Parking parking2;
    getParkingNumber(dir, &n);
    createSortFile(dir);
    while(!sorted) {
        sorted = 1;
        FILE *sortedFile = fopen("sorted.txt", "r");
        FILE *tempFile = fopen("temp.txt", "w");

        scanParking(sortedFile, &parking1);
        while(scanParking(sortedFile, &parking2) != EOF) {
            if (compare(parking1, parking2)) {
                sorted = 0;
                printParking(tempFile, parking2);
            } else {
                printParking(tempFile, parking1);
                swapParking(&parking1, &parking2);
            }
        }
        printParking(tempFile, parking1);
        fclose(sortedFile);
        fclose(tempFile);
        remove("sorted.txt");
        rename("temp.txt", "sorted.txt");
    }
}

void swapParking(Parking *parking1, Parking *parking2) {
    Parking temp = *parking1;
    *parking1 = *parking2;
    *parking2 = temp;
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