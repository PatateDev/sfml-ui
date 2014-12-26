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

#include <SFML/UI/Focusable.hpp>
#include <SFML/UI/Event/FocusedEvent.hpp>

using namespace sf::ui;

Focusable::Focusable()
: Component(),
  m_textureFocused(0), m_focused(false)
{

}

Focusable::Focusable(const sf::Texture& texture, const sf::Texture& textureFocused)
: Component(texture),
  m_textureFocused(0), m_focused(false)
{
	setTextureFocused(textureFocused);
}

Focusable::~Focusable()
{

}

void Focusable::gainFocus()
{
    m_focused = true;
    FocusedEvent event(this, m_focused);
    triggerEvent(event);
}

void Focusable::lostFocus()
{
    m_focused = false;
    FocusedEvent event(this, m_focused);
    triggerEvent(event);
}

bool Focusable::isFocused() const
{
	return m_focused;
}

void Focusable::setFocused(bool focused)
{
    if (focused && !m_focused)
    {
        gainFocus();
    }
    else if (!focused && m_focused)
    {
        lostFocus();
    }

	m_focused = focused;
	m_sprite.setTexture(*(m_focused ? m_textureFocused : m_texture), false);
}

const sf::Texture* Focusable::getTextureFocused() const
{
	return m_textureFocused;
}

void Focusable::setTextureFocused(const sf::Texture& textureFocused)
{
	m_textureFocused = &textureFocused;
}

bool Focusable::checkClickOn(int x, int y) const
{
	return isCoordOnComponent(x, y);
}

bool Focusable::isCoordOnComponent(int x, int y) const
{
	sf::Vector2f pos(x, y);

	return m_sprite.getGlobalBounds().contains(pos);
}
