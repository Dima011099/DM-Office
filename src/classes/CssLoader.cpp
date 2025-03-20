#include "CssLoader.h"
#include <iostream>

using namespace DM;

void CssLoader::load_from_file(const Glib::RefPtr<Gtk::StyleContext>& context, const std::string& path) {
    auto css_provider = Gtk::CssProvider::create();
    try {
        css_provider->load_from_path(path);
    } catch (const Glib::Error& error) {
        std::cerr << "Error loading CSS from file: " << error.what() << std::endl;
        return;
    }
    context->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

void CssLoader::load_from_string(const Glib::RefPtr<Gtk::StyleContext>& context, const std::string& str) {
    auto css_provider = Gtk::CssProvider::create();
    try {
        css_provider->load_from_data(str.c_str());
    } catch (const Glib::Error& error) {
        std::cerr << "Error loading CSS: " << error.what() << std::endl;
        return;
    }
    context->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}