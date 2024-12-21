#include <string.h>
#include "parking.h"

char *tempFileDirectory = "Cashe/temp.txt";

void fillNotif(Parking parking, char notification[]) {
    strcpy(notification, "Parking ");
    strcat(notification, parking.ID);
}

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

int addParking(char *dir, Parking parking) {
    int value;
    FILE *parkingFile = fopen(dir, "a");
    value = printParking(parkingFile, parking);
    fclose(parkingFile);
    return value;
}

int deleteParking(char *dir, char IDparking[8]) {
    Parking parking;
    FILE* parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    FILE* tempFile = fopen(tempFileDirectory, "w");
    while(scanParking(parkingFile, &parking) != EOF) {
        if (strcmp(parking.ID, IDparking) != 0) {
            printParking(tempFile, parking);
        }
    }
    fclose(parkingFile);
    fclose(tempFile);
    remove(dir);
    rename(tempFileDirectory, dir);
    return 0;
}

int modifyParking(char *dir, Parking modifiedParking) {
    Parking parking;
    int notModified = 1;
    FILE* parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    FILE* tempFile = fopen(tempFileDirectory, "w");

    while(scanParking(parkingFile, &parking) != EOF) {
            if (strcmp(parking.ID, modifiedParking.ID) != 0) {
                printParking(tempFile, parking);
            } else {
                printParking(tempFile, modifiedParking);
                notModified = 0;
            }
        }
    fclose(parkingFile);
    fclose(tempFile);
    remove(dir);
    rename(tempFileDirectory, dir);
    return notModified;
}

int printParking(FILE *parkingFile, Parking parking) {
    return fprintf(parkingFile, "%s %d %s %s %f %d %d %d %d %d\n",
            parking.ID, parking.numberOfSpots,
            parking.address, parking.municipality,
            parking.price,
            parking.vehicules[0], parking.vehicules[1],
            parking.vehicules[2], parking.vehicules[3],
            parking.hasElectricCharger
            );
}

void displayParking(Parking parking) {
    int n, i;
    char vehiculeNames[4][10] = {"Voiture", "Camion", "Moto", "Velo"};
    
    printf("ID: %s\nNSpots: %d\nAddress: %s\nMunic: %s\nPrice: %f\nElect: %d\n",
        parking.ID, parking.numberOfSpots,
        parking.address, parking.municipality,
        parking.price,
        parking.hasElectricCharger);
    printf("Vehicules: \n");
    for (i = 0; i < 5; i++) {
        if (parking.vehicules[i] == 1) {
            printf("  %s\n", vehiculeNames[i]);
        }
    }
}

void displayParkings(char *dir) {
    Parking parking;
    FILE* parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    while (scanParking(parkingFile, &parking) != EOF) {
        displayParking(parking);
    }
    fclose(parkingFile);
}

int scanParking(FILE *parkingFile, Parking *parking) {
    return fscanf(parkingFile, "%s %d %s %s %f %d %d %d %d %d\n",
    parking->ID, &parking->numberOfSpots,
    parking->address, parking->municipality,
    &parking->price, &parking->vehicules[0], 
    &parking->vehicules[1], &parking->vehicules[2],
    &parking->vehicules[3], &parking->hasElectricCharger);
}



int scanAgent(FILE *agentFile, Agent *agent) {
    return fscanf(agentFile, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %d %d %s %s\n",
        agent->cin, agent->nom, agent->prenom, &agent->date_naissance.jour, &agent->date_naissance.mois,
        &agent->date_naissance.annee, agent->salaire, agent->adresse, &agent->sexe,
        &agent->services[0], &agent->services[1], &agent->services[2], &agent->services[3], &agent->services[4],
        &agent->services[5], &agent->services[6], agent->id_parking, agent->numtel);
}

int priceInRange(Parking parking1, Parking parking2, int sup) {
    if (sup) {
        return parking1.price < parking2.price;
    }
    return parking1.price > parking2.price;
}

int spotsInRange(Parking parking1, Parking parking2, int sup) {
    if (sup) {
        return parking1.numberOfSpots < parking2.numberOfSpots;
    }
    return parking1.numberOfSpots > parking2.numberOfSpots;
}

int IDInRange(Parking parking1, Parking parking2, int sup) {
    if (sup) {
        return (strcmp(parking1.ID, parking2.ID) < 0);
    }
    return (strcmp(parking1.ID, parking2.ID) > 0);
}

int addressInRange(Parking parking1, Parking parking2, int sup) {
    if (sup) {
        return (strcmp(parking1.address, parking2.address) < 0);
    }
    return (strcmp(parking1.address, parking2.address) > 0);
}

int municipalityInRange(Parking parking1, Parking parking2, int sup) {
    if (sup) {
        return (strcmp(parking1.municipality, parking2.municipality) < 0);
    }
    return (strcmp(parking1.municipality, parking2.municipality) > 0);
}


void updateParkingDisplayFile(char *parkingFileDirectory, char *parkingDisplayFileDirectory) {
    Parking parking;
    FILE* parkingFile = fopen(parkingFileDirectory, "r");
    FILE *parkingDisplayFile = fopen(parkingDisplayFileDirectory, "w");
    while (scanParking(parkingFile, &parking) != EOF) {
        printParking(parkingDisplayFile, parking);
    }
    fclose(parkingFile);
    fclose(parkingDisplayFile);
}

