#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Def_Documentos
{
  int ID, Hojas, NumID, Imprimiendo;
  char NombreDocumento[100];
  struct Def_Documentos *sig;
}TipoDocumento;

void IntroducirDocumento(TipoDocumento **Inicio, TipoDocumento NuevoDocumento, int Numeracion);
void ListarTrabajos(TipoDocumento *Inicio);
void EliminarTrabajo(TipoDocumento *Inicio);
void ImprimirDocumento(TipoDocumento *Inicio);
void GuardarArchivo(TipoDocumento *Inicio);
void LeerArchivo(TipoDocumento *Inicio);
void BorrarLista(TipoDocumento *Inicio);

int main (void)
{
  TipoDocumento *Inicio=NULL, NuevoDocumento;
  int Opcion, Salir=0, Numeracion=101, Imprimir=0;
  

  do
    {
      system("clear");
      printf("\nBienvedido al Menú de Cola de Impresión\n\n");
      printf("Elija la opción que desee:\n");
      printf("1. Introducir documento a la cola de impresión\n");
      printf("2. Listar trabajos en la cola de impresión\n");
      printf("3. Eliminar trabajo de la cola de impresión\n");
      printf("4. Imprimir documento\n");
      printf("5. Guardar cola en archivo\n");
      printf("6. Leer cola en archivo\n");
      printf("7. Salir\n");
      scanf("%d", &Opcion);
      printf("\n");

      switch(Opcion)
	{
	case 1:
	  system("clear");
	  printf("Registro de nuevo documento:\n");
	  printf("Introduzca el nombre del documento, con extensión:\n");
	  __fpurge(stdin);
	  gets(NuevoDocumento.NombreDocumento);
	  printf("Introduzca el numero de páginas que tiene el documento:\n");
	  __fpurge(stdin);
	  scanf("%d", &NuevoDocumento.Hojas);
	  IntroducirDocumento(&Inicio, NuevoDocumento, Numeracion);
	  Numeracion++;
	  break;
	case 2:
	  system("clear");
	  printf("Lista de trabajos de cola de impresión:\n\n");
	  ListarTrabajos(Inicio);
	  break;
	case 3:
	  system("clear");
	  printf("Introduzca el numero de ID del cual desea eliminar trabajo\n");
	  scanf("%d", &NuevoDocumento.NumID);
	  EliminarTrabajo(Inicio);
	  break;
	case 4:
	  ImprimirDocumento(Inicio);
	  break;
	case 5:
	  GuardarArchivo(Inicio);
	  break;
	case 6:
	  LeerArchivo(Inicio);
	  break;
	case 7:
	  Salir=1;
	  exit(0);
	  break;
	default:
	  printf("Opcion inválida, intente de nuevo\n");
	  break;
	}
    }while(Salir!=1);
  BorrarLista(Inicio);
}

void IntroducirDocumento(TipoDocumento **Inicio, TipoDocumento NuevoDocumento, int Numeracion)
{
  TipoDocumento *temp, *nuevo;

  nuevo = (TipoDocumento *)malloc(sizeof(TipoDocumento));
  strcpy(nuevo->NombreDocumento, NuevoDocumento.NombreDocumento);
  nuevo->Hojas=NuevoDocumento.Hojas;
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
    *Inicio=nuevo;
}

void ListarTrabajos(TipoDocumento *Inicio)
{
  char letra;
  TipoDocumento *temp;

  temp=Inicio;
  while(temp!=NULL)
    {
      printf("%d:", temp->ID);
      printf("%s", temp->NombreDocumento);
      printf(", %d hojas, espera", temp->Hojas);
      printf("\n\n");
      temp=temp->sig;
    }
  printf("Presione enter para continuar\n");
  __fpurge(stdin);
  getchar();
}

void EliminarTrabajo(TipoDocumento *Inicio)
{
  TipoDocumento *temp;

  temp=Inicio;
  
  while(temp!=NULL)
    {
      if(temp->ID != temp->NumID)
	printf("No se encontró el ID a eliminar\n");
      else
	{
	  printf("Se encontró el ID a eliminar\n");
	  free(temp);
	}
      temp=temp->sig;
    }
  printf("Presione enter para continuar\n");
  __fpurge(stdin);
  getchar();
}

void ImprimirDocumento(TipoDocumento *Inicio)
{
    TipoDocumento *temp;
    char NombreImprimir[100];

    temp=Inicio;

    printf("Introduzca el nombre del archivo que desea comenzar a imprimir:\n");
    __fpurge(stdin);
    gets(NombreImprimir);

    while(temp!=NULL)
      {
	if(strcmp(NombreImprimir, temp->NombreDocumento)==0)
	  
	  printf("Archivo buscado impreso: %d: %s, %d hojas, imprmiendo", temp->ID, temp->NombreDocumento, temp->Hojas);
	  temp=temp->sig;
      }
  
}

void GuardarArchivo(TipoDocumento *Inicio)
{
  TipoDocumento *temp;
  FILE *Archivo;
  char NombreArchivo[100];

  temp=Inicio;
  
  printf("Introduzca el nombre donde desea guardar el archivo\n");
  __fpurge(stdin);
  gets(NombreArchivo);

  Archivo = fopen(NombreArchivo, "wt");

  while(temp!=NULL)
    {
  fprintf(Archivo, "%d: %s, %d hojas, espera\n", temp->ID, temp->NombreDocumento, temp->Hojas);
  temp=temp->sig;
    }
}

void LeerArchivo(TipoDocumento *Inicio)
{
  TipoDocumento *temp;
  char NombreArchivo[200];
  FILE *Archivo;

   temp=Inicio;
  
  printf("Introduzca el nombre del que desea leer el archivo\n");
  __fpurge(stdin);
  gets(NombreArchivo);

  Archivo = fopen(NombreArchivo, "rt");

  if(Archivo==NULL)
    printf("No existe el archivo");
  else
    {
  while(temp!=NULL)
    {
  fscanf(Archivo, "%d: %s, %d hojas, espera", temp->ID, temp->NombreDocumento, temp->Hojas);
  temp=temp->sig;
    }
    }
}

void BorrarLista(TipoDocumento *Inicio)
{
  TipoDocumento *temp;
  temp=Inicio;
  
  while(temp!=NULL)
    {
      Inicio=Inicio->sig;
      free(temp);
      temp=Inicio;
    }
}



