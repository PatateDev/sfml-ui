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

#ifndef ALPHANUMERICTEXTFIELDMODEL_H_
#define ALPHANUMERICTEXTFIELDMODEL_H_

#include <SFML/UI/Model/WhitelistTextFieldModel.h>

namespace sf
{
namespace ui
{

class AlphaNumericTextFieldModel : public WhitelistTextFieldModel
{
public:
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	/*
	 * A text field model that allows letters and numbers,
	 * only character between 'A' - 'Z', 'a' - 'z', '0' - '9' and '-'.
	 */
	AlphaNumericTextFieldModel();
	virtual ~AlphaNumericTextFieldModel();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------

	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------

	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------

	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* ALPHANUMERICTEXTFIELDMODEL_H_ */
