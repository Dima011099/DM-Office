#include <gtkmm.h>

#include "MHeaderBar.h"

class AppWin : public Gtk::Window
{
public:
AppWin(); // Constructor for the AppWin class

private:
DM::MHeaderBar header_bar; // Header bar for the application window

Gtk::ScrolledWindow scrolled_window; // Scrolled window to contain the text view
Gtk::TextView text_view; // Text view for displaying and editing text
Glib::RefPtr<Gtk::TextBuffer> text_buffer; // Reference pointer to the text buffer

Gtk::Box vbox {Gtk::Orientation::VERTICAL};  // Vertical box for layout management
};