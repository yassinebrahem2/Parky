
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

int scanParking(FILE *parkingFile, Parking *parking);
void getParkingNumber(char *dir, int* n);
void getParking(Parking *parking);
void printParking(Parking parking);
void printParkings(char *dir);
void getVehicules(int vehicules[4], char vehiculeCode[4]);
void addParking(char *dir, Parking newParking);
void deleteParking(char *dir, char IDparking[8]);
void modifyParking(char *dir, Parking modifiedParking);
void createSortFile(char *dir);
void sortParking(char *dir, char attribute);

#endif
