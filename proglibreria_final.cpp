/*
//Archivo .cpp
Autor: Franciscomilan
Fechas: 14/05/2022 - 21/05/2022
Escuela: Universidad uvm
Materia: Programacion estructurada
Profesor: Armando Cruz
Ciclo: 01/2022
Descripcion: Programa en C que sera proyecto final de la materia programacion estructurada
*/

#include "proglibreria_final.h"

void leers(char *mensaje, char s[],  int n) {
  //void leers(char s[], int n) {
  char text[30];
	printf(mensaje);
	fflush(stdin);	//se agrego para evitar problemas
	fgets (s, n, stdin);
  //sprintf(text, "%%%d[^\\n]",n);
  //printf("\n[%s]\n",text);
  //fscanf(stdin,text,s);
	fflush(stdin);
	if (s[strlen(s)-1]=='\n') {
		s[strlen(s)-1]=0;
	}
}


float leerf(char *mensaje, float inferior, float superior) {
	float valor=superior+1;
  //int valor;
   char s[10];
	do {
		printf(mensaje);
		//scanf("%f",&valor);
    //Primero leerlo como cadena
    fflush(stdin);
    fgets(s,10,stdin);
    fflush(stdin);
    //Aqui se podria cambiar por el codigo del enter o no
    if (s[strlen(s)-1]=='\n') {
		  s[strlen(s)-1]=0;
	  }
    //Antes de convertir preguntar
    if (validar_decimal(s)) {
      //Convertir
      valor=atof(s);
      if (valor<inferior || valor>superior); {
			  printf("Dato invalido !!! Debe estar entre (%.2f - %.2f). Vuelve a introducirlo: \n", inferior, superior);
		  }
    } else {
     printf("Dato invalido !!! Debe ser un numero decimal.   Vuelve a introducirlo: \n"); 
    }
    //Convertir    valor=atof(s);
		
	}while (valor<inferior || valor>superior);
	return valor;
}


int leerd(char *mensaje, int inferior, int superior) {
	int valor=superior+1;
  //int valor;
  char s[10]; 
	do {
		printf(mensaje);
		fflush(stdin);
    fgets(s,10,stdin);
    fflush(stdin);
    if (s[strlen(s)-1]=='\n') {
		  s[strlen(s)-1]=0;
	  }
    if (validar_entero(s)) {
      //Antes de validar convertir
      valor=atoi(s);
      if (valor<inferior || valor>inferior) {
			printf("\n Dato invalido !!! Debe estar entre (%d - %d). Vuelva a introducirlo: \n\n", inferior, superior);
		  }   
    } 
      else {
      printf("\nDato invalido!!! Debe ser un numero entero. Vuelva a introducirlo\n\n ");
    }
		
	}while (valor<inferior || valor>superior);
	return valor;
}


//Funcion validar enteros
int validar_entero(char *cadena){
  int i, valor;
  for (i=0; i<strlen(cadena); i++) {
    valor = cadena [i] - '0';
    if (valor <0 || valor >9) {
      if(i==0 && valor==-3) continue;
        return 0;
    }
  }
  return 1;
}


//Validar flotante - decimal 
int validar_decimal (char *cadena) {
  int i, valor;
  int tiene_punto = 0;
  for (i=0; i<strlen(cadena); i++) {
    valor = cadena[i]-'0';
    if(valor<0 || valor >9) {
      //Primer valor es -
      if(i==0 && valor==-3) continue;
      //Validar solo contenga un .
      if(valor==-2 && !tiene_punto) {
        tiene_punto=1;
        continue;
      }
      return 0;
    }
  }
  return 1;
}