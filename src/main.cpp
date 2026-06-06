#include <iostream>

#include "AppWin.h"

// Unique application identifier required for the OS desktop environment.
// Used by D-Bus / Wayland / X11 for single-instance management and desktop file integration.
constexpr auto DEFAULT_APP_ID = "org.dm.dmoffice";

// Base UI layout dimensions. 
// Chosen as a reasonable default for standard desktop resolutions (1080p and scaling factor 1x).
constexpr int DEFAULT_WIN_WIDTH = 940;
constexpr int DEFAULT_WIN_HEIGHT = 640;


int main(int argc, char* argv[])
{
    // RAII-compliant entry point. Standard library exceptions from gtkmm/glibmm are caught here.
    try
    {
        // Initializes Gtkmm runtime, registers the application ID with the system session bus,
        // and handles standard CLI arguments (e.g., --display, --g-fatal-warnings).
        auto app = Gtk::Application::create(DEFAULT_APP_ID);

        // Instantiates the main window via RAII, binds it to the application lifecycle,
        // and blocks the main thread by starting the GLib/Gtk event loop.
        // Returns the exit code directly to the OS upon window closure.
        return app->make_window_and_run<AppWin>(
            argc, 
            argv,
            DEFAULT_WIN_WIDTH,
            DEFAULT_WIN_HEIGHT
        );
    }catch (const std::exception& e)
    {
        // Critical initialization or runtime failure fallback. 
        // Logged to stderr as the UI environment might not be available or stable at this point.
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}