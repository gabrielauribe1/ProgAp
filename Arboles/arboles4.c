//Arbol recursivo Nombres

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct nodo
{
 char dato[200];
 struct nodo *der,*izq;
}tiponodo;

void insertar(tiponodo *raiz,tiponodo *nuevo);
void imprime(tiponodo *raiz);
void borra(tiponodo *raiz);

int main(void)
{
  char *Nombre;
 tiponodo *raiz,*nuevo;
 int i;
 raiz=NULL;
 printf("Inserta un nombre, teclea 5 para acabar.\n");
 do{
   __fpurge(stdin);
   gets(Nombre);
   if(strcmp(Nombre, "5")!=0)
     {
       nuevo=(struct nodo*)malloc(sizeof(struct nodo));
       strcpy(nuevo->dato, Nombre);
       nuevo->izq=NULL;
       nuevo->der=NULL;
       if(raiz==NULL)
	 raiz=nuevo;
       else
	 insertar(raiz,nuevo);
     }
 }while(strcmp(Nombre, "5")!=0);
 printf("Los nombres en orden son:\n");
 imprime(raiz);
 borra(raiz);
}

void insertar(tiponodo *raiz,tiponodo *nuevo)
{
 tiponodo *avanza;
 avanza=raiz;
 if(avanza!=NULL)
   {
     if(strcmp(nuevo->dato,avanza->dato)>0)
       {
	 if(avanza->der!=NULL)
	   insertar(raiz->der,nuevo);
	 else
	   {
	     avanza->der=nuevo;
	     return;
	   }
       }
     if(strcmp(nuevo->dato,avanza->dato)<=0)
       {
	 if(avanza->izq!=NULL)
	   insertar(raiz->izq,nuevo);
	 else
	   {
	     avanza->izq=nuevo;
	     return;
	   }
       }
   }
}

void imprime(tiponodo *raiz)
{
  if(raiz!=NULL)
    {
      imprime(raiz->izq);
      printf("%s\n",raiz->dato);
      imprime(raiz->der);
    }
}

void borra(tiponodo *raiz)
{
  if(raiz!=NULL)
    {
      borra(raiz->izq);
      borra(raiz->der);
      free(raiz);
    }
}
