#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_dato
{
  int dato;
  struct def_dato  *ant;
  struct def_dato  *sig;
} tipodato;

void Imprime (tipodato *Inicio);
void BorrarLista (tipodato *Inicio);
void InsertaOrdena (tipodato **Inicio, int numero);
void InsertaPrincipio(tipodato **Inicio, int valor);
void InsertaFinal(tipodato **Inicio, int valor);


int main (void)
{
  int valor, Opcion;
  tipodato *Primero = NULL;
  system("clear");
  printf("Elija como imprimir los numeros:\n");
  printf("1. De manera invertida a como los inserto:\n");
  printf("2. De la manera en la que los insertó:\n");
  printf("3. En orden de menor a mayor\n");
  printf("4. Salir\n\n");
  __fpurge(stdin);
  scanf("%d", &Opcion);

  switch(Opcion)
    {
    case 1:
      system("clear");
      printf ("Inserte numeros (letra para terminar)\n");
      while (scanf ("%d", &valor) == 1)
	InsertaPrincipio(&Primero, valor);
      printf ("Los valores introducidos de manera invertida son: \n");
      Imprime (Primero);
      break;
    case 2:
      system("clear");
      printf ("Inserte numeros (letra para terminar)\n");
      while (scanf ("%d", &valor) == 1)
	InsertaFinal(&Primero, valor);
      printf ("Los valores introducidos son: \n");
      Imprime (Primero);
      break;
    case 3:
      system("clear");
      printf ("Inserte numeros (letra para terminar)\n");
      while (scanf ("%d", &valor) == 1)
	InsertaOrdena (&Primero, valor);
      printf ("Los valores ordenados introducidos son: \n");
      Imprime (Primero);
      break;
    case 4:
      printf("Saliendo del programa...\n");
      exit(0);
      break;
    default:
      printf("Introduzca una opción válida, gracias\n");
      printf("Saliendo del programa...\n");
    }
  BorrarLista (Primero);
}

void Imprime (tipodato *Inicio)
{
  tipodato *temp;
  temp = Inicio;
  while (temp != NULL)
    {
      printf ("%d\n", temp -> dato);
      temp = temp -> sig;
    }
}

void BorrarLista (tipodato *Inicio)
{
  tipodato *temp;
  temp = Inicio;
  while (temp != NULL)
    {
      Inicio = Inicio -> sig;
      free (temp);
      temp = Inicio;
    }
}

void InsertaOrdena (tipodato **Inicio, int numero)
{
  tipodato *tmp, *tmp2, *nuevo;
  nuevo = (tipodato *) malloc (sizeof (tipodato));
  nuevo -> dato = numero;
  tmp = *Inicio;
  while ((tmp != NULL) && (numero > tmp -> dato))
    tmp = tmp -> sig;
  if (tmp != NULL)
    {
      if (tmp != *Inicio)
    {
      tmp2 = *Inicio;
      while (tmp2 -> sig != tmp)
        tmp2 = tmp2 -> sig;
      nuevo -> sig = tmp;
      tmp2 -> sig = nuevo;
    }
      else
	{
	  nuevo -> sig = *Inicio;
	  *Inicio = nuevo;
	}
    }
  else
    {
      if (*Inicio == NULL)
	{
	  nuevo -> sig = NULL;
	  *Inicio = nuevo;
	}
      else
	{
	  tmp = *Inicio;
	  while (tmp -> sig != NULL)
	    tmp = tmp -> sig;
	  tmp -> sig = nuevo;
	  nuevo -> sig = NULL;
	}
    }
}

void InsertaPrincipio(tipodato **Inicio, int valor)
{
  tipodato *temp;

  temp=(tipodato *)malloc(sizeof(tipodato));

  temp->dato = valor;
  temp->sig = *Inicio;
  temp->ant = NULL;
  if(*Inicio!=NULL)
    (*Inicio)->ant = temp;
  *Inicio = temp;
}

void InsertaFinal(tipodato **Inicio, int valor)
{
  tipodato *temp, *ultimo;

  temp=(tipodato *)malloc(sizeof(tipodato));

  temp -> dato = valor;
  temp -> sig = NULL;
  if(*Inicio!=NULL)
    {
      ultimo=*Inicio;
      while(ultimo->sig!=NULL)
	ultimo=ultimo->sig;
      ultimo->sig=temp;
      temp->ant=ultimo;
    }
  else
    {
      temp->ant=NULL;
      *Inicio=temp;
    }
}

