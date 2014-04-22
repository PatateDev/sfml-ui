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

#include <SFML/UI/Event/ButtonTouchedEvent.h>

using namespace sf::ui;

ButtonTouchedEvent::ButtonTouchedEvent(AbstractButton* source, unsigned int finger, int x, int y)
: ComponentEvent(source),
  m_finger(finger), m_x(x), m_y(y)
{

}

ButtonTouchedEvent::~ButtonTouchedEvent()
{

}

unsigned int ButtonTouchedEvent::getFinger() const
{
    return m_finger;
}

int ButtonTouchedEvent::getX() const
{
    return m_x;
}

int ButtonTouchedEvent::getY() const
{
    return m_y;
}


