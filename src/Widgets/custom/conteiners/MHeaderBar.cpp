#include "MHeaderBar.h"
#include "CssLoader.h"

using namespace DM;

// Constructor of the MHeaderBar class
MHeaderBar::MHeaderBar()
{
    this->update_css();
}

void MHeaderBar::update_css()
{
    DM::CssLoader::load_from_string(get_style_context(), css_style());
}

// Method that returns CSS styles for the header
std::string MHeaderBar::css_style()
{
    // Return a multi-line string with CSS styles
    return R"(
    headerbar {
        background: #ffffff; /* Set the background to white */
        color: #2a4a5a; /* Set the text color */
        font-size: 14px; /* Set the font size */
        box-shadow: none; /* Remove the shadow */
    }
    )";
}