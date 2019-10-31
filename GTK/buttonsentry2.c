#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

typedef struct def_Nodo
{
	GtkWidget *Edad;
	GtkWidget *Peso;
	GtkWidget *Zona[6];
	char Genero; 
}TipoLista;

void GeneroM(GtkToggleButton *button, gpointer data);
void GeneroF(GtkToggleButton *button, gpointer data);
void CalcularPPM(GtkButton *button, gpointer data);
void DetenerApp(GtkWidget *window, gpointer data);

gint main(gint argc, gchar *argv[])
{
  GtkWidget *window;
  GtkWidget *grancajav;
  GtkWidget *cajash[12], *otracaja;
  GtkWidget *texto;
  GtkWidget *inputedad; 
  GtkWidget *inputpeso;
  GtkWidget *button, *Hombre, *Mujer; 
  TipoLista datos; 
  int i; 
  
  gtk_init(&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window),320,200);
  gtk_container_border_width(GTK_CONTAINER(window),4);

  for(i=0; i<13; i++)
  	cajash[i] = gtk_hbox_new(TRUE,5);

  grancajav = gtk_vbox_new(TRUE,5);
  otracaja = gtk_hbox_new(TRUE,5);

  inputedad = gtk_entry_new();
  inputpeso = gtk_entry_new();

  texto = gtk_label_new("");   
  gtk_box_pack_start(GTK_BOX(otracaja), texto, TRUE, TRUE, 0);
  texto = gtk_label_new("Edad:"); 
  inputedad = gtk_entry_new();
  datos.Edad = inputedad; /*Usamos esto para guardar en un info. lo que meta el usuaio*/
  gtk_box_pack_start(GTK_BOX(cajash[0]), texto, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(cajash[0]), inputedad, TRUE, TRUE, 0);

  
  texto = gtk_label_new("Peso (libras):");
  inputpeso = gtk_entry_new();
  datos.Peso=inputpeso;
  gtk_box_pack_start(GTK_BOX(cajash[1]), texto, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(cajash[1]), inputpeso, TRUE, TRUE, 0);

  texto = gtk_label_new(""); 
  Hombre = gtk_radio_button_new_with_label(NULL, "Hombre"); 
  gtk_signal_connect(GTK_OBJECT(Hombre), "toggled", GTK_SIGNAL_FUNC(GeneroM), &datos);
  gtk_box_pack_start(GTK_BOX(cajash[2]), texto, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(cajash[2]), Hombre, TRUE, TRUE, 0);

  
  texto = gtk_label_new(""); 
  Mujer = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(Hombre)), "Mujer");
  gtk_signal_connect(GTK_OBJECT(Mujer), "toggled", GTK_SIGNAL_FUNC(GeneroF), &datos);
  gtk_box_pack_start(GTK_BOX(cajash[3]), texto, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(cajash[3]), Mujer, TRUE, TRUE, 0);

  button = gtk_button_new_with_label("Calcular");
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CalcularPPM), &datos);
  gtk_box_pack_start(GTK_BOX(cajash[4]), button, TRUE, TRUE, 0);
  texto = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[4]), texto, TRUE, TRUE, 0);

  
  texto = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[5]), texto, TRUE, TRUE, 0);
  texto = gtk_label_new("Zonas");
  gtk_box_pack_start(GTK_BOX(cajash[5]), texto, TRUE, TRUE, 0);
  texto = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[5]), texto, TRUE, TRUE, 0);
  
  
  texto = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[6]), texto, TRUE, FALSE, 0);
  texto = gtk_label_new("Zona 1");
  gtk_box_pack_start(GTK_BOX(cajash[6]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("50%          -");
  gtk_box_pack_start(GTK_BOX(cajash[6]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("0 ppm");
  datos.Zona[0]=texto;
  gtk_box_pack_start(GTK_BOX(cajash[6]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[6]), texto, TRUE, TRUE, 0);

  texto = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[7]), texto, TRUE, FALSE, 0);
  texto = gtk_label_new("Zona 2");
  gtk_box_pack_start(GTK_BOX(cajash[7]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("60%          -");
  gtk_box_pack_start(GTK_BOX(cajash[7]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("0 ppm");
  datos.Zona[1]=texto;
  gtk_box_pack_start(GTK_BOX(cajash[7]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[7]), texto, TRUE, TRUE, 0);

  texto = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[8]), texto, TRUE, FALSE, 0);
  texto = gtk_label_new("Zona 3");
  gtk_box_pack_start(GTK_BOX(cajash[8]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("70%          -");
  gtk_box_pack_start(GTK_BOX(cajash[8]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("0 ppm");
  datos.Zona[2]=texto;
  gtk_box_pack_start(GTK_BOX(cajash[8]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[8]), texto, TRUE, TRUE, 0);

  texto = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[9]), texto, TRUE, FALSE, 0);
  texto = gtk_label_new("Zona 4");
  gtk_box_pack_start(GTK_BOX(cajash[9]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("80%          -");
  gtk_box_pack_start(GTK_BOX(cajash[9]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("0 ppm");
  datos.Zona[3]=texto;
  gtk_box_pack_start(GTK_BOX(cajash[9]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[9]), texto, TRUE, TRUE, 0);

  texto = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[10]), texto, TRUE, FALSE, 0);
  texto = gtk_label_new("Zona 5");
  gtk_box_pack_start(GTK_BOX(cajash[10]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("90%          -");
  gtk_box_pack_start(GTK_BOX(cajash[10]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("0 ppm");
  datos.Zona[4]=texto;
  gtk_box_pack_start(GTK_BOX(cajash[10]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[10]), texto, TRUE, TRUE, 0);

  texto = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[11]), texto, TRUE, FALSE, 0);
  texto = gtk_label_new("Zona 6");
  gtk_box_pack_start(GTK_BOX(cajash[11]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("100%          -");
  gtk_box_pack_start(GTK_BOX(cajash[11]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("0 ppm");
  datos.Zona[5]=texto;
  gtk_box_pack_start(GTK_BOX(cajash[11]), texto, TRUE, TRUE, 0);
  texto=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(cajash[11]), texto, TRUE, TRUE, 0);

  gtk_box_pack_start(GTK_BOX(grancajav), otracaja, TRUE, TRUE, 0);
  for(i=0;i<13;i++) /*Metemos todas las cajas al verticalbox*/
    gtk_box_pack_start(GTK_BOX(grancajav), cajash[i], TRUE, TRUE, 0);
  
  gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(DetenerApp),NULL);

  gtk_container_add(GTK_CONTAINER(window),grancajav);

  gtk_widget_show_all(window);
  
  gtk_main();
}


void GeneroM(GtkToggleButton *button, gpointer data)
{
  TipoLista *datos = (TipoLista *) data;
  datos->Genero = 'H';
}
void GeneroF(GtkToggleButton *button, gpointer data)
{
  TipoLista *datos = (TipoLista *) data;
  datos->Genero = 'M';
}

void CalcularPPM(GtkButton *button, gpointer data)
{ 
  TipoLista *datos =  (TipoLista *) data; 
  float max, edad, peso, porcentaje=1; 
  int i, almacen[6];
  char impresion[20];
  const gchar *Age, *Weight;
  Age = gtk_entry_get_text(GTK_ENTRY(datos->Edad));
  Weight = gtk_entry_get_text(GTK_ENTRY(datos->Peso));
  sscanf(Age, "%f", &edad); 
  sscanf(Weight, "%f", &peso);
	
  if(datos->Genero == 'H')
    {
      for(i=5;i>=0;i--)
	{
	  max = (210 - (edad/2) -.05 * (peso) + 4) * porcentaje;
	  porcentaje = porcentaje - .1;
	  almacen[i] = max; 
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
      gtk_label_set_text(GTK_LABEL(datos->Zona[i]), impresion); 
    }
}

void DetenerApp(GtkWidget *window, gpointer data)
{
	gtk_main_quit();
}
