#include "AppWin.h"

AppWin::AppWin()
{
    // Set the default window size
    set_default_size(920, 540);

    // Create CSS providers for styling
    auto css_provider = Gtk::CssProvider::create();

    // Define CSS styles for TextView
    const char* css = R"(
    textview{
    background: #EEEEEE;
    color: #112233;
    font-size: 16px;
    }
    )";

    // Load CSS styles into the providers
    css_provider->load_from_data(css);
  

    // Configure the TextView
    text_view.set_wrap_mode(Gtk::WrapMode::WORD);
    text_buffer = Gtk::TextBuffer::create();
    text_view.get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    text_view.set_buffer(text_buffer);

    // Set up the ScrolledWindow with the TextView
    scrolled_window.set_child(text_view);
    scrolled_window.set_vexpand(true);

    // Arrange the layout in a VBox
    vbox.append(scrolled_window);

    // Set the main child of the window
    set_child(vbox);
    set_titlebar(header_bar);
}