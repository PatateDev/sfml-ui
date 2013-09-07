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

#include <SFML/UI/Component.h>

using namespace sf::ui;

Component::Component()
: m_sprite(), m_texture(0)
{

}

Component::Component(sf::Texture const &texture)
: m_sprite(), m_texture(0)
{
	setTexture(texture);
}

Component::~Component()
{

}

void Component::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}

void Component::updateCoord()
{

}

const sf::Texture* Component::getTexture() const
{
	return m_texture;
}

void Component::setTexture(const sf::Texture& texture)
{
	m_texture = &texture;
	m_sprite.setTexture(texture, true);
}

void Component::move(const sf::Vector2f& vector)
{
	setPosition(getPosition() + vector);
}

void Component::move(float x, float y)
{
	move(sf::Vector2f(x, y));
}

const sf::Vector2f& Component::getPosition() const
{
	return m_sprite.getPosition();
}

void Component::setPosition(sf::Vector2f const &position)
{
	setPosition(position.x, position.y);
}

void Component::setPosition(float x, float y)
{
	m_sprite.setPosition(x, y);
	updateCoord();
}

sf::Vector2f Component::getSize() const
{
	sf::FloatRect bounds = m_sprite.getGlobalBounds();

	return sf::Vector2f(bounds.width, bounds.top);
}
