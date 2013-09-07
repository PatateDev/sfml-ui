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

#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <SFML/Graphics.hpp>

namespace sf
{
namespace ui
{

class Component : public Drawable
{

	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
	/*
	 * Creates an empty component, without texture
	 */
	Component();

	/*
	 * Creates a component with the give texture
	 * Params:
	 * 	texture - the texture displayed by the component
	 */
	Component(sf::Texture const &texture);

	virtual ~Component();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
public:
	/*
	 * Update the component each time an event has been polled
	 * Params:
	 * 	event - the window's event polled
	 */
	virtual void updateEvent(sf::Event const &event) = 0;

	/*
	 * Update the component with the main loop's frequency.
	 * Can be useful for animation, or time's needed stuff
	 * Params:
	 * 	delta - the time between this update and the last
	 */
	virtual void updateFixed(sf::Time delta) = 0;

	/*
	 * Move the component
	 * Params:
	 *  vector - the move's vector
	 */
	void move(sf::Vector2f const &vector);

	/*
	 * Move the component
	 * Params:
	 *  x - the x move
	 *  y - the y move
	 */
	void move(float x, float y);

protected:
	/*
	 * Draw the component to the render target
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	/*
	 * Called when the component need update its geometry
	 * Inherit when you need to update some sprite
	 */
	virtual void updateCoord();
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
public:
	/*
	 * Returns the texture of the component
	 */
	const sf::Texture* getTexture() const;

	/*
	 * Set the texture of the component
	 */
	void setTexture(const sf::Texture& texture);

	/*
	 * Returns the position of the component
	 */
	const sf::Vector2f& getPosition() const;

	/*
	 * Set the component's position
	 * Params:
	 * 	position - the position vector
	 */
	void setPosition(sf::Vector2f const &position);

	/*
	 * Set the component's position
	 * Params:
	 * 	x - the x coordinate
	 * 	y - the y coordinate
	 */
	void setPosition(float x, float y);

	/*
	 * Returns the size of the component
	 */
	sf::Vector2f getSize() const;
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	sf::Sprite m_sprite; // The component's sprite displayed
	sf::Texture const *m_texture; //The component's texture
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */

#endif /* COMPONENT_H_ */
