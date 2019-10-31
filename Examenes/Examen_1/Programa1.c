#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
  int min=0, may=0, esp=0, i, salto=0;
  char NombreArchivo[100], Cadena[300];
  FILE *Archivo;

  printf("Introduzca el nombre del archivo a analizar:\n");
  __fpurge(stdin);
  gets(NombreArchivo);

  Archivo = fopen(NombreArchivo, "rt");

  if(Archivo == NULL)
    {
      printf("El archivo no existe, intente de nuevo\n");
      printf("Saliendo del programa...\n");
      exit(0);
    }
  else
    {
      while(fgets(Cadena, 300, Archivo)!=NULL)
	{
	  for(i=0; i<strlen(Cadena); i++)
	    {
	      if(Cadena[i]>='a' && Cadena[i]<='z')
		min++;
	      if(Cadena[i]>='A' && Cadena[i]<='Z')
		may++;
	      if(Cadena[i]==' ')
		esp++;
	      if(Cadena[i]=='\n')
		salto++;
	    }
	}
    }
      
  printf("Minusculas: %d\n", min);
  printf("Mayusculas: %d\n", may);
  printf("Espacios: %d\n", esp);
  printf("Letras totales: %d\n", min+may);
}
