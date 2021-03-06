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

#ifndef ALPHATEXTFIELDMODEL_H_
#define ALPHATEXTFIELDMODEL_H_

#include <SFML/UI/Model/WhitelistTextFieldModel.hpp>

namespace sf
{
namespace ui
{

class AlphaTextFieldModel : public WhitelistTextFieldModel
{
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
	////////////////////////////////////////////////////////////
	///
	/// \brief An alphabetic text field model that allows
	/// only character in range 'A' - 'Z' and 'a' - 'z'
	///
	////////////////////////////////////////////////////////////
	AlphaTextFieldModel();
	
	virtual ~AlphaTextFieldModel();
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
#endif /* ALPHATEXTFIELDMODEL_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::AlphaTextFieldModel
/// \brief A textfield model that allows only letters
/// \ingroup ui
///
////////////////////////////////////////////////////////////
