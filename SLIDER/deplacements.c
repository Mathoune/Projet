#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "jeu.h"

SLIDER avance_droite(SLIDER S)
{
	int n;
		for (n=S.x;n<S.L;n++)
		{
			if (S.mury[n]==S.y && (S.murz[n]==9))
			{
				S.x=n;
				return S;
			}
			if (S.mury[n]==S.y && (S.murz[n]==3))
			{
				S.x=n+1;
				return S;
			}
		}
		if(n==S.L) S.x=S.L-1;

		return S;
	
}
SLIDER avance_gauche(SLIDER S)
{
	int n;
		for (n=S.x;n>0;n--)
		{
			if (S.mury[n]==S.y && (S.murz[n]==9))
			{
				S.x=n;
				return S;
			}
			if (S.mury[n]==S.y && (S.murz[n]==3))
			{
				S.x=n-1;
				return S;
			}
		}
		S.x=0;
		return S;
		
}
SLIDER avance_haut(SLIDER S)
{

	int n;
		for (n=S.y;n<S.H;n++)
		{
			if (S.murx[n]==S.x && (S.murz[n]==0))
			{
				S.y=n;
				return S;
			}
			if (S.murx[n]==S.x && (S.murz[n]==6))
			{
				S.y=n-1;
				return S;
			}
		}
		printf("n= %d",n);
		S.y=S.H-1;
		return S;
}
SLIDER avance_bas(SLIDER S)
{
	int n;
		for (n=S.y;n>0;n--)
		{
			if (S.murx[n]==S.y && (S.murz[n]==0))
			{
				S.y=n;
				return S;
			}
			if (S.murx[n]==S.y && (S.murz[n]==6))
			{
				S.y=n-1;
				return S;
			}
			
		}
	
		S.y=0;
		return S;
}
