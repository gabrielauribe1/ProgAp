#include <gtk/gtk.h>
#include <string.h>

typedef struct _general
{
  GtkWidget *entrybox;
  GtkWidget *entrybox2;
  int sexo;
  GtkWidget *label4;
  GtkWidget *label5;
  GtkWidget *label6;
  GtkWidget *label7;
  GtkWidget *label8;
  GtkWidget *label9;
}general;

void Calcula (GtkWidget *button, gpointer data);
void Hombre (GtkWidget *Radio1, gpointer data);
void Mujer (GtkWidget *Radio2, gpointer data);
void StopTheApp (GtkWidget *window, gpointer data);

gint main ( gint argc, gchar *argv[])
{

  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *horizontalbox;
  GtkWidget *verticalbox, *verticalbox2, *verticalbox3;
  GtkWidget *Radio1,*Radio2;
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *label3;
  GtkWidget *label_espacio;
  general principal;


  principal.sexo=1;
  gtk_init(&argc, &argv);
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Zonas Cardiacas");
  gtk_window_set_default_size(GTK_WINDOW(window),400,250);
  gtk_container_border_width(GTK_CONTAINER(window),0);
  verticalbox = gtk_vbox_new(FALSE,0);

  //EDAD Y ENTRYBOX
  horizontalbox= gtk_hbox_new(FALSE,0);
  label1=gtk_label_new("Edad:");
  principal.entrybox=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(horizontalbox),label1,TRUE,FALSE,70);
  gtk_box_pack_start(GTK_BOX(horizontalbox),principal.entrybox,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),horizontalbox,TRUE,TRUE,0);

  //PESO Y ENTRYBOX
  horizontalbox=gtk_hbox_new(FALSE,0);
  label2=gtk_label_new("Peso (libras):");
  principal.entrybox2=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(horizontalbox),label2,TRUE,FALSE,45);
  gtk_box_pack_start(GTK_BOX(horizontalbox),principal.entrybox2,TRUE,FALSE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),horizontalbox,TRUE,TRUE,0);

  //RADIOS
  
  //RADIO 1  
  verticalbox2 = gtk_vbox_new(FALSE,0);
  horizontalbox = gtk_hbox_new(FALSE,0);
  
  label_espacio=gtk_label_new(" ");
  gtk_box_pack_start(GTK_BOX(horizontalbox),label_espacio,TRUE,TRUE,58);
  
  Radio1 = gtk_radio_button_new_with_label(NULL,"Hombre");
  gtk_box_pack_start(GTK_BOX(verticalbox2),Radio1,FALSE,FALSE,0);
  gtk_signal_connect(GTK_OBJECT(Radio1),"toggled",GTK_SIGNAL_FUNC(Hombre),&principal);

  //RADIO 2
  Radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(Radio1)),"Mujer");
  gtk_box_pack_start(GTK_BOX(verticalbox2),Radio2,TRUE,TRUE,0);
  gtk_signal_connect(GTK_OBJECT(Radio2),"toggled",GTK_SIGNAL_FUNC(Mujer),&principal);
  
  gtk_box_pack_start(GTK_BOX(horizontalbox),verticalbox2,TRUE,TRUE,0);
  gtk_box_pack_start(GTK_BOX(verticalbox),horizontalbox,TRUE,TRUE,0);

  
  //BOTON "CALCULA"
  horizontalbox=gtk_hbox_new(FALSE,0);
  
  label_espacio=gtk_label_new(" ");
  button=gtk_button_new_with_label("Calcula");
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(Calcula),&principal);
  gtk_box_pack_start(GTK_BOX(horizontalbox),button,TRUE,TRUE,10);
  gtk_box_pack_start(GTK_BOX(horizontalbox),label_espacio,TRUE,TRUE,45);
  gtk_box_pack_start(GTK_BOX(verticalbox),horizontalbox,FALSE,FALSE,0);

  
  //ZONAS CON LABEL
  verticalbox3=gtk_vbox_new(FALSE,0);
  
  label3=gtk_label_new("Zonas");
  gtk_box_pack_start(GTK_BOX(verticalbox3),label3,FALSE,FALSE,20);
  
  principal.label4=gtk_label_new("Zona 1    50% -");
  gtk_box_pack_start(GTK_BOX(verticalbox3),principal.label4,FALSE,FALSE,5);
  
  principal.label5=gtk_label_new("Zona 2    60% -");
  gtk_box_pack_start(GTK_BOX(verticalbox3),principal.label5,FALSE,FALSE,5);
  
  principal.label6=gtk_label_new("Zona 3    70% -");
  gtk_box_pack_start(GTK_BOX(verticalbox3),principal.label6,FALSE,FALSE,5);
  
  principal.label7=gtk_label_new("Zona 4    80% -");
  gtk_box_pack_start(GTK_BOX(verticalbox3),principal.label7,FALSE,FALSE,5);
  
  principal.label8=gtk_label_new("Zona 5    90% -");
  gtk_box_pack_start(GTK_BOX(verticalbox3),principal.label8,FALSE,FALSE,5);
  
  principal.label9=gtk_label_new("Zona 6   100% -");
  gtk_box_pack_start(GTK_BOX(verticalbox3),principal.label9,FALSE,FALSE,5);

  gtk_box_pack_start(GTK_BOX(verticalbox),verticalbox3,FALSE,FALSE,0);

  
  //ULTIMAS FUNCIONES
  gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(StopTheApp),NULL);
  
  gtk_container_add(GTK_CONTAINER(window),verticalbox);
  
  gtk_widget_show_all(window);
  
  gtk_main();

  return 0;

}



