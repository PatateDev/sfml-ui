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

#include <SFML/UI/Event/TextDeletedEvent.hpp>

using namespace sf::ui;

TextDeletedEvent::TextDeletedEvent(TextField* source, sf::Uint32 text, unsigned int position)
: ComponentEvent(source),
  m_text(text), m_position(position)
{

}

TextDeletedEvent::~TextDeletedEvent()
{

}

sf::Uint32 TextDeletedEvent::getText() const
{
    return m_text;
}

unsigned int TextDeletedEvent::getPosition() const
{
    return m_position;
}

