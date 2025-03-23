#include "AppWin.h"

AppWin::AppWin(int width, int height)
{
    // Set the default window size
    set_default_size(width, height);

    // Set up the ScrolledWindow with the TextView
    scrolled_window.set_child(this->editTextView);
    scrolled_window.set_vexpand(true);

    // Arrange the layout in a VBox
    vbox.append(scrolled_window);

    // Set the main child of the window
    set_child(vbox);
    set_titlebar(header_bar);
}