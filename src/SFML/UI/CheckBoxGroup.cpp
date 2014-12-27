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

#include <SFML/UI/CheckBoxGroup.hpp>
#include <SFML/UI/Event/CheckBoxChangeEvent.hpp>
#include <iostream>

using namespace sf::ui;

CheckBoxGroup::CheckBoxGroup()
: ComponentObserver(),
  m_checkBox()
{

}

CheckBoxGroup::~CheckBoxGroup()
{

}

void CheckBoxGroup::addCheckBox(CheckBox& checkbox)
{
    m_checkBox.insert(&checkbox);
    checkbox.addObserver(this);
}

std::set<CheckBox*>::const_iterator CheckBoxGroup::getCheckboxBegin() const
{
    return m_checkBox.begin();
}

std::set<CheckBox*>::const_iterator CheckBoxGroup::getCheckboxEnd() const
{
    return m_checkBox.end();
}


void CheckBoxGroup::removeCheckbox(CheckBox& checkbox)
{
    m_checkBox.erase(&checkbox);
}

unsigned int CheckBoxGroup::countCheckbox() const
{
    return m_checkBox.size();
}

bool CheckBoxGroup::isCheckBoxInGroup(CheckBox* checkbox) const
{
    return m_checkBox.find(checkbox) != m_checkBox.end();
}

void CheckBoxGroup::onComponentEvent(const ComponentEvent& event)
{
    if (dynamic_cast<CheckBoxChangeEvent const*>(&event))
    {
        const CheckBoxChangeEvent &changeEvent = dynamic_cast<CheckBoxChangeEvent const&>(event);
        
        if (isCheckBoxInGroup(static_cast<CheckBox*>(changeEvent.getSource())))
        {
            if (changeEvent.isSelected())
            {
                CheckBox *newSelected = dynamic_cast<CheckBox*>(changeEvent.getSource());
                CheckBox *beforeSelected = firstSelected(newSelected);

                if (beforeSelected)
                    beforeSelected->setSelected(false);
            }
            else
            {
                CheckBox *unselected = dynamic_cast<CheckBox*>(changeEvent.getSource());

                if (!firstSelected(unselected))
                    unselected->setSelected(true);
            }
        }
    }
}

CheckBox* CheckBoxGroup::firstSelected(CheckBox* excluded) const
{
    for (std::set<CheckBox*>::iterator it = m_checkBox.begin(); it != m_checkBox.end(); it++)
    {
        CheckBox *c = *it;

        if (c->isSelected() && c != excluded)
            return c;
    }

    return 0;
}

