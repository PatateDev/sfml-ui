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

#ifndef TEXTFIELD_H_
#define TEXTFIELD_H_

#include <SFML/UI/Focusable.h>
#include <SFML/UI/IText.h>
#include <SFML/UI/Model/TextFieldModel.h>

namespace sf
{
namespace ui
{

class TextField: public Focusable, public IText
{
public:
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	/*
	 * Creates an empty text field without texture, font ...
	 * Then do not forget to set its before displaying it
	 */
	TextField();

	/*
	 * Creates a text field without font
	 * Then do not forget to set the font before displaying it
	 * Params:
	 * 	texture - the texture of the text field
	 * 	textureFocused - the texture when the text field is focused
	 * 	text - the default text of the text field
	 */
	TextField(sf::Texture const &texture, sf::Texture const &textureFocused, sf::String const &text = "");

	/*
	 * Creates a text field
	 * Params:
	 * 	texture - the texture of the text field
	 * 	textureFocused - the texture when the text field is focused
	 * 	font - the text's font
	 * 	text - the default text of the text field
	 */
	TextField(sf::Texture const &texture, sf::Texture const &textureFocused, sf::Font const &font, sf::String text = "");

	virtual ~TextField();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
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
	 * Returns the object that defines what can be typed in the text field
	 */
	const TextFieldModel* getModel() const;

	/*
	 * Sets the model of the text field
	 * Params:
	 * 	model - the object that defines which characters can be typed
	 */
	void setModel(TextFieldModel* model);

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

	/*
	 * Return the position of the cursor
	 */
	unsigned int getCursor() const;

	/*
	 * Sets the cursor's position
	 * Params:
	 * 	cursor - the cursor's position
	 */
	void setCursor(unsigned int cursor);

	/*
	 * Returns the max length that the string can have
	 * Or -1 if the string has no length limit
	 */
	int getMaxLength() const;

	/*
	 * Sets the max length that the string can have
	 * -1 means the string has no length limit
	 */
	void setMaxLength(int maxLength);

	/*
	 * Returns if the string can be empty
	 */
	bool canBeEmpty() const;

	/*
	 * Sets if the string ca be empty
	 */
	void setCanBeEmpty(bool canBeEmpty);
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	sf::Text m_text;
	TextFieldModel *m_model;
	unsigned int m_cursor;
	sf::RectangleShape m_cursorShape;
	int m_maxLength;
	bool m_canBeEmpty;
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* TEXTFIELD_H_ */
