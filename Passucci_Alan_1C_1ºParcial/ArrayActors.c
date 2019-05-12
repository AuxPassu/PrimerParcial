#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayMovies.h"

sActor actor_getActor(sActor listA[], int sizeA)
{
    int i, actor;
    sActor actorReturn; //Creo una variable auxiliar de actor.
    for(i=0; i<sizeA; i++)
    {   //Recorro mi array de actores y voy imprimiendo su ID y nombre correspondiente.
        printf("\n%d. %s", listA[i].id, listA[i].name);
    }
    printf("\n\n");
    actor = getValidInt("id del actor", 1, sizeA, 0); //El usuario elige un actor.
    for(i=0; i<sizeA; i++)
    {   //Recorro nuevamente mi array de actores y comparo si el ID del actor ingresado corresponde.
        if(listA[i].id == actor)
        {   //Guardo el actor elegido.
            actorReturn = listA[i];
            break;
        }
    }
    return actorReturn;
}

void actor_sortAndPrintActByCountry(sActor listA[], int sizeA)
{
    int i, j;
    sActor auxAct; //Creo una variable auxiliar de actor.
    sActor auxListA[sizeA]; //El ordenamiento se va a hacer sobre un auxiliar de mi array de actores para evitar desordenar el original.
    for(i=0; i<sizeA; i++)
    {
        auxListA[i] = listA[i]; //Copio mi array de actores en el array auxiliar.
    }
    for(i=0; i<sizeA-1; i++) //Utilizo el metodo de burbujeo y ordeno por pais.
    {
        for(j=i+1; j<sizeA; j++)
        {
            if(strcmp(auxListA[i].country, auxListA[j].country) > 0)
            {
                auxAct = auxListA[i];
                auxListA[i] = auxListA[j];
                auxListA[j] = auxAct;
            }
        }
    }
    printf("-----------------------------------------------\n");
    printf("%3s %27s %14s\n", "ID", "Actor", "Pais");
    printf("-----------------------------------------------\n");
    for(i=0; i<sizeA; i++)
    {   //Recorro mi array de actores y voy imprimiendo su ID y descripcion correspondiente.
        printf("%3d %27s %14s\n", auxListA[i].id, auxListA[i].name, auxListA[i].country);
    }
    printf("-----------------------------------------------\n\n");
}