void StopTheApp(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
    
}

void Hombre (GtkWidget *Radio1, gpointer data)
{
  general *dato= (general*)data;
  dato->sexo=1;
}

void Mujer (GtkWidget *Radio2, gpointer data)
{
  general *dato= (general*)data;
  dato->sexo=2;
}

void Calcula (GtkWidget *button, gpointer data)
{
  const gchar *Peso, *Edad;
  float Age,Pounds;
  int Hr_max,Zona1,Zona2,Zona3,Zona4,Zona5;
  char z1[150],z2[150],z3[150],z4[150],z5[150],z6[150];
  char cien[150], noventa[150], ochenta[150], setenta[150], sesenta[150], cincuenta[150];
  
  general *dato= (general*)data;
    
  Edad=gtk_entry_get_text(GTK_ENTRY(dato->entrybox));
  Peso=gtk_entry_get_text(GTK_ENTRY(dato->entrybox2));
  sscanf(Edad,"%f",&Age);
  sscanf(Peso,"%f",&Pounds);
  if(dato->sexo==1)//Es Hombre
    {
      Hr_max=210-(Age/2)-(.05*(Pounds))+4;
      Zona1=(Hr_max)*(0.5);
      Zona2=Hr_max*.6;
      Zona3=Hr_max*.7;
      Zona4=Hr_max*.8;
      Zona5=Hr_max*.9;    
    }
  else if(dato->sexo==2)//Es Mujer
    {
      Hr_max=210-(Age/2)-(.01*(Pounds))+0;
      Zona1=Hr_max*.5;
      Zona2=Hr_max*.6;
      Zona3=Hr_max*.7;
      Zona4=Hr_max*.8;
      Zona5=Hr_max*.9;
    }

  strcpy(z1,"Zona 1    50% - ");
  sprintf(cincuenta,"%i",Zona1);
  strcat(z1,cincuenta);
  strcat(z1,"ppm");
  gtk_label_set_text(GTK_LABEL(dato->label4),z1);
  
  strcpy(z2,"Zona 2    60% - ");
  sprintf(sesenta,"%i",Zona2);
  strcat(z2,sesenta);
  strcat(z2,"ppm");
  gtk_label_set_text(GTK_LABEL(dato->label5),z2);
  
  strcpy(z3,"Zona 3    70% - ");
  sprintf(setenta,"%i",Zona3);
  strcat(z3,setenta);
  strcat(z3,"ppm");
  gtk_label_set_text(GTK_LABEL(dato->label6),z3);
  
  strcpy(z4,"Zona 4    80% - ");
  sprintf(ochenta,"%i",Zona4);
  strcat(z4,ochenta);
  strcat(z4,"ppm");
  gtk_label_set_text(GTK_LABEL(dato->label7),z4);
  
  strcpy(z5,"Zona 5    90% - ");
  sprintf(noventa,"%i",Zona5);
  strcat(z5,noventa);
  strcat(z5,"ppm");
  gtk_label_set_text(GTK_LABEL(dato->label8),z5);
  
  strcpy(z6,"Zona 6   100% - ");
  sprintf(cien,"%i",Hr_max);
  strcat(z6,cien);
  strcat(z6,"ppm");
  gtk_label_set_text(GTK_LABEL(dato->label9),z6);
  
}
