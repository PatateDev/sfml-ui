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

#ifndef TEXTENTEREDEVENT_H_
#define TEXTENTEREDEVENT_H_

#include <SFML/UI/Event/ComponentEvent.h>
#include <SFML/UI/TextField.h>
#include <SFML/System.hpp>

namespace sf
{
namespace ui
{

class TextEnteredEvent : public ComponentEvent
{
//CONSTRUCTORS - DESTRUCTOR -----------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief An event that is triggered each time a text is typed
    /// Triggered only with TextField
    ///
    /// \param source source the TextField that has triggered this event
    /// \param text the text entered
    /// \param position the position where the text is entered
    ///
    ///////////////////////////////////////////////////////////////
    TextEnteredEvent(TextField* source, sf::Uint32 text, unsigned int position);

    virtual ~TextEnteredEvent();
//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return the text entered
    ///
    ////////////////////////////////////////////////////////////
    sf::Uint32 getText() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the position where the text's been entered
    ///
    ////////////////////////////////////////////////////////////
    unsigned int getPosition() const;
//-------------------------------------------------------------------------------------

//FIELDS ------------------------------------------------------------------------------
private:
    const sf::Uint32 m_text;
    unsigned int m_position;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* TEXTENTEREDEVENT_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::TextEnteredEvent
/// \brief An event triggered when a text is typed on a TextField
/// \ingroup ui
///
////////////////////////////////////////////////////////////
