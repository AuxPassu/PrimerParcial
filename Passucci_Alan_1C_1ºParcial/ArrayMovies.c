#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayMovies.h"
#include "ArrayGenres.h"
#include "ArrayActors.h"

int movie_showMenu(char message[])
{
    int option;
    system("cls");
    printf("---------------------------------\n");
    printf("%s", message);
    printf("\n---------------------------------\n\n");
    option = getValidInt("una opcion", 1, 5, 0); //Pido un entero valido sin rango.
    printf("\n");
    return option;
}

void movie_initMovies(sMovie listM[], int sizeM)
{
    int i;
    for(i=0; i<sizeM; i++)
    {
        listM[i].isEmpty = EMPTY; //Dejo en libre todos los espacios de mi array de peliculas.
    }
}

int movie_addMovie(sMovie listM[], int sizeM, sGenre listG[], int sizeG, sActor listA[], int sizeA)
{
    int loaded = -1, isSatisfied;
    int index = movie_searchEmpty(listM, sizeM); //Busco lugar libre en mi array de peliculas.
    sGenre genre; //Variable auxiliar de genero.
    sActor actor;
    if(index != -1) //Si hay lugar, empiezo a pedir datos de una pelicula.
    {
        printf("Dando de alta una pelicula...\n\n");
        listM[index].id = getRandomNumber(1000, 1999, 1); //Calculo de manera random el id de la pelicula.
        movie_getMovieTitle(listM, 51, index); //Llamo a la funcion que me permite pedir titulo.
        movie_getMovieDate(listM, sizeM, index);
        genre = genre_getGenre(listG, sizeG); //Obtengo los datos del genero ingresado y lo vinculo a la pelicula.
        listM[index].genreId = genre.id;
        actor = actor_getActor(listA, sizeA); //Obtengo los datos del actor ingresado y lo vinculo a la pelicula.
        listM[index].actorId = actor.id;
        movie_printOneMovie(listM[index], listG, sizeG, listA, sizeA, 1);
        isSatisfied = movie_verifyCompliance("'s' para confirmar el alta de la pelicula"); //Verifico la conformidad del usuario con esta alta.
        if(isSatisfied == 1)
        {   //Si esta satisfecho, el lugar pasa a estar ocupado e indico que se pudo cargar a la pelicula.
            listM[index].isEmpty = BUSY;
            loaded = 0;
        }
        else
        {
            printf("\nSe cancelo el alta de la pelicula.\n\n");
        }
    }
    else{
        printf("Error: No hay mas espacio libre.\n\n");
    }
    return loaded;
}

