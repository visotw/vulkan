/*  dialog.cpp
 *  PCSX2 Dev Team
 *  Copyright (C) 2015
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "dialog.h"

// Construtor of Dialog
Dialog::Dialog()
    : wxDialog(NULL,                                  // Parent
               wxID_ANY,                              // ID
               _T("OnePad configuration"),            // Title
               wxDefaultPosition,                     // Position
               wxSize(DEFAULT_WIDTH, DEFAULT_HEIGHT), // Width + Length
               // Style
               wxSYSTEM_MENU |
                   wxCAPTION |
                   wxCLOSE_BOX |
                   wxCLIP_CHILDREN)
{

    /*
     * Define the size and the position of each button :
     * padding[ButtonID][0] : Width
     * padding[ButtonID][1] : Height
     * padding[ButtonID][2] : x position
     * padding[ButtonID][3] : y position
    */
    int padding[BUTTONS_LENGTH][4];

    // L1
    padding[PAD_L1][0] = 218; // Width
    padding[PAD_L1][1] = 28;  // Height
    padding[PAD_L1][2] = 50;  // X
    padding[PAD_L1][3] = 175; // Y

    // L2
    padding[PAD_L2][0] = 218; // Width
    padding[PAD_L2][1] = 28;  // Height
    padding[PAD_L2][2] = 50;  // X
    padding[PAD_L2][3] = 104; // Y

    // R1
    padding[PAD_R1][0] = 218; // Width
    padding[PAD_R1][1] = 28;  // Height
    padding[PAD_R1][2] = 726; // X
    padding[PAD_R1][3] = 175; // Y

    // R2
    padding[PAD_R2][0] = 218; // Width
    padding[PAD_R2][1] = 28;  // Height
    padding[PAD_R2][2] = 726; // X
    padding[PAD_R2][3] = 104; // Y

    // Triangle
    padding[PAD_TRIANGLE][0] = 218; // Width
    padding[PAD_TRIANGLE][1] = 28;  // Height
    padding[PAD_TRIANGLE][2] = 726; // X
    padding[PAD_TRIANGLE][3] = 246; // Y

    // Circle
    padding[PAD_CIRCLE][0] = 218; // Width
    padding[PAD_CIRCLE][1] = 28;  // Height
    padding[PAD_CIRCLE][2] = 726; // X
    padding[PAD_CIRCLE][3] = 319; // Y

    // Cross
    padding[PAD_CROSS][0] = 218; // Width
    padding[PAD_CROSS][1] = 28;  // Height
    padding[PAD_CROSS][2] = 726; // X
    padding[PAD_CROSS][3] = 391; // Y

    // Square
    padding[PAD_SQUARE][0] = 218; // Width
    padding[PAD_SQUARE][1] = 28;  // Height
    padding[PAD_SQUARE][2] = 726; // X
    padding[PAD_SQUARE][3] = 463; // Y

    // Directional pad up
    padding[PAD_UP][0] = 100; // Width
    padding[PAD_UP][1] = 25;  // Height
    padding[PAD_UP][2] = 108; // X
    padding[PAD_UP][3] = 290; // Y

    // Directional pad down
    padding[PAD_DOWN][0] = 100; // Width
    padding[PAD_DOWN][1] = 25;  // Height
    padding[PAD_DOWN][2] = 108; // X
    padding[PAD_DOWN][3] = 340; // Y

    // Directional pad right
    padding[PAD_RIGHT][0] = 109; // Width
    padding[PAD_RIGHT][1] = 25;  // Height
    padding[PAD_RIGHT][2] = 159; // X
    padding[PAD_RIGHT][3] = 315; // Y

    // Directional pad left
    padding[PAD_LEFT][0] = 109; // Width
    padding[PAD_LEFT][1] = 25;  // Height
    padding[PAD_LEFT][2] = 50;  // X
    padding[PAD_LEFT][3] = 315; // Y

    // Left Joystick up
    padding[PAD_L_UP][0] = 100; // Width
    padding[PAD_L_UP][1] = 25;  // Height
    padding[PAD_L_UP][2] = 325; // X
    padding[PAD_L_UP][3] = 527; // Y

    // Left Joystick down
    padding[PAD_L_DOWN][0] = 100; // Width
    padding[PAD_L_DOWN][1] = 25;  // Height
    padding[PAD_L_DOWN][2] = 325; // X
    padding[PAD_L_DOWN][3] = 577; // Y

    // Left Joystick right
    padding[PAD_L_RIGHT][0] = 109; // Width
    padding[PAD_L_RIGHT][1] = 25;  // Height
    padding[PAD_L_RIGHT][2] = 377; // X
    padding[PAD_L_RIGHT][3] = 552; // Y

    // Left Joystick left
    padding[PAD_L_LEFT][0] = 109; // Width
    padding[PAD_L_LEFT][1] = 25;  // Height
    padding[PAD_L_LEFT][2] = 268; // X
    padding[PAD_L_LEFT][3] = 552; // Y

    // L3
    padding[PAD_L3][0] = 218; // Width
    padding[PAD_L3][1] = 28;  // Height
    padding[PAD_L3][2] = 268; // X
    padding[PAD_L3][3] = 641; // Y

    // Right Joystick up
    padding[PAD_R_UP][0] = 100; // Width
    padding[PAD_R_UP][1] = 25;  // Height
    padding[PAD_R_UP][2] = 555; // X
    padding[PAD_R_UP][3] = 527; // Y

    // Right Joystick down
    padding[PAD_R_DOWN][0] = 100; // Width
    padding[PAD_R_DOWN][1] = 25;  // Height
    padding[PAD_R_DOWN][2] = 555; // X
    padding[PAD_R_DOWN][3] = 577; // Y

    // Right Joystick right
    padding[PAD_R_RIGHT][0] = 109; // Width
    padding[PAD_R_RIGHT][1] = 25;  // Height
    padding[PAD_R_RIGHT][2] = 607; // X
    padding[PAD_R_RIGHT][3] = 552; // Y

    // Right Joystick left
    padding[PAD_R_LEFT][0] = 109; // Width
    padding[PAD_R_LEFT][1] = 25;  // Height
    padding[PAD_R_LEFT][2] = 498; // X
    padding[PAD_R_LEFT][3] = 552; // Y

    // R3
    padding[PAD_R3][0] = 218; // Width
    padding[PAD_R3][1] = 28;  // Height
    padding[PAD_R3][2] = 498; // X
    padding[PAD_R3][3] = 641; // Y

    // Start
    padding[PAD_START][0] = 218; // Width
    padding[PAD_START][1] = 28;  // Height
    padding[PAD_START][2] = 503; // X
    padding[PAD_START][3] = 34;  // Y

    // Select
    padding[PAD_SELECT][0] = 218; // Width
    padding[PAD_SELECT][1] = 28;  // Height
    padding[PAD_SELECT][2] = 273; // X
    padding[PAD_SELECT][3] = 34;  // Y

    // Analog
    padding[Analog][0] = 218; // Width
    padding[Analog][1] = 28;  // Height
    padding[Analog][2] = 50;  // X
    padding[Analog][3] = 452; // Y

    // Left Joystick Configuration
    padding[JoyL_config][0] = 180; // Width
    padding[JoyL_config][1] = 28;  // Height
    padding[JoyL_config][2] = 50;  // X
    padding[JoyL_config][3] = 550; // Y

    // Right Joystick Configuration
    padding[JoyR_config][0] = 180; // Width
    padding[JoyR_config][1] = 28;  // Height
    padding[JoyR_config][2] = 764; // X
    padding[JoyR_config][3] = 550; // Y

    // Gamepad Configuration
    padding[Gamepad_config][0] = 180; // Width
    padding[Gamepad_config][1] = 28;  // Height
    padding[Gamepad_config][2] = 50;  // X
    padding[Gamepad_config][3] = 585; // Y

    // Set All Buttons
    padding[Set_all][0] = 180; // Width
    padding[Set_all][1] = 28;  // Height
    padding[Set_all][2] = 764; // X
    padding[Set_all][3] = 585; // Y

    // Apply modifications without exit
    padding[Apply][0] = 70;  // Width
    padding[Apply][1] = 28;  // Height
    padding[Apply][2] = 833; // X
    padding[Apply][3] = 642; // Y

    // Ok button
    padding[Ok][0] = 70;  // Width
    padding[Ok][1] = 28;  // Height
    padding[Ok][2] = 913; // X
    padding[Ok][3] = 642; // Y

    // Cancel button
    padding[Cancel][0] = 70;  // Width
    padding[Cancel][1] = 28;  // Height
    padding[Cancel][2] = 753; // X
    padding[Cancel][3] = 642; // Y

    // create a new Notebook
    m_tab_gamepad = new wxNotebook(this, wxID_ANY);
    for (int i = 0; i < GAMEPAD_NUMBER; ++i)
    {
        // Tabs panels
        m_pan_tabs[i] = new opPanel(
            m_tab_gamepad,
            wxID_ANY,
            wxDefaultPosition,
            wxSize(DEFAULT_WIDTH, DEFAULT_HEIGHT));
        // Add new page
        // Define label
        std::stringstream sstm;
        std::string label = "Gamepad ";
        sstm << label << i;
        // New page creation
        m_tab_gamepad->AddPage(
            m_pan_tabs[i],                           // Parent
            wxString(sstm.str().c_str(), wxConvUTF8) // Title
        );

        for (int j = 0; j < BUTTONS_LENGTH; ++j)
        {
            // Gamepad buttons
            m_bt_gamepad[i][j] = new wxButton(
                m_pan_tabs[i],                         // Parent
                wxID_HIGHEST + j + 1,                  // ID
                _T("Undefined"),                       // Label
                wxPoint(padding[j][2], padding[j][3]), // Position
                wxSize(padding[j][0], padding[j][1])   // Size
            );
        }
        // Redefine others gui buttons label
        m_bt_gamepad[i][JoyL_config]->SetLabel(_T("&Left Joystick Config"));
        m_bt_gamepad[i][JoyR_config]->SetLabel(_T("&Right Joystick Config"));
        m_bt_gamepad[i][Gamepad_config]->SetLabel(_T("&Gamepad Configuration"));
        m_bt_gamepad[i][Set_all]->SetLabel(_T("&Set All Buttons"));
        m_bt_gamepad[i][Cancel]->SetLabel(_T("&Cancel"));
        m_bt_gamepad[i][Apply]->SetLabel(_T("&Apply"));
        m_bt_gamepad[i][Ok]->SetLabel(_T("&Ok"));

        // Disable analog button (not yet supported)
        m_bt_gamepad[i][Analog]->Disable();
    }

    Bind(wxEVT_BUTTON, &Dialog::OnButtonClicked, this);

    m_time_update_gui.SetOwner(this);
    Bind(wxEVT_TIMER, &Dialog::JoystickEvent, this);
    m_time_update_gui.Start(UPDATE_TIME, wxTIMER_CONTINUOUS);

    for (int i = 0; i < GAMEPAD_NUMBER; ++i)
    {
        for (int j = 0; j < NB_IMG; ++j)
        {
            m_pressed[i][j] = false;
        }
    }
}

