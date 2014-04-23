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

#ifndef CHECKBOXGROUP_H_
#define CHECKBOXGROUP_H_

#include <SFML/UI/ComponentObserver.h>
#include <SFML/UI/CheckBox.h>
#include <set>

namespace sf
{
namespace ui
{

class CheckBoxGroup : public sf::ui::ComponentObserver
{
//CONSTRUCTORS - DESTRUCTOR -----------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief A group of check box.
    /// Only one of this check boxes can be selected
    /// at time.
    ///
    ////////////////////////////////////////////////////////////
    CheckBoxGroup();

    virtual ~CheckBoxGroup();
//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Add a checkbox to this group
    ///
    /// \param checkbox the checkbox to add
    ///
    ////////////////////////////////////////////////////////////
    void addCheckBox(CheckBox &checkbox);

    ////////////////////////////////////////////////////////////
    ///
    /// \return the begin of checkbox's iterator
    ///
    ////////////////////////////////////////////////////////////
    std::set<CheckBox*>::const_iterator getCheckboxBegin() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the end of checkbox's iterator
    ///
    ////////////////////////////////////////////////////////////
    std::set<CheckBox*>::const_iterator getCheckboxEnd() const;

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Remove a checkbox to this group;
    /// This function does NOT delete the checkbox
    ///
    /// \param checkbox - the checkbox to remove
    ///
    ////////////////////////////////////////////////////////////
    void removeCheckbox(CheckBox& checkbox);

    ////////////////////////////////////////////////////////////
    ///
    /// \return the number of checkboxes in this group
    ///
    ////////////////////////////////////////////////////////////
    unsigned int countCheckbox() const;

    ////////////////////////////////////////////////////////////
    ///
    /// \return if the check box is in this group
    ///
    /// \param checkbox the checkbox to check
    ///
    ////////////////////////////////////////////////////////////
    bool isCheckBoxInGroup(CheckBox *checkbox) const;

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Called each time a component change
    ///
    ////////////////////////////////////////////////////////////
    virtual void onComponentEvent(const ComponentEvent &event);

private:
    ////////////////////////////////////////////////////////////
    ///
    /// \return the first checkbox selected excluded the given one,
    /// or 0 if none
    ///
    /// \param excluded an extra checkbox which will be ignored
    ///
    ////////////////////////////////////////////////////////////
    CheckBox* firstSelected(CheckBox* excluded = 0) const;
//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//FIELDS ------------------------------------------------------------------------------
private:
    std::set<CheckBox*> m_checkBox;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* CHECKBOXGROUP_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::CheckBoxGroup
/// \brief A group that allow only one check box selected in the same time
/// \ingroup ui
/// \see sf::ui::CheckBox
///
////////////////////////////////////////////////////////////
