
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
int getParkingNumber(char *dir, int* n);
void getParking(Parking *parking);
void displayParking(Parking parking);
void displayParkings(char *dir);
void getVehicules(int vehicules[4], char vehiculeCode[4]);
void printParking(FILE *parkingFile, Parking parking);
void addParking(char *dir, Parking parking);
void deleteParking(char *dir, char IDparking[8]);
void modifyParking(char *dir, Parking modifiedParking);
void createSortFile(char *dir);
int price(Parking parking1, Parking parking2, int sup);
void sortParking(char *dir, int (*compare)(Parking, Parking, int), int ascending);
void swapParking(Parking *parking1, Parking *parking2);

#endif
