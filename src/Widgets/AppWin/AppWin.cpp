#include "AppWin.h"

AppWin::AppWin()
{
    set_title("DM-Office App");
    set_default_size(400, 350);

    

    header_bar.pack_start(str);
    header_bar.pack_end(button);

    set_titlebar(header_bar);

}