void Dialog::InitDialog()
{
    GamePad::EnumerateGamePads(s_vgamePad); // activate gamepads
    LoadConfig();                           // Load configuration from the ini file
    repopulate();                           // Set label and fit simulated key array
}

/****************************************/
/*********** Events functions ***********/
/****************************************/

void Dialog::OnButtonClicked(wxCommandEvent &event)
{
    // Affichage d'un message ?? chaque clic sur le bouton
    // Per Google Translate: Display a message each time the button is clicked.
    wxButton *bt_tmp = (wxButton *)event.GetEventObject(); // get the button object
    int bt_id = bt_tmp->GetId() - wxID_HIGHEST - 1;        // get the real ID
    int gamepad_id = m_tab_gamepad->GetSelection();        // get the tab ID (equivalent to the gamepad id)
    if (bt_id >= 0 && bt_id <= PAD_R_LEFT)                 // if the button ID is a gamepad button
    {
        bt_tmp->Disable();                                 // switch the button state to "Disable"
        config_key(gamepad_id, bt_id);
        bt_tmp->Enable();                                  // switch the button state to "Enable"
    }
    else if (bt_id == Gamepad_config)                      // If the button ID is equals to the Gamepad_config button ID
    {
        GamepadConfiguration gamepad_config(gamepad_id, this);

        gamepad_config.InitGamepadConfiguration();
        gamepad_config.ShowModal();
    }
    else if (bt_id == JoyL_config)                         // If the button ID is equals to the JoyL_config button ID
    {
        JoystickConfiguration joystick_config(gamepad_id, true, this);

        joystick_config.InitJoystickConfiguration();
        joystick_config.ShowModal();
    }
    else if (bt_id == JoyR_config)                         // If the button ID is equals to the JoyR_config button ID
    {
        JoystickConfiguration joystick_config(gamepad_id, false, this);

        joystick_config.InitJoystickConfiguration();
        joystick_config.ShowModal();
    }
    else if (bt_id == Set_all)                            // If the button ID is equals to the Set_all button ID
    {
        for (int i = 0; i < MAX_KEYS; ++i)
        {
            bt_tmp = m_bt_gamepad[gamepad_id][i];
            switch (i)
            {
                case PAD_L_UP: // Left joystick (Up) ???
                    m_pan_tabs[gamepad_id]->ShowImg(img_l_arrow_up);
                    break;
                case PAD_L_RIGHT: // Left joystick (Right) ???
                    m_pan_tabs[gamepad_id]->ShowImg(img_l_arrow_right);
                    break;
                case PAD_L_DOWN: // Left joystick (Down) ???
                    m_pan_tabs[gamepad_id]->ShowImg(img_l_arrow_bottom);
                    break;
                case PAD_L_LEFT: // Left joystick (Left) ???
                    m_pan_tabs[gamepad_id]->ShowImg(img_l_arrow_left);
                    break;
                case PAD_R_UP: // Right joystick (Up) ???
                    m_pan_tabs[gamepad_id]->ShowImg(img_r_arrow_up);
                    break;
                case PAD_R_RIGHT: // Right joystick (Right) ???
                    m_pan_tabs[gamepad_id]->ShowImg(img_r_arrow_right);
                    break;
                case PAD_R_DOWN: // Right joystick (Down) ???
                    m_pan_tabs[gamepad_id]->ShowImg(img_r_arrow_bottom);
                    break;
                case PAD_R_LEFT: // Right joystick (Left) ???
                    m_pan_tabs[gamepad_id]->ShowImg(img_r_arrow_left);
                    break;
                default:
                    m_pan_tabs[gamepad_id]->ShowImg(i);
                    break;
            }
            m_pan_tabs[gamepad_id]->Refresh();
            m_pan_tabs[gamepad_id]->Update();
            config_key(gamepad_id, i);
            switch (i)
            {
                case PAD_L_UP: // Left joystick (Up) ???
                    m_pan_tabs[gamepad_id]->HideImg(img_l_arrow_up);
                    break;
                case PAD_L_RIGHT: // Left joystick (Right) ???
                    m_pan_tabs[gamepad_id]->HideImg(img_l_arrow_right);
                    break;
                case PAD_L_DOWN: // Left joystick (Down) ???
                    m_pan_tabs[gamepad_id]->HideImg(img_l_arrow_bottom);
                    break;
                case PAD_L_LEFT: // Left joystick (Left) ???
                    m_pan_tabs[gamepad_id]->HideImg(img_l_arrow_left);
                    break;
                case PAD_R_UP: // Right joystick (Up) ???
                    m_pan_tabs[gamepad_id]->HideImg(img_r_arrow_up);
                    break;
                case PAD_R_RIGHT: // Right joystick (Right) ???
                    m_pan_tabs[gamepad_id]->HideImg(img_r_arrow_right);
                    break;
                case PAD_R_DOWN: // Right joystick (Down) ???
                    m_pan_tabs[gamepad_id]->HideImg(img_r_arrow_bottom);
                    break;
                case PAD_R_LEFT: // Right joystick (Left) ???
                    m_pan_tabs[gamepad_id]->HideImg(img_r_arrow_left);
                    break;
                default:
                    m_pan_tabs[gamepad_id]->HideImg(i);
                    break;
            }
            m_pan_tabs[gamepad_id]->Refresh();
            m_pan_tabs[gamepad_id]->Update();
            usleep(500000); // give enough time to the user to release the button
        }
    }
    else if (bt_id == Ok)                 // If the button ID is equals to the Ok button ID
    {
        SaveConfig();                     // Save the configuration
        Close();                          // Close the window
    }
    else if (bt_id == Apply)              // If the button ID is equals to the Apply button ID
    {
        SaveConfig();                     // Save the configuration
    }
    else if (bt_id == Cancel)             // If the button ID is equals to the cancel button ID
    {
        Close();                          // Close the window
    }
}

