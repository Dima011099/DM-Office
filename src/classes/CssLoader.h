#include <gtkmm.h>
#include <string>

namespace DM {

    class CssLoader {
    public:
        static void load_from_file(const Glib::RefPtr<Gtk::StyleContext>& context, const std::string& path);
        static void load_from_string(const Glib::RefPtr<Gtk::StyleContext>& context, const std::string& str);
    };

}