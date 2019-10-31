#include<stdio.h>

void PedirDatos(int *lista, int num);
void Ordenar(int *lista, int num);
void Imprimir(int *lista, int num);


int main (void)
{
  int lista [100], num;
  do
    {
  printf("Indique cuantos numeros va a introducir (mayor a 0 menor a 100): \n");
  scanf("%d", &num);
    }
  while(num<=0 || num>100);
  PedirDatos(lista, num);
  Ordenar(lista, num);
  Imprimir(lista, num);
}

void PedirDatos(int *lista, int num)
{
  int i;
   printf("Introduzca los numeros: \n");
   for (i=0; i<num; i++)
    {
      scanf("%d", lista+i);
    }
}

void Ordenar(int *lista, int num)
{
  int i, j, temp;
   for (i=0; i<num; i++)
     {
       for (j=i+1; j<num; j++)
	 {
	   if (*(lista+i)>*(lista + j))
	     {
	       temp=*(lista + i);
	       *(lista + i)=*(lista + j);
	       *(lista + j)=temp;
	     }
	 }
     }
}
void Imprimir(int *lista, int num)
{
  int m;
    for(m=0; m<num; m++)
     {
       printf("numero %d: %d \n", m+1, *(lista + m));
     }
   
}



     