void movie_modifyMovieInfo(sMovie listM[], int sizeM, sGenre listG[], int sizeG, sActor listA[], int sizeA)
{
    int option, idToFind, index, isSatisfied, found = 0;
    sMovie auxMov[sizeM]; //Creo un array auxiliar de peliculas.
    sActor actor;
    do
    {
        option = movie_showMenu(" 1. Seleccionar una pelicula.\n 2. Modificar titulo.\n 3. Modificar actor.\n 4. Modificar fecha de estreno.\n 5. Atras."); //Creo un nuevo menu correspondiente a modificaciones.
        switch(option)
        {
            case 1:
                if(found == 1)
                {   //La variable found me ayuda a saber si se selecciono a un pelicula para realizar modificaciones en sus datos.
                    printf("Pelicula seleccionado actualmente:\n");
                    movie_printOneMovie(listM[index], listG, sizeG, listA, sizeA, 1); //Mostrare a la pelicula seleccionada actualmente al elegir cualquier opcion.
                    printf("\n");
                } //Ordeno y muestro la lista actual de peliculas por año para que se puedan visualizar todos los datos de las mismos.
                movie_sortMovies(listM, sizeM, 1);
                movie_printMovies(listM, sizeM, listG, sizeG, listA, sizeA);
                idToFind = getValidInt("ID de la pelicula a modificar datos", 1000, 1999, 0); //Pido el ID de la pelicula a modificar sus datos.
                index = movie_findMovieById(listM, sizeM, idToFind); //Lo busco.
                if(index != -1)
                {   //Si existe, tengo a una pelicula seleccionada y lista para realizar modificaciones.
                    found = 1;
                    printf("\nPelicula seleccionada actualmente:\n");
                    movie_printOneMovie(listM[index], listG, sizeG, listA, sizeA, 1);
                    printf("\n");
                }
                else
                {
                    printf("\nError: Pelicula no encontrada.\n");
                }
                system("pause");
                break;
            case 2:
                if(found == 1)
                {   //Siempre y cuando haya seleccionado a una pelicula, la muestro y pido el nuevo titulo de la misma.
                    printf("Pelicula seleccionado actualmente:\n");
                    movie_printOneMovie(listM[index], listG, sizeG, listA, sizeA, 1);
                    printf("\nModificando el titulo de la pelicula...\n\n");
                    movie_getMovieTitle(auxMov, 51, index); //Pido titulo.
                    isSatisfied = movie_verifyCompliance("'s' para confirmar la modificacion"); //Pregunto si quiere realizar la modificacion.
                    if(isSatisfied == 1)
                    {   //Si el usuario esta satisfecho con la modificacion, actualizo el dato de la pelicula.
                        strcpy(listM[index].title, auxMov[index].title);
                        printf("\nModificacion exitosa.\n\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada.\n\n");
                    }
                }
                else
                {
                    printf("Error: Primero debe seleccionar una pelicula.\n\n");
                }
                system("pause");
                break;
            case 3:
                if(found == 1)
                {   //Los mismos pasos pero para el actor.
                    printf("Pelicula seleccionada actualmente:\n");
                    movie_printOneMovie(listM[index], listG, sizeG, listA, sizeA, 1);
                    printf("\nModificando el actor de la pelicula...\n");
                    actor = actor_getActor(listA, sizeA);
                    auxMov[index].actorId = actor.id;
                    isSatisfied = movie_verifyCompliance("'s' para confirmar la modificacion");
                    if(isSatisfied == 1)
                    {
                        listM[index].actorId = auxMov[index].actorId;
                        printf("\nModificacion exitosa.\n\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada.\n\n");
                    }
                }
                else
                {
                    printf("Error: Primero debe seleccionar una pelicula.\n\n");
                }
                system("pause");
                break;
            case 4:
                if(found == 1)
                {   //Lo mismo para la fecha de estreno.
                    printf("Pelicula seleccionada actualmente:\n");
                    movie_printOneMovie(listM[index], listG, sizeG, listA, sizeA, 1);
                    printf("\nModificando fecha de estreno de la pelicula...\n");
                    movie_getMovieDate(auxMov, sizeM, index);
                    isSatisfied = movie_verifyCompliance("'s' para confirmar la modificacion");
                    if(isSatisfied == 1)
                    {
                        listM[index].premiere.month = auxMov[index].premiere.month;
                        listM[index].premiere.day = auxMov[index].premiere.day;
                        listM[index].premiere.year = auxMov[index].premiere.year;
                        printf("\nModificacion exitosa.\n\n");
                    }
                    else
                    {
                        printf("\nModificacion cancelada.\n\n");
                    }
                }
                else
                {
                    printf("Error: Primero debe seleccionar una pelicula.\n\n");
                }
                system("pause");
                break;
            case 5: //Si se elige la opcion 5, salimos del menu modificar y volvemos al anterior.
                break;
            default:
                printf("Error: Opcion invalida.\n\n");
                system("pause");
                break;
        }
    }while(option != 5); //Permaneceremos en este menu hasta que se elija la opcion 5.
}

