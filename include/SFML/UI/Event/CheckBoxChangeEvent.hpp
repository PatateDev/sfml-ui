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

#ifndef CHECKBOXCHANGEEVENT_H_
#define CHECKBOXCHANGEEVENT_H_

#include <SFML/UI/Event/ComponentEvent.hpp>
#include <SFML/UI/CheckBox.hpp>

namespace sf
{
namespace ui
{

class CheckBoxChangeEvent : public ComponentEvent
{
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief An event that is triggered each time a check box switch from unselected to selected, and vice-versa
    ///
    /// \param source the check box that triggers this event
    /// \param isSelected whether the check box is selected currently
    ///
    ////////////////////////////////////////////////////////////
    CheckBoxChangeEvent(CheckBox* source, bool isSelected);

    virtual ~CheckBoxChangeEvent();

//CONSTRUCTORS - DESTRUCTOR -----------------------------------------------------------

//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return if the check box is selected now
    ///
    ////////////////////////////////////////////////////////////
    bool isSelected() const;

    ////////////////////////////////////////////////////////////
    ///
    /// \return if the check box was selected before this event
    ///
    ////////////////////////////////////////////////////////////
    bool wasSelected() const;
//-------------------------------------------------------------------------------------

//FIELDS ------------------------------------------------------------------------------
private:
    bool m_selected;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* CHECKBOXCHANGEEVENT_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::CheckBoxChangeEvent
/// \brief A checkbox's change event
/// \ingroup ui
///
////////////////////////////////////////////////////////////
