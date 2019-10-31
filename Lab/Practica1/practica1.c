#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void LeerArchivo(unsigned char *MatrizActual[], int *MagnitudY, int *MagnitudX, char NombreArchivo[]);
void GuardarMatrizActual(unsigned char *MatrizActual[], int MagnitudY, int MagnitudX, char NombreArchivo[]);
void NegativoImagen(int MagnitudY, int MagnitudX, unsigned char *MatrizActual [], unsigned char *MatrizNueva []);
void EcualizacionLineal(int MagnitudY, int MagnitudX, unsigned char *MatrizActual[], unsigned char *MatrizNueva[]);
void AmpliarImagen(int MagnitudY, int MagnitudX, unsigned char *MatrizActual[], unsigned char *MatrizNueva[]);
void ReducirImagen(int X2, int Y2, unsigned char *MatrizActual[], unsigned char *MatrizNueva[]);
void GuardarArchivo(int X2, int Y2, unsigned char *MatrizNueva[]);
void BorrarMemoria(int MagnitudY, int MagnitudX, unsigned char *MatrizActual[], unsigned char *MatrizNueva[]);

int main (void)
{
  unsigned char **MatrizActual, **MatrizNueva;
  int  MagnitudY, MagnitudX, Magnitud2X, Magnitud2Y, Opcion, i,j, X2, Y2;
  char NombreArchivo[50];

  LeerArchivo(MatrizActual, &MagnitudY, &MagnitudX, NombreArchivo);
  
  MatrizActual = (unsigned char **) malloc(sizeof(unsigned char *)*MagnitudY);
  for(i=0; i<MagnitudY; i++)
    {
      MatrizActual[i] = (unsigned char *) malloc(sizeof(unsigned char)*MagnitudX); 
    }
  
  GuardarMatrizActual(MatrizActual, MagnitudY, MagnitudX, NombreArchivo);
  
  printf("\n\nBienvenido al menú para modificar su imagen, eliga la opción que desea:\n");
  printf("1. El Negativo de la Imagen\n");
  printf("2. La Ecualización Lineal de la Imagen\n");
  printf("3. Ampliar la Imagen\n");
  printf("4. Reducir la Imagen\n");
  printf("5. Salir\n\n");
  scanf("%d", &Opcion);
  printf("\n");

  switch(Opcion)
    {
    case 1:
      X2 = MagnitudX; //Para cada opcion del menu se definen los parámetros de las columnas y filas (x)(y)
      Y2 = MagnitudY;
      MatrizNueva = (unsigned char **) malloc (sizeof(unsigned char *)*MagnitudY); //Para cada opción se asigna memoria a una Matriz Nueva, basandose en las magnitudes X2 y Y2
      for (j=0; j<MagnitudY; j++)
	{
	  MatrizNueva[j] = (unsigned char *) malloc (sizeof(unsigned char)*MagnitudX);
	}
      NegativoImagen(MagnitudY, MagnitudX, MatrizActual, MatrizNueva); //Se llama a la función para hacer el negativo de la imagen
      break;
      
    case 2:
      X2 = MagnitudX; 
      Y2 = MagnitudY;
      MatrizNueva = (unsigned char **) malloc (sizeof(unsigned char *)*MagnitudY);
      for (j=0; j<MagnitudY; j++)
	{
	  MatrizNueva[j] = (unsigned char *) malloc (sizeof(unsigned char)*MagnitudX);
	}
      EcualizacionLineal(MagnitudY, MagnitudX, MatrizActual, MatrizNueva); //Se llama a la función para hacer la ecualizacion lineal de la imagen
      break;
      
    case 3:
      X2 = MagnitudX*2; //Se multiplican por 2 las dimensiones porque la imagen se va a ampliar al doble
      Y2 = MagnitudY*2;
      MatrizNueva = (unsigned char **) malloc (sizeof(unsigned char *)*Y2);
      for (j=0; j<Y2; j++)
	{
	  MatrizNueva[j] = (unsigned char *) malloc (sizeof(unsigned char)*X2);
	}
      AmpliarImagen(MagnitudY, MagnitudX, MatrizActual, MatrizNueva);
      break;
      
    case 4:
      X2 = MagnitudX/2; //Se dividen entre 2 las dimensiones porque la imagen se va a reducir an la mitad
      Y2 = MagnitudY/2;
      MatrizNueva = (unsigned char **) malloc (sizeof(unsigned char *)*MagnitudY);
      for (j=0; j<MagnitudY; j++)
	{
	  MatrizNueva[j] = (unsigned char *) malloc (sizeof(unsigned char)*MagnitudX);
	}
      ReducirImagen(X2, Y2, MatrizActual, MatrizNueva);
      break;
    case 5:
      printf("Saliendo del programa...\n\n");
      exit(0); //Se sale del programa
      break;
    default:
      printf("Elija una opción válida.\n");
      exit(0);//Se sale del programa al introducir una opción inválida
    }
  GuardarArchivo(X2, Y2, MatrizNueva); //Se llama la funcion de guardar la imagen en un archivo
  BorrarMemoria(MagnitudY, MagnitudX, MatrizActual, MatrizNueva); //Se llama a la funcion para liberar el espacio de memoria asignado de la Matriz Nueva
}

