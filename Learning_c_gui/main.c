#include <gtk/gtk.h>

static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Modern button clicked!\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;
    GtkCssProvider *css_provider;
    GdkScreen *screen;

    // Create the main window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Modern GTK3 App");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a button
    button = gtk_button_new_with_label("Click Me");
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(button, GTK_ALIGN_CENTER);
    
    // In GTK3, we use name or style context directly
    gtk_widget_set_name(button, "modern-button");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    // Load custom CSS
    css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider,
        "#modern-button {"
        "  background-image: none;" // Remove default GTK theme gradient
        "  background-color: #3584e4;"
        "  color: white;"
        "  border-radius: 12px;"
        "  border: none;"
        "  padding: 10px 20px;"
        "  font-weight: bold;"
        "}"
        "#modern-button:hover {"
        "  background-color: #1c71d8;"
        "}", -1, NULL); // Added missing NULL for GError

    // Apply CSS to the screen in GTK3
    screen = gdk_screen_get_default();
    gtk_style_context_add_provider_for_screen(
        screen,
        GTK_STYLE_PROVIDER(css_provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    // In GTK3, use gtk_container_add instead of gtk_window_set_child
    gtk_container_add(GTK_CONTAINER(window), button);
    
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

