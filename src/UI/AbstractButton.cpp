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

#include <SFML/UI/AbstractButton.h>

using namespace sf::ui;

AbstractButton::AbstractButton()
: Focusable()
{

}

AbstractButton::AbstractButton(const sf::Texture& texture, const sf::Texture& textureFocused)
: Focusable(texture, textureFocused)
{

}

AbstractButton::~AbstractButton()
{

}

void AbstractButton::updateEvent(const sf::Event& event)
{
	switch(event.type)
	{
	case sf::Event::MouseButtonReleased:

		if (checkClickOn(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y))
		{
			onClick();
		}

		break;
	default:
		break;
	}
}
