#include <string> // Include the string library for using std::string

// Define a namespace for the DM_OFFICE components
namespace DM_OFFICE {
    // Interface for EditTextView functionality
    class IEditTextView {
    public:
        // Virtual destructor to allow proper cleanup of derived classes
        virtual ~IEditTextView() = default;
        // Pure virtual function to initialize the edit text view
        virtual void initialize_edit_text() = 0;
         // Pure virtual function to get the CSS style as a string
        virtual std::string css_style() const = 0;
        // Pure virtual function to update the CSS style of the edit text view
        virtual void update_css() = 0;
    };

}