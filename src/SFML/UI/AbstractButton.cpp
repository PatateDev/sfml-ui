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

#include <SFML/UI/AbstractButton.hpp>
#include <SFML/UI/ComponentEvent.hpp>

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

		if (checkClickOn(event.mouseButton.x, event.mouseButton.y))
		{
			sf::ui::ComponentEvent cevent;
			cevent.source = this;
			cevent.type = sf::ui::ComponentEvent::ButtonClicked;
			cevent.buttonClick.source = this;
			cevent.buttonClick.button = event.mouseButton.button;
			cevent.buttonClick.x = event.mouseButton.x;
			cevent.buttonClick.y = event.mouseButton.y;
			onClick();
			triggerEvent(cevent);
		}

		break;
	case sf::Event::TouchEnded:
	    
	    if (checkClickOn(event.touch.x, event.touch.y))
	    {
		sf::ui::ComponentEvent cevent;
		cevent.source = this;
		cevent.type = sf::ui::ComponentEvent::ButtonTouched;
		cevent.buttonTouch.source = this;
		cevent.buttonTouch.finger = event.touch.finger;
		cevent.buttonTouch.x = event.touch.x;
		cevent.buttonTouch.y = event.touch.y;
	        onClick();
	        triggerEvent(cevent);
	    }
	    
	    break;
	default:
		break;
	}
}