void sortParking(char *dir, int (*inRange)(Parking, Parking, int), int ascending) {
    int n, i, j, sorted = 0;
    Parking parking1;
    Parking parking2;
    getParkingNumber(dir, &n);
    while(!sorted) {
        sorted = 1;
        FILE *sortedFile = fopen(dir, "r");
        FILE *tempFile = fopen(tempFileDirectory, "w");
        if (sortedFile == NULL) {
            perror("Error opening file");
            return 1;
        }
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
        remove(dir);
        rename(tempFileDirectory, dir);
    }
}

void swapParking(Parking *parking1, Parking *parking2) {
    Parking temp = *parking1;
    *parking1 = *parking2;
    *parking2 = temp;
}

void filterByPrice(char *dir, float startValue, float endValue) {
    Parking parking;
    FILE *filteredFile = fopen(tempFileDirectory, "w");
    FILE *parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    while(scanParking(parkingFile, &parking) != EOF) {
        if (parking.price >= startValue && parking.price <= endValue) {
            printParking(filteredFile, parking);
        }
    }
    fclose(filteredFile);
    fclose(parkingFile);
    remove(dir);
    rename(tempFileDirectory, dir);
}

void filterBySpots(char *dir, int startValue, int endValue) {
    Parking parking;
    FILE *filteredFile = fopen(tempFileDirectory, "w");
    FILE *parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1;
    }
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
    remove(dir);
    rename(tempFileDirectory, dir);
}

void filterbyVehicule(char *dir, int vehicules[4]) {
    Parking parking;
    int i;
    FILE *filteredFile = fopen(tempFileDirectory, "w");
    FILE *parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    while(scanParking(parkingFile, &parking) != EOF) {
        for(i = 0; i < 4; i++) {
            if (vehicules[i] == 1) {
                if (parking.vehicules[i] == 1) {
                    printParking(filteredFile, parking);
                    break;
                }
            }
        }
    }
    fclose(filteredFile);
    fclose(parkingFile);
    remove(dir);
    rename(tempFileDirectory, dir);
}

void filterbyHasElectricCharger(char *dir, int hasElectricCharger) {
    Parking parking;
    FILE *filteredFile = fopen(tempFileDirectory, "w");
    FILE *parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    while(scanParking(parkingFile, &parking) != EOF) {
        if (parking.hasElectricCharger == hasElectricCharger) {
            printParking(filteredFile, parking);
        }
    }
    fclose(filteredFile);
    fclose(parkingFile);
    remove(dir);
    rename(tempFileDirectory, dir);
}

