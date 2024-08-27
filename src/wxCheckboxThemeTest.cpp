#include <wx/wx.h>
#include "wxCheckboxThemeTest.h"
#include "wxThemer/wxThemer.h"

wxCheckboxThemeTest::wxCheckboxThemeTest(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300))
{
    // create theme instance and switch to the theme name set in this project (m_arrayThemeNames[m_themeIndex])
    m_theme = new wxThemer(); // dev-note: wxThemer objects detect user OS values on creation

    // m_theme->SwitchToTheme(m_arrayThemeNames[m_themeIndex]);
    //   create some widgets
    m_flexGridSizer = new wxFlexGridSizer(GRID_ROWS_DEFAULT, GRID_VGAP, GRID_HGAP);
    m_panel = new wxPanel(this, wxID_ANY);
    m_staticText = new wxStaticText(m_panel, wxID_ANY, "Static Text Label");
    m_checkBox = new wxCheckBox(m_panel, wxID_ANY, "Test Checkbox");
    m_button = new wxButton(m_panel, wxID_ANY, m_arrayThemeNames[m_themeIndex], wxDefaultPosition, wxDefaultSize, wxBORDER_THEME);
    m_filePickerCtrl = new wxFilePickerCtrl(m_panel, wxID_ANY, "File Picker");
    m_staticBox = new wxStaticBox(m_panel, wxID_ANY, "Static Box");

    m_flexGridSizer->Add(m_staticText, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
    m_flexGridSizer->Add(m_checkBox, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
    m_flexGridSizer->Add(m_button, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL);
    m_flexGridSizer->Add(m_filePickerCtrl, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL | wxEXPAND);
    m_flexGridSizer->Add(m_staticBox, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL | wxEXPAND);
    // m_flexGridSizer->AddGrowableRow(0);
    // m_flexGridSizer->AddGrowableRow(1);
    // m_flexGridSizer->AddGrowableRow(2);
    m_flexGridSizer->AddGrowableRow(3);
    m_flexGridSizer->AddGrowableRow(4);
    m_flexGridSizer->AddGrowableCol(0);
    m_panel->SetSizer(m_flexGridSizer);

    m_button->SetLabel(m_theme->ActiveTheme.themeName);

    if (m_theme->SearchForTheme(m_theme->ActiveTheme.themeName))
    {
        m_theme->ApplyThemeToAllRecursively(this);
    }

    // bind event handlers
    m_button->Bind(wxEVT_BUTTON, &wxCheckboxThemeTest::OnButtonClick, this);
}

// handle button click to cycle through available themes
void wxCheckboxThemeTest::OnButtonClick(wxCommandEvent &event)
{
    // Increment the index, and wrap around if necessary
    m_themeIndex = (m_themeIndex + 1) % m_arrayThemeNames.GetCount();
    // Update the button label
    m_button->SetLabel(m_arrayThemeNames[m_themeIndex]);
    // Attempt switch theme
    if (m_theme->SearchForTheme(m_arrayThemeNames[m_themeIndex]))
    {
        m_theme->ApplyThemeToOSControlledAreas(this);
        m_theme->ApplyThemeToAllRecursively(this);
    }
}
