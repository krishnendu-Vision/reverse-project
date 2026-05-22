#include <gtk/gtk.h>

static void on_button_clicked(GtkWidget *widget, gpointer data) {
    g_print("Modern button clicked!\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;
    GtkWidget *header_bar;
    GtkCssProvider *css_provider;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Modern App");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a Modern Header Bar (Title Bar)
    header_bar = gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);

    // Use a Box to center the button properly
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_halign(box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(box, GTK_ALIGN_CENTER);
    gtk_window_set_child(GTK_WINDOW(window), box);

    // Create the Styled Button
    button = gtk_button_new_with_label("Get Started");
    gtk_widget_add_css_class(button, "modern-button");
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_box_append(GTK_BOX(box), button);

    // Modern CSS styling
    css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider,
        "window { background-color: #1e1e1e; }" // Dark theme background
        ".modern-button {"
        "  background: linear-gradient(to bottom, #3584e4, #1c71d8);"
        "  color: white;"
        "  border-radius: 20px;" // Extra rounded for modern look
        "  padding: 12px 30px;"
        "  font-size: 16px;"
        "  font-weight: bold;"
        "  border: none;"
        "  box-shadow: 0 4px 6px rgba(0,0,0,0.3);"
        "  transition: all 200ms ease;"
        "}"
        ".modern-button:hover {"
        "  background: #3584e4;"
        "  margin-top: -2px;" // Slight "lift" effect on hover
        "}", -1);

    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(),
        GTK_STYLE_PROVIDER(css_provider),
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("org.gtk.modern", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}

