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
#include <vector>

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
    /// \return the index of the checkbox in this group
    ///
    ////////////////////////////////////////////////////////////
    unsigned int addCheckBox(CheckBox &checkbox);

    ////////////////////////////////////////////////////////////
    ///
    /// \return the checkbox at the given index
    ///
    /// \param index the checkbox's index in this group
    ///
    ////////////////////////////////////////////////////////////
    CheckBox* getCheckbox(unsigned int index);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Remove a checkbox to this group;
    /// This function does NOT delete the checkbox
    ///
    /// \param index - the checkbox's index in this group
    ///
    ////////////////////////////////////////////////////////////
    void removeCheckbox(unsigned int index);

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
    std::vector<CheckBox*> m_checkBoxVector;
    std::vector<int> m_checkBoxIndexVector;
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
