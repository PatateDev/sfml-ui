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

#ifndef FOCUSABLE_H_
#define FOCUSABLE_H_

#include <SFML/UI/Component.h>

namespace sf
{
namespace ui
{

class Focusable: public Component
{
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
	/*
	 * Creates an empty Component Focusable, without textures.
	 * This class does NOT define when the component should be focused,
	 * You have to do that in the inherited class
	 */
	Focusable();

	/*
	 * Creates a Component Focusable with given textures.
	 * This class does NOT define when the component should be focused,
	 * You have to do that in the inherited class.
	 *
	 * Params:
	 * 	texture - the default texture of the component
	 * 	textureFocused - the texture when the component is focused
	 */
	Focusable(sf::Texture const &texture, sf::Texture const &textureFocused);

	virtual ~Focusable();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
protected:
	/*
	 * Returns whether the click should focus the component or not
	 */
	virtual bool checkClickOn(sf::Mouse::Button button, int x, int y) const;

	/*
	 * Returns whether the given coordinate is on the component or out
	 */
	virtual bool isCoordOnComponent(int x, int y) const;
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
public:
	/*
	 * Returns whether the component is focused or not
	 */
	bool isFocused() const;

	/*
	 * Set if the component is focused
	 * Params:
	 * 	focused - is focused
	 */
	void setFocused(bool focused);

	/*
	 * Returns the texture when the component is focused
	 */
	const sf::Texture* getTextureFocused() const;

	/*
	 * Set the texture that is displayed when the component is displayed
	 * Params:
	 * 	textureFocused - the texture when the component is focused
	 */
	void setTextureFocused(const sf::Texture& textureFocused);
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	sf::Texture const *m_textureFocused;
	bool m_focused;
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* FOCUSABLE_H_ */
