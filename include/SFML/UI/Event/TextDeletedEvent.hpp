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

#ifndef EVENTTEXTDELETEDEVENT_H_
#define EVENTTEXTDELETEDEVENT_H_

#include <SFML/UI/Event/ComponentEvent.hpp>
#include <SFML/UI/TextField.hpp>
#include <SFML/System.hpp>

namespace sf
{
namespace ui
{

class TextDeletedEvent : public sf::ui::ComponentEvent
{
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief An event that is triggered each time a text is deleted
    /// Triggered only with TextField
    ///
    /// \param source source the TextField that has triggered this event
    /// \param text the text deleted
    /// \param position the index of the char deleted
    ///
    ///////////////////////////////////////////////////////////////
    TextDeletedEvent(TextField* source, sf::Uint32 text, unsigned int position);

    virtual ~TextDeletedEvent();

//CONSTRUCTORS - DESTRUCTOR -----------------------------------------------------------

//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------
public:
    ///////////////////////////////////////////////////////////////
    ///
    /// \return the text deleted
    ///
    ///////////////////////////////////////////////////////////////
    sf::Uint32 getText() const;

    ///////////////////////////////////////////////////////////////
    ///
    /// \return the position of the char deleted
    ///
    ///////////////////////////////////////////////////////////////
    unsigned int getPosition() const;
//-------------------------------------------------------------------------------------

//FIELDS ------------------------------------------------------------------------------
private:
    const sf::Uint32 m_text;
    const unsigned int m_position;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* EVENTTEXTDELETEDEVENT_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::TextDeletedEvent
/// \brief An event triggered when a text is deleted on a TextField
/// \ingroup ui
///
////////////////////////////////////////////////////////////
