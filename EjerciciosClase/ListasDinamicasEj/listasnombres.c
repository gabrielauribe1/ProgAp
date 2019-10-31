#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Def_Alumnos
{
  char Nombre[200], Escuela[200];
  int Colegiatura, ID;
  struct Def_Alumnos *sig;
}TipoAlumno;

void InsertarAlumnos(TipoAlumno **Inicio, TipoAlumno NuevoAlumno, int Numeracion);
void BuscarAlumnos(TipoAlumno *Inicio);
void ImprimeAlumnos(TipoAlumno *Inicio);
void BorrarLista(TipoAlumno *Inicio);
void GuardaArchivo(TipoAlumno *Inicio, int Numeracion);

int main (void)
{
  TipoAlumno *Inicio=NULL, NuevoAlumno;
  int Opcion,Numeracion=1,Salir=0;
  do
    {
      system("clear");
      printf("Bienvenido al menú, elija la opción que desea\n");
      printf("1. Insertar Alumnos\n");
      printf("2. Buscar Alumnos\n");
      printf("3. Imprimir datos de Alumnos\n");
      printf("4. Guardar en Archivo Binario\n");
      printf("5. Salir\n");
      printf("Ingresa una opción\n");
      scanf("%d",&Opcion);
      switch(Opcion)
	{
	case 1:
	  system("clear");
	  printf("Registro Alumno\n");
	  printf("Ingresa el nombre: \n");
	  __fpurge(stdin);
 	  gets(NuevoAlumno.Nombre);
	  printf("Ingresa el nombre del colegio\n");
	  __fpurge(stdin);
	  gets(NuevoAlumno.Escuela);
	  printf("Ingresa el costo de la colegiatura.\n");
	  scanf(" %d", &NuevoAlumno.Colegiatura);
	  InsertarAlumnos(&Inicio,NuevoAlumno,Numeracion);
	  Numeracion++;
	  break;
	case 2:
	  BuscarAlumnos(Inicio);
	  break;
	case 3:
	  ImprimeAlumnos(Inicio);
	  break;
	case 4:
	  GuardaArchivo(Inicio,Numeracion);
	  break;
	case 5:
	  Salir=1;
	}
    }while(Salir==0);
  
  BorrarLista(Inicio);
  
}

void InsertarAlumnos(TipoAlumno **Inicio,TipoAlumno NuevoAlumno,int Numeracion)
{
  TipoAlumno *temp,*nuevo;

  nuevo=(TipoAlumno *)malloc(sizeof(TipoAlumno));
  strcpy(nuevo->Nombre,NuevoAlumno.Nombre);
  strcpy(nuevo->Escuela,NuevoAlumno.Escuela);
  nuevo->Colegiatura=NuevoAlumno.Colegiatura;
  nuevo->ID=Numeracion;
  nuevo->sig=NULL;
  
  if(*Inicio!=NULL)
    {
      temp=*Inicio;
      while(temp->sig!=NULL)
	temp=temp->sig;
      temp->sig=nuevo;
    }
  else
    {
      *Inicio=nuevo;
    }
   
}
 
  
void ImprimeAlumnos(TipoAlumno *Inicio)
{
  TipoAlumno *temp;
  char Letra;
  temp=Inicio;
  while(temp!=NULL)
    {
      puts(temp->Nombre);
      puts(temp->Escuela);
      printf("Colegiatura: %d",temp->Colegiatura);
      printf("ID: %d",temp->ID);
      temp=temp->sig;
    }
  printf("Ingresa una letra para continuar...\n");
  scanf(" %c",&Letra);
}

void BuscarAlumnos(TipoAlumno *Inicio)
{
  TipoAlumno *temp;
  char Nombre[200];
  temp=Inicio;
  printf("Ingrese el alumno que desee buscar\n");
  __fpurge(stdin);
  gets(Nombre);
  while(temp!=NULL)
    {
      if(strcmp(Nombre,temp->Nombre)==0)
	printf("El alumno ha sido encontrado");
      else
	printf("El alumno no existe en la base datos\n");
      temp=temp->sig;
    }
  printf("Presione Enter para continuar\n");
  getchar();
}
/*void LeerArchivo(TipoAlumno **Inicio)
{
  TipoAlumno *temp,*nuevo;
  FILE *Archivo;
  int Elementos;
  char NombreArchivo[200];
  nuevo=(TipoAlumno *)malloc(sizeof(TipoAlumno));
  printf("¿Cual es el nombre del archivo a leer?\n");
  __fpurge(stdin);
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo,"rb");
  fseek(Archivo,0L,SEEK_END);
  Elementos=ftell(Archivo);
  Elementos/=sizeof(TipoAlumno);
  fseek(Archivo,0L,SEEK_SET);
  temp=*Inicio;
  for(int i=0; i<Elementos;i++)
    {
      fread(&nuevo,sizeof(TipoAlumno),1,Archivo);
      nuevo->sig=NULL;
    }
  if(*Inicio!=NULL)
    {
      temp=*Inicio;
      while(temp->sig!=NULL)
	temp=temp->sig;
      temp->sig=nuevo;
    }
  else
    {
      *Inicio=nuevo;
      }*/
  


void GuardaArchivo(TipoAlumno *Inicio, int Numeracion)
{
  TipoAlumno *temp;
  FILE *Archivo;
  char NombreArchivo[200];
  temp=Inicio;
  printf("¿Cual es el nombre del archivo prro?\n");
  __fpurge(stdin);
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo,"wb");
  fwrite(temp,sizeof(TipoAlumno),Numeracion,Archivo);
  fclose(Archivo);
}
void BorrarLista(TipoAlumno *Inicio)
{
  TipoAlumno *temp;
  temp=Inicio;
  while(temp!=NULL)
    {
      Inicio=Inicio->sig;
      free(temp);
      temp=Inicio;
    }
}