void Dialog::JoystickEvent(wxTimerEvent &event)
{
#ifdef SDL_BUILD
    u32 key;
    int map;
    std::map<u32, int>::iterator it;
    std::map<u32, int>::iterator it2;
    SDL_JoystickEventState(SDL_ENABLE);
    SDL_Event events;
    while (SDL_PollEvent(&events))
    {
        switch (events.type)
        {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                break;
            case SDL_JOYAXISMOTION:
                if (events.jaxis.which < GAMEPAD_NUMBER)
                {
                    key = axis_to_key(false, (events.jaxis.value < 0), events.jaxis.axis);
                    it = m_map_images[events.jaxis.which].find(key);
                    if (it != m_map_images[events.jaxis.which].end())
                    {
                        map = m_map_images[events.jaxis.which][key];
                        if (events.jaxis.value == 0)
                        {
                            if (map >= PAD_L_UP && map <= PAD_L_LEFT)
                                m_pan_tabs[events.jaxis.which]->HideImg(img_left_cursor);
                            else if (map >= PAD_R_UP && map <= PAD_R_LEFT)
                                m_pan_tabs[events.jaxis.which]->HideImg(img_right_cursor);
                            else if (map < PAD_L_UP)
                                m_pan_tabs[events.jaxis.which]->HideImg(map);
                        }
                        else
                        {
                            int dir=0;
                            if (map >= PAD_L_UP && map <= PAD_L_LEFT)
                            {
                                if ((map==PAD_L_LEFT) || (map==PAD_L_RIGHT)) dir=0;         // Assumption that LEFT-RIGHT axis is always 0 and UP-DOWN always 1
                                else if ((map==PAD_L_UP) || (map==PAD_L_DOWN)) dir=1;       // and so on, can be wrong.
                                m_pan_tabs[events.jaxis.which]->MoveJoystick(dir, events.jaxis.value);
                                m_pan_tabs[events.jaxis.which]->ShowImg(img_left_cursor);
                            }
                            else if (map >= PAD_R_UP && map <= PAD_R_LEFT)
                            {
                                if ((map==PAD_R_LEFT) || (map==PAD_R_RIGHT)) dir=2;
                                else if ((map==PAD_R_UP) || (map==PAD_R_DOWN)) dir=3;
                                m_pan_tabs[events.jaxis.which]->MoveJoystick(dir, events.jaxis.value);
                                m_pan_tabs[events.jaxis.which]->ShowImg(img_right_cursor);
                            }
                            else if (map < PAD_L_UP) // if this is not a joystick
                            {
                                m_pan_tabs[events.jaxis.which]->ShowImg(map);
                            }
                        }
                        break;
                    }
                    // Hack Dualshock 4 (L2, R2)
                    key = axis_to_key(false, (events.jaxis.value > 0), events.jaxis.axis);
                    it2 = m_map_images[events.jaxis.which].find(key);
                    if (it2 != m_map_images[events.jaxis.which].end())
                    {
                        map = m_map_images[events.jaxis.which][key];
                        if (map < PAD_L_UP) // if this is not a joystick
                        {
                            m_pan_tabs[events.jaxis.which]->HideImg(map);
                        }
                        break;
                    }
                }
                break;
            case SDL_JOYBUTTONDOWN:
                if (events.jbutton.which < GAMEPAD_NUMBER)
                {
                    key = button_to_key(events.jbutton.button);
                    it = m_map_images[events.jbutton.which].find(key);
                    if (it != m_map_images[events.jbutton.which].end())
                    {
                        map = m_map_images[events.jbutton.which][key];
                        m_pan_tabs[events.jbutton.which]->ShowImg(map);
                    }
                }
                break;
            case SDL_JOYBUTTONUP:
                if (events.jbutton.which < GAMEPAD_NUMBER)
                {
                    key = button_to_key(events.jbutton.button);
                    it = m_map_images[events.jbutton.which].find(key);
                    if (it != m_map_images[events.jbutton.which].end())
                    {
                        map = m_map_images[events.jbutton.which][key];
                        m_pan_tabs[events.jbutton.which]->HideImg(map);
                    }
                }
                break;
            case SDL_JOYHATMOTION:
                if (events.jhat.which < GAMEPAD_NUMBER)
                {
                    switch (events.jhat.value)
                    {
                        case SDL_HAT_UP:
                            key = hat_to_key(events.jhat.value, events.jhat.hat);
                            it = m_map_images[events.jhat.which].find(key);
                            if (it != m_map_images[events.jhat.which].end())
                            {
                                m_pan_tabs[events.jhat.which]->ShowImg(img_dp_up);
                            }
                            break;
                        case SDL_HAT_DOWN:
                            key = hat_to_key(events.jhat.value, events.jhat.hat);
                            it = m_map_images[events.jhat.which].find(key);
                            if (it != m_map_images[events.jhat.which].end())
                            {
                                m_pan_tabs[events.jhat.which]->ShowImg(img_dp_bottom);
                            }
                            break;
                        case SDL_HAT_RIGHT:
                            key = hat_to_key(events.jhat.value, events.jhat.hat);
                            it = m_map_images[events.jhat.which].find(key);
                            if (it != m_map_images[events.jhat.which].end())
                            {
                                m_pan_tabs[events.jhat.which]->ShowImg(img_dp_right);
                            }
                            break;
                        case SDL_HAT_LEFT:
                            key = hat_to_key(events.jhat.value, events.jhat.hat);
                            it = m_map_images[events.jhat.which].find(key);
                            if (it != m_map_images[events.jhat.which].end())
                            {
                                m_pan_tabs[events.jhat.which]->ShowImg(img_dp_left);
                            }
                            break;
                        case SDL_HAT_CENTERED:
                            m_pan_tabs[events.jhat.which]->HideImg(img_dp_up);
                            m_pan_tabs[events.jhat.which]->HideImg(img_dp_bottom);
                            m_pan_tabs[events.jhat.which]->HideImg(img_dp_right);
                            m_pan_tabs[events.jhat.which]->HideImg(img_dp_left);
                    }
                }
                break;
            default:
                break;
        }
    }
#endif // SDL_BUILD
}

