#include <string.h>
#include <stdio.h>
#include "projet.h"

void ajouter_citoyen(char *filename, citoyen c)
{  int i;
   FILE *f=fopen(filename,"a");
   if(f!=NULL)
   {
    fprintf(f,"%s %s %s %s %s %s %s %d %d %d %d  "
    , c.cin, c.nom, c.prenom, c.tel, c.email, c.adresse, c.mdp,c.dn[0],c.dn[1],c.dn[2],c.genre);
    //Options
    for (i=0;i<6;i++)
    {   fprintf(f,"%d ",c.options[i]);
        
    }fprintf(f,"\n");
    fclose(f);
   }
}


void modifier_citoyen(char *filename, char cin[10], citoyen new) {
    ajouter_citoyen("citoyen.txt", new);
    citoyen c;
    int i,x=0;
    int feedback = 0;
    FILE *f = fopen(filename, "r");
    FILE *f1 = fopen("temp.txt", "w");

    if (f != NULL && f1 != NULL) {
        while (fscanf(f, "%s %s %s %s %s %s %s %d %d %d %d %d %d %d %d %d %d",
                      c.cin, c.nom, c.prenom, c.tel, c.email, c.adresse, c.mdp,
                      &c.dn[0], &c.dn[1], &c.dn[2], &c.genre,
                      &c.options[0], &c.options[1], &c.options[2], &c.options[3], &c.options[4], &c.options[5]) != EOF) 
        {
            
            // Check if the `cin` matches
            if (strcmp(c.cin, cin) == 0 && x==0) { x++;
              
              
                printf("Match found for CIN: %s. Updating record.\n", cin);
                fprintf(f1, "%s %s %s %s %s %s %s ",
                        new.cin, new.nom, new.prenom, new.tel, new.email, new.adresse, new.mdp);
                        fprintf(f1,"%d %d %d ",new.dn[0], new.dn[1], new.dn[2]);
                        fprintf(f1,"%d ",new.genre);
                        for (i=0;i<6;i++)
                        {
                            fprintf(f1,"%d ",new.options[i]);
                        }
                        fprintf(f1,"\n");
                feedback = 1;}
                if(strcmp(c.cin,new.cin)==0)
                {
                    //do nothing
                    }
                if(strcmp(c.cin,new.cin)!=0 &&strcmp(c.cin, cin)!=0){
                // If not matched, write the original data
                fprintf(f1,"%s %s %s %s %s %s %s %d %d %d "
                          , c.cin, c.nom, c.prenom, c.tel, c.email, c.adresse, c.mdp, c.dn[0], c.dn[1], c.dn[2]);
                          fprintf(f1,"%d ",c.genre);
                          for (i=0;i<6;i++)
                          {
                         fprintf(f1,"%d ",c.options[i]);
                          }fprintf(f1,"\n");
                    }
            }
            
            } 
            
            
    

        fclose(f);
        fclose(f1);
        
        // Replace the original file with the modified one
        remove(filename);
        rename("temp.txt", filename);
        
        printf("Modification result (1 = success, 0 = failure): %d\n", feedback);
      
    
}

void supprimer_citoyen(char *filename,char cin[10])
{
    int feedback=0,i;
    citoyen c;
    FILE * f=fopen(filename, "r");
    FILE * f1=fopen("temp.txt", "w");
    if(f!=NULL && f1!=NULL)
    {
        while(fscanf(f, "%s %s %s %s %s %s %s %d %d %d %d %d %d %d %d %d %d",
                      c.cin, c.nom, c.prenom, c.tel, c.email, c.adresse, c.mdp,
                      &c.dn[0], &c.dn[1], &c.dn[2], &c.genre,
                      &c.options[0], &c.options[1], &c.options[2], &c.options[3], &c.options[4], &c.options[5]) != EOF)
        {
            if(strcmp(c.cin, cin) == 0)
                feedback=1;
            else
            {
                fprintf(f1,"%s %s %s %s %s %s %s %d %d %d "
                          , c.cin, c.nom, c.prenom, c.tel, c.email, c.adresse, c.mdp, c.dn[0], c.dn[1], c.dn[2]);
                          fprintf(f1,"%d ",c.genre);
                          for (i=0;i<6;i++)
                          {
                         fprintf(f1,"%d ",c.options[i]);
                          }fprintf(f1,"\n");

           }
        }
        fclose(f);
    fclose(f1);
    remove(filename);
    rename("temp.txt", filename);
    printf(" feedback: %d\n",feedback);
    }
}
void chercher_citoyen(char *filename,char cin[10])
{   
    int i,feedback;
    citoyen c;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    { while(fscanf(f, "%s %s %s %s %s %s %s %d %d %d %d %d %d %d %d %d %d",
                      c.cin, c.nom, c.prenom, c.tel, c.email, c.adresse, c.mdp,
                      &c.dn[0], &c.dn[1], &c.dn[2], &c.genre,
                      &c.options[0], &c.options[1], &c.options[2], &c.options[3], &c.options[4], &c.options[5]) != EOF)
                      {
                        if (strcmp(c.cin, cin)==0)
                        {
                            printf("Read citoyen: CIN=%s, Name=%s %s, Tel=%s, Email=%s, Address=%s, MDP=%s\n",
                   c.cin, c.nom, c.prenom, c.tel, c.email, c.adresse, c.mdp);
            printf("Birth Date: %d/%d/%d, Genre: %d, Options: %d %d %d %d %d %d\n",
                   c.dn[0], c.dn[1], c.dn[2], c.genre,
                   c.options[0], c.options[1], c.options[2], c.options[3], c.options[4], c.options[5]);printf("\n");
                      }
                      else
                      feedback=0;
                      
                      

} if (feedback==0){printf("feedback: %d\n", feedback);}
    }
    fclose(f);
}

