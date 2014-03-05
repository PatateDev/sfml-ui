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
//TODO Replace int index of ComponentObservable by a better system (directly with the ComponentObserver pointer)

#include <SFML/UI/CheckBoxGroup.h>
#include <SFML/UI/Event/CheckBoxChangeEvent.h>

using namespace sf::ui;

CheckBoxGroup::CheckBoxGroup()
: ComponentObserver(),
  m_checkBoxVector(), m_checkBoxIndexVector()
{

}

CheckBoxGroup::~CheckBoxGroup()
{

}

unsigned int CheckBoxGroup::addCheckBox(CheckBox& checkbox)
{
    int index = countCheckbox();
    m_checkBoxVector.push_back(&checkbox);
    m_checkBoxIndexVector.push_back(checkbox.addObserver(this));
    return index;
}

CheckBox* CheckBoxGroup::getCheckbox(unsigned int index)
{
    return m_checkBoxVector[index];
}

void CheckBoxGroup::removeCheckbox(unsigned int index)
{
    if (index < countCheckbox())
    {
        CheckBox* checkbox = getCheckbox(index);
        checkbox->removeObserver(m_checkBoxIndexVector[index]);
        m_checkBoxVector.erase(m_checkBoxVector.begin() + index);
        m_checkBoxIndexVector.erase(m_checkBoxIndexVector.begin() + index);
    }
    else
        throw "index out of bounds";
}

unsigned int CheckBoxGroup::countCheckbox() const
{
    return m_checkBoxVector.size();
}

bool CheckBoxGroup::isCheckBoxInGroup(CheckBox* checkbox) const
{
    for (unsigned int i = 0; i < countCheckbox(); i++)
    {
        if (checkbox == m_checkBoxVector[i])
            return true;
    }

    return false;
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
    for (unsigned int i = 0; i < countCheckbox(); i++)
    {
        CheckBox *c = m_checkBoxVector[i];

        if (c->isSelected() && c != excluded)
            return c;
    }

    return 0;
}

