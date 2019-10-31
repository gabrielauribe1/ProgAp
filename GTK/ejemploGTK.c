#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

typedef struct nodo /*Nuestra estructura tiene 3 entradas y 6 salidas*/
{
  GtkWidget *Edad;
  GtkWidget *Peso;
  char Sexo;
  GtkWidget *Zona[6];
}NODO;

void Determina_Fem(GtkToggleButton *button, gpointer data);/*Primero, determinamos qué radio button picó*/
void Determina_Mas(GtkToggleButton *button, gpointer data); 
void Calcular(GtkButton *button, gpointer data); /*Calculamos zonas cardiacas*/
void StopTheApp(GtkButton *button, gpointer data); 

gint main(gint argc, gchar *argv[])
{
  GtkWidget *window;
  GtkWidget *verticalbox;
  GtkWidget *box[12];
  GtkWidget *label;
  GtkWidget *entryedad; /*Ambas cajas reciben los valores del usuario*/
  GtkWidget *entrypeso;
  GtkWidget *button, *masculino, *femenino; /*Tendremos un botón para cada opción*/
  NODO informacion; /*Aquí, almacenaremos toda la info involucrada*/
  int i; 
  
  gtk_init(&argc, &argv);
  
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 450, 200); 
  gtk_container_border_width(GTK_CONTAINER(window), 5);
  
  for(i=0;i<13;i++) /*En total, tenemos 13 cajas horizontales*/
      box[i]= gtk_hbox_new(TRUE, 5);
  
  verticalbox = gtk_vbox_new(TRUE,5);

  /*Aquí, colocaremos toda la información que se presenta en pantalla*/
  
  label = gtk_label_new("Edad:"); 
  entryedad = gtk_entry_new();
  informacion.Edad = entryedad; /*Usamos esto para guardar en un info. lo que meta el usuaio*/
  gtk_box_pack_start(GTK_BOX(box[0]), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box[0]), entryedad, TRUE, TRUE, 0);

  
  label = gtk_label_new("Peso (libras):");
  entrypeso = gtk_entry_new();
  informacion.Peso=entrypeso;
  gtk_box_pack_start(GTK_BOX(box[1]), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box[1]), entrypeso, TRUE, TRUE, 0);

  /*Usamos radio buttons para que, al seleccionar uno, se deseleccione el otro*/
  
  label = gtk_label_new(""); /*Ambos botones siguientes tienen un espacio primero*/
  masculino = gtk_radio_button_new_with_label(NULL, "Hombre"); 
  gtk_signal_connect(GTK_OBJECT(masculino), "toggled", GTK_SIGNAL_FUNC(Determina_Mas), &informacion);
  gtk_box_pack_start(GTK_BOX(box[2]), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box[2]), masculino, FALSE, TRUE, 0);

  
  label = gtk_label_new(""); 
  femenino = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(masculino)), "Mujer");
  gtk_signal_connect(GTK_OBJECT(femenino), "toggled", GTK_SIGNAL_FUNC(Determina_Fem), &informacion);
  gtk_box_pack_start(GTK_BOX(box[3]), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box[3]), femenino, TRUE, TRUE, 0);

  /*Cuando presione este botón, iniciará la función Calcular*/
  
  button = gtk_button_new_with_label("Calcula");
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(Calcular), &informacion);
  gtk_box_pack_start(GTK_BOX(box[4]), button, TRUE, TRUE, 0);
  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[4]), label, TRUE, TRUE, 0);

  
  /*Ahora, ponemos todas las cajas en donde solamente se despliega información*/
  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[5]), label, TRUE, TRUE, 0);
  label = gtk_label_new("Zonas");
  gtk_box_pack_start(GTK_BOX(box[5]), label, TRUE, TRUE, 0);
  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[5]), label, TRUE, TRUE, 0);
  
  /*Empezando aquí, la información en pantalla será la calculada*/
  
  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, FALSE, 30);
  label = gtk_label_new("Zona 1");
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, TRUE, 0);
  label=gtk_label_new("50%          -");
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0 ppm");
  informacion.Zona[0]=label;
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, TRUE, 0);

  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);
  label=gtk_label_new("Zona 2");
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);
  label=gtk_label_new("60%          -");
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0 ppm");
  informacion.Zona[1]=label;
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);

  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[8]), label, TRUE, TRUE, 0);
  label=gtk_label_new("Zona 3");
  gtk_box_pack_start(GTK_BOX(box[8]), label, TRUE, TRUE, 0);
  label=gtk_label_new("70%          -");
  gtk_box_pack_start(GTK_BOX(box[8]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0 ppm");
  informacion.Zona[2]=label;
  gtk_box_pack_start(GTK_BOX(box[8]) ,label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[8]), label, TRUE, TRUE, 0);

  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);
  label=gtk_label_new("Zona 4");
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);
  label=gtk_label_new("80%          -");
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0 ppm");
  informacion.Zona[3]=label;
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);

  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);
  label=gtk_label_new("Zona 5");
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);
  label=gtk_label_new("90%          -");
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0 ppm");
  informacion.Zona[4]=label;
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);

  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[11]),label, TRUE, TRUE, 0);
  label=gtk_label_new("Zona 6");
  gtk_box_pack_start(GTK_BOX(box[11]),label, TRUE, TRUE, 0);
  label=gtk_label_new("100%        -");
  gtk_box_pack_start(GTK_BOX(box[11]),label, TRUE, TRUE, 0);
  label=gtk_label_new("0 ppm");
  informacion.Zona[5]=label;
  gtk_box_pack_start(GTK_BOX(box[11]),label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[11]),label, TRUE, TRUE, 0);

  /*Terminamos de posicionar todo lo que aparecerá en pantalla*/
  
  for(i=0;i<13;i++) /*Metemos todas las cajas al verticalbox*/
    gtk_box_pack_start(GTK_BOX(verticalbox), box[i], TRUE, TRUE, 0);
  
  gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(StopTheApp),NULL);

  gtk_container_add(GTK_CONTAINER(window),verticalbox);

  gtk_widget_show_all(window);
  
  gtk_main();
}

