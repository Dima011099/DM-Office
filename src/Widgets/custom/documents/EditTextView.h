#include <gtkmm.h> // Include the GTKmm library for creating graphical user interfaces
#include <string> // Include the string library for using std::string
#include "IEditTextView.h" // Include the header file for the IEditTextView interface

// Define a namespace for the DM_OFFICE components
namespace DM_OFFICE {
    // EditTextView class inherits from Gtk::TextView and implements IEditTextView interface
    class EditTextView : public Gtk::TextView, public IEditTextView {
    public:
        EditTextView();  // Constructor for the EditTextView class

    protected:
        void initialize_edit_text() override; // Override the initialize_edit_text method from IEditTextView
        std::string css_style() const override; // Override the css_style method from IEditTextView to return CSS style as a string
        void update_css() override; // Override the update_css method from IEditTextView to apply CSS styles

    private:
         // Reference pointer to the text buffer used by the TextView
        Glib::RefPtr<Gtk::TextBuffer> text_buffer;
    };

}