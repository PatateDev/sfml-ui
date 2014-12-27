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

#include <SFML/UI/Event/FocusedEvent.hpp>

using namespace sf::ui;

FocusedEvent::FocusedEvent(Component* source, bool nowFocused)
: ComponentEvent(source),
  m_isFocused(nowFocused)
{
}

FocusedEvent::~FocusedEvent()
{
}

bool FocusedEvent::isFocused() const
{
    return m_isFocused;
}

bool FocusedEvent::wasFocused() const
{
    return !m_isFocused;
}
