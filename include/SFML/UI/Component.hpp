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
#include <SFML/UI/ComponentObservable.hpp>

namespace sf
{
namespace ui
{

class Component : public Drawable, public ComponentObservable
{

	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
	////////////////////////////////////////////////////////////
	///
	/// \brief Creates an empty component, without texture
	///
	////////////////////////////////////////////////////////////
	Component();

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a component with the give texture
	///
	/// \param texture - the texture displayed by the component
	///
	////////////////////////////////////////////////////////////
	Component(sf::Texture const &texture);

	virtual ~Component();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
public:
	////////////////////////////////////////////////////////////
	///
	/// \brief Update the component each time an event has been polled
	///
	/// \param event the window's event polled
	///
	////////////////////////////////////////////////////////////
	virtual void updateEvent(sf::Event const &event) = 0;

	////////////////////////////////////////////////////////////
	///
	/// \brief Update the component with the main loop's frequency
	/// Can be useful for animation, or time's needed stuff
	///
	/// \param delta the time between this update and the last one
	///
	////////////////////////////////////////////////////////////
	virtual void updateFixed(sf::Time delta) = 0;

	////////////////////////////////////////////////////////////
	///
	/// \brief Update the size of the component
	/// Call it when you update your texture
	/// after it was set, to recalculate the component's size
	/// with new texture loaded.
	///
	/// Example:
	/// \code
	/// sf::Texture texture;
	/// sf::Label label(texture); // Now label has a pointer to texture, moreover its size is (0;0)
	/// texture.loadFromFile("texture.png"); // New texture loaded, and so its size has changed
	/// label.updateSize(); // Tell label that it have to change its size, and calculate it with the updated texture's size
	/// \endcode
	///
	////////////////////////////////////////////////////////////
	void updateSize();

	////////////////////////////////////////////////////////////
	///
	/// \brief Move the component
	///
	/// \param vector the move's vector
	///
	////////////////////////////////////////////////////////////
	void move(sf::Vector2f const &vector);

	////////////////////////////////////////////////////////////
	///
	/// \brief Move the component
	///
	/// \param x the x movement
	/// \param y the y movement
	////////////////////////////////////////////////////////////
	void move(float x, float y);

protected:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Draw the component to the render target
    ///
    ////////////////////////////////////////////////////////////
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Called when the component need update its geometry
	/// Inherit when you need to update some sprite
	///
	////////////////////////////////////////////////////////////
	virtual void updateCoord();
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
public:
	////////////////////////////////////////////////////////////
	///
	/// \return the texture of the component
	///
	////////////////////////////////////////////////////////////
	const sf::Texture* getTexture() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Set the texture of the component
	///
	////////////////////////////////////////////////////////////
	void setTexture(const sf::Texture& texture);

	////////////////////////////////////////////////////////////
	///
	/// \return the position of the component
	///
	////////////////////////////////////////////////////////////
	const sf::Vector2f& getPosition() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Set the component's position
	///
	/// \param position - the position vector
	///
	////////////////////////////////////////////////////////////
	void setPosition(sf::Vector2f const &position);

	////////////////////////////////////////////////////////////
	///
	/// \brief Set the component's position
	///
	///
	/// \param x - the x coordinate
	/// \param y - the y coordinate
	///
	////////////////////////////////////////////////////////////
	void setPosition(float x, float y);

	////////////////////////////////////////////////////////////
	///
	/// \return the size of the component
	///
	////////////////////////////////////////////////////////////
	virtual sf::Vector2f getSize() const;
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

////////////////////////////////////////////////////////////
///
/// \class sf::ui::Component
/// \brief The base class for all UI components
/// \ingroup ui
///
////////////////////////////////////////////////////////////
