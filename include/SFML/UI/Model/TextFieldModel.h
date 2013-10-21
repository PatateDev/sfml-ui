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

#ifndef TEXTFIELDMODEL_H_
#define TEXTFIELDMODEL_H_

#include <SFML/System.hpp>

namespace sf
{
namespace ui
{

class TextFieldModel
{
public:
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	/*
	 * An abstract class that control if the text field should or not
	 * allow a given character
	 */
	TextFieldModel();
	virtual ~TextFieldModel();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
	/*
	 * Returns if the given character is allowed for the text field
	 * Params:
	 * 	c - the character to check
	 */
	virtual bool isCharAllowed(sf::Uint32 c) const = 0;
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------

	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------

	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* TEXTFIELDMODEL_H_ */
