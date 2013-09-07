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

#ifndef BUTTON_H_
#define BUTTON_H_

#include "AbstractButton.h"

namespace sf
{
namespace ui
{

class Button : public AbstractButton
{
public:

	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	/*
	 * Creates a button without textures that does nothing
	 */
	Button()
	: AbstractButton(),
	  m_textureFired(0), m_text(), m_clicked(false),
	  m_task(0)
	{

	}

	/*
	 * Creates a button with textures that does nothing
	 * Do not forget to set the font !
	 * Params:
	 * 	texture - the texture of this button
	 * 	textureFocused - the texture when the button is focused
	 * 	textureFired - the texture when the button is fired
	 */
	Button(sf::Texture const &texture, sf::Texture const &textureFocused, sf::Texture const &textureFired)
	: AbstractButton(texture, textureFocused),
	  m_textureFired(&textureFired), m_text(), m_clicked(false),
	  m_task(0)
	{

	}

	/*
	 * Creates a button without textures that call a function in a object
	 * Do not forget to set textures and font !
	 * Params:
	 * 	object - the object that contains the function to execute
	 * 	function - the function to execute
	 */
	template<typename C>
	Button(C *object, void (C::*function)())
	: AbstractButton(),
	  m_textureFired(0), m_text(), m_clicked(false),
	  m_task(new sf::priv::ThreadMemberFunc<C>(function, object))
	{

	}

	/*
	 * Creates a button with textures that call a function in a object
	 * Do not forget to set the font !
	 * Params:
	 * 	object - the object that contains the function to execute
	 * 	function - the function to execute
	 * 	texture - the texture of this button
	 * 	textureFocused - the texture when the button is focused
	 * 	textureFired - the texture when the button is fired
	 */
	template<typename C>
	Button(C *object, void (C::*function)(), sf::Texture const &texture, sf::Texture const &textureFocused, sf::Texture const &textureFired)
	: AbstractButton(texture, textureFocused),
	  m_textureFired(&textureFired), m_text(), m_clicked(false),
	  m_task(new sf::priv::ThreadMemberFunc<C>(function, object))
	{

	}

	/*
	 * Creates a button without textures that call a function or a functor (struct with operator() )
	 * Do not forget to set textures and font !
	 * Params:
	 * 	function - the function/functor to execute
	 */
	template<typename F>
	Button(F function)
	: AbstractButton(),
	  m_textureFired(0), m_text(), m_clicked(false),
	  m_task(new sf::priv::ThreadFunctor<F>(function))
	{

	}

	/*
	 * Creates a button with textures that call a function or a functor (struct with operator() )
	 * Do not forget to set the font !
	 * Params:
	 * 	function - the function/functor to execute
	 * 	texture - the texture of this button
	 * 	textureFocused - the texture when the button is focused
	 * 	textureFired - the texture when the button is fired
	 */
	template<typename F>
	Button(F function, sf::Texture const &texture, sf::Texture const &textureFocused, sf::Texture const &textureFired)
	: AbstractButton(texture, textureFocused),
	  m_textureFired(&textureFired), m_text(), m_clicked(false),
	  m_task(new sf::priv::ThreadFunctor<F>(function))
	{

	}


	virtual ~Button();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
protected:
	/*
	 * Called when the button is clicked
	 * Execute the task
	 */
	virtual void onClick();

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
	 * Returns if the button is fired (or clicked)
	 */
	bool isFired() const;

	/*
	 * Returns the texture when the button is fired
	 */
	sf::Texture const *getTextureFired() const;

	/*
	 * Sets the texture fired
	 * Params:
	 * 	textureFired - the texture when the button is fired
	 */
	void setTextureFired(sf::Texture const *textureFired);

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
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	sf::Texture const *m_textureFired;
	sf::Text m_text;
	bool m_clicked;
	sf::priv::ThreadFunc *m_task; //The task executed each times the button is fired
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* BUTTON_H_ */
