/*
 * arrayEmployees.h
 *
 *  Created on: May 15, 2021
 *      Author: sofia
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;


#endif /* ARRAYEMPLOYEES_H_ */


/** \brief funcion que indica que todas las posiciones del array estan vacias
 *
 * \param list[] sEmployee  array de empleados
 * \param len int   tamanio del array
 * \return int  devuelve 1 si esta todo bien y 0 sino
 *
 */
int initEmployees(sEmployee list[], int len);

/** \brief  funcion que agrega en una lista existente un nuevo empleado en la primera posicion disponible
 *
 * \param list[] sEmployee  array de empleados
 * \param len int  tamanio del array
 * \param id int*    puntero al id del empleado
 * \return int    devuelve 1 si se pudo ejecutar correctamente y 0 si el tamanio es invalido o el puntero null
 *
 */
int addEmployee(sEmployee list[], int len, int* id);

/** \brief  funcion que recorre un array buscando el primer indice libre
 *
 * \param list[] sEmployee array de estructura sEmployee
 * \param len int tamanio del array
 * \return int   devuelve el primer indice libre
 *
 */
int buscarLibre(sEmployee list[], int len);

/** \brief busqueda de un empleado por su id que se pasa por parametro (en las estructuras que estan llenas)
 *
 * \param list[] sEmployee array que recorre la busqueda
 * \param len int   tamanio del array
 * \param id int   id del empleado que se quiere buscar
 * \return int    indice del empleado
 *
 */
int findEmployeeById(sEmployee list[], int len, int id);///

/** \brief   funcion que elimina de manera logica un empleado por su id
 *
 * \param list[] sEmployee    array
 * \param len int
 * \param id int   id del empleado a eliminar
 * \return int   devuelve 1 si se ejecuto correctamente y 0 si el len es incorrecto o el puntero null
 *
 */
int removeEmployee(sEmployee list[], int len, int id);




/** \brief   funcion que elimina de manera logica un empleado por su id
 *
 * \param list[] sEmployee    array
 * \param len int
 * \return int   devuelve 1 si se ejecuto correctamente y 0 si el len es incorrecto o el puntero null
 *
 */
int modifyEmployee(sEmployee list[], int len);


/** \brief   funcion que imprime un array
 *
 * \param list[] sEmployee
 * \param len int
 * \return int  devuelve 1 si se ejecuto correctamente y 0 si el len es incorrecto o el puntero null
 *
 */
int printEmployees(sEmployee list[], int len);

/** \brief  funcion que imprime un elemento del tipo sEmployee
 *
 * \param employee sEmployee
 * \param len int
 * \return int
 *
 */
int printEmployee(sEmployee employee, int len);

/** \brief  funcion que ordena el array por apellido y sector
 *
 * \param list[] sEmployee
 * \param len int
 * \param order int   criterio de ordenamiento //criterio 1: apellido A-Z y sector Asc, 2: apellido Z-A y sector Des
 * \return int devuelve 1 si se ejecuto correctamente y 0 si el len es incorrecto o el puntero null
 *
 */
int sortEmployees(sEmployee list[], int len, int order);


/** \brief funcion que calcula el total de los sueldos, el promedio y los empleados que cobran mas que el promedio
 *
 * \param list[] sEmployee   array que recorre
 * \param len int   tamanio del array
 * \return int   devuelve 1 si se ejecuto correctamente y 0 si el len es incorrecto o el puntero null
 *
 */
int sueldosTotalesYPromedio(sEmployee list[], int len);


/** \brief imprime las opciones del menu de informes
 *
 * \return void
 *
 */
void menuInformes();

/** \brief  imprime las opciones del ABM
 *
 * \return void
 *
 */
void menu();

void mostrarSectores();