int movie_removeMovie(sMovie listM[], int sizeM, sGenre listG[], int sizeG, sActor listA[], int sizeA, int toRemove)
{
    int itCould = -1, index, isSatisfied;
    index = movie_findMovieById(listM, sizeM, toRemove); //Busco el ID de la pelicula a dar de baja.
    if(index != -1)
    {   //Si existe, pido la conformidad del usuario.
        movie_printOneMovie(listM[index], listG, sizeG, listA, sizeA, 1);
        isSatisfied = movie_verifyCompliance("'s' para confirmar la baja del pelicula");
        if(isSatisfied == 1)
        {   //Si esta satisfecho con su decision, hago una baja logica cambiando isEmpty a 0.
            listM[index].isEmpty = EMPTY;
            itCould = 0; //Tambien señalo que se pudo eliminar del sistema a esa pelicula.
        }
        else
        {
            printf("\nSe cancelo la baja de la pelicula.\n\n");
        }
    }
    else
    {
        printf("\nError: Pelicula no encontrada.\n\n");
    }
    return itCould;
}

int movie_searchEmpty(sMovie listM[], int sizeM)
{
    int i, index = -1;
    for(i=0; i<sizeM; i++)
    {   //Recorro mi array de peliculas hasta encontrar una posicion libre.
        if(listM[i].isEmpty == EMPTY)
        {   //Si encuentro espacio libre, mi index sera esa posicion.
            index = i;
            break;
        }
    }
    return index;
}

int movie_findMovieById(sMovie listM[], int sizeM, int idToFind)
{
    int i, index = -1;
    for(i=0; i<sizeM; i++)
    {   //Recorro mi array de peliculas y voy comparando el ID ingresado por el usuario.
        if(listM[i].id == idToFind && listM[i].isEmpty == BUSY) //Tambien debo tener en cuenta si es una pelicula activa.
        {   //Si encuentro la pelicula, mi index sera esa posicion.
            index = i;
            break;
        }
    }
    return index;
}

void movie_getMovieTitle(sMovie listM[], int strSize, int index)
{
    getValidString("titulo", listM[index].title, strSize, 1); //Pido titulo de la pelicula y luego le doy formato.
    changeStringToLower(listM[index].title);
    changeFirstToUpper(listM[index].title);
}

void movie_getMovieDate(sMovie listM[], int sizeM, int index)
{
    printf("\nIngresando fecha de estreno...\n\n");
    listM[index].premiere.month = getValidInt("mes", 1, 12, 0); //Pido el mes.
    switch(listM[index].premiere.month) //De acuerdo al mes, realizo las validaciones correspondientes.
    {
        case 2:
            listM[index].premiere.day = getValidInt("dia", 1, 28, 0);
            break;
        case 4:
        case 6:
        case 7:
        case 8:
            listM[index].premiere.day = getValidInt("dia", 1, 30, 0);
            break;
        default:
            listM[index].premiere.day = getValidInt("dia", 1, 31, 0);
            break;
    }
    listM[index].premiere.year = getValidInt("anio", 1992, 2019, 0);
}

void movie_sortMovies(sMovie listM[], int sizeM, int order)
{   //Utilizo el metodo de burbujeo para ordenar por año a las peliculas en orden ascendente o descendente.
    int i, j;
    sMovie auxMov;
    for(i=0; i<sizeM-1; i++)
    {
        for(j=i+1; j<sizeM; j++)
        {
            if(order == 1) //Ascendente
            {
                if(listM[i].premiere.year > listM[j].premiere.year)
                {
                    auxMov = listM[i];
                    listM[i] = listM[j];
                    listM[j] = auxMov;
                }
            }
            else{ //Descendente
                if(listM[j].premiere.year > listM[i].premiere.year)
                {
                    auxMov = listM[j];
                    listM[j] = listM[i];
                    listM[i] = auxMov;
                }
            }
        }
    }
}

void movie_printMovies(sMovie listM[], int sizeM, sGenre listG[], int sizeG, sActor listA[], int sizeA)
{
    int i;
    printf("---------------------------------------------------------------------------------------------\n");
    printf("%4s %26s %13s %23s %22s\n", "ID", "Titulo", "Genero", "Fecha de Estreno", "Actor");
    printf("---------------------------------------------------------------------------------------------\n");
    for(i=0; i<sizeM; i++) //Recorro mi array de peliculas.
    {
        if(listM[i].isEmpty == BUSY)
        {   //Imprimo la pelicula siempre y cuando este activa.
            movie_printOneMovie(listM[i], listG, sizeG, listA, sizeA, 0);
        }
    }
    printf("---------------------------------------------------------------------------------------------\n\n");
}

