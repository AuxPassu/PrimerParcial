#include "Inputs.h"
#include "Utilities.h"
#include "stringFormat.h"
#define EMPTY 0
#define BUSY 1

typedef struct
{
	int genreId;
	char description[51];
	int moviesCounter;
} sAuxGenre;

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
} sGenre; /** Estructura de genero **/

typedef struct
{
    int day;
    int month;
    int year;
} sDate; /** Estructura de fecha **/

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
           esta funcion pone la bandera (isEmpty) en 0 en todas las posiciones
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
 * \return int Devuelve 0 si la carga de la pelicula fue exitosa, -1 caso contrario.
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

/** \brief Busca una pelicula en el array de peliculas recibiendo como parametro su ID.
 *
 * \param sMovie[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \param int El id de la pelicula a buscar.
 * \return int Devuelve la posicion de la pelicula dentro del array, -1 si no esta en el sistema.
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
 * \return int Devuelve 0 si la pelicula fue dada de baja, -1 caso contrario.
 *
 */
int movie_removeMovie(sMovie[], int, sGenre[], int, sActor[], int, int);

/** \brief Verifica si el usuario esta conforme con alguna accion (alta, modificar, baja).
 *
 * \param char[] Mensaje que preguntara sobre la satisfaccion del usuario ante tal accion.
 * \return int Devuelve la respuesta del usuario, 1 si esta satisfecho, 0 si no lo esta.
 *
 */
int movie_verifyCompliance(char[]);

/** \brief Le pide al usuario el nombre de una pelicula y lo guarda en la posicion
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

/** \brief Le pide al usuario la fecha de estreno de una pelicula realizando las
           validaciones correspondientes y guarda mes, dia, año en la posicion
           correspondiente.
 *
 * \param sMovie[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \param int La posicion en la que se quiere guardar dia, mes, año.
 * \return void No devuelve algo.
 *
 */
void movie_getMovieDate(sMovie[], int, int);

/** \brief Ordena el array de peliculas por año de manera ascendente o descendente.
 *
 * \param sMovie[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \param int Orden 1 para ascendente, 0 para descendente.
 * \return void No devuelve algo.
 *
 */
void movie_sortMovies(sMovie[], int, int);

/** \brief Imprime el array de peliculas en forma encolumnada.
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
void movie_printMovies(sMovie[], int, sGenre[], int, sActor[], int);

/** \brief
 *
 * \param sMovie Una pelicula.
 * \param sGenre[] El array de generos.
 * \param int El tamaño del array de generos.
 * \param sActor[] El array de actores.
 * \param int El tamaño del array de actores.
 * \param int Formato 0 para forma de lista, 1 para seleccion.
 * \return void No devuelve algo.
 *
 */
void movie_printOneMovie(sMovie, sGenre[], int, sActor[], int, int);

/** \brief Carga peliculas en el array de forma automatica con datos preestablecidos.
 *
 * \param sMovie[] El array de peliculas.
 * \param int El tamaño del array de peliculas.
 * \return void No devuelve algo.
 *
 */
void movie_hardCodeMovies(sMovie[], int);

void movie_report(sMovie[], int, sGenre[], int, sActor[], int);

void movie_reportMoviesActorEEUU(sMovie[], int, sGenre[], int, sActor[], int);

void movie_reportMoviesPerGenre(sMovie[], int, sGenre[], int, sActor[], int);

void movie_reportGenreQuantityMovies(sMovie[], int, sGenre[], int);

void movie_reportGenreLessMovies(sMovie[], int, sGenre[], int);
