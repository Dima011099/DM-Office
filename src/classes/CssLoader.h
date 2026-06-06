#include <gtkmm.h>
#include <string>

namespace DM {

    /**
    * @brief Utility class for runtime GTK application skinning via CSS.
    * 
    * Handles style provider instantiation, parsing, and attachment to specific widgets 
    * or screen contexts. Design note: Methods are kept static as the class maintains no 
    * internal state and serves as a pure stateless helper.
    */
    class CssLoader {
    public:
        /**
        * @brief Loads and parses a CSS stylesheet from the local filesystem.
        * @param context Target style context (usually the root window or screen context).
        * @param path Absolute or relative file path to the .css asset.
        * @note Fails gracefully if the file is missing or contains invalid CSS syntax.
        */
        static void load_from_file(const Glib::RefPtr<Gtk::StyleContext>& context, const std::string& path);

        /**
        * @brief Parses raw CSS string data and applies it to the context.
        * @param context Target style context.
        * @param str Valid CSS markup string.
        * @note Useful for dynamic themes, in-memory modifications, or embedded resource loading.
        */
        static void load_from_string(const Glib::RefPtr<Gtk::StyleContext>& context, const std::string& str);
    };

} // namespace DM