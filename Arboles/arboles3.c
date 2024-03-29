//Arbol recursivo letras

#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
 char dato;
 struct nodo *der,*izq;
}tiponodo;

void insertar(tiponodo *raiz,tiponodo *nuevo);
void imprime(tiponodo *raiz);
void borra(tiponodo *raiz);

int main(void)
{
 char letra;
 tiponodo *raiz,*nuevo;
 raiz=NULL;
 printf("Inserta letras, teclea un numero para acabar.\n");
 do{
   __fpurge(stdin);
   scanf("%c",&letra);
   if((letra>='a'&&letra<='z')||(letra>='A'&&letra<='Z'))
     {
       nuevo=(struct nodo*)malloc(sizeof(struct nodo));
       nuevo->dato=letra;
       nuevo->izq=NULL;
       nuevo->der=NULL;
       if(raiz==NULL)
	 raiz=nuevo;
       else
	 insertar(raiz,nuevo);
     }
 }while((letra>='a'&&letra<='z')||(letra>='A'&&letra<='Z'));
 printf("Las letras en orden son:\n");
 imprime(raiz);
 borra(raiz);
}

void insertar(tiponodo *raiz,tiponodo *nuevo){
 tiponodo *avanza;
 avanza=raiz;
 if(avanza!=NULL){
   if(nuevo->dato>avanza->dato){
     if(avanza->der!=NULL)
       insertar(raiz->der,nuevo);
     else{
       avanza->der=nuevo;
       return;
     }
   }
   if(nuevo->dato<=avanza->dato){
     if(avanza->izq!=NULL)
       insertar(raiz->izq,nuevo);
     else{
       avanza->izq=nuevo;
       return;
     }
   }
 }
}

void imprime(tiponodo *raiz){
 //Recorremos el arbol en orden
 if(raiz!=NULL){
   imprime(raiz->izq);
   printf("%c\n",raiz->dato);
   imprime(raiz->der);
 }
}

void borra(tiponodo *raiz){
 //Lo borramos en post orden
 if(raiz!=NULL){
   borra(raiz->izq);
   borra(raiz->der);
   free(raiz);
 }
}