void filterByText(char *dir, char *text, int attributeNumber) {
    Parking parking;
    FILE *filteredFile = fopen(tempFileDirectory, "w");
    FILE *parkingFile = fopen(dir, "r");
    if (parkingFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    while(scanParking(parkingFile, &parking) != EOF) {
        if (compareAttribute(parking, text, attributeNumber)) {
            printParking(filteredFile, parking);
        }
    }
    fclose(filteredFile);
    fclose(parkingFile);
    remove(dir);
    rename(tempFileDirectory, dir);
}

int compareAttribute(Parking parking, char *text, int attributeNumber) {
    char attribute[50];
    if (attributeNumber == 0) {
        strcpy(attribute, parking.ID);
    } else if (attributeNumber == 1) {
        strcpy(attribute, parking.address);
    } else if (attributeNumber == 2) {
        strcpy(attribute, parking.municipality);
    }
    return validString(text, attribute);
}

int validString(char *string1, char *string2) {
    int i;
    if (strlen(string1) > strlen(string2)) {
        return 0;
    }

    for (int i = 0; i < strlen(string1); i++) {
        if (string2[i] != string1[i]) {
            return 0;
        }
    }
    return 1;
}

void displayAgent(Agent agent) {
    printf("cin:%s\nnom:%s %s\ndate:%d %d %d\nsalaire:%s\nadresse%s\nsexe:%d\nservice:%d %d %d %d %d %d %d\nidp:%s\nnum:%s\n\n",
            agent.cin, agent.nom, agent.prenom, agent.date_naissance.jour, agent.date_naissance.mois,
            agent.date_naissance.annee, agent.salaire, agent.adresse, agent.sexe,
            agent.services[0], agent.services[1], agent.services[2], agent.services[3], agent.services[4],
            agent.services[5], agent.services[6], agent.id_parking, agent.numtel);
}

void displayAgents(char *dir) {
    Agent agent;
    FILE* agentFile = fopen(dir, "r");

    while (scanAgent(agentFile, &agent) != EOF) {
        displayAgent(agent);
    }
    fclose(agentFile);
}

void printAgent(FILE *agentFile, Agent agent) {
    fprintf(agentFile, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %d %d %s %s\n",
        agent.cin, agent.nom, agent.prenom, agent.date_naissance.jour, agent.date_naissance.mois,
        agent.date_naissance.annee, agent.salaire, agent.adresse, agent.sexe,
        agent.services[0], agent.services[1], agent.services[2], agent.services[3], agent.services[4],
        agent.services[5], agent.services[6], agent.id_parking, agent.numtel);
}
/*
int scanAgent(FILE *agentFile, Agent *agent) {
    return fscanf(agentFile, "%s %s %s %d %d %d %s %s %d %d %d %d %d %d %d %d %s %s\n",
        agent->cin, agent->nom, agent->prenom, &agent->date_naissance.jour, &agent->date_naissance.mois,
        &agent->date_naissance.annee, agent->salaire, agent->adresse, &agent->sexe,
        &agent->services[0], &agent->services[1], &agent->services[2], &agent->services[3], &agent->services[4],
        &agent->services[5], &agent->services[6], agent->id_parking, agent->numtel);
}*/

Agent *filterAvailableAgents(char *dir, int numAvailableAgents) {
    Agent agent;
    Agent *availableAgents = (Agent *)malloc((numAvailableAgents+2) * sizeof(Agent));
    int i = 0;
    
    FILE *agentFile = fopen(dir, "r");
    while ((scanAgent(agentFile, &agent) != EOF) && (i != numAvailableAgents)) {
        if (strcmp(agent.id_parking, "-1") == 0) {
            
            fillAgent(&availableAgents[i], agent);
            i++;
        }
    }
    fclose(agentFile);
    return availableAgents;
}

void fillAgent(Agent *agent1, Agent agent2) {
    strcpy(agent1->cin, agent2.cin);
    strcpy(agent1->nom, agent2.nom);
    strcpy(agent1->prenom, agent2.prenom);
    agent1->date_naissance.jour = agent2.date_naissance.jour;
    agent1->date_naissance.mois = agent2.date_naissance.mois;
    agent1->date_naissance.annee = agent2.date_naissance.annee;
    strcpy(agent1->salaire, agent2.salaire);
    strcpy(agent1->adresse, agent2.adresse);
    agent1->sexe = agent2.sexe;
    agent1->services[0] = agent2.services[0];
    agent1->services[1] = agent2.services[1];
    agent1->services[2] = agent2.services[2];
    agent1->services[3] = agent2.services[3];
    agent1->services[4] = agent2.services[4];
    agent1->services[5] = agent2.services[5];
    agent1->services[6] = agent2.services[6];
    strcpy(agent1->id_parking, agent2.id_parking);
    strcpy(agent1->numtel, agent2.numtel);
} 




int getNumAvailableAgents(char *dir) {
    Agent agent;
    int i = 0;
    FILE *agentFile = fopen(dir, "r");
    while (scanAgent(agentFile, &agent) != EOF) {
        if (strcmp(agent.id_parking, "-1") == 0) {
            i++;
        }
    }
    fclose(agentFile);
    return i;
}

void filterParkingAgents(char *dir, char *parkingAgentDir, Parking parking) {
    Agent agent;
    FILE *agentFile = fopen(dir, "r");
    FILE *parkingAgentsFile = fopen(parkingAgentDir, "w");
    while (scanAgent(agentFile, &agent) != EOF) {
        if (strcmp(agent.id_parking, parking.ID) == 0) {
            printAgent(parkingAgentsFile, agent);
        }
    }

    fclose(agentFile);
    fclose(parkingAgentsFile);
}

void searchAgentByCIN(char *dir, char *agentCIN, Agent *agent) {

    FILE *agentFile = fopen(dir, "r");
    while (scanAgent(agentFile, agent) != EOF) {
        if (strcmp(agent->cin, agentCIN) == 0) {
            return agent;
        }
    }

    fclose(agentFile);
}

void getServicesChar(char ch[100], Agent agent) {
    strcpy(ch, "");
    if (agent.services[0] == 1) {
        strcat(ch, "Service1\n");
    }
    if (agent.services[1] == 1) {
        strcat(ch, "Service2\n");
    }
    if (agent.services[2] == 1) {
        strcat(ch, "Service3\n");
    }
    if (agent.services[3] == 1) {
        strcat(ch, "Service4\n");
    }
    if (agent.services[4] == 1) {
        strcat(ch, "Service5\n");
    }
    if (agent.services[5] == 1) {
        strcat(ch, "Service6\n");
    }
    if (agent.services[6] == 1) {
        strcat(ch, "Service7\n");
    }
}

int modifyAgent(char *dir, Agent modifiedAgent) {
    Agent agent;
    FILE* agentFile = fopen(dir, "r");
    FILE* tempFile = fopen(tempFileDirectory, "w");
    int notModified = 1;
    if (agentFile == NULL) {
        perror("Error opening file");
        return 1;
    }
    printf("STARTED!!\n");
    while(scanAgent(agentFile, &agent) != EOF) {
            if (strcmp(agent.cin, modifiedAgent.cin) != 0) {
                printAgent(tempFile, agent);

            } else {
                printAgent(tempFile, modifiedAgent);
                notModified = 0;
            }
        }
    fclose(agentFile);
    fclose(tempFile);
    remove(dir);
    rename(tempFileDirectory, dir);
    return notModified;
}
