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

#ifndef CHECKBOX_H_
#define CHECKBOX_H_

#include <SFML/UI/AbstractButton.h>
#include <SFML/UI/IText.h>

namespace sf
{
namespace ui
{

class CheckBox : public AbstractButton, public IText
{
public:
	/*
	 * Creates a Check Box without texture
	 * Params:
	 * 	selected - if the check box is selected
	 */
	CheckBox(bool selected = false);

	/*
	 * Creates a Check Box with texture
	 * If you add a name, do not forget to set the font
	 * Params:
	 * 	texture - the texture of the check box
	 * 	textureSelected - the texture when the button is selected (same as focused)
	 * 	selected - if the check box is selected
	 */
	CheckBox(sf::Texture const &texture, sf::Texture const &textureSelected, bool selected = false);

	/*
	 * Creates a Check Box with texture and font
	 * Params:
	 * 	texture - the texture of the check box
	 * 	textureSelected - the texture when the button is selected (same as focused)
	 * 	font - the font of the text
	 * 	name - the text displayed behind the check box
	 * 	selected - if the check box is selected
	 */
	CheckBox(sf::Texture const &texture, sf::Texture const &textureSelected, sf::Font const& font, sf::String name = "", bool selected = false);

	virtual ~CheckBox();
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------

	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
protected:
	/*
	 * Called when the button is clicked
	 * That defines whether the check box is selected or not
	 */
	virtual void onClick();

	/*
	 * Called when the component need update its geometry
	 * Inherit when you need to update some sprite
	 */
	virtual void updateCoord();

	/*
	 * Draw the component to the render target
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
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
	 * Returns if the check box is selected or not
	 * Similar to isFocused
	 */
	bool isSelected() const;

	/*
	 * Sets if the check box is selected or not
	 * Params:
	 * 	selected - if the check box is selected
	 */
	void setSelected(bool selected);

	/*
	 * Returns the size of the component
	 */
	virtual sf::Vector2f getSize() const;

	/*
	 * Returns the text's string
	 */
	virtual const sf::String& getText() const;

	/*
	 * Sets the text's string of the component
	 * Don't forget to set the font
	 * Params:
	 * 	text - the new string of the component
	 */
	virtual void setText(sf::String const &text);

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
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* CHECKBOX_H_ */
