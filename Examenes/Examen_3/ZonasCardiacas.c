#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>

typedef struct nodo 
{
  GtkWidget *Edad;
  GtkWidget *Peso;
  char Gen;
  GtkWidget *Zona[6];
}tipo;

void Calcular(GtkButton *button, gpointer data); 
void StopTheApp(GtkButton *button, gpointer data);
void Fem(GtkToggleButton *button, gpointer data);
void Mas(GtkToggleButton *button, gpointer data); 

gint main(gint argc, gchar *argv[])
{
  GtkWidget *window;
  GtkWidget *verticalbox;
  GtkWidget *box[12];
  GtkWidget *label;
  GtkWidget *entrye; 
  GtkWidget *entryp;
  GtkWidget *button, *masculino, *femenino; 
  tipo datos; 
  int i; 
  
  gtk_init(&argc, &argv);
  
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 470, 220); 
  gtk_container_border_width(GTK_CONTAINER(window), 5);
  gtk_window_set_title(GTK_WINDOW(window),"Zonas Cardiacas");

  verticalbox = gtk_vbox_new(TRUE,5);
    
  for(i=0;i<11;i++) 
    box[i]= gtk_hbox_new(TRUE, 5);


  //edad
  
  label = gtk_label_new("Edad:"); 
  entrye = gtk_entry_new();
  datos.Edad = entrye;
  gtk_box_pack_start(GTK_BOX(box[0]), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box[0]), entrye, TRUE, TRUE, 0);

  //peso
  
  label = gtk_label_new("Peso (libras):");
  entryp = gtk_entry_new();
  datos.Peso=entryp;
  gtk_box_pack_start(GTK_BOX(box[1]), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box[1]), entryp, TRUE, TRUE, 0);

  //radio buttons
  
  label = gtk_label_new(""); 
  masculino = gtk_radio_button_new_with_label(NULL, "Hombre"); 
  gtk_signal_connect(GTK_OBJECT(masculino), "toggled", GTK_SIGNAL_FUNC(Mas), &datos);
  gtk_box_pack_start(GTK_BOX(box[2]), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box[2]), masculino, FALSE, TRUE, 0);

  
  label = gtk_label_new(""); 
  femenino = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(masculino)), "Mujer");
  gtk_signal_connect(GTK_OBJECT(femenino), "toggled", GTK_SIGNAL_FUNC(Fem), &datos);
  gtk_box_pack_start(GTK_BOX(box[3]), label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box[3]), femenino, TRUE, TRUE, 0);

  //boton calcula
  
  button = gtk_button_new_with_label("Calcula");
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(Calcular), &datos);
  gtk_box_pack_start(GTK_BOX(box[4]), button, TRUE, TRUE, 0);
  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[4]), label, TRUE, TRUE, 0);

  //label zonas
  
  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[5]), label, TRUE, TRUE, 0);
  label = gtk_label_new("Zonas");
  gtk_box_pack_start(GTK_BOX(box[5]), label, TRUE, TRUE, 0);
  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[5]), label, TRUE, TRUE, 0);

  //zona 1
  
  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, FALSE, 30);
  label = gtk_label_new("Zona 1");
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, TRUE, 0);
  label=gtk_label_new("50% - 60%");
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0");
  datos.Zona[0]=label;
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[6]), label, TRUE, TRUE, 0);

  //zona 2
  
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);
  label=gtk_label_new("Zona 2");
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);
  label=gtk_label_new("60% - 70%");
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0");
  datos.Zona[1]=label;
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[7]), label, TRUE, TRUE, 0);

  //zona 3

  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[8]), label, TRUE, TRUE, 0);
  label=gtk_label_new("Zona 3");
  gtk_box_pack_start(GTK_BOX(box[8]), label, TRUE, TRUE, 0);
  label=gtk_label_new("70% - 80%");
  gtk_box_pack_start(GTK_BOX(box[8]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0");
  datos.Zona[2]=label;
  gtk_box_pack_start(GTK_BOX(box[8]) ,label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[8]), label, TRUE, TRUE, 0);

  //zona 4

  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);
  label=gtk_label_new("Zona 4");
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);
  label=gtk_label_new("80% - 90%");
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0");
  datos.Zona[3]=label;
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[9]), label, TRUE, TRUE, 0);

  //zona 5
  label = gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);
  label=gtk_label_new("Zona 5");
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);
  label=gtk_label_new("90% - 100%");
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);
  label=gtk_label_new("0");
  datos.Zona[4]=label;
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);
  label=gtk_label_new("");
  gtk_box_pack_start(GTK_BOX(box[10]), label, TRUE, TRUE, 0);

  
  for(i=0;i<11;i++) 
    gtk_box_pack_start(GTK_BOX(verticalbox), box[i], TRUE, TRUE, 0);
  
  gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(StopTheApp),NULL);

  gtk_container_add(GTK_CONTAINER(window),verticalbox);

  gtk_widget_show_all(window);
  
  gtk_main();
}

void Calcular(GtkButton *button, gpointer data)
{
  tipo *info =  (tipo *) data; 
  float max, edad, peso, porc=1; 
  int i, guardah[6], guardah2[6], guardam[6], guardam2[6];
  char imp[20];
  const gchar *EDAD, *PESO;
  
  EDAD=gtk_entry_get_text(GTK_ENTRY(info->Edad));
  PESO=gtk_entry_get_text(GTK_ENTRY(info->Peso));
  sscanf(EDAD, "%f", &edad); 
  sscanf(PESO, "%f", &peso);

  if(info->Gen == 'H')
    {
      for(i=5;i>=0;i--)
	{
	  max = (210 - (edad/2) -.05 * (peso) + 4) * porc;
	  porc = porc - .1;
	  guardah[i] = max;
	  guardah2[i] = max;
	}
      for(i=0;i<6;i++)
	{
	  guardah2[i]=guardah2[i]+18;
	  sprintf(imp, "%d - %d ppm", guardah[i], guardah2[i]);
	  gtk_label_set_text(GTK_LABEL(info->Zona[i]), imp); 
	}
    }
  else 
    {
      __fpurge(stdin);
      for(i=5;i>=0;i--)
	{
	  max = (210 - (edad/2) -.01 * (peso)) * porc;
	  porc = porc - .1;
	  guardam[i] = max;
	  guardam2[i] = max;
	}
      
      for(i=0;i<6;i++)
	{
	  guardam2[i]=guardam2[i]+19;
	  sprintf(imp, "%d - %d ppm", guardam[i], guardam2[i]);
	  gtk_label_set_text(GTK_LABEL(info->Zona[i]), imp); 
	}
    }


}


void Fem(GtkToggleButton *button, gpointer data)
{
  tipo *info = (tipo *) data;
  info->Gen = 'M';
}
void Mas(GtkToggleButton *button, gpointer data)
{
  tipo *info = (tipo *) data;
  info->Gen = 'H';
}

void StopTheApp(GtkButton *button, gpointer data)
{
  gtk_main_quit();
}


 

