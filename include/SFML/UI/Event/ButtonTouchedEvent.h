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

#ifndef BUTTON_TOUCHED_EVENT_H_
#define BUTTON_TOUCHED_EVENT_H_

#include <SFML/UI/Event/ComponentEvent.h>
#include <SFML/UI/AbstractButton.h>
#include <SFML/Window.hpp>

namespace sf
{
namespace ui
{

class ButtonTouchedEvent : public ComponentEvent
{
//CONSTRUCTORS - DESTRUCTOR -----------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief An event that is triggered each time a button is fired, touched (on mobile OSs)
    ///
    /// \param source the abstract button fired
    /// \param finger index of the finger which touched the button
    /// \param x
    /// \param y
    ///
    ////////////////////////////////////////////////////////////    
    ButtonTouchedEvent(AbstractButton* source, unsigned int finger, int x, int y);
    
    virtual ~ButtonTouchedEvent();
//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return index of the finger used
    ///
    ////////////////////////////////////////////////////////////
    unsigned int getFinger() const;
    
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
    const unsigned int m_finger;
    const int m_x, m_y;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* BUTTON_TOUCHED_EVENT_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::ButtonTouchedEvent
/// \brief An event triggered when an AbstractButton is fired
///    by a finger (on mobile OSs such as Android)
/// \ingroup ui
///
////////////////////////////////////////////////////////////
