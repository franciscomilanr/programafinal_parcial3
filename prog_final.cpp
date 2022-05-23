/*
Autor: Franciscomilan
Fechas: 14/05/2022 - 21/05/2022
Escuela: Universidad uvm
Materia: Programacion estructurada
Profesor: Armando Cruz
Ciclo: 01/2022
Descripcion: Programa en C que sera proyecto final de la materia programacion estructurada
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
//Declaracion de variables globales
#define MAX 20
int n=0;
//Librerias propias
#include "proglibreria_final.h"
//Variables golbales
//Estrcutura
struct extintores {
	char tipo[30];
	char edificio[30];
	char area[30];  
	int mesRecarga;
	int añoRecarga;
};
//Prototipos de funcion
int menu();
//Funcion principal
int main () {
	int op;
	struct extintores datos[MAX];
	do {
		op=menu();
		switch(op) {
			case 0: printf("\n \t- Adios - \n");
				break;
			case 1:  agregar (datos);
				break;
			case 2: listarTodos (datos);
				break;
			case 3: listarPorEdificio (datos);
				break;
			case 4: listarPorFecha (datos);
				break;
			case 5: listarPorTipo (datos);
				break;
			case 6: recarga (datos);
				break;
			case 7: guardarArchivo (datos);
				break;
			case 8: cargarArchivo (datos);
				break;
		}
	}while (op!=0);
	return 0;
	}

//Menu
int menu() {
	int opcion;
  printf("\n\t Proyecto final de franciso \n");
	printf("\n\n--------------------------------------------------------\n");
	printf("|                       < MENU >                           |\n");
	printf("|----------------------------------------------------------|\n");
	printf("|          Num. Opcion      |	      	Funcion             |\n");
	printf("|                 0.        |       Salir                  |\n");
	printf("|                 1.        |       Agregar extintor       |\n");
	printf("|                 2.        |       Listar el total        |\n");
	printf("|                 3.        |       Listar por edificio    |\n");
	printf("|                 4.        |       Listar por fecha       |\n");
	printf("|                 5.        |       Listar por tipo        |\n");
	printf("|                 6.        |       Registrar recarga      |\n");
	printf("|                 7.        |       Guardar archivo        |\n");
	printf("|                 8.        |       Cargar archivo         |\n");
	printf("----------------------------------------------------------\n");
	opcion=leerd(" \n * Ingresa la opcion que deseas usar: ", 0, 8);	
	return opcion;
}	            

//lers para los char
//leerf para los flotantes
//leerd para los enteros

//Funcion 1 - Agregar extintor
void agregar (struct extintores x[]) {
	printf("\n \t- 1 - Entraste a agregar el extintor -\n");
  	int pregunta;
	while (n<MAX) {
    printf("\n \t < Ingresa los siguientes datos para agregar >\n");
		leers("\nTipo de extintor: ", x[n].tipo,30);
    leers("\nEdificio en el que se ubica: ", x[n].edificio,30);
    leers("\nArea en la que se ubica: ", x[n].area,30);
    x[n].mesRecarga=leerd("\nMes de recarga : ", 01, 12);
    x[n].añoRecarga=leerd("\nAño de recarga : ", 01, 23);
		pregunta=leerd("\n ¿ Agregar otro extintor? (1-Si, 0-No): ",0,1);
		n++;
		if (pregunta==0) {
			break;
		}	
	}
	if (n==MAX) {
		printf(" Arreglo lleno ! \n");
		system("PAUSE");
	}
}

//Funcion 2 - Listar todos los extintores
void listarTodos (struct extintores x[]) {
	printf("\n \t- 2 - Entraste a listar todos -\n");
  //La funcion imprimir en el parametro tipo de le indica que va a imprimir
	char mensaje[20];

	printf("\n--------------------Extintores %s---------------------\n", mensaje);
	printf("--------------/- DATOS DE LOS EXTINTORES -/-----------------\n");
	printf(" Num\t Tipo\t\t Edificio\t\t Area\t\t MesRecarga\t AñoRecarga");
	printf("\n------------------------------------------------------\n\n");

	for (int i=0;i<n;i++) {
		//int aprobados;
    printf("%2d\t\t %s\t\t %s\t\t\t %s\t\t\t %2.2d\t\t\t %2.2d\n", i+1 , x[i].tipo,  x[i].edificio, x[i].area, x[i].mesRecarga, x[i].añoRecarga);
				//break;

		}
	printf("\n----------------------------------------------------\n");
	system("PAUSE");
 // }
}

//Funcion 3 - Listar extintores de un edificio especifico
void listarPorEdificio (struct extintores x[]) {
  char filtroEdificio[30];
   int i=0;
	printf("\n \t- 3 -Entraste a listar por edificio -\n");
  printf("\n \t¿De cual edificio quieres filtrar los datos? ");
  scanf("%s",filtroEdificio);
  printf("\nMostrando los datos del edificio: ' %s ' \n", filtroEdificio);
for (i = 0; i<n; i++) {
   int resultado = (strcmp (x[i].edificio, filtroEdificio));
  printf("\n\t-------------------------------------------\n");
    if (resultado == 0) { 
      printf("%2d\t\t %s\t\t %s\t\t\t %s\t\t\t %2.2d\t\t\t %2.2d\n", i+1 , x[i].tipo,  x[i].edificio, x[i].area, x[i].mesRecarga, x[i].añoRecarga); 
    } else {
      printf("\n\t No existe el edificio \n");
    }
  printf("\n\t--------------------------------------------\n");
   } 
  system("PAUSE");
}

//Funcion 4 - Listar extintores de una fecha especifica
void listarPorFecha (struct extintores x[]) {
//Preguntar por mes y año
int mesFiltro;
int añoFiltro;  
int i=0;
	printf("\n \t- 4 - Entraste a listar por fecha especifica de la ultima recarga-\n");
  printf("\n¿Cual es el mes de recarga deseas consultar? ");
  scanf("%d",&mesFiltro);
  printf("\n¿Cual es el año de recarga que deseas consultar? ");
  scanf("%d",&añoFiltro);
  printf("\nMostrando los datos del mes: ' %d ' \n",mesFiltro);
    printf("\n----------------------------------------------------------\n");
    printf(" Num\t Tipo\t Edificio\t\t Area\t\t MesRecarga\t AñoRecarga");
for (i=0; i<n; i++) {
  if (mesFiltro==x[i].mesRecarga && añoFiltro==x[i].añoRecarga) {
    printf("%2d\t\t %s\t\t %s\t\t\t %s\t\t\t %2.2d\t\t\t %2.2d\n", i+1 , x[i].tipo,  x[i].edificio, x[i].area, x[i].mesRecarga, x[i].añoRecarga); 
    }
  }
  system("PAUSE");
}


//Funcion 5 - Listar extintores de un tipo especifico
void listarPorTipo (struct extintores x[]) {
  char filtroTipo[30];
  int i=0;
	printf("\n \t- 5 - Entraste a listar por tipo especifico -\n");
  printf("¿Por cual tipo de extintor deseas filtrar?: ");
  scanf("%s",filtroTipo);
  printf("\n Mostrando los datos del tipo: ' %s ' \n",filtroTipo);
  for (i = 0; i<n; i++) {
   int resultado = (strcmp (x[i].tipo, filtroTipo));
  printf("\n\t-------------------------------------------\n");
    if (resultado == 0) { 
      printf(" Num\t Tipo\t Edificio\t\t Area\t\t MesRecarga\t AñoRecarga");
      printf("%2d\t\t %s\t\t %s\t\t\t %s\t\t\t %2.2d\t\t\t %2.2d\n", i+1 , x[i].tipo,  x[i].edificio, x[i].area, x[i].mesRecarga, x[i].añoRecarga); 
    } else {
      printf("\n\t No existe el tipo ingresado \n");
    }
  printf("\n\t--------------------------------------------\n");
   } 
  system("PAUSE");
}

//Funcion 6 - Recargar extintor
void recarga (struct extintores x[]) {
  //Modificar al extintor que se ubico con el contador su fecha de recarga
  int modificacionMes;
  int modificacionAño;
  int buscarContador;
  int i=0;
	printf("\n \t- 6 - Entraste a registrar nueva recarga -\n\n");
  printf("\n¿De cual no. de extintor deseas modificar? ");
  scanf("%d",&buscarContador);
  printf("\n¿Cual es el mes de la nueva recarga?: ");
  scanf("%d",&modificacionMes);
  printf("\n¿Cual es el año de la nueva recarga?: ");
  scanf("%d",&modificacionAño);
printf(" Num\t Tipo\t Edificio\t\t Area\t\t MesRecarga\t AñoRecarga");
  //while (bucarContador==i+1)
  while (buscarContador==i+1) {
    printf("%2d\t\t %s\t\t %s\t\t\t %s\t\t\t %2.2d\t\t\t %2.2d\n", i+1 , x[i].tipo,  x[i].edificio, x[i].area, x[i].mesRecarga, x[i].añoRecarga);
    x[i].mesRecarga=modificacionMes;
    x[i].añoRecarga=modificacionAño;
    printf("\n\nSe ha modificado el registro de la fecha y mes \n");
    printf("%2d\t\t %s\t\t %s\t\t\t %s\t\t\t %2.2d\t\t\t %2.2d\n", i+1 , x[i].tipo,  x[i].edificio, x[i].area, x[i].mesRecarga, x[i].añoRecarga);     
    //break;
    //system("PAUSE");
    } 
  // MAX tiene el valor de 20
  while (buscarContador<=0 && buscarContador>=MAX) {
    printf("\nEl registro del extintor que intentas modificar no existe ");
  } 
  system("PAUSE");
}

//Funcion 7 - Guardar archivo
void guardarArchivo (struct extintores x[]) {
	printf("\n \t- 7 - Entraste a guardar archivo -\n");
  
  //Variable del archivo
	FILE *f;
  //Abrir archivo
	f=fopen("extintores.dat","w");
  //Condicionante del arreglo para validar si no se abrio
	if (f==NULL) {
		printf("\n Error al intentar guardar los datos !!! \n");
	} else {
    //Al entrar aqui significa que si abrio el archivo
		for (int i=0; i<n; i++) {
      //sixeof dice cuanto mide el dato en bites   //funcion|direccion|tamañoBites|cauntasVecesEscribir|Donde
			fwrite(&x[i],sizeof(x[i]),1,f);
		}
    //Cerrar el proceso del archivo
		fclose(f);
		printf("\n--> Se guardaron %d registro \n\n", n);
		system("PAUSE");
	}

}

//Funcion 8 - Cargar archivo
void cargarArchivo (struct extintores x[]) {
	printf("\n \t- 8 - Entraste a cargar archivo -\n");
//Leer el archivo binario y cargarlo al arreglo de estructuras
  FILE *f;
  f=fopen("extintores.dat","r");
  n=0;
  if (f==NULL){
    printf("\nError al intentar cargar el archivo !! \n ");
  } else {
    printf("\n leyendo ....\n\n ");
    while (fread(&x[n], sizeof (x[n]),1,f)==1) {
      //Cuando regresa un valor diferente que 1 significa que termino de leer y se sale
      n++;
      printf("\n\n Se cargo exitosamente el archivo \n");
    }
    fclose(f);
    printf("\n--> %d de registros leidos\n\n\n",n);
    system("PAUSE");
  }  
}
 