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

#include <SFML/UI/Label.h>
#include <cmath>
#include <iostream>

using namespace sf::ui;

Label::Label()
: Component()
{
}

Label::Label(const sf::Texture& image)
: Component(image)
{
}

Label::Label(const sf::Font& font, const sf::String& text, int fontSize)
: Component()
{
	setFont(font);
	setText(text);
	setFontSize(fontSize);
}

Label::~Label()
{

}

void Label::updateEvent(const sf::Event& event)
{
}

void Label::updateFixed(sf::Time delta)
{
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_text.getString() == "")
		target.draw(m_sprite, states);
	else
		target.draw(m_text, states);
}

void Label::updateCoord()
{
	m_text.setPosition(m_sprite.getPosition());
}

const sf::String& Label::getText() const
{
	return m_text.getString();
}

void Label::setText(const sf::String& text)
{
	m_text.setString(text);
}

const sf::Font* Label::getFont() const
{
	return m_text.getFont();
}

void Label::setFont(const sf::Font& font)
{
	m_text.setFont(font);
}

const sf::Texture* Label::getImage() const
{
	return m_texture;
}

unsigned int Label::getFontSize() const
{
	return m_text.getCharacterSize();
}

void Label::setFontSize(unsigned int size)
{
	m_text.setCharacterSize(size);
}

sf::Color Label::getFontColor() const
{
	return m_text.getColor();
}

void Label::setFontColor(sf::Color color)
{
	m_text.setColor(color);
}

void Label::setImage(const sf::Texture& image)
{
	m_texture = &image;
	m_sprite.setTexture(image, true);
}

sf::Vector2f Label::getSize() const
{
    float x = fmaxf(m_text.getLocalBounds().width, m_sprite.getLocalBounds().width);
    float y = fmaxf(m_text.getLocalBounds().height, m_sprite.getLocalBounds().height);
    
    return sf::Vector2f(x, y);
}
