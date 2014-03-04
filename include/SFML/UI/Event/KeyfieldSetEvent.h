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

#ifndef KEYFIELDSETEVENT_H_
#define KEYFIELDSETEVENT_H_

#include <SFML/UI/Event/ComponentEvent.h>
#include <SFML/UI/KeyField.h>

namespace sf
{
namespace ui
{

class KeyfieldSetEvent : public sf::ui::ComponentEvent
{
//CONSTRUCTORS - DESTRUCTOR -----------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief An event that is triggered each time a key is set
    /// Triggered only with KeyField
    ///
    /// \param source the KeyField that has triggered
    /// \param key the key that has been set
    ///
    ////////////////////////////////////////////////////////////
    KeyfieldSetEvent(KeyField* source, sf::Keyboard::Key key);

    virtual ~KeyfieldSetEvent();
//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return the key set
    ///
    ////////////////////////////////////////////////////////////
    sf::Keyboard::Key getKey() const;
//-------------------------------------------------------------------------------------

//FIELDS ------------------------------------------------------------------------------
private:
    const sf::Keyboard::Key m_key;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* KEYFIELDSETEVENT_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::KeyfieldSetEvent
/// \brief An event triggered when a keyfield is set
/// \ingroup ui
///
////////////////////////////////////////////////////////////