void movie_printOneMovie(sMovie oneMovie, sGenre listG[], int sizeG, sActor listA[], int sizeA, int format)
{
    int i, j;
    char genreDescription[51]; //Cadena de caracteres auxiliar para guardar descripcion de genero.
    char actorName[51]; //Cadena de caracteres auxiliar para guardar nombre del actor.
    for(i=0; i<sizeG; i++)
    {   //Recorro el array de generos y si el ID de genero de un pelicula corresponde con alguno de los generoes existentes, guardo descripcion.
        if(oneMovie.genreId == listG[i].id)
        {
            strcpy(genreDescription, listG[i].description);
            break;
        }
    }
    for(j=0; j<sizeA; j++)
    {   //Hago lo mismo pero para los actores y guardo el nombre.
        if(oneMovie.actorId == listA[j].id)
        {
            strcpy(actorName, listA[j].name);
            break;
        }
    }
    if(format == 0)
    {   //Una vez que tengo descripcion del genero y nombre del actor de la pelicula, segun el formato elegido, imprimo de una u otra manera a la misma.
        printf("%5d %25s %13s %12d/%2d/%d %25s\n", oneMovie.id, oneMovie.title, genreDescription, oneMovie.premiere.day, oneMovie.premiere.month, oneMovie.premiere.year, actorName);
    }
    else
    {
        printf("\nID: %d | Titulo: %s | Genero: %s | Fecha de estreno: %d/%d/%d | Actor: %s\n", oneMovie.id, oneMovie.title, genreDescription, oneMovie.premiere.day, oneMovie.premiere.month, oneMovie.premiere.year, actorName);
    }
}

int movie_verifyCompliance(char message[])
{
    int isSatisfied = 0; //Esta variable va a indicar si el usuario esta satisfecho con lo que hizo.
    char answer; //Repuesta del usuario.
    printf("\n");
    answer = getChar(message); //Le pido al usuario que ingrese una respuesta.
    if(answer == 's' || answer == 'S')
    {   //Si responde 's' o 'S', esta satisfecho.
        isSatisfied = 1;
    }
    return isSatisfied; //Retorno ese valor.
}

void movie_hardCodeMovies(sMovie listM[], int sizeM)
{   //Harcodeo id, titulo, fecha de estreno, actor y genero de varias peliculas.
    int i;
    int ids[] = {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020};
    char titles[][51] = {"Avengers EndGame","Thor","Cellular","Men in Black 4","IronMan","13 Going on 30","Lucy","Nace una estrella","Dime con cuantos?","Guardianes de la galaxia","A perfect murder","La isla","Que paso ayer","Home Alone 3","Deadpool","Sherlock Holmes","Men in Black 3","Avengers Infinity War","Grandes esperanzas","SWAT","XxX"};
    int premiereDay[] = {20,10,2,10,5,7,9,8,4,20,6,3,5,6,7,5,2,6,8,20,11};
    int premiereMonth[] = {4,6,5,7,9,5,2,3,4,5,8,10,2,10,12,6,5,4,12,2,5};
    int premiereYear[] = {2019,2013,2004,2019,2012,2004,2014,2018,2010,2014,1995,2005,2013,1997,2015,2011,2010,2017,1995,1998,1992};
    int actorIds[] = {2,5,4,5,2,3,1,9,4,9,7,1,9,1,10,2,10,10,7,6,6};
    int genres[] = {1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1};
    for(i=0; i<sizeM-979; i++)
    {
        listM[i].id = ids[i];
        strcpy(listM[i].title, titles[i]);
        listM[i].premiere.day = premiereDay[i];
        listM[i].premiere.month = premiereMonth[i];
        listM[i].premiere.year = premiereYear[i];
        listM[i].actorId = actorIds[i];
        listM[i].genreId = genres[i];
        listM[i].isEmpty = BUSY;
    }
}
