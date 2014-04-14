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
#include <SFML/UI/IText.h>

namespace sf
{
namespace ui
{

class Label : public Component, public IText
{
public:

	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	
	////////////////////////////////////////////////////////////
	///
	/// \brief Creates an empty label
	///
	////////////////////////////////////////////////////////////
	Label();

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a label-image
	///
	/// \param image the label's image
	///
	////////////////////////////////////////////////////////////
	Label(sf::Texture const &image);

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a text label
	///
	/// \param font the text's font
	/// \param text the text's string
	/// \param fontSize the fint's size
	///
	////////////////////////////////////////////////////////////
	Label(sf::Font const &font, sf::String const &text, int fontSize = 35);

	virtual ~Label();
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
	virtual void updateEvent(sf::Event const &event);

	////////////////////////////////////////////////////////////
	///
	/// \brief Update the component with the main loop's frequency
	/// Can be useful for animation, or time's needed stuff
	///
	/// \param delta - the time between this update and the last
	///
	////////////////////////////////////////////////////////////
	virtual void updateFixed(sf::Time delta);

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
	///Inherit when you need to update some sprite
	///
	////////////////////////////////////////////////////////////
	virtual void updateCoord();
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
public:
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

	////////////////////////////////////////////////////////////
	///
	/// \return the label's image or null
	/// Similar to getTexture()
	///
	////////////////////////////////////////////////////////////
	const sf::Texture* getImage() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets the label's image
	/// Similar to setTexture(sf::Texture const&)
	///
	////////////////////////////////////////////////////////////
	void setImage(sf::Texture const &image);
	
    ///////////////////////////////////////////////////////////
	///
	/// \return the size of the label
	///
	////////////////////////////////////////////////////////////
	virtual sf::Vector2f getSize() const;
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	sf::Text m_text;
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* LABEL_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::Label
/// \brief A label which show text or image 
/// \ingroup ui
///
////////////////////////////////////////////////////////////