void Calcular(GtkButton *button, gpointer data)
{
  NODO *info =  (NODO *) data; /*Tomamos los datos de informacion*/
  float max, edad, peso, porcentaje=1; /*Igualamos porcentaja a 1 e iremos reduciéndolo*/
  int i, almacen[6];
  char impresion[20];
  const gchar *EDAD, *PESO;
  EDAD=gtk_entry_get_text(GTK_ENTRY(info->Edad));
  PESO=gtk_entry_get_text(GTK_ENTRY(info->Peso));
  sscanf(EDAD, "%f", &edad); /*Necesitamos trabajar los valores como float, así que los sacamos de esta forma*/
  sscanf(PESO, "%f", &peso);

  if(info->Sexo == 'H')
    {
      for(i=5;i>=0;i--)
	{
	  max = (210 - (edad/2) -.05 * (peso) + 4) * porcentaje;
	  porcentaje = porcentaje - .1;
	  almacen[i] = max; /*Almacen sirve como variable temporal*/
	}
    }
  else
    {
      for(i=5;i>=0;i--)
	{
	  max = (210 - (edad/2) -.01 * (peso)) * porcentaje;
	  porcentaje = porcentaje - .1;
	  almacen[i] = max;
	}
    }
  for(i=0;i<6;i++)
    {
      sprintf(impresion, "%d ppm", almacen[i]);
      gtk_label_set_text(GTK_LABEL(info->Zona[i]), impresion); /*Imprimimos en los labels de hasta abajo la info*/
    }
}

void Determina_Fem(GtkToggleButton *button, gpointer data)/*Primero, determinamos qué radio button picó*/
{
  NODO *info = (NODO *) data;
  info->Sexo = 'M';
}
void Determina_Mas(GtkToggleButton *button, gpointer data)
{
  NODO *info = (NODO *) data;
  info->Sexo = 'H';
}

void StopTheApp(GtkButton *button, gpointer data)
{
  gtk_main_quit();
}
