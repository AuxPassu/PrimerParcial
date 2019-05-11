#include <stdio.h>
#include <stdlib.h>
#include "ArrayMovies.h"
#include "ArrayActors.h"
#define SIZE_MOVIES 1000
#define SIZE_GENRES 5
#define SIZE_ACTORS 10

/**
- Falta hacer una funcion que verifique fecha segun mes.
- Falta cambiar y agregar comentarios.
**/

int main()
{
    int option, loaded, toRemove, removed, moviesCounter = 21; //Inicializo el contador de peliculas en 21 porque hardcodie 21 peliculas.
    char userContinue = 's';
    sMovie arrayMovie[SIZE_MOVIES];
    sGenre arrayGenre[SIZE_GENRES] = {{1,"Accion"},{2,"Comedia"},{3, "Drama"},{4, "Romance"},{5, "Terror"}}; //Hardcodeo un array de generos y actores.
    sActor arrayActor[SIZE_ACTORS] = {{1,"Scarlett Johansson","Argentina"},{2,"Robert Downey Jr.","EEUU"},{3, "Mark Rufalo","Canada"},{4, "Chris Evans","EEUU"},{5, "Chris Hermsworth","Argentina"},{6,"Samuel Jackson","EEUU"},{7,"Gwyneth Paltrow","Canada"},{8,"Paul Rudd","Argentina"},{9,"Bradley Cooper","EEUU"},{10,"Josh Brolin","Canada"}};
    movie_initMovies(arrayMovie, SIZE_MOVIES); //Indico que el vector esta limpio de datos.
    movie_hardCodeMovies(arrayMovie, SIZE_MOVIES); //Hardcodeo peliculas para tener algunas con las cuales trabajar.
    do
    {
        option = movie_showMenu(" 1. Alta de pelicula.\n 2. Modificar datos de pelicula.\n 3. Baja de pelicula.\n 4. Listar peliculas y actores.\n 5. Salir."); //Creo el menu principal.
        switch(option)
        {
            case 1:
                loaded = movie_addMovie(arrayMovie, SIZE_MOVIES, arrayGenre, SIZE_GENRES, arrayActor, SIZE_ACTORS);
                if(loaded == 0) //Si la carga de la pelicula fue exitosa, mi contador de peliculas aumenta.
                {
                    moviesCounter++;
                    printf("\nPelicula dada de alta con exito\n\n");
                }
                system("pause");
                break;
            case 2:
                if(moviesCounter > 0) //Solo puedo modificar datos si existen peliculas en el sistema.
                {
                    movie_modifyMovieInfo(arrayMovie, SIZE_MOVIES, arrayGenre, SIZE_GENRES, arrayActor, SIZE_ACTORS);
                }
                else
                {
                    printf("Error: No hay peliculas cargadas en el sistema.\n\n");
                    system("pause");
                }

                break;
            case 3:
                if(moviesCounter > 0) //Solo puedo dar de baja si existen peliculas en el sistema.
                {   //Ordeno y muestro la lista actual de peliculas (por año) para que se puedan visualizar todos los datos de las mismas.
                    movie_sortMovies(arrayMovie, SIZE_MOVIES, 1);
                    movie_printMovies(arrayMovie, SIZE_MOVIES, arrayGenre, SIZE_GENRES, arrayActor, SIZE_ACTORS);
                    toRemove = getValidInt("ID de la pelicula a dar de baja", 1000, 1999, 0); //Pido un ID valido para hacer su baja logica.
                    removed = movie_removeMovie(arrayMovie, SIZE_MOVIES, arrayGenre, SIZE_GENRES, arrayActor, SIZE_ACTORS, toRemove);
                    if(removed != -1) //Si ese pelicula existe en el sistema, la doy de baja y disminuyo mi numero de peliculas en el sistema.
                    {
                        printf("\nSe ha dado de baja a la pelicula exitosamente.\n\n");
                        moviesCounter--;
                    }
                }
                else
                {
                    printf("Error: No hay peliculas cargadas en el sistema.\n\n");
                }
                system("pause");
                break;
            case 4:
                if(moviesCounter > 0) //Solo puedo informar si existen peliculas en el sistema.
                {   //Ordeno y muestro la lista actual de peliculas (por año). Luego realizo el listar.
                    movie_sortMovies(arrayMovie, SIZE_MOVIES, 1);
                    movie_printMovies(arrayMovie, SIZE_MOVIES, arrayGenre, SIZE_GENRES, arrayActor, SIZE_ACTORS);
                    actor_sortAndPrintActByCountry(arrayActor, SIZE_ACTORS);
                }
                else
                {
                    printf("Error: No hay peliculas cargadas en el sistema.\n\n");
                }
                system("pause");
                break;
            case 5:
                userContinue = 'n'; //Si la opcion 5 es elegida, cierro el programa.
                printf("Saliendo...\nPrograma terminado.\n\n");
                system("pause");
                break;
            default:
                printf("Error: Opcion invalida.\n\n");
                system("pause");
                break;
        }
    } while(userContinue == 's');
    return 0;
}
