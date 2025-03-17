#include "AppWin.h"
#include <gtkmm.h>

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create("org.dm.dmoffice");
    return app->make_window_and_run<AppWin>(argc, argv);
}