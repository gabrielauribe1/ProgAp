#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>


GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox);
void StopTheApp(GtkWidget *window, gpointer data);
void ButtonClicked(GtkButton *button, gpointer data);
void Resultado(GtkButton *button, gpointer data);


gint main (gint argc, gchar *argv[])
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *box;
  GtkWidget *verticalbox;
  GtkWidget *entrybox;
  GtkWidget *label;
  
  gtk_init(&argc, &argv);

  window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window),330,210);
  gtk_container_border_width(GTK_CONTAINER(window),5);
  gtk_window_set_title(GTK_WINDOW(window),"Gaby");

  verticalbox = gtk_vbox_new(TRUE,5);
  gtk_container_add(GTK_CONTAINER(window),verticalbox);

  entrybox = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(verticalbox),entrybox,TRUE,TRUE,5);

  box=gtk_hbox_new(TRUE,5);

  button=AddButton(box,"1",ButtonClicked,entrybox);
  button=AddButton(box,"2",ButtonClicked,entrybox);
  button=AddButton(box,"3",ButtonClicked,entrybox);
  
  label=gtk_label_new("");
  gtk_box_pack_end(GTK_BOX(box),label,TRUE,TRUE,0);
  
  gtk_box_pack_start(GTK_BOX(verticalbox),box,TRUE,TRUE,0);

  box=gtk_hbox_new(TRUE,0);

  button=AddButton(box,"4",ButtonClicked,entrybox);
  button=AddButton(box,"5",ButtonClicked,entrybox);
  button=AddButton(box,"6",ButtonClicked,entrybox);
  button=AddButton(box,"-",ButtonClicked,entrybox);

  gtk_box_pack_start(GTK_BOX(verticalbox),box,TRUE,TRUE,0);

  box=gtk_hbox_new(TRUE,0);

  button=AddButton(box,"7",ButtonClicked,entrybox);
  button=AddButton(box,"8",ButtonClicked,entrybox);
  button=AddButton(box,"9",ButtonClicked,entrybox);
  button=AddButton(box,"+",ButtonClicked,entrybox);

  gtk_box_pack_start(GTK_BOX(verticalbox),box,TRUE,TRUE,0);

  box=gtk_hbox_new(TRUE,0);

  button=AddButton(box,"0",ButtonClicked,entrybox);
  button=AddButton(box,"/",ButtonClicked,entrybox);
  button=AddButton(box,"*",ButtonClicked,entrybox);
  button=AddButton(box,"=",Resultado,entrybox);

  gtk_box_pack_start(GTK_BOX(verticalbox),box,TRUE,TRUE,0);

  gtk_widget_show_all(window);
  gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(StopTheApp),NULL);
  gtk_main();
  return 0;
}

GtkWidget *AddButton(GtkWidget *theBox, const gchar *buttonText, gpointer CallBackFunction, GtkWidget *EntryBox){
  GtkWidget *button;
  button = gtk_button_new_with_label(buttonText);
  gtk_box_pack_start(GTK_BOX(theBox),button,FALSE,TRUE,0);
  gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(CallBackFunction),EntryBox);
  gtk_widget_show(button);
  return button;
}


void ButtonClicked(GtkButton *button, gpointer data)
{
  const gchar *valor;
  char string[20];


  valor=gtk_entry_get_text(GTK_ENTRY(data));


  gtk_entry_set_text(GTK_ENTRY(data), valor);
  strcpy(string, valor);
  strcat(string, gtk_button_get_label(button));
  g_print("Button got clicked: %s \n", gtk_button_get_label(button));
  gtk_entry_set_text(GTK_ENTRY(data), string);

  
}

void StopTheApp(GtkWidget *window, gpointer data)
{
  gtk_main_quit();
}

void Resultado(GtkButton *button, gpointer data)
{
  const gchar *valor;
  char string[20];
  float v1, v2, resultado;
  char tipoop;

  valor=gtk_entry_get_text(GTK_ENTRY(data));

  sscanf(valor,"%f%c%f",&v1,&tipoop,&v2);
  if(tipoop=='+')
    resultado = v1+v2;
  if(tipoop=='-')
    resultado = v1-v2;
  if(tipoop=='*')
    resultado = (v1*v2);
  if(tipoop=='/')
    resultado = v1/v2;

  sprintf(string, "%.3f", resultado);
  gtk_entry_set_text(GTK_ENTRY(data), string);

}
