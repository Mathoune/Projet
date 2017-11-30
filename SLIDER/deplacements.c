#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "jeu.h"
#include "afficher.h"
int mur_verticalG(SLIDER S)// retourne la postion à gauche du mur le plus proche à gauche du slider
{
	int a,tmp,n;
	a=tmp=-1;
	for(n=0;n<S.N;n++)
	{
		if (S.mury[n]==S.y && S.murx[n]==S.x && S.murz[n]==9)
		{
			return S.x;
		}
		if (S.mury[n]==S.y && S.murx[n]<S.x && S.murz[n]==9)
		{
			tmp=S.murx[n];
		}
		if (S.mury[n]==S.y && S.murx[n]<S.x && S.murz[n]==3)
		{
			tmp=S.murx[n]+1;
		}
		if (tmp>a) a=tmp;
	}
	if(a==-1) a=0;
	return a;
}
int mur_verticalD(SLIDER S)
{
	int a,tmp,n;
	a=tmp=S.L+1;
	for(n=0;n<S.N;n++)
	{
		if (S.mury[n]==S.y && S.murx[n]==S.x && S.murz[n]==3)
		{
			return S.x;
		}
		if (S.mury[n]==S.y && S.murx[n]>S.x && S.murz[n]==9)
		{
			tmp=S.murx[n]-1;
			printf("ici \n");
		}
		if (S.mury[n]==S.y && S.murx[n]>S.x && S.murz[n]==3)
		{
			tmp=S.murx[n];
			printf("la \n");
		}
		if (tmp<a) a=tmp;
	}
	if(a==S.L+1) a=S.L-1;
	return a;
}
int mur_horizontalH(SLIDER S)// retourne la position du slider en dessous du mur le plus proche de lui
{
	int a,tmp,n;
	a=tmp=S.H+1;
	for(n=0;n<S.N;n++)
	{
		if (S.mury[n]==S.y && S.murx[n]==S.x && S.murz[n]==0)
		{
			return S.y;
		}
		if (S.murx[n]==S.x && S.mury[n]>S.y && S.murz[n]==0)
		{
			tmp=S.mury[n];
		}
		if (S.murx[n]==S.x && S.mury[n]>S.y && S.murz[n]==6)
		{
			tmp=S.mury[n]+1;
		}
		if (tmp>a) a=tmp;
	}
	if(a==S.H+1) a=S.H-1;
	return a;
}
int mur_horizontalB(SLIDER S)
{
	int a,tmp,n;
	a=tmp=-2;
	for(n=0;n<S.N;n++)
	{
		if (S.mury[n]==S.y && S.murx[n]==S.x && S.murz[n]==6)
		{
			return S.y;
		}
		if (S.murx[n]==S.x && S.mury[n]<S.y && S.murz[n]==0)
		{
			tmp=S.mury[n]+1;
		}
		if (S.murx[n]==S.x && S.mury[n]<S.y && S.murz[n]==6)
		{
			tmp=S.mury[n];
		}
		if (tmp>a) a=tmp;
	}
	if(a==-2) a=0;
	return a;
}

SLIDER avance_droite(SLIDER S)
{
	int a,i;
	a=mur_verticalD(S);
	S.x=a;
	printf("S.x= %d",S.x);
	if (a<S.sx && S.y==S.sy)
	{
		a=S.sx;
	}
	a=a*TAILLE_CASE+(TAILLE_CASE/2);
		for(i=S.px;i<a;i+=50)
		{
			attendre(10);
			effacer_le_slider(S);
			S.px+=50;
			afficher_le_slider(S);
		}
	
	return S;
}
SLIDER avance_gauche(SLIDER S) 
{
	int a,i;
	a=mur_verticalG(S);
	S.x=a;
	if (a<S.sx && S.y==S.sy)
	{
		a=S.sx;
	}
	a=a*TAILLE_CASE+(TAILLE_CASE/2);
		for(i=S.px;i>a;i-=50)
		{
			attendre(10);
			effacer_le_slider(S);
			S.px-=50;
			afficher_le_slider(S);
		}
	return S;
}
SLIDER avance_haut(SLIDER S)
{
	int a,i;
	a=mur_horizontalH(S);
	S.y=a;
	if (a>S.sy && S.x==S.sx)
	{
		a=S.sy;
	}
	a=a*TAILLE_CASE+(TAILLE_CASE/2);
		for(i=S.py;i<a;i+=50)
		{
			attendre(10);
			effacer_le_slider(S);
			S.py+=50;
			afficher_le_slider(S);
		}
	
	return S;
}
SLIDER avance_bas(SLIDER S)
{	int a,i;
	a=mur_horizontalB(S);
	S.y=a;
	if (a<S.sy && S.x==S.sx)
	{
		a=S.sy;
	}
	a=a*TAILLE_CASE+(TAILLE_CASE/2);
		for(i=S.py;i>a;i-=50)
		{
			attendre(10);
			effacer_le_slider(S);
			S.py-=50;
			afficher_le_slider(S);
		}
	return S;
}
