
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

    while (scanParking(parkingFile, &parking) != EOF) {
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
    FILE* parkingFile = fopen(dir, "r");
    FILE* tempFile = fopen("temp.txt", "w");
    Parking parking;
    char vehiculeCode[4];
    while(scanParking(parkingFile, &parking) != EOF) {
            getVehicules(parking.vehicules, vehiculeCode);
            if (strcmp(parking.ID, IDparking) != 0) {
                printParking(tempFile, parking);
            }
        }
    fclose(parkingFile);
    fclose(tempFile);
    remove(dir);
    rename("temp.txt", dir);
}

void modifyParking(char *dir, Parking modifiedParking) {
    FILE* parkingFile = fopen(dir, "r");
    FILE* tempFile = fopen("temp.txt", "w");
    Parking parking;
    char vehiculeCode[4];
    while(scanParking(parkingFile, &parking) != EOF) {
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

int priceInRange(Parking parking1, Parking parking2, int sup) {
    if (sup) {
        return parking1.price > parking2.price;
    }
    return parking1.price < parking2.price;
}

int spotsInRange(Parking parking1, Parking parking2, int sup) {
    if (sup) {
        return parking1.numberOfSpots > parking2.numberOfSpots;
    }
    return parking1.numberOfSpots < parking2.numberOfSpots;
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

void sortParking(char *dir, int (*inRange)(Parking, Parking, int), int ascending) {
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
            if (inRange(parking1, parking2, ascending)) {
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

void filterByPrice(char *dir, float startValue, float endValue) {
    Parking parking;
    FILE *filteredFile = fopen("filtered.txt", "w");
    FILE *parkingFile = fopen(dir, "r");
    while(scanParking(parkingFile, &parking) != EOF) {
        if (parking.price >= startValue && parking.price <= endValue) {
            printParking(filteredFile, parking);
        }
    }
    fclose(filteredFile);
    fclose(parkingFile);
}

void filterBySpots(char *dir, int startValue, int endValue) {
    Parking parking;
    FILE *filteredFile = fopen("filtered.txt", "w");
    FILE *parkingFile = fopen(dir, "r");
    while(scanParking(parkingFile, &parking) != EOF) {
        if (parking.numberOfSpots >= startValue) {
            if (endValue == 0) {
                printParking(filteredFile, parking);
            } else {
                if (parking.numberOfSpots <= endValue) {
                    printParking(filteredFile, parking);
                }
            }
        }
    }
    fclose(filteredFile);
    fclose(parkingFile);
}

void filterbyVehicule(char *dir, int vehicules[4]) {
    Parking parking;
    int i;
    FILE *filteredFile = fopen("filtered.txt", "w");
    FILE *parkingFile = fopen(dir, "r");
    while(scanParking(filteredFile, &parking) != EOF) {
        for(i = 0; i < 4; i++) {
            if (vehicules[i] == 1) {
                if (parking.vehicules[i] == 1) {
                    printParking(filteredFile, parking);
                }
            }
        }
    }
    fclose(filteredFile);
    fclose(parkingFile);
}

void filterbyHasElectricCharger(char *dir, int hasElectricCharger) {
    Parking parking;
    FILE *filteredFile = fopen("filtered.txt", "w");
    FILE *parkingFile = fopen(dir, "r");
    while(scanParking(filteredFile, &parking) != EOF) {
        if (parking.hasElectricCharger == hasElectricCharger) {
            printParking(filteredFile, parking);
        }
    }
    fclose(filteredFile);
    fclose(parkingFile);
}

void filterByText(char *dir, char *text, int attributeNumber) {
    Parking parking;
    FILE *filteredFile = fopen("filtered.txt", "w");
    FILE *parkingFile = fopen(dir, "r");
    while(scanParking(filteredFile, &parking) != EOF) {
        if (compareAttribute(parking, text, attributeNumber)) {
            printParking(filteredFile, parking);
        }
    }
    fclose(filteredFile);
    fclose(parkingFile);
}

int compareAttribute(Parking parking, char *text, int attributeNumber) {
    char *attribute;
    if (attributeNumber == 0) {
        attribute = parking.ID;
    } else if (attributeNumber == 1) {
        attribute = parking.address;
    } else if (attributeNumber == 2) {
        attribute = parking.municipality;
    } else if (attributeNumber == 3) {
        attribute = parking.agentCIN;
    }
    return validString(text, attribute);
}

int validString(char *string1, char *string2) {
    int i;
    if (strlen(string1) > strlen(string2)) {
        return 0;
    }

    for (int i = 0; i < strlen(string2); i++) {
        if (string2[i] != string1[i]) {
            return 0;
        }
    }
    return 1;
}

void printAgent(FILE *agentFile, Agent agent) {
    printf("PRINTING...\n");
    fprintf(agentFile, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %d %d %d %s %s\n",
            agent.cin, agent.nom, agent.prenom, agent.date_naissance.jour, agent.date_naissance.mois,
            agent.date_naissance.annee, agent.salaire, agent.adresse, agent.sexe,
            agent.services[0], agent.services[1], agent.services[2], agent.services[3], agent.services[4],
            agent.services[5], agent.services[6], agent.etat, agent.id_parking, agent.numtel);
}

int scanAgent(FILE *agentFile, Agent *agent) {
    return fscanf(agentFile, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %d %d %d %s %s\n",
            agent->cin, agent->nom, agent->prenom, &agent->date_naissance.jour, &agent->date_naissance.mois,
            &agent->date_naissance.annee, agent->salaire, agent->adresse, &agent->sexe,
            &agent->services[0], &agent->services[1], &agent->services[2], &agent->services[3], &agent->services[4],
            &agent->services[5], &agent->services[6], &agent->etat, agent->id_parking, agent->numtel);
}

void filterAvailableAgents() {
    Agent agent;
    int i;
    FILE *agentFile = fopen("Agent.txt", "r");
    FILE *filteredFile = fopen("filteredAgent.txt", "w");
    printf("started");
    while (fscanf(agentFile, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %d %d %d %s %s\n",
            agent.cin, agent.nom, agent.prenom, &agent.date_naissance.jour, &agent.date_naissance.mois,
            &agent.date_naissance.annee, agent.salaire, agent.adresse, &agent.sexe,
            &agent.services[0], &agent.services[1], &agent.services[2], &agent.services[3], &agent.services[4],
            &agent.services[5], &agent.services[6], &agent.etat, agent.id_parking, agent.numtel) != EOF) {
        printf("ENTERED...\n");
        if (agent.id_parking == "0") {
            printAgent(filteredFile, agent);
        }
    }

    printf("\nDONE\n");

    fclose(agentFile);
    fclose(filteredFile);
}