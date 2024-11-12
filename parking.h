
#ifndef parking_h
#define parking_h

#include <stdio.h>
#include <string.h>


typedef struct {
    char ID[8];
    int numberOfSpots;
    char address[20];
    char municipality[20];
    float price;
    char agentCIN[10];
    int vehicules[4];
    int hasElectricCharger;
} Parking;

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char cin[20];
    char nom[50];
    char prenom[50];
    Date date_naissance;
    char salaire[10];
    char adresse[100];
    int sexe;
    int services[7];
    int etat;
    char id_parking[10];
    char numtel[20];
} Agent;

void getParking(Parking *parking);

void displayParking(Parking parking);
void displayParkings(char *dir);

int scanParking(FILE *parkingFile, Parking *parking);
void printParking(FILE *parkingFile, Parking parking);
void getVehicules(int vehicules[4], char vehiculeCode[4]);
int scanAgent(char *filename, Agent *agent);
int printAgent(char *filename, Agent *agent);

void addParking(char *dir, Parking parking);
void deleteParking(char *dir, char IDparking[8]);
void modifyParking(char *dir, Parking modifiedParking);

int getParkingNumber(char *dir, int* n);
void swapParking(Parking *parking1, Parking *parking2);

int priceInRange(Parking parking1, Parking parking2, int sup);
int spotsInRange(Parking parking1, Parking parking2, int sup);

void createSortFile(char *dir);
void sortParking(char *dir, int (*compare)(Parking, Parking, int), int ascending);

void filterByPrice(char *dir, float startValue, float endValue);
void filterBySpots(char *dir, int startValue, int endValue);
void filterbyVehicule(char *dir, int vehicules[4]);
void filterbyHasElectricCharger(char *dir, int hasElectricCharger);
void filterByText(char *dir, char *text, int attributeNumber);
int compareAttribute(Parking parking, char *text, int attributeNumber);
int validString(char *string1, char *string2);

#endif