/****************************************/
/*********** Methods functions **********/
/****************************************/

void Dialog::config_key(int pad, int key)
{
    bool captured = false;
    u32 key_pressed = 0;

    // I don't have any guarantee that not-yet-pressed state is egual to released state
    GamePad::UpdateReleaseState();
    while (!captured)
    {
        std::vector<GamePad *>::iterator itjoy;
        if (PollX11KeyboardMouseEvent(key_pressed))
        {
            // special case for keyboard/mouse to handle multiple keys
            // Note: key_pressed == 0 when ESC is hit to abort the capture
            if (key_pressed > 0)
            {
                clear_key(pad, key);
                set_keyboard_key(pad, key_pressed, key);
                m_simulatedKeys[pad][key] = key_pressed;
                m_map_images[pad][key_pressed] = key;
            }
            captured = true;
        }
        else
        {
            GamePad::UpdateGamePadState();

            itjoy = s_vgamePad.begin();
            while ((itjoy != s_vgamePad.end()) && (!captured))
            {
                if ((*itjoy)->PollButtons(key_pressed))
                {
                    clear_key(pad, key);
                    set_key(pad, key, key_pressed);
                    m_map_images[pad][key_pressed] = key;
                    captured = true;
                }
                else if ((*itjoy)->PollAxes(key_pressed))
                {
                    clear_key(pad, key);
                    set_key(pad, key, key_pressed);
                    m_map_images[pad][key_pressed] = key;
                    captured = true;
                }
                else if ((*itjoy)->PollHats(key_pressed))
                {
                    clear_key(pad, key);
                    set_key(pad, key, key_pressed);
                    m_map_images[pad][key_pressed] = key;
                    captured = true;
                }
                ++itjoy;
            }
        }
    }
    m_bt_gamepad[pad][key]->SetLabel(
        KeyName(pad, key, m_simulatedKeys[pad][key]).c_str());
}