void LeerArchivo(unsigned char *MatrizActual[], int *MagnitudY, int *MagnitudX, char NombreArchivo[])
{
  FILE *Archivo;

  printf("\nIntroduzca el nombre del archivo con la imagen a modificar:\n");
  gets(NombreArchivo);
  printf("\n");

  Archivo = fopen(NombreArchivo, "rb"); //Se abre el archivo de la imagen

  if(Archivo == NULL) //Se valida si el archivo de la imagen existe
    {
      printf("El archivo no existe, intente de nuevo abriendo otra vez el programa\n\n");
      printf("Saliendo del programa...\n\n");
      exit(0);
    }
  else
    {
      fseek(Archivo, 2L, SEEK_SET); //Se salta los bytes de P5 y se posiciona al inicio
      fscanf(Archivo," %d %d 255", MagnitudX, MagnitudY); //Se leen los parámetros de las magnitudes de columnas y filas
      fclose(Archivo);
    }

 

}
void GuardarMatrizActual(unsigned char *MatrizActual[], int MagnitudY, int MagnitudX, char NombreArchivo[])
{
  FILE *Archivo;
  int i, j, Aux;
  
  Archivo = fopen(NombreArchivo, "rb");
  
  fseek(Archivo, 15L, SEEK_SET); //Se saltan 15 bytes para leer la informacion que nos interesa
  for(j=0; j<MagnitudY; j++) //Se recorren los renglones
    {
      for(i=0;i<MagnitudX; i++) //Se recorren las columnas
	{
	  fread (&MatrizActual[j][i], 1, 1, Archivo);  //Se va leyendo cada byte de la Matriz Actual
	}
    }
  fclose(Archivo); //Se cierra el archivo  
}

void NegativoImagen(int MagnitudY, int MagnitudX, unsigned char *MatrizActual [], unsigned char *MatrizNueva [])
{
  int i, j;
  
  for(j=0; j<MagnitudY; j++) //Se recorren los renglones
    {
      for(i=0; i<MagnitudX; i++) //Se recorren las columnas
	{
	  MatrizNueva[j][i] = 255 - MatrizActual[j][i]; //Se aplica la ecuación para obtener el negativo y=x-1
	}
    }
}

void EcualizacionLineal(int MagnitudY, int MagnitudX, unsigned char *MatrizActual[], unsigned char *MatrizNueva[])
{
  int i, j, Max, Min;
  double m, b;

  Min = 255; //Se asigna el valor minimo
  Max = 0; //Se asigna el valor maximo

  for(j=0; j<MagnitudY; j++) //Se recorren los renglones
    {
      for(i=0; i<MagnitudX; i++) //Se recorren las columnas
	{
    
	  if(MatrizActual[j][i] > Max) //Se obtiene el valor maximo de pixeles en la imagen
	    {
	      Max = MatrizActual[j][i]; //Se le da el valor en la Matriz Actual
	    }
	  if(MatrizActual[j][i] < Min) //Se obtiene el valor minimo de pixeles en la imagen
	    {
	      Min = MatrizActual[j][i]; //Se le da el valor en la Matriz Actual
	    }
	}
    }

  m = 255 / (Max - Min); //Se obtiene la pendiente con la ecuacion m=(y2-y1)/(x2-x1) siendo y2=255, y1=0, x2=Max, x1=Min
  b = 255 - (m*Max); //Para obtener la ordenada al origen se despejó la ecuación y=mx+b

  //printf("Maximo %d\n", Max);
  //printf("Minimo %d\n", Min);

  for(j=0; j<MagnitudY; j++) //Se recorren los renglones
    {
      for(i=0; i<MagnitudX; i++) //Se recorren las columnas
	{
	  MatrizNueva[j][i] = MatrizActual[j][i]*m; //Se obtiene la ecuacion en la Matriz, por y=mx+b
	  MatrizNueva[j][i] = MatrizNueva[j][i] + b;
	}
    }
}

