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
#include <SFML/UI/Format/IntFormat.h>

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
	//--------------------------------------------------------------------
	
	//GETTERS/SETTERS ----------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief The value returned should be copy into a full object,
    /// or a primitive type, as the pointer is deleted when the
    /// value is changed    /// \brief The value returned should be copy into a full object,
    /// or a primitive type, as the pointer is deleted when the
    /// value is changed (with the function parse for example)
    ///
    /// \return a pointer to the value got with the format
    ///
    ////////////////////////////////////////////////////////////
    const void* getValue() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Set the value for this formatted text field
    /// The given value is automatically deleted when changed
    ///
    /// \param value the new value
    ///
    ////////////////////////////////////////////////////////////
    void setValue(void* value);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format
    ///
    ////////////////////////////////////////////////////////////
    const Format* getFormat() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Sets the new format of this field, and delete the old one
    ///
    /// \param format the new format, automatically deleted by the field
    ///
    ////////////////////////////////////////////////////////////
    void setFormat(Format *format);
    
    ////////////////////////////////////////////////////////////
	///
	/// \brief Sets the text's string of the component
	/// Don't forget to set the font
	///
	/// \param text - the new string of the component
	///
	////////////////////////////////////////////////////////////
	virtual void setText(sf::String const &text);
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