void ajouter_vehicule(char * filename ,vehicule v )
{   
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d ", v.cin,v.matricule,v.marque,v.type, v.type_matricule);
        fprintf(f,"\n");
        fclose(f);
    
    }
    
}
void supprimer_vehicule(char *filename,char cin[10])
{
    int feedback=0,i;
    vehicule v;
    FILE * f=fopen(filename, "r");
    FILE * f1=fopen("temp.txt", "w");
    if(f!=NULL && f1!=NULL)
    {
        while(fscanf(f, "%s %s %s %d %d ", v.cin,v.matricule,v.marque,&v.type, &v.type_matricule )!= EOF)
        {
            if(strcmp(v.cin, cin) == 0)
                feedback=1;
            else
            {
                fprintf(f1,"%s %s %s %d %d ",v.cin,v.matricule,v.marque,v.type, v.type_matricule );
                fprintf(f1,"\n");

           }
        }
        fclose(f);
    fclose(f1);
    remove(filename);
    rename("temp.txt", filename);
    printf(" feedback: %d\n",feedback);
    }
}

/*void chercher_vehicule(char *filename,char cin[10])
{   
    int i,feedback;
    vehicule v;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    { while(fscanf(f, "%s %s %s %d %d",v.cin,v.matricule,v.marque,&v.type, &v.type_matricule) != EOF)
                      {
                        if (strcmp(v.cin, cin)==0)
                        { feedback=1;
                          printf("CIN=%s ""Matricule= %s ""Marque est %s ""Type: %d\n",v.cin,v.matricule,v.marque,v.type);}
                      
                      
                      

} if (feedback==0){printf("feedback: %d\n", feedback);}
    }
    fclose(f);
}
void modifier_vehicule(char *filename , char matricule[20], vehicule new) {
    vehicule v;
    int feedback = 0;
    FILE *f = fopen(filename, "r");
    FILE *f1 = fopen("temp.txt", "w");

    if (f != NULL && f1 != NULL) {
        while (fscanf(f, "%s %s %s %d %d", v.cin, v.matricule, v.marque, &v.type, &v.type_matricule) != EOF) {
            if (strcmp(v.matricule, matricule) == 0 && feedback == 0) {
                // Replace the entry
                fprintf(f1, "%s %s %s %d %d\n",
                        new.cin, new.matricule, new.marque, new.type, new.type_matricule);
                feedback = 1;
            } else {
                // Write the existing entry
                fprintf(f1, "%s %s %s %d %d\n",
                        v.cin, v.matricule, v.marque, v.type, v.type_matricule);
            }
        }

        fclose(f);
        fclose(f1);

        // Replace the original file with the modified one
        remove(filename);
        rename("temp.txt", filename);

        printf("Modification result (1 = success, 0 = failure): %d\n", feedback);
    } else {
        if (f) fclose(f);
        if (f1) fclose(f1);
        printf("Error: Could not open files.\n");
    }
}
*/
void modifier_vehicule(char *filename, char matricule[20], vehicule new) {
    vehicule v;
    int feedback = 0;
    FILE *f = fopen(filename, "r");
    FILE *f1 = fopen("temp.txt", "w");

    if (f != NULL && f1 != NULL) {
        while (fscanf(f, "%s %s %s %d %d", v.cin, v.matricule, v.marque, &v.type, &v.type_matricule) != EOF) {
            if (strcmp(v.matricule, matricule) == 0 && feedback == 0) {
                // Replace the old vehicule with the new one
                fprintf(f1, "%s %s %s %d %d\n",
                        new.cin, new.matricule, new.marque, new.type, new.type_matricule);
                feedback = 1;
            } else {
                // Write the existing vehicule to the temp file
                fprintf(f1, "%s %s %s %d %d\n",
                        v.cin, v.matricule, v.marque, v.type, v.type_matricule);
            }
        }

        if (feedback == 0) {
            // If no match was found, add the new vehicule at the end
            fprintf(f1, "%s %s %s %d %d\n",
                    new.cin, new.matricule, new.marque, new.type, new.type_matricule);
        }

        fclose(f);
        fclose(f1);

        // Replace the original file with the modified one
        remove(filename);
        rename("temp.txt", filename);

        printf("Modification result (1 = success, 0 = not found, added): %d\n", feedback);
    } else {
        if (f) fclose(f);
        if (f1) fclose(f1);
        printf("Error: Could not open files.\n");
    }
}
