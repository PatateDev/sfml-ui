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

#ifndef FORMATTED_TEXT_FIELD_H
#define FORMATTED_TEXT_FIELD_H

#include <SFML/UI/TextField.h>
#include <SFML/UI/Format/Format.h>

namespace sf
{
namespace ui
{

class FormattedTextField : public TextField
{
public:
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	////////////////////////////////////////////////////////////
	///
	/// \brief Creates an empty text field without texture, font ...
	/// Then do not forget to set its before displaying it
	///
	/// \param format the format of this formatted text field
	///
	////////////////////////////////////////////////////////////
	FormattedTextField(Format* format = 0);

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a text field without font
	/// Then do not forget to set the font before displaying it
	///
	/// \param texture the texture of the text field
	/// \param textureFocused the texture when the text field is focused
	/// \param format the format of this formatted text field
	/// \param text the default text of the text field
	///
	////////////////////////////////////////////////////////////
	FormattedTextField(sf::Texture const &texture, sf::Texture const &textureFocused, Format* format = 0, sf::String const &text = "");

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a text field
	///
	/// \param texture the texture of the text field
	/// \param textureFocused the texture when the text field is focused
	/// \param font the text's font
	/// \param format the format of this formatted text field
	/// \param text the default text of the text field
	///
	////////////////////////////////////////////////////////////
	FormattedTextField(sf::Texture const &texture, sf::Texture const &textureFocused, sf::Font const &font, Format* format = 0, sf::String text = "");

	virtual ~FormattedTextField();
	//--------------------------------------------------------------------
	
	//METHODS ------------------------------------------------------------
protected:
	////////////////////////////////////////////////////////////
	///
	/// \brief Called when the component lost focus
	///
	////////////////////////////////////////////////////////////
	virtual void lostFocus();
	
	////////////////////////////////////////////////////////////
	///
	/// \brief Update the value with the field's text
	///
	////////////////////////////////////////////////////////////
	virtual void updateValue();
	//--------------------------------------------------------------------
	
	//GETTERS/SETTERS ----------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format
    ///
    ////////////////////////////////////////////////////////////
    const Format* getFormat() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format
    ///
    ////////////////////////////////////////////////////////////
    Format* getFormat();
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Sets the new format of this field, and delete the old one
    ///
    /// \param format the new format, automatically deleted by the field
    ///
    ////////////////////////////////////////////////////////////
    void setFormat(Format *format);
    //--------------------------------------------------------------------
    
    //FIELDS -------------------------------------------------------------
protected:
    Format *m_format;
	//--------------------------------------------------------------------
};

}
}
#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::FormattedTextField
/// \brief A formatted text field which stores a value defined by a sf::ui::Format
/// It can be a sf::Int64, a double, or even a class ... 
/// \ingroup ui
///
////////////////////////////////////////////////////////////
