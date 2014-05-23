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

#ifndef PASSWORD_FIELD_H
#define PASSWORD_FIELD_H

#include <SFML/UI/TextField.h>

namespace sf
{
namespace ui
{

class PasswordField : public TextField
{
public:
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	////////////////////////////////////////////////////////////
	///
	/// \brief Creates an empty password field without texture, font ...
	/// Then do not forget to set its before displaying it
	///
	////////////////////////////////////////////////////////////
	PasswordField();

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a password field without font
	/// Then do not forget to set the font before displaying it
	///
	/// \param texture the texture of the text field
	/// \param textureFocused the texture when the text field is focused
	///
	////////////////////////////////////////////////////////////
	PasswordField(sf::Texture const &texture, sf::Texture const &textureFocused);

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a password field
	///
	/// \param texture the texture of the text field
	/// \param textureFocused the texture when the text field is focused
	/// \param font the text's font
	///
	////////////////////////////////////////////////////////////
	PasswordField(sf::Texture const &texture, sf::Texture const &textureFocused, sf::Font const &font);

	virtual ~PasswordField();
	//--------------------------------------------------------------------
	
	//METHODS ------------------------------------------------------------
protected:
	////////////////////////////////////////////////////////////
	///
	/// \brief Insert a char at the given index
	/// Trigger a TextEnteredEvent
	///
	/// \param text the text to insert
	/// \param index the index of the insertion
	///
	/// \return if the text has been successfully inserted
	///
	////////////////////////////////////////////////////////////
	virtual bool insertText(sf::Uint32 text, unsigned int index);	

	////////////////////////////////////////////////////////////
	///
	/// \brief Delete the char at the given index
	/// Trigger a TextDeletedEvent
	///
	/// \param index the index of the char to delete
	///
	/// \return if the text has been successfully deleted
	///
	////////////////////////////////////////////////////////////
	virtual bool deleteText(unsigned int index);
	
	////////////////////////////////////////////////////////////
	///
	/// \brief Replace the TextField's chars by '•'
	///
	////////////////////////////////////////////////////////////
	void replaceTextDisplayed();
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
public:

	////////////////////////////////////////////////////////////
	///
	/// \return the password stored
	///
	////////////////////////////////////////////////////////////
	const sf::String& getPassword() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Sets the password of the component
	/// Don't forget to set the font
	///
	/// \param password the new password of the component
	///
	////////////////////////////////////////////////////////////
	void setPassword(sf::String const &password);

	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
    sf::String m_password;
	//--------------------------------------------------------------------
};

}
}

////////////////////////////////////////////////////////////
///
/// \class sf::ui::PasswordField
/// \brief A text field which stores a password
/// \ingroup ui
///
////////////////////////////////////////////////////////////

#endif
