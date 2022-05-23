//Archivo .h
/*
Autor: Franciscomilan
Fechas: 14/05/2022 - 21/05/2022
Escuela: Universidad uvm
Materia: Programacion estructurada
Profesor: Armando Cruz
Ciclo: 01/2022
Descripcion: Programa en C que sera proyecto final de la materia programacion estructurada
*/

indef _MILIBRERIA
define _MILIBRERIA

//Librerias universales
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Prototipos
//lers para los char
//leerf para los flotantes
//leerd para los enteros
void leers(char *mensaje, char s[], int n);
//void leers(char s[], int n);
float leerf(char *mensaje, float inferior, float superior);
int leerd(char *mensaje, int inferior, int superior);


//Encabezados de funciones 
void agregar (struct extintores x[]);
void listarTodos (struct extintores x[]);
void listarPorEdificio (struct extintores x[]);
void listarPorFecha (struct extintores x[]);
void listarPorTipo (struct extintores x[]);
void recarga (struct extintores x[]);
void guardarArchivo (struct extintores x[]);
void cargarArchivo (struct extintores x[]);

//Prototipos de las funciones de validar entero
int validar_entero(char *cadena);
int validar_decimal (char *cadena);

include "proglibreria_final.cpp"
endif