#include <gtkmm.h>
#include<string>

namespace DM
{

class MHeaderBar : public Gtk::HeaderBar
{
public:
MHeaderBar(); // Constructor for the MHeaderBar class

protected:
std::string css_style(); // Method to return CSS styles
void update_css();

private:

};

}

