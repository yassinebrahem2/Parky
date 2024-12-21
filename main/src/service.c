#include "service.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
	PAR,
	SER,
	TYPE,
	TAR,
	DISPO1,
	DISPO2,
	DISPO3,
	HORAIRE,
	DUREEJ,
	DUREEH,
	COLUMNS
};


char types[7][50] = {"Agent de sécurité",
                "Voiturier",
                "Lavage",
                "Technicien de maintenance",
                "Entretien de véhicule",
                "Service client",
                "Service de navette"};

int addService(char* filename, Service service) {
	FILE*f=fopen(filename,"a");
	if (f!=NULL) {
		printService(f, service);
		fclose(f);
		return 1;
	}
	else return 0;
}

int printService(FILE *serviceFile, Service service) {
	int typeIndex = 0;
	int i;
	for (i = 0; i < 7; i++) {
		if (strcmp(types[i], service.type) == 0) {
			typeIndex = i;
		}
	}
    return fprintf(serviceFile,"%s %s %s %d %f %d %d %d %d %d %d\n",
	service.ID, service.ID_Parking, service.reservationID, typeIndex,
	service.tarif, service.dispo[0], service.dispo[1],
	service.dispo[2], service.horaire, service.dureeJ, service.dureeH);

}


int scanService(FILE *serviceFile, Service *service) {
	int typeIndex = 0;
	int value;
    value =  fscanf(serviceFile,"%s %s %s %d %f %d %d %d %d %d %d\n", 
	service->ID, service->ID_Parking, service->reservationID, &typeIndex, &service->tarif, 
	&service->dispo[0],&service->dispo[1], &service->dispo[2], 
	&service->horaire, &service->dureeJ, &service->dureeH);
	strcpy(service->type, types[typeIndex]);
	return value;
}




void afficher_service(GtkWidget *liste ,char* filename)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	
	char chartar[30];
	char chardispo1[3];
	char chardispo2[3];
	char chardispo3[3];
	char charhor[20];
	char chardurj[20];
	char chardurh[20];
	store=NULL;
	Service sv;

}



int modifyService(char* filename, Service modifiedService) {
	int tr=1;
	Service service;
	FILE* f1 = fopen("temp.txt", "w");
	FILE* f = fopen(filename,"r");
	if (f == NULL) {
        perror("Error opening file");
        return 1;
    }
	if (f1 == NULL) {
        perror("Error opening file");
        return 1;
    }
	while(scanService(f, &service)!=EOF){
		if(strcmp(service.ID, modifiedService.ID) == 0) {
			printService(f1, modifiedService);
			tr=0;
		} else {
			printService(f1, service);
		}
	}
	fclose(f);
	fclose(f1);
	remove(filename);
	rename("temp.txt",filename);
	return tr;
}


int supprimer( char *filename ,char *ID) {

	int tr=0;
	Service service;
	FILE *f=fopen(filename, "r");
	FILE *f1=fopen("temp.txt", "w");
	if (f !=NULL && f1!=NULL) {
		while(scanService(f, &service)!=EOF){
			if(strcmp(service.ID, ID) == 0) {
				tr=1; }
			else {
  				printService(f1, service);
			}
		}
	}

	fclose(f);
	fclose(f1);
	remove(filename);
	rename("temp.txt", filename); 
                                                                                                          
	return tr;
}


int searchService(char *filename, char*displayFile, char *type) {
	Service service;
	int notFound = 1;
	FILE*f1=fopen(displayFile, "w");
	FILE * f=fopen(filename, "r");
	if (f1 == NULL) {
        perror("Error opening file");
        return 1;
    }
	if (f == NULL) {
        perror("Error opening file");
        return 1;
    }
	while(scanService(f, &service)!=EOF){
		if(strcmp(service.type, type) == 0) {
			printService(f1, service);
			notFound = 0;
		}
	}
	fclose(f);
	fclose(f1);
	return notFound;
}



int chercher_reservation(char * filename,char *idreservation, Reservation*res){
	FILE *f=fopen(filename,"r");
	if(f==NULL){
	printf("erreur d'ouverture du fichier de réservation\n");
	return 0;
	}
	while(fscanf(f,"%s \n",res->idreservation)!=EOF){
		if(strcmp(res->idreservation,idreservation)==0){
			fclose(f);
			return 1;
		}
	}
	fclose(f);
	return 0;
}
int chercher_service(char * filename,char *ID_service1, Service *service){
	FILE *f=fopen(filename,"r");
	if(f==NULL){
	printf("erreur d'ouverture du fichier de services\n");
	return 0;
	}
	while(scanService(f, service) !=EOF){
		if(strcmp(service->ID,ID_service1)==0){
			fclose(f);
			return 1;
		}
	}
	fclose(f);
	return 0;
}
int affecter_service(char *fileName, Service service, Reservation reservation) {
	strcpy(service.reservationID, reservation.idreservation);
	modifyService(fileName, service);
	return 1;
}










