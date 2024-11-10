
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


void getParkingNumber(char dir[], int* n);
void getParking(Parking *parking);
void printParking(Parking parking);
void printParkings(char dir[]);
char *getVehiculesCode(char *vehicules[4]);
void addParking(char dir[], Parking newParking);
void deleteParking(int IDparking);
void modifyParking(Parking modifiedParking);
void sortParking(char attribute);
#endif
