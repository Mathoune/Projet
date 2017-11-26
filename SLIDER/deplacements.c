#include <stdio.h>
#include <stdlib.h>
#include <uvsqgraphics.h>
#include "mes_types.h"
#include "jeu.h"

SLIDER avance_droite(SLIDER S)
{
	int n;
		for (n=S.x;n<S.N;n++)
		{
			if (S.mury[n]==S.y && (S.murz[n]==9))
			{
				S.x=n-1;
				return S;
			}
			if (S.mury[n]==S.y && (S.murz[n]==3))
			{
				S.x=n;
				return S;
			}
		}
		return S;
	
}
SLIDER avance_gauche(JEU j,SLIDER S)
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
		return S;
}
SLIDER avance_haut(JEU j,SLIDER S)
{

	int n;
		for (n=S.y;n<S.H;n++)
		{
			if (S.mury[n]==S.y && (S.murz[n]==0))
			{
				S.y=n;
				return S;
			}
			if (S.mury[n]==S.y && (S.murz[n]==6))
			{
				S.y=n-1;
				return S;
			}
		}
		return S;
}
SLIDER avance_bas(JEU j,SLIDER S)
{
	int n;
		for (n=S.y;n>0;n--)
		{
			if (S.mury[n]==S.y && (S.murz[n]==0))
			{
				S.y=n+1;
				return S;
			}
			if (S.mury[n]==S.y && (S.murz[n]==6))
			{
				S.y=n;
				return S;
			}
		}
		return S;
}
