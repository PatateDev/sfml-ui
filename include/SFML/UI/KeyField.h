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

#ifndef KEYFIELD_H_
#define KEYFIELD_H_

#include <SFML/UI/Focusable.h>
#include <SFML/UI/IText.h>
#include <set>

namespace sf
{
namespace ui
{

class KeyField : public Focusable, public IText
{
public:
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	/*
	 * Creates a key field without textures, which store a (keyboard's) key
	 * Do not forget to set the textures and fonts later
	 */
	KeyField(sf::Keyboard::Key key);

	/*
	 * Creates a key field, which store a (keyboard's) key
	 */
	KeyField(sf::Texture const &texture, sf::Texture const &textureFocused, sf::Font const &font, sf::Keyboard::Key key);


	virtual ~KeyField();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
private:
	/*
	 * Initialize the set of keys allowed
	 */
	void setKeys();

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

public:
	/*
	 * Update the component each time an event has been polled
	 * Params:
	 * 	event - the window's event polled
	 */
	virtual void updateEvent(sf::Event const &event);

	/*
	 * Update the component with the main loop's frequency.
	 * Can be useful for animation, or time's needed stuff
	 * Params:
	 * 	delta - the time between this update and the last
	 */
	virtual void updateFixed(sf::Time delta);
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
	/*
	 * Returns the set of the allowed keys
	 */
	const std::set<sf::Keyboard::Key>& getAllowedKeys() const;
	/*
	 * Add a key to the allowed keys set
	 */
	void addKey(sf::Keyboard::Key key);
	/*
	 * Check if the key is in the allowed keys
	 */
	bool isKeyAllowed(sf::Keyboard::Key key) const;
	/*
	 * Remove the key from the allowed keys set
	 */
	void removeKey(sf::Keyboard::Key key);

	/*
	 * Returns the text's string
	 */
	virtual const sf::String& getText() const;

private:
	/*
	 * Sets the text's string of the component
	 * Don't forget to set the font
	 * Params:
	 * 	text - the new string of the component
	 */
	virtual void setText(sf::String const &text);

public:
	/*
	 * Returns the font of the component, if any returns null
	 */
	virtual const sf::Font* getFont() const;

	/*
	 * Sets the font of the component's text
	 */
	virtual void setFont(sf::Font const &font);

	/*
	 * Returns the font's size of the component
	 */
	virtual unsigned int getFontSize() const;

	/*
	 * Set the font's size of the component
	 * Params:
	 * 	size - the font's size
	 */
	virtual void setFontSize(unsigned int size);

	/*
	 * Returns the font's color of the text
	 */
	virtual sf::Color getFontColor() const;

	/*
	 * Sets the color's font of the text
	 * Params: the text's color
	 */
	virtual void setFontColor(sf::Color color);
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	sf::Text m_text;
	sf::Keyboard::Key m_key;
	std::set<sf::Keyboard::Key> m_keysAllowed;
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* KEYFIELD_H_ */
