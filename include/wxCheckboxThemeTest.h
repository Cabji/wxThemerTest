#ifndef WXCHECKBOXTHEMETEST_H
#define WXCHECKBOXTHEMETEST_H

#include <wx/wx.h>
#include <wx/filepicker.h>
#include "wxThemer/wxThemer.h"
#include "wxThemer/wxThemerCheckBox.h"

class wxCheckboxThemeTest : public wxFrame
{
public:
    wxCheckboxThemeTest(const wxString &title);
    void OnButtonClick(wxCommandEvent &event);

private:
    const int GRID_ROWS_DEFAULT = 1, GRID_VGAP = FromDIP(5), GRID_HGAP = FromDIP(5);
    wxThemer *m_theme;
    wxFlexGridSizer *m_flexGridSizer;
    wxPanel *m_panel;
    wxStaticText *m_staticText;
    wxCheckBox *m_checkBox;
    wxButton *m_button;
    wxFilePickerCtrl *m_filePickerCtrl;
    wxStaticBox *m_staticBox;
    wxArrayString m_arrayThemeNames = {"WinOS Light", "WinOS Dark"};
    size_t m_themeIndex = 0;
};

#endif // WXCHECKBOXTHEMETEST_H