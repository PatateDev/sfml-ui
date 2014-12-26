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

#include <SFML/UI/Event/ButtonClickedEvent.hpp>

using namespace sf::ui;

ButtonClickedEvent::ButtonClickedEvent(AbstractButton* source, sf::Mouse::Button button, int x, int y)
: ComponentEvent(source),
  m_button(button), m_x(x), m_y(y)
{

}

ButtonClickedEvent::~ButtonClickedEvent()
{

}

sf::Mouse::Button ButtonClickedEvent::getButton() const
{
    return m_button;
}

int ButtonClickedEvent::getX() const
{
    return m_x;
}

int ButtonClickedEvent::getY() const
{
    return m_y;
}


