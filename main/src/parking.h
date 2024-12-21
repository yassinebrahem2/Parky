#ifndef PARKING_H_INCLUDED
#define PARKING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agent.h"

typedef struct {
    char ID[8];
    int numberOfSpots;
    char address[20];
    char municipality[20];
    float price;
    int vehicules[4];
    int hasElectricCharger;
} Parking;




void getParking(Parking *parking);

void displayParking(Parking parking);
void displayParkings(char *dir);
void displayAgent(Agent agent);
void displayAgents(char *dir);
void getServicesChar(char *ch, Agent agent);

int scanParking(FILE *parkingFile, Parking *parking);
int printParking(FILE *parkingFile, Parking parking);
void getVehicules(int vehicules[4], char vehiculeCode[4]);
int scanAgent(FILE *agentFile, Agent *agent);
void printAgent(FILE *agentFile, Agent agent);
int modifyAgent(char *dir, Agent modifiedAgent);
Agent *filterAvailableAgents(char *dir, int numAvailableAgents);
int getNumAvailableAgents(char *dir);
void searchAgentByCIN(char *dir, char *agentCIN, Agent *agent);
void filterParkingAgents(char *dir, char *parkingAgentDir, Parking parking);

int addParking(char *dir, Parking parking);
int deleteParking(char *dir, char IDparking[8]);
int modifyParking(char *dir, Parking modifiedParking);

int getParkingNumber(char *dir, int* n);
void swapParking(Parking *parking1, Parking *parking2);

int IDInRange(Parking parking1, Parking parking2, int sup);
int priceInRange(Parking parking1, Parking parking2, int sup);
int spotsInRange(Parking parking1, Parking parking2, int sup);
int addressInRange(Parking parking1, Parking parking2, int sup);
int municipalityInRange(Parking parking1, Parking parking2, int sup);

void sortParking(char *dir, int (*compare)(Parking, Parking, int), int ascending);

void filterByPrice(char *dir, float startValue, float endValue);
void filterBySpots(char *dir, int startValue, int endValue);
void filterbyVehicule(char *dir, int vehicules[4]);
void filterbyHasElectricCharger(char *dir, int hasElectricCharger);
void filterByText(char *dir, char *text, int attributeNumber);
int compareAttribute(Parking parking, char *text, int attributeNumber);
int validString(char *string1, char *string2);

void updateParkingDisplayFile(char *parkingFileDirectory, char *parkingDisplayFileDirectory);

#endif
