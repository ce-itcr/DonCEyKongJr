#include "Interface.h"

GtkWidget *window;
GtkWidget *window2;
GtkWidget *fixed1;
GtkWidget *fixed2;
GtkWidget *button1;
GtkWidget *button2;
GtkWidget *label1;
GtkWidget *builder;

void loadInterface(){

    builder = gtk_builder_new_from_file("Interface.glade");

//    builder = gtk_builder_new();
//    gtk_builder_add_from_file(builder, "Interface.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    window2 = GTK_WIDGET(gtk_builder_get_object(builder,"window2"));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect(window2, "destroy", G_CALLBACK(gtk_main_quit),NULL);

    gtk_builder_connect_signals(builder,NULL);

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    fixed2 = GTK_WIDGET(gtk_builder_get_object(builder,"fixed2"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    button2 = GTK_WIDGET(gtk_builder_get_object(builder,"button2"));
    label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));

    gtk_widget_show(window);
}

void changeLable(){
    printf("hola");
}


void createbutton(int x,int y){
    GtkWidget *newButton = gtk_button_new_with_label("Test");
    g_signal_connect(newButton,"clicked",G_CALLBACK(changeLable),NULL);
    gtk_fixed_put(fixed1,newButton,x,y);
    gtk_widget_show(newButton);
}


void on_button1_clicked(GtkButton *b){
    gtk_widget_hide(window);
    gtk_widget_show(window2);
}

void on_button2_clicked(GtkButton *b){
    gtk_widget_hide(window2);
    gtk_widget_show(window);
    createbutton(50,50);
}