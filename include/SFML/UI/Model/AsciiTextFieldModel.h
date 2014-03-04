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

#ifndef ASCIITEXTFIELDMODEL_H_
#define ASCIITEXTFIELDMODEL_H_

#include <SFML/UI/Model/TextFieldModel.h>

namespace sf
{
namespace ui
{

class AsciiTextFieldModel : public TextFieldModel
{
public:
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	////////////////////////////////////////////////////////////
	///
	/// \brief A textfield model which allow all ASCII characters
	/// i.e all characters between 32 (include) and 126 (include)
	/// as 127 is backspace
	///
	////////////////////////////////////////////////////////////
	AsciiTextFieldModel();
	virtual ~AsciiTextFieldModel();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
	////////////////////////////////////////////////////////////
	///
	/// \return if the given character is allowed for the text field
	///
	/// \param c the character to check
	///
	////////////////////////////////////////////////////////////
	virtual bool isCharAllowed(sf::Uint32 c) const;
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------

	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------

	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* ASCIITEXTFIELDMODEL_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::AsciiTextFieldModel
/// \brief A textfield model that allows only ASCII chars
/// \ingroup ui
///
////////////////////////////////////////////////////////////
