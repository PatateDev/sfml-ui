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

#ifndef ABSTRACTBUTTON_H_
#define ABSTRACTBUTTON_H_

#include <SFML/UI/Focusable.hpp>

namespace sf
{
namespace ui
{

class AbstractButton : public Focusable
{
public:
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	
    ////////////////////////////////////////////////////////////
	///
	/// \brief Creates an empty abstract button that is implemented by buttons, check box ...
	///
    ////////////////////////////////////////////////////////////
	AbstractButton();

    ////////////////////////////////////////////////////////////
    ///
	/// \brief Creates an abstract button that is implemented by buttons, check box ...
	/// 
	///	\param texture the basic texture of this abstract button
	/// \param textureFocused the texture when the abstract button is focused
    ///	
    ////////////////////////////////////////////////////////////
	AbstractButton(sf::Texture const &texture, sf::Texture const &textureFocused);

	virtual ~AbstractButton();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
protected:
    ////////////////////////////////////////////////////////////
	///
	/// \brief Called when the button is clicked
	/// 
	/// This function defines what the button does
	///
    ////////////////////////////////////////////////////////////
	virtual void onClick() = 0;

public:
    ////////////////////////////////////////////////////////////
	///
	/// \brief Update the component each time an event has been polled
	/// \param event the window's event polled
	///
	////////////////////////////////////////////////////////////
	virtual void updateEvent(sf::Event const &event);
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------

	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------

	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* ABSTRACTBUTTON_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::AbstractButton
/// \brief Abstract class for all component that are button-like
/// \ingroup ui
///
////////////////////////////////////////////////////////////
