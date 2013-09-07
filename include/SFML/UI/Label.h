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

#ifndef LABEL_H_
#define LABEL_H_

#include <SFML/UI/Component.h>

namespace sf
{
namespace ui
{

class Label: public Component
{
public:

	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	/*
	 * Creates an empty label
	 */
	Label();

	/*
	 * Creates a label-image
	 * Params:
	 * 	image - the label's image
	 */
	Label(sf::Texture const &image);

	/*
	 * Creates a text label
	 * Params:
	 * 	font - the text's font
	 * 	text - the string
	 * 	fontSize - the fint's size
	 */
	Label(sf::Font const &font, sf::String const &text, int fontSize = 35);

	virtual ~Label();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
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
	 * Returns the text's string
	 */
	const sf::String& getText() const;

	/*
	 * Sets the text's string of the label
	 * Don't forget to set the font ;)
	 * Params:
	 * 	text - the new string of the label
	 */
	void setText(sf::String const &text);

	/*
	 * Returns the font of the label, if any returns null
	 */
	const sf::Font* getFont() const;

	/*
	 * Sets the font of the label's text
	 */
	void setFont(sf::Font const &font);

	/*
	 * Returns the font's size of the label
	 */
	unsigned int getFontSize() const;

	/*
	 * Set the font's size of the label
	 * Params:
	 * 	size - the font's size
	 */
	void setFontSize(unsigned int size);

	/*
	 * Returns the font's color of the text
	 */
	sf::Color getFontColor() const;

	/*
	 * Sets the color's font of the text
	 * Params: the text's color
	 */
	void setFontColor(sf::Color color);

	/*
	 * Returns the label's image or null
	 * Similar to getTexture()
	 */
	const sf::Texture* getImage() const;

	/*
	 * Sets the label's image
	 * Similar to setTexture(sf::Texture const&)
	 */
	void setImage(sf::Texture const &image);
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	sf::Text m_text;
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* LABEL_H_ */
