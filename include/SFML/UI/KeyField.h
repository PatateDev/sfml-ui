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
	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a key field without textures, which store a (keyboard's) key
	/// Do not forget to set the textures and fonts later
	///
	/// \param key the default key
	///
	////////////////////////////////////////////////////////////
	KeyField(sf::Keyboard::Key key);

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a key field, which store a (keyboard's) key
	///
	/// \param texture the texture when the keyfield is not focused
	/// \param textureFocused the texture when the keyfield is focused
	/// \param font the font of the keyfield
	/// \param key the default key
	///
	////////////////////////////////////////////////////////////
	KeyField(sf::Texture const &texture, sf::Texture const &textureFocused, sf::Font const &font, sf::Keyboard::Key key);


	virtual ~KeyField();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
private:
	////////////////////////////////////////////////////////////
	///
	/// \brief Initialize the set of keys allowed
	///
	////////////////////////////////////////////////////////////
	void setKeys();

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
	/// \brief Update the component with the main loop's frequency.
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
	/// \return the set of the allowed keys
	///
	////////////////////////////////////////////////////////////
	const std::set<sf::Keyboard::Key>& getAllowedKeys() const;
	
	////////////////////////////////////////////////////////////
	///
	/// \brief Add a key to the allowed keys set
	///
	/// \param key key to allow
	///
	////////////////////////////////////////////////////////////
	void addKey(sf::Keyboard::Key key);
	
	////////////////////////////////////////////////////////////
	///
	/// \return if the key is in the allowed keys
	///
	/// \param key key to check
	///
	////////////////////////////////////////////////////////////
	bool isKeyAllowed(sf::Keyboard::Key key) const;
	
	////////////////////////////////////////////////////////////
	///
	/// \brief Remove the key from the allowed keys set
	///
	////////////////////////////////////////////////////////////
	void removeKey(sf::Keyboard::Key key);

	////////////////////////////////////////////////////////////
	///
	/// \return the text's string
	///
	////////////////////////////////////////////////////////////
	virtual const sf::String& getText() const;

private:
	////////////////////////////////////////////////////////////
	///
	/// \brief Sets the text's string of the component
	/// Don't forget to set the font
	///
	/// \param text the new string of the component
	///
	////////////////////////////////////////////////////////////
	virtual void setText(sf::String const &text);

public:
	////////////////////////////////////////////////////////////
	///
	/// \return the font of the component, or null if any
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
	/// \return Returns the font's size of the component
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
	/// \param color the text's color
	///
	////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////
///
/// \class sf::ui::KeyField
/// \brief A field that stores a keyboard's key
/// Not supported on mobile platforms
/// \ingroup ui
///
////////////////////////////////////////////////////////////
