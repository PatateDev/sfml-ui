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

#ifndef DEFAULTTEXTFIELDMODEL_H_
#define DEFAULTTEXTFIELDMODEL_H_

#include <SFML/UI/Model/BlacklistTextFieldModel.hpp>

namespace sf
{
namespace ui
{

class DefaultTextFieldModel : public BlacklistTextFieldModel
{
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
	/// \brief The default text field model used
	/// It allows all character excluding 0(NUL) - 31(US) and 127(DEL)
	///
	////////////////////////////////////////////////////////////
	DefaultTextFieldModel();

	virtual ~DefaultTextFieldModel();
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
#endif /* DEFAULTTEXTFIELDMODEL_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::DefaultTextFieldModel
/// \brief The default textfield model
/// \ingroup ui
///
////////////////////////////////////////////////////////////
