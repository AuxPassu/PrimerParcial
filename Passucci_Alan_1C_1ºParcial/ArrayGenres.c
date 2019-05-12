#include <stdio.h>
#include <stdlib.h>
#include "ArrayMovies.h"

sGenre genre_getGenre(sGenre listG[], int sizeG)
{
    int i, genre;
    sGenre genreReturn; //Creo una variable auxiliar de genre.
    for(i=0; i<sizeG; i++)
    {   //Recorro mi array de generos y voy imprimiendo su ID y descripcion correspondiente.
        printf("\n%d. %s", listG[i].id, listG[i].description);
    }
    printf("\n\n");
    genre = getValidInt("id del genero", 1, sizeG, 0); //El usuario elige un genero.
    for(i=0; i<sizeG; i++)
    {   //Recorro nuevamente mi array de generos y comparo si el ID del genero ingresado corresponde.
        if(listG[i].id == genre)
        {   //Guardo el genero elegido.
            genreReturn = listG[i];
            break;
        }
    }
    return genreReturn;
}
