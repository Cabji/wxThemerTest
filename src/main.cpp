#include "wxCheckboxThemeTest.h"
#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    // Check if the "--console" argument is passed
    for (int i = 0; i < argc; ++i)
    {
        if (wxString(argv[i]) == "--console")
        {
            // Attach a console window to the GUI application
            if (AllocConsole())
            {
                FILE *pCout;
                freopen_s(&pCout, "CONOUT$", "w", stdout);
                freopen_s(&pCout, "CONOUT$", "w", stderr);
                freopen_s(&pCout, "CONIN$", "r", stdin);
                std::cout << "wxThemeTest Console" << std::endl;
            }
            break;
        }
    }
    wxCheckboxThemeTest *frame = new wxCheckboxThemeTest("wxCheckbox Theme Test");
    frame->Show(true);
    return true;
}
