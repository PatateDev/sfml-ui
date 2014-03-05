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

#include <SFML/UI/AbstractButton.h>
#include <SFML/UI/IText.h>

namespace sf
{
namespace ui
{

class Button : public AbstractButton, public IText
{
public:

	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	
	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a button without textures that does nothing
	///
	////////////////////////////////////////////////////////////
	Button()
	: AbstractButton(),
	  m_textureFired(0), m_text(), m_clicked(false),
	  m_task(0)
	{

	}

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a button with textures that does nothing
	/// Do not forget to set the font !
	///
	///	\param texture the texture of this button
	///	\param textureFocused the texture when the button is focused
	/// \param textureFired the texture when the button is fired
	///
	////////////////////////////////////////////////////////////
	Button(sf::Texture const &texture, sf::Texture const &textureFocused, sf::Texture const &textureFired)
	: AbstractButton(texture, textureFocused),
	  m_textureFired(&textureFired), m_text(), m_clicked(false),
	  m_task(0)
	{

	}

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a button without textures that call a function in a object
	/// Do not forget to set textures and font !
	///
	/// \param object the object that contains the function to execute
	///	\function the function to execute
	///
	////////////////////////////////////////////////////////////
	template<typename C>
	Button(C *object, void (C::*function)())
	: AbstractButton(),
	  m_textureFired(0), m_text(), m_clicked(false),
	  m_task(new sf::priv::ThreadMemberFunc<C>(function, object))
	{

	}

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a button with textures that call a function in a object
	/// Do not forget to set the font !
	///
	///	\param object the object that contains the function to execute
	/// \param function the function to execute
	/// \param texture the texture of this button
	/// \param textureFocused the texture when the button is focused
	/// \param textureFired the texture when the button is fired
	///
	////////////////////////////////////////////////////////////
	template<typename C>
	Button(C *object, void (C::*function)(), sf::Texture const &texture, sf::Texture const &textureFocused, sf::Texture const &textureFired)
	: AbstractButton(texture, textureFocused),
	  m_textureFired(&textureFired), m_text(), m_clicked(false),
	  m_task(new sf::priv::ThreadMemberFunc<C>(function, object))
	{

	}

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a button without textures that call a function or a functor (struct with operator() )
	/// Do not forget to set textures and font !
	///
	/// \param function the function/functor to execute
	///
	////////////////////////////////////////////////////////////
	template<typename F>
	Button(F function)
	: AbstractButton(),
	  m_textureFired(0), m_text(), m_clicked(false),
	  m_task(new sf::priv::ThreadFunctor<F>(function))
	{

	}

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a button with textures that call a function or a functor (struct with operator() )
	/// Do not forget to set the font !
	///
	/// \param function the function/functor to execute
	/// \param texture the texture of this button
	/// \param textureFocused the texture when the button is focused
	/// \param textureFired the texture when the button is fired
	///
	////////////////////////////////////////////////////////////
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
	////////////////////////////////////////////////////////////
	///
	/// \brief Called when the button is clicked
	/// Execute the task
	///
	////////////////////////////////////////////////////////////
	virtual void onClick();

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

public:
	////////////////////////////////////////////////////////////
	///
	/// \brief Perform a click on the button
	///
	////////////////////////////////////////////////////////////
	void doClick();

	////////////////////////////////////////////////////////////
	///
	/// \brief Update the component each time an event has been polled
	///
	/// \param event the window's event polled
	///
	////////////////////////////////////////////////////////////
	virtual void updateEvent(sf::Event const &event);

	////////////////////////////////////////////////////////////
	///
	/// \brief Update the component with the main loop's frequency
	/// Can be useful for animation, or time's needed stuff
	///
	/// \param delta the time between this update and the last
	///
	////////////////////////////////////////////////////////////
	virtual void updateFixed(sf::Time delta);
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
	////////////////////////////////////////////////////////////
	///
	/// \return if the button is fired (or clicked)
	///
	////////////////////////////////////////////////////////////
	bool isFired() const;

	////////////////////////////////////////////////////////////
	///
	/// \return the texture when the button is fired
	///
	////////////////////////////////////////////////////////////
	sf::Texture const *getTextureFired() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets the texture fired
	///
	/// \param textureFired the texture when the button is fired
	///
	////////////////////////////////////////////////////////////
	void setTextureFired(sf::Texture const &textureFired);

	////////////////////////////////////////////////////////////
	///
	/// \return the text's string
	///
	////////////////////////////////////////////////////////////
	virtual const sf::String& getText() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets the text's string of the component
	/// Don't forget to set the font
	///
	/// \param text the new string of the component
	///
	////////////////////////////////////////////////////////////
	virtual void setText(sf::String const &text);

	////////////////////////////////////////////////////////////
	///
	/// \return the font of the component, if any returns null
	///
	////////////////////////////////////////////////////////////
	virtual const sf::Font* getFont() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets the font of the component's text
	///
	////////////////////////////////////////////////////////////
	virtual void setFont(sf::Font const &font);

	////////////////////////////////////////////////////////////
	///
	/// \return the font's size of the component
	///
	////////////////////////////////////////////////////////////
	virtual unsigned int getFontSize() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Set the font's size of the component
    ///
	/// \param size the font's size
	///
	////////////////////////////////////////////////////////////
	virtual void setFontSize(unsigned int size);

	////////////////////////////////////////////////////////////
	///
	/// \return the font's color of the text
	///
	////////////////////////////////////////////////////////////
	virtual sf::Color getFontColor() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets the color's font of the text
	/// 
	/// \param the text's color
	///
	////////////////////////////////////////////////////////////
	virtual void setFontColor(sf::Color color);
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

////////////////////////////////////////////////////////////
///
/// \class sf::ui::Button
/// \brief A button which does a simply task when clicked
/// \ingroup ui
///
////////////////////////////////////////////////////////////
