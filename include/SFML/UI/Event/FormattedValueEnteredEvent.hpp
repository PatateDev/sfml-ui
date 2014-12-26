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

#ifndef FORMATTED_VALUE_EVENT_H
#define FORMATTED_VALUE_EVENT_H

#include <SFML/UI/Event/ComponentEvent.hpp>
#include <SFML/UI/Format/Format.hpp>

namespace sf
{
namespace ui
{

class FormattedValueEnteredEvent : public ComponentEvent
{
    //CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief An event related to a formatted value entered (e.g on sf::ui::FormattedTextField)
    ///
    /// \param source the component that triggers this event
    /// \param format the format of the value
    ///
    ////////////////////////////////////////////////////////////
    FormattedValueEnteredEvent(Component *source, const Format& format);

    virtual ~FormattedValueEnteredEvent();
    //--------------------------------------------------------------------
    
    //GETTERS/SETTERS ----------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format of the value
    ///
    ////////////////////////////////////////////////////////////
    const Format& getFormat() const;
    //--------------------------------------------------------------------
    
    //FIELDS -------------------------------------------------------------
protected:
    const Format &m_format;
    //--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */

#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::FormattedValueEnteredEvent
/// \brief An event triggered when the value of a formatted component
/// is entered (e.g on a sf::ui::FormattedTextField)
/// \ingroup ui
///
////////////////////////////////////////////////////////////
