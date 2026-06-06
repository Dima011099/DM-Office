#include "CssLoader.h"
#include <iostream>

namespace DM {

    void CssLoader::load_from_file(const Glib::RefPtr<Gtk::StyleContext>& context, const std::string& path) {

        // Gtk::CssProvider uses internal reference counting via Glib::RefPtr.
        // It must outlive this function scope; Gtk::StyleContext increments the ref count internally upon attachment.
        auto css_provider = Gtk::CssProvider::create();

        try {
            css_provider->load_from_path(path);
        } catch (const Glib::Error& error) {
            // Glib::Error encapsulates underlying GError domain and code (e.g., file not found or parser error).
            // Non-breaking failure: We log and abort attachment to prevent corrupted UI states.
            std::cerr << "Error loading CSS from file: " << error.what() << std::endl;
            return;
        }
        // Application priority overrides standard system themes (Adwaita, etc.) but allows 
        // widget-specific inline styles to take higher precedence if needed.
        context->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    }

    void CssLoader::load_from_string(const Glib::RefPtr<Gtk::StyleContext>& context, const std::string& str) {
        auto css_provider = Gtk::CssProvider::create();
        try {
            // Intercepts glibmm parser warnings/errors. 
            // Note: load_from_data expects valid CSS syntax; syntax errors will trigger Glib::MarkupError or similar.
            css_provider->load_from_data(str.c_str());
        } catch (const Glib::Error& error) {
            std::cerr << "Error loading CSS: " << error.what() << std::endl;
            return;
        }
        context->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    }
} // namespace DM