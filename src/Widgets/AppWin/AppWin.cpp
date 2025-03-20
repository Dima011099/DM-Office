#include "AppWin.h"

AppWin::AppWin()
{
    // Set the default window size
    set_default_size(920, 540);

/*
    text_view.set_wrap_mode(Gtk::WrapMode::WORD);
    text_buffer = Gtk::TextBuffer::create();
    text_view.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    text_view.set_buffer(text_buffer);
    */

    // Set up the ScrolledWindow with the TextView
    scrolled_window.set_child(this->editTextView);
    scrolled_window.set_vexpand(true);

    // Arrange the layout in a VBox
    vbox.append(scrolled_window);

    // Set the main child of the window
    set_child(vbox);
    set_titlebar(header_bar);
}