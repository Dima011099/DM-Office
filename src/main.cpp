// Сonnects the standard input/output stream for error handling
#include <iostream>

// Application Window Class Header File
#include "AppWin.h"

// Unique identifier of the application by default
constexpr auto DEFAULT_APP_ID = "org.dm.dmoffice";

// DEFAULT_WIN_WIDTH and DEFAULT_WIN_HEIGHT set the default size of the main window.
constexpr int DEFAULT_WIN_WIDTH = 940;
constexpr int DEFAULT_WIN_HEIGHT = 640;


int main(int argc, char* argv[])
{
    try
    {
        // Сreating an instance of a GTK application
        auto app = Gtk::Application::create(DEFAULT_APP_ID);

        // An AppWin window is created and the event loop is started
        return app->make_window_and_run<AppWin>(
            argc, 
            argv,
            DEFAULT_WIN_WIDTH,
            DEFAULT_WIN_HEIGHT
        );
    }catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}