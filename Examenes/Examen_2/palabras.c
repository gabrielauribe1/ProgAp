#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct arb
{
  char palabra[50];
  int frec;
  struct arb *izq, *der;
}arbol;

void CrearArbol(arbol **Raiz, char palabra [20]);
void ImprimirOrden(arbol *Raiz);
void ImprimirPreorden(arbol *Raiz);
void ImprimirPosorden(arbol *Raiz);
void Buscar(arbol *Raiz, char palabra[20], int *i);
void BorrarArbol(arbol *Raiz);

int main (void)
{
  int Opcion, i=0, gaby=0;
  char NombreArchivo[50], palabra[20];
  FILE *Archivo;
  arbol *Raiz=NULL;
  
  system("clear");
  
  printf("Ingrese el nombre del archivo del que desea la creación del árbol:\n");
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo,"rt");
  
  if(Archivo == NULL)
    {
      printf("El archivo no existe. Introduzca un archivo válido para la próxima.\n");
      printf("Saliendo del programa...\n\n");
      exit(0);
    }
  else
    {
      while(fgets(palabra, 100, Archivo) != NULL)
	{
	  palabra[strlen(palabra)-1]='\0';
	  CrearArbol(&Raiz, palabra);
	}
      fclose(Archivo);
    }
  
  do
    {
      printf("\n");
      printf("Elija la opción que desea:\n");
      printf("1. Imprimir en orden\n");
      printf("2. Imprimir en pre orden\n");
      printf("3. Imprimir en pos orden\n");
      printf("4. Salir\n");
      scanf("%d", &Opcion);
      printf("\n");
      switch(Opcion)
	{
	case 1:
	  system("clear");
	  ImprimirOrden(Raiz);
	  break;
	case 2:
	  system("clear");
	  ImprimirPreorden(Raiz);
	  break;
	case 3:
	  system("clear");
	  ImprimirPosorden(Raiz);
	  break;
	case 4:
	  system("clear");
	  printf("Saliendo del programa...\n\n");
	  gaby=1;
	  BorrarArbol(Raiz);
	  exit(0);
	  break;
	default:
	  system("clear");
	  printf("Introduzca una opción valida para continuar. Gracias.\n");	
	  break;
	}
    } while(gaby!=1);
}

void CrearArbol (arbol **Raiz, char palabra [20])
{
  arbol *Avanza, *Nuevo;
  
  Avanza = *Raiz;
  Nuevo = (arbol *) malloc(sizeof(arbol));
  strcpy(Nuevo->palabra, palabra);
  Nuevo->frec=1;
  Nuevo->izq= NULL;
  Nuevo->der= NULL;
  while(Avanza !=NULL)
    {
      if((strcmp(palabra, Avanza->palabra))>0) //muevete a la derecha
	{
	   if(Avanza->der != NULL)
	    Avanza = Avanza->der;
	  else
	    {
	      Avanza->der=Nuevo;
	      return;
	    }
	}
       if((strcmp(palabra, Avanza->palabra))==0)
	 {
	   (Avanza->frec)++;
	   return;
	 }
      if((strcmp(palabra, Avanza->palabra))<=0) //muevete a la izquierda
	{
	  if(Avanza->izq != NULL)
	    Avanza = Avanza->izq;
	  else
	    {
	      Avanza->izq = Nuevo;
	      return;
	    }
	}
     
    }
  Avanza = Nuevo;
  *Raiz = Avanza;    
}

void ImprimirOrden(arbol *Raiz)
{
   if(Raiz != NULL)
    {
      ImprimirOrden(Raiz->izq);
      printf("palabra: %s, ", Raiz->palabra);
      printf("frecuencia: %d\n",Raiz->frec);
      ImprimirOrden(Raiz->der);
    }
}
void ImprimirPreorden(arbol *Raiz)
{
   if(Raiz != NULL)
    {
      printf("palabra: %s, ", Raiz->palabra);
      printf("frecuencia: %d\n",Raiz->frec);
      ImprimirPreorden(Raiz->izq);
      ImprimirPreorden(Raiz->der);
    }
}

void ImprimirPosorden(arbol *Raiz)
{
  if(Raiz != NULL)
    {
      ImprimirPosorden(Raiz->izq);
      ImprimirPosorden(Raiz->der);
      printf("palabra: %s, ", Raiz->palabra);
      printf("frecuencia: %d\n",Raiz->frec);
    }
}

void BorrarArbol(arbol *Raiz)
{
  if(Raiz != NULL)
    {
      BorrarArbol(Raiz->izq);
      BorrarArbol(Raiz->der);
      free(Raiz);
    }
}
