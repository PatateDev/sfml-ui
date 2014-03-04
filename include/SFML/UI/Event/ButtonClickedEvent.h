/*
 *  Copyright © 2013 mathdu07
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BUTTONCLICKEDEVENT_H_
#define BUTTONCLICKEDEVENT_H_

#include <SFML/UI/Event/ComponentEvent.h>
#include <SFML/UI/AbstractButton.h>
#include <SFML/Window.hpp>

namespace sf
{
namespace ui
{

class ButtonClickedEvent : public ComponentEvent
{
//CONSTRUCTORS - DESTRUCTOR -----------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief An event that is triggered each time a button is fired
    ///
    /// \param source the abstract button fired
    /// \param button the mouse button clicked
    /// \param x
    /// \param y
    ///
    ////////////////////////////////////////////////////////////    
    ButtonClickedEvent(AbstractButton* source, sf::Mouse::Button button, int x, int y);
    
    virtual ~ButtonClickedEvent();
//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return the mouse button used
    ///
    ////////////////////////////////////////////////////////////
    sf::Mouse::Button getButton() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return x
    ///
    ////////////////////////////////////////////////////////////
    int getX() const;
    
    ////////////////////////////////////////////////////////////  
    ///
    /// \return y
    ///
    ////////////////////////////////////////////////////////////  
    int getY() const;
//-------------------------------------------------------------------------------------

//FIELDS ------------------------------------------------------------------------------
private:
    const sf::Mouse::Button m_button;
    const int m_x, m_y;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* BUTTONCLICKEDEVENT_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::ButtonClickedEvent
/// \brief An event triggered when an AbstractButton is fired
/// \ingroup ui
///
////////////////////////////////////////////////////////////
