#include <gtkmm.h>

#include "MHeaderBar.h"

class AppWin : public Gtk::Window
{
public:
AppWin();

private:
MCustom::MHeaderBar header_bar;
Gtk::Button button {"OK"};
Gtk::Button str {"STR"};
};