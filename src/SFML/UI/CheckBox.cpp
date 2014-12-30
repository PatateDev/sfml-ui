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

#include <SFML/UI/CheckBox.hpp>
#include <SFML/UI/SFMLUtils.hpp>
#include <SFML/UI/ComponentEvent.hpp>

using namespace sf::ui;

CheckBox::CheckBox(bool selected)
: AbstractButton()
{
	setSelected(selected);
}

CheckBox::CheckBox(const sf::Texture& texture, const sf::Texture& textureSelected, bool selected)
: AbstractButton(texture, textureSelected)
{
	setSelected(selected);
}

CheckBox::CheckBox(const sf::Texture& texture, const sf::Texture& textureSelected, const sf::Font& font, sf::String name, bool selected)
: AbstractButton(texture, textureSelected)
{
	setFont(font);
	setText(name);
	setSelected(selected);
}

CheckBox::~CheckBox()
{

}

void CheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	AbstractButton::draw(target, states);

	if (m_text.getFont())
		target.draw(m_text, states);
}

void CheckBox::onClick()
{
	setFocused(!m_focused);

	sf::ui::ComponentEvent cevent;
	cevent.source = this;
	cevent.type = sf::ui::ComponentEvent::CheckBoxChanged;
	cevent.checkBoxChange.source = this;
	cevent.checkBoxChange.selected = m_focused;

	m_sprite.setTexture(*(m_focused ? m_textureFocused : m_texture), false);
	triggerEvent(cevent);
}

bool CheckBox::isSelected() const
{
	return isFocused();
}

void CheckBox::updateCoord()
{
	sf::Vector2f pos(m_sprite.getPosition()), size(SFMLUtils::getLocalSize(m_text));

	m_text.setOrigin(0, size.y/2.f);
	m_text.setPosition(pos.x + m_sprite.getGlobalBounds().width, pos.y + m_sprite.getGlobalBounds().height/2.f);
}

void CheckBox::setSelected(bool selected)
{
	setFocused(selected);
}

sf::Vector2f CheckBox::getSize() const
{
	float x = m_text.getGlobalBounds().left + m_text.getGlobalBounds().width - m_sprite.getGlobalBounds().left;
	float y = 0;

	if (m_sprite.getGlobalBounds().height >= m_text.getGlobalBounds().height)
		y = m_sprite.getGlobalBounds().height;
	else
		y = m_text.getGlobalBounds().height;

	return sf::Vector2f(x, y);
}

const sf::String& CheckBox::getText() const
{
	return m_text.getString();
}

void CheckBox::setText(const sf::String& text)
{
	m_text.setString(text);
}

const sf::Font* CheckBox::getFont() const
{
	return m_text.getFont();
}

void CheckBox::setFont(const sf::Font& font)
{
	m_text.setFont(font);
}

unsigned int CheckBox::getFontSize() const
{
	return m_text.getCharacterSize();
}

void CheckBox::setFontSize(unsigned int size)
{
	m_text.setCharacterSize(size);

}

sf::Color CheckBox::getFontColor() const
{
	return m_text.getColor();
}

void CheckBox::updateFixed(sf::Time delta)
{

}

void CheckBox::setFontColor(sf::Color color)
{
	m_text.setColor(color);
}
