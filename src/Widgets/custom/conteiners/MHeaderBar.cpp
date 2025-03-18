#include "MHeaderBar.h"
#include <iostream>

using namespace DM;

// Constructor of the MHeaderBar class
MHeaderBar::MHeaderBar()
{
    // Create a new instance of the CSS provider
    auto css_provider = Gtk::CssProvider::create();

    // Attempt to load the CSS styles
    try {
        // Load styles from the string returned by the css_style() method
        css_provider->load_from_data(this->css_style());
    } catch (const Glib::Error& error) {
        // If an error occurs while loading, output the error message to the standard error stream
        std::cerr << "Error loading CSS: " << error.what() << std::endl;
        return; // Exit the constructor if loading styles failed
    }
    // Add the CSS provider to the style context of the header
    this->get_style_context()->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

// Method that returns CSS styles for the header
std::string MHeaderBar::css_style()
{
    // Return a multi-line string with CSS styles
    return R"(
    headerbar {
        background: #ffffff; // Set the background to white
        color: #2a4a5a; // Set the text color
        font-size: 14px; // Set the font size
        box-shadow: none; // Remove the shadow
    }
    )";
}