void Dialog::clear_key(int pad, int key)
{
    // Erase the keyboard binded key
    u32 keysim = m_simulatedKeys[pad][key];
    m_simulatedKeys[pad][key] = 0;

    // erase gamepad entry (keysim map)
    std::map<u32, u32>::iterator it1;
    it1 = conf->keysym_map[pad].find(keysim);
    if (it1 != conf->keysym_map[pad].end())
        conf->keysym_map[pad].erase(it1);

    // erase gamepad entry (image map)
    int val = get_key(pad, key);
    std::map<u32, int>::iterator it2;
    it2 = m_map_images[pad].find(val);
    if (it2 != m_map_images[pad].end())
    {
        m_map_images[pad].erase(it2);
    }

    // Erase the keyboard image map
    //m_map_images[pad].erase(keysim);
    // Erase the Gamepad binded key
    set_key(pad, key, 0);
}


// Set button values
void Dialog::repopulate()
{
    for (int gamepad_id = 0; gamepad_id < GAMEPAD_NUMBER; ++gamepad_id)
    {
        for (int key = 0; key < MAX_KEYS; key++)
        {
            if (get_key(gamepad_id, key) != 0)
            {
                m_bt_gamepad[gamepad_id][key]->SetLabel(
                    KeyName(gamepad_id, key).c_str());

                m_map_images[gamepad_id][get_key(gamepad_id, key)] = key;
            }
        }

        // keyboard/mouse key
        std::map<u32, u32>::iterator it;
        for (it = conf->keysym_map[gamepad_id].begin();
             it != conf->keysym_map[gamepad_id].end(); ++it)
        {
            int keysym = it->first;
            int key = it->second;

            m_bt_gamepad[gamepad_id][key]->SetLabel(
                KeyName(gamepad_id, key, keysym).c_str());

            m_simulatedKeys[gamepad_id][key] = keysym;
            m_map_images[gamepad_id][keysym] = key;
        }
    }
}

// Main
void DisplayDialog()
{
    Dialog dialog;

    dialog.InitDialog();
    dialog.ShowModal();
}
