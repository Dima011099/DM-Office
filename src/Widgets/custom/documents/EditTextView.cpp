#include "EditTextView.h"
#include "CssLoader.h"

using namespace DM_OFFICE;

EditTextView::EditTextView() {
    this->initialize_edit_text();
    this->update_css();
}

void EditTextView::initialize_edit_text() {
    set_wrap_mode(Gtk::WrapMode::WORD);
    text_buffer = Gtk::TextBuffer::create();
    set_buffer(text_buffer);
}

void EditTextView::update_css() {
    DM::CssLoader::load_from_string(get_style_context(), css_style());
}

std::string EditTextView::css_style() const { // Добавлено const
    return R"(
        textview {
            background: #EEEEEE;
            color: #112233;
            font-size: 16px;
        }
    )";
}