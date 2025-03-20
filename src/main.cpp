#include "AppWin.h" // Include the header file for the AppWin class

// Main function: entry point of the application
int main(int argc, char* argv[])
{
    // Create a new GTK application with a unique application ID
    auto app = Gtk::Application::create("org.dm.dmoffice");
    // Run the application, creating an instance of AppWin as the main window
    return app->make_window_and_run<AppWin>(argc, argv);
}