void AmpliarImagen(int MagnitudY, int MagnitudX, unsigned char *MatrizActual[], unsigned char *MatrizNueva[])
{
  int i, i2, j, j2; //Para cada eje se declaran 2 variables para incrementar el eje de 2 en 2
  
  j2=0; //Se inicializa en 0 el valor de los renglones
  for (j = 0; j < MagnitudY; j++) //Se recorren los renglones
  {
    i2 = 0; //Se inicializa en 0 el valor de las columnas
    for (i=0; i<MagnitudX; i++) //Se recorren las columnas
    {
      MatrizNueva[j2][i2] = MatrizActual[j][i]; //Se copia el valor actual en la Matriz Actual
      MatrizNueva[j2+1][i2] = MatrizActual[j][i]; //Se copia el valor multipicado por 2 en los renglones
      MatrizNueva[j2][i2+1] = MatrizActual[j][i]; //Se copia el valor multiplicado por 2 en las columnas
      MatrizNueva[j2+1][i2+1] = MatrizActual[j][i]; //Se copia totalmente
      i2+=2; //El ciclo avanza de 2 en 2 columnas
    }
    j2+=2; //El ciclo avanza de 2 en 2 renglones 
  }
}


void ReducirImagen(int X2, int Y2, unsigned char *MatrizActual[], unsigned char *MatrizNueva[])
{
  int i, i2, j, j2; //Para cada eje se declaran 2 variables para reducir el eje de 2 en 2
  
  j = 0; //Se inicializa en 0 el valor de los renglones
  j2 = 0;
  
  while (j2<Y2) //Con las dimensiones definidas en el case se recorren los renglones
  {
    i = 0; //Se inicializa en 0 el valor de las columnas
    i2 = 0;
    while (i2<X2) //Con las dimensiones definidas en el case se recorren las columnas
    {
      MatrizNueva[j2][i2] = MatrizActual[j][i]; //Se guarda en la Matriz Nueva
      i = i + 2; //Se avanzan 2 columnas de la Matriz Actual
      i2 ++; //Se avanza 1 columna de la Matriz Nueva
    }
    j=j+2; //Se hace lo mismo pero con los renglones de cada Matriz (Actual y Nueva)
    j2 ++;
  }

}

void GuardarArchivo(int X2, int Y2, unsigned char *MatrizNueva[])
{
  FILE *Archivo;
  int i, j;
  char NombreArchivo2[50];

  printf("Elija el nombre del archivo donde desea guardar la imagen:\n");
  __fpurge(stdin);
  gets(NombreArchivo2);
 
  
  Archivo = fopen (NombreArchivo2,"wb"); //Se abre la Matriz Nueva guardada en el archivo
  fprintf (Archivo, "P5 %d %d 255 ", X2, Y2);
  for (j=0; j<Y2; j++) //Se recorren los renglones en base a las dimensiones de la Matriz Nueva
    {
    for (i=0; i<X2; i++) //Se recorren las columnas en base a las dimensiones de la Matriz Nueva
      {
	fwrite (&MatrizNueva[j][i], 1, 1, Archivo); //Se escribe en base al byte
      }
    }
  printf ("\n ¡Imagen Guardada! \n\n"); 
  fclose (Archivo); //Se cierra el archivo
}

void BorrarMemoria(int MagnitudY, int MagnitudX, unsigned char *MatrizActual[], unsigned char *MatrizNueva[]) //Se borra el espacio asignado de memoria
{
  int i, j;
  for (j=0; j<MagnitudY; j++)
    {
      free (MatrizActual[j]);
    }
  free(MatrizActual);
}

