#include <gtk/gtk.h>

// Logic for switching pages
static void on_nav_clicked(GtkButton *btn, GtkStack *stack) {
    const char *id = gtk_widget_get_name(GTK_WIDGET(btn));
    gtk_stack_set_visible_child_name(stack, id);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window, *main_box, *sidebar, *content_stack, *header_bar;
    GtkWidget *home_page, *settings_page, *home_label, *set_label;
    GtkCssProvider *provider;

    // 1. Main Window Setup
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Titan Dashboard Pro");
    gtk_window_set_default_size(GTK_WINDOW(window), 900, 600);

    // 2. Modern Header Bar
    header_bar = gtk_header_bar_new();
    gtk_window_set_titlebar(GTK_WINDOW(window), header_bar);

    // 3. Main Horizontal Layout (Sidebar + Content)
    main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_window_set_child(GTK_WINDOW(window), main_box);

    // 4. Sidebar Setup
    sidebar = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_add_css_class(sidebar, "sidebar");
    gtk_widget_set_size_request(sidebar, 200, -1);
    gtk_box_append(GTK_BOX(main_box), sidebar);

    // 5. Content Stack (The "pages")
    content_stack = gtk_stack_new();
    gtk_stack_set_transition_type(GTK_STACK(content_stack), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
    gtk_widget_set_hexpand(content_stack, TRUE);
    gtk_box_append(GTK_BOX(main_box), content_stack);

    // --- Page 1: Dashboard ---
    home_page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_widget_set_halign(home_page, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(home_page, GTK_ALIGN_CENTER);
    home_label = gtk_label_new("Welcome to the Command Center");
    gtk_widget_add_css_class(home_label, "title-text");
    gtk_box_append(GTK_BOX(home_page), home_label);
    gtk_stack_add_named(GTK_STACK(content_stack), home_page, "home");

    // --- Page 2: Settings ---
    settings_page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    gtk_widget_set_halign(settings_page, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(settings_page, GTK_ALIGN_CENTER);
    set_label = gtk_label_new("System Configuration");
    gtk_widget_add_css_class(set_label, "title-text");
    gtk_box_append(GTK_BOX(settings_page), set_label);
    gtk_stack_add_named(GTK_STACK(content_stack), settings_page, "settings");

    // 6. Navigation Buttons
    const char *btns[] = {"Home", "Settings"};
    const char *ids[] = {"home", "settings"};
    for(int i=0; i<2; i++) {
        GtkWidget *nb = gtk_button_new_with_label(btns[i]);
        gtk_widget_set_name(nb, ids[i]);
        gtk_widget_add_css_class(nb, "nav-button");
        g_signal_connect(nb, "clicked", G_CALLBACK(on_nav_clicked), content_stack);
        gtk_box_append(GTK_BOX(sidebar), nb);
    }

    // 7. Advanced CSS Styling
    provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider,
        "window { background-color: #0f0f0f; color: #ffffff; }"
        ".sidebar { background-color: #1a1a1a; padding: 20px; border-right: 1px solid #333; }"
        ".nav-button { "
        "  background: transparent; color: #ccc; border: none; "
        "  padding: 10px; text-align: left; font-size: 14px; border-radius: 8px;"
        "}"
        ".nav-button:hover { background: #333; color: white; }"
        ".title-text { font-size: 32px; font-weight: 800; color: #3584e4; }"
        "headerbar { background: #1a1a1a; border-bottom: 1px solid #333; color: white; }", -1);

    gtk_style_context_add_provider_for_display(gdk_display_get_default(), 
        GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("com.heavy.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    return g_application_run(G_APPLICATION(app), argc, argv);
}

