#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "mes_types.h"
#include "jeu.h"


#define nb_fichiers 3

void
lireDossier (char *s, DIR * rep, char *nom[3])
{
  int i = 0;
  struct dirent *ent = NULL;

  while ((ent = readdir (rep)))
    {
		  printf ("FICHIER: %s\n", ent->d_name);
		  if (strcmp (ent->d_name, ".") != 0 && strcmp (ent->d_name, "..") != 0)
		{
		  nom[i] = ent->d_name;
		  printf ("nom = %s \n", nom[i]);
		  i++;
		}

    }
}

void
parcourirDossier (DIR * rep, char *nom[3])
{
  char *chemin = "dir_slider";
  rep = opendir (chemin);

  if (rep == NULL)
    {
      printf ("Le dossier '%s' n'a pas pu etre ouvert", chemin);
      exit (-1);
    }

  lireDossier (chemin, rep, nom);	
}

int taille(char chemin[100])
{
	int i=0;
	while(chemin[i] !='\0') i++;
	printf("i = %d",i);
	return i;
}

void
ouvrir_dir (SLIDER S, LISTE l)
{
  DIR *rep = NULL;
  char* nom[nb_fichiers];
  int i=0;
  int t=0;
  char* nomfichier;
  parcourirDossier (rep,nom);

	while(i!=3){
		
	 char chemin[100]="dir_slider/";
	 strcat(chemin,nom[i]);
	 t=taille(chemin);
	 nomfichier=malloc(t*sizeof(char)+1);
	 strcpy(nomfichier,chemin);
	 partie(S,nomfichier,l);
	}

  if (closedir (rep) == -1)
    {
      printf ("fermeture dossier impossible");
      exit (-1);
    }
}
