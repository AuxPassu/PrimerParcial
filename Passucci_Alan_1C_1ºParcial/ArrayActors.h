/** \brief Muestra una lista con los actores actuales y le pide al usuario
           que ingrese uno.
 *
 * \param sActor[] El array de actores.
 * \param int El tamaño del array de actores.
 * \return sGenre Devuelve una estructura del tipo sActor.
 *
 */
sActor actor_getActor(sActor[], int);

/** \brief Ordena a los actores por pais y los imprime.
 *
 * \param sActor[] El array de actores.
 * \param int El tamaño del array de actores.
 * \return void No devuelve algo.
 *
 */
void actor_sortAndPrintActByCountry(sActor[], int);
