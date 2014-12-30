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

#include <SFML/UI/Button.hpp>
#include <SFML/UI/SFMLUtils.hpp>
#include <SFML/UI/ComponentEvent.hpp>

using namespace sf::ui;

Button::~Button()
{
	delete m_task;
}

void Button::updateEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseMoved || event.type == sf::Event::TouchMoved)
    {
        int x = (event.type == sf::Event::MouseMoved ? event.mouseMove.x : event.touch.x);
        int y = (event.type == sf::Event::MouseMoved ? event.mouseMove.y : event.touch.y);
        
		setFocused(isCoordOnComponent(x, y));

		if (m_focused && (event.type == sf::Event::MouseMoved ? sf::Mouse::isButtonPressed(sf::Mouse::Left) : true) && m_textureFired)
			m_sprite.setTexture(*m_textureFired, false);
		else if (m_focused && m_textureFocused)
			m_sprite.setTexture(*m_textureFocused, false);
		else
			m_sprite.setTexture(*m_texture, false);
	}
	else if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::TouchBegan)
	{
	    int x = (event.type == sf::Event::MouseButtonPressed ? event.mouseButton.x : event.touch.x);
        int y = (event.type == sf::Event::MouseButtonPressed ? event.mouseButton.y : event.touch.y);
	    
	    
		if (event.type != sf::Event::MouseButtonPressed || event.mouseButton.button == sf::Mouse::Left)
		{
		    m_clicked = checkClickOn(x, y);

		    if (m_clicked && m_textureFired)
			    m_sprite.setTexture(*m_textureFired, false);
		    else if (m_clicked)
			    m_sprite.setTexture(*m_textureFocused, false);
		}

	}
	else if (event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::TouchEnded)
	{
		int x = (event.type == sf::Event::MouseButtonReleased ? event.mouseButton.x : event.touch.x);
        	int y = (event.type == sf::Event::MouseButtonReleased ? event.mouseButton.y : event.touch.y);
        
        	if (event.type != sf::Event::MouseButtonPressed || event.mouseButton.button == sf::Mouse::Left)
        	{
			if (isCoordOnComponent(x, y) && m_textureFocused)
			{
				onClick();
				if (event.type == sf::Event::MouseButtonReleased)
				{
					sf::ui::ComponentEvent cevent;
					cevent.source = this;
					cevent.type = sf::ui::ComponentEvent::ButtonClicked;
					cevent.buttonClick.source = this;
					cevent.buttonClick.button = event.mouseButton.button;
					cevent.buttonClick.x = event.mouseButton.x;
					cevent.buttonClick.y =  event.mouseButton.y;
			        	triggerEvent(cevent);
				}
				else if (event.type == sf::Event::TouchEnded)
				{
					sf::ui::ComponentEvent cevent;
					cevent.source = this;
					cevent.type = sf::ui::ComponentEvent::ButtonTouched;
					cevent.buttonTouch.source = this;
					cevent.buttonTouch.finger = event.touch.finger;
					cevent.buttonTouch.x = event.touch.x;
					cevent.buttonTouch.y = event.touch.y;
					triggerEvent(cevent);
				}
			    
				m_sprite.setTexture(*m_textureFocused, false);
			}
			else
				m_sprite.setTexture(*m_texture, false);
		}
	}

}

void Button::updateFixed(sf::Time delta)
{

}

void Button::doClick()
{
	m_clicked = true;
	onClick();
	m_clicked = false;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	AbstractButton::draw(target, states);
	target.draw(m_text, states);
}

void Button::updateCoord()
{
	sf::FloatRect spriteBounds(m_sprite.getGlobalBounds());
	sf::Vector2f pos(m_sprite.getPosition()), size(SFMLUtils::getLocalSize(m_text));

	m_text.setOrigin(size.x/2.f, size.y/2.f);
	m_text.setPosition(pos.x + spriteBounds.width/2.f, pos.y + spriteBounds.height/2.f);
}

void Button::onClick()
{
	if (m_task)
		m_task->run();
}

bool Button::isFired() const
{
	return m_clicked;
}

const sf::Texture* Button::getTextureFired() const
{
	return m_textureFired;
}

void Button::setTextureFired(const sf::Texture& textureFired)
{
	m_textureFired = &textureFired;
}

const sf::String& Button::getText() const
{
	return m_text.getString();
}

void Button::setText(const sf::String& text)
{
	m_text.setString(text);
	updateCoord();
}

const sf::Font* Button::getFont() const
{
	return m_text.getFont();
}

void Button::setFont(const sf::Font& font)
{
	m_text.setFont(font);
	updateCoord();
}

unsigned int Button::getFontSize() const
{
	return m_text.getCharacterSize();
}

void Button::setFontSize(unsigned int size)
{
	m_text.setCharacterSize(size);
	updateCoord();
}

sf::Color Button::getFontColor() const
{
	return m_text.getColor();
}

void Button::setFontColor(sf::Color color)
{
	m_text.setColor(color);
}
