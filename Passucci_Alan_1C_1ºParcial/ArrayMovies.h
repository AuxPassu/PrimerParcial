#include "Inputs.h"
#include "Utilities.h"
#include "stringFormat.h"
#define EMPTY 0
#define BUSY 1

typedef struct
{
    int id;
    char name[51];
    char country[51];
} sActor; /** Estructura de actor **/

typedef struct
{
    int id;
    char description[51];
} sGenre; /** Estructura de genero**/

typedef struct
{
    int day;
    int month;
    int year;
} sDate; /** Estructura de fecha**/

typedef struct
{
    int id;
    char title[51];
    sDate premiere;
    int genreId;
    int actorId;
    int isEmpty;
} sMovie; /** Estructura de peliculas **/

/** \brief Limpia la pantalla, muestra un menu de opciones en base al parametro recibido
           y devuelve un entero que representa la opcion elegida por el usuario.
 *
 * \param char[] Las opciones a mostrar.
 * \return int Opcion elegida por el usuario.
 *
 */
int movie_showMenu(char[]);

/** \brief Para indicar que todas las posiciones del array estan vacias,
           esta funcion pone la bandera (isEmpty) en cero en todas las posiciones
           del array.
 *
 * \param sMovies[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \return void No devuelve algo.
 *
 */
void movie_initMovies(sMovie[], int);

/** \brief Busca en el array de peliculas la primer posicion libre fijandose si
           isEmpty == EMPTY
 *
 * \param sMovie[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \return int Devuelve la primer posicion libre, -1 en caso de que no encuentre
               espacio disponible.
 *
 */
int movie_searchEmpty(sMovie[], int);

/** \brief Pide los datos de una pelicula y los agrega al array de peliculas en la primer
           posicion libre.
 *
 * \param sMovie[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \param sGenre[] El array de generos.
 * \param int El tamaño del array de generos.
 * \param sActor[] El array de actores.
 * \param int El tamaño del array de actores.
 * \return int Devuelve cero si la carga de la pelicula fue exitosa, -1 caso contrario.
 *
 */
int movie_addMovie(sMovie[], int, sGenre[], int, sActor[], int);

/** \brief Se realizan operaciones relacionadas a la modificacion de datos de una pelicula.
           El usuario podra elegir opciones en un nuevo menu.
 *
 * \param sMovie[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \param sGenre[] El array de generos.
 * \param int El tamaño del array de generos.
 * \param sActor[] El array de actores.
 * \param int El tamaño del array de actores.
 * \return void No devuelve algo.
 *
 */
void movie_modifyMovieInfo(sMovie[], int, sGenre[], int, sActor[], int);

/** \brief Muestra una lista con los generos actuales y le pide al usuario
           que ingrese uno.
 *
 * \param sGenre[] El array de generos.
 * \param int El tamaño del array de generos.
 * \return sGenre Devuelve una estructura del tipo sGenre.
 *
 */

int movie_findMovieById(sMovie[], int, int);

/** \brief Elimina de manera logica (isEmpty = EMPTY) una pelicula recibiendo como
           parametro su ID.
 *
 * \param sMovie[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \param sGenre[] El array de generos.
 * \param int El tamaño del array de generos.
 * \param sActor[] El array de actores.
 * \param int El tamaño del array de actores.
 * \param int El id de la pelicula a eliminar.
 * \return int Devuelve cero si la pelicula fue dada de baja, -1 caso contrario.
 *
 */
int movie_removeMovie(sMovie[], int, sGenre[], int, sActor[], int, int);

/** \brief Verifica si el usuario esta conforme con alguna accion (alta, modificar, baja).
 *
 * \param char[] Mensaje que preguntara sobre la satisfaccion del usuario ante tal accion.
 * \return int Devuelve la respuesta del usuario, 1 si esta satisfecho, cero si no lo esta.
 *
 */
int movie_verifyCompliance(char[]);

/** \brief Le pide al usuario el nombre de un pelicula y lo guarda en la posicion
           correspondiente. Luego corrige el formato de tal manera que quede una mayuscula
           al principio de un nombre y el resto en minusculas.
 *
 * \param sMovie[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \param int La posicion en la que se quiere guardar ese nombre.
 * \return void No devuelve algo.
 *
 */
void movie_getMovieTitle(sMovie[], int, int);

void movie_getMovieDate(sMovie[], int, int);

void movie_sortMovies(sMovie[], int, int);

void movie_printMovies(sMovie[], int, sGenre[], int, sActor[], int);

void movie_printOneMovie(sMovie, sGenre[], int, sActor[], int, int);

/** \brief Carga peliculas en el arreglo de forma automatica con datos preestablecidos.
 *
 * \param sEmployee[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \return void No devuelve algo.
 *
 */
void movie_hardCodeMovies(sMovie[], int);
