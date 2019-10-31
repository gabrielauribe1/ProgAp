#include<stdio.h>
#include<stdlib.h>

typedef struct defdato
{
  int dato;
  struct defdato*sig;
} tipodato;

void InsertaInicio(tipodato **Inicio, int *numero);
void InsertaFin(tipodato **Inicio, int *numero);
void ImprimeNum(tipodato *Inicio);
void BorrarLista(tipodato *Inicio);

int main (void)
{
  tipodato *Inicio=NULL;
  int Opcion, numero, Salir=0;
  do
    {
      printf("\n");
      printf("Bienvenido al menú\n");
      printf("\n");
      printf("Escoja la opción que deseé:\n");
      printf("1. Insertar numeros\n");
      printf("2. Mostrar numeros insertados\n");
      printf("3. Salir\n");
      printf("\n");
      __fpurge(stdin);
  scanf("%d", &Opcion);
  printf("\n");
  switch(Opcion)
    {
    case 1:
      printf("Introduzca los numeros que desea insertar en la lista (letra para terminar) :\n");
      while(scanf("%d", &numero)==1)
	{
	  __fpurge(stdin);
	  InsertaFin(&Inicio, &numero);
	  //InsertaInicio(&Inicio, &numero);
	}
      break;
    case 2:
      printf("Los numeros insertados son:\n");
      ImprimeNum(Inicio);
      break;
    case 3:
      BorrarLista(Inicio);
      Salir=1;
      printf("Saliendo del programa...\n");
      break;
    default: printf("Opcion incorrecta\n");
    }
    }while (Salir!=1);
  return 0;
}
    
/*void InsertaInicio(tipodato **Inicio, int *numero)
{
  tipodato *temp;
  temp=(tipodato *) malloc(sizeof(tipodato));
  temp -> dato = *numero;
  temp -> sig = *Inicio;
  *Inicio = temp;
}
*/

void InsertaFin(tipodato **Inicio, int *numero)
{
  tipodato *temp, *temp2;
  temp=(tipodato *) malloc(sizeof(tipodato));
  temp->dato=*numero;
  temp->sig=NULL;
  if(*Inicio!=NULL)
    {
      temp2=*Inicio;
      while(temp2->sig!=NULL)
	temp2=temp2->sig;
      temp2->sig=temp;
    }
  else
    *Inicio=temp;
}


void ImprimeNum(tipodato *Inicio)
{
  tipodato *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      printf("%d\n", temp->dato);
      temp = temp->sig;
    }
}

void BorrarLista(tipodato *Inicio)
{
  tipodato *temp;
  temp = Inicio;
  while(temp!=NULL)
    {
      Inicio=Inicio->sig;
      free(temp);
      temp=Inicio;
    }
}
