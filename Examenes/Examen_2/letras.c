#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct arb
{
  char Letra;
  struct arb *izq, *der;
}arbol;

void CrearArbol(arbol **Raiz, char letra);
void ImprimirArbol(arbol *Raiz);
void Nodos(arbol *Raiz, int *nodos);
void Altura(arbol *Raiz, int n, int *niveles);
void Hojas(arbol *Raiz, int *hojas);
void BorrarArbol(arbol *Raiz);

int main(void)
{
  char NombreArchivo[20], letra;
  int Opcion, gaby=1, nodos=0, hojas=0,niveles=0;
  arbol *Raiz=NULL;
  FILE *Archivo;

  system("clear");
  printf("Introduzca el nombre del archivo del cual desea la creación del árbol:\n");
  gets(NombreArchivo);
  Archivo=fopen(NombreArchivo, "rt");
  if(Archivo==NULL)
    {
      printf("El archivo no existe. Introduzca un archivo válido para la próxima.\n");
      printf("Saliendo del programa...\n\n");
      exit(0);
    }
  else
    {
      while((fscanf(Archivo, "%c", &letra))==1)
      {
	if((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <='z'))
	CrearArbol(&Raiz, letra);
      }
    }
  do
    {
      printf("Elija que desea hacer:\n");
      printf("1. Imprimir en orden\n");
      printf("2. Número de nodos\n");
      printf("3. Altura del árbol\n");
      printf("4. Número de hojas\n");
      printf("5. Salir\n");
      __fpurge(stdin);
      scanf("%d", &Opcion);
      system("clear");
      switch(Opcion)
	{
	case 1:
	  ImprimirArbol(Raiz);
	  break;
	case 2:
	  Nodos(Raiz, &nodos);
	  printf("El número de nodos del arbol es: %d \n\n", nodos);
	  nodos=0;
	  break;
	case 3:
	  Altura(Raiz, 1, &niveles);
	  printf("El número de niveles del arbol es: %d \n\n", niveles);
	  niveles=0;
	  break;
	case 4:
	  Hojas(Raiz, &hojas);
	  printf("El número de hojas del arbol es: %d \n\n", hojas);
	  hojas=0;
	  break;
	case 5:
	  printf("Saliendo del programa...\n\n");
	  gaby=1;
	  BorrarArbol(Raiz);
	  exit(0);
	default:
	  printf("Introduzca una opción valida para continuar. Gracias.\n");
	  break;
	}
    }while(gaby!=0); 
}

void CrearArbol(arbol **Raiz, char letra)
{
  arbol *avanza, *nuevo;

  avanza = *Raiz;
  if((nuevo=(arbol *)malloc(sizeof(arbol)))==NULL)
    {
      printf("No hay memoria\n");
      exit(0);
    }
  nuevo->Letra=letra;
  nuevo->izq=NULL;
  nuevo->der=NULL;

  while(avanza != NULL)
    {
      if(letra > avanza->Letra) //muevete a la derecha
	{
	  if(avanza->der != NULL)
	    avanza = avanza->der;
	  else
	    {
	      avanza->der=nuevo;
	      return;
	    }
	}
      if(letra <= avanza->Letra) //muevete a la izquierda
	{
	  if(avanza->izq != NULL)
	    avanza = avanza->izq;
	  else
	    {
	      avanza->izq = nuevo;
	      return;
	    }
	}
    }
  avanza = nuevo;
  *Raiz = avanza;
}

void ImprimirArbol(arbol *Raiz)
{
  if(Raiz != NULL)
    {
      ImprimirArbol(Raiz->izq);
      printf("%c\n", Raiz->Letra);
      ImprimirArbol(Raiz->der);
    }
}

void Nodos(arbol *Raiz, int *nodos)
{
  if(Raiz != NULL)
    {
      Nodos(Raiz->izq, nodos);
      (*nodos)++;
      Nodos(Raiz->der, nodos);
    }
}

void Altura(arbol *Raiz, int n, int *niveles)
{
  if(Raiz->izq)
    Altura(Raiz->izq, n+1, niveles);
  if(Raiz->der)
    Altura(Raiz->der, n+1, niveles);
  if((Raiz->izq == NULL && Raiz->der == NULL) && n > *niveles)
  *niveles = n;
}

void Hojas(arbol *Raiz, int *hojas)
{
   if(Raiz != NULL)
    {
      if((Raiz->izq == NULL) && (Raiz->der == NULL))
	(*hojas)++;
      Hojas(Raiz->izq, hojas);
      Hojas(Raiz->der, hojas);
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
