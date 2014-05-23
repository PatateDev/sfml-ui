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

#ifndef FOCUSABLE_H_
#define FOCUSABLE_H_

#include <SFML/UI/Component.h>

namespace sf
{
namespace ui
{

class Focusable: public Component
{
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
	////////////////////////////////////////////////////////////
	///
	/// \brief Creates an empty Component Focusable, without textures.
	/// This class does NOT define when the component should be focused,
	/// You have to do that in the inherited class
	///
	////////////////////////////////////////////////////////////
	Focusable();

	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a Component Focusable with given textures.
	/// This class does NOT define when the component should be focused,
	/// You have to do that in the inherited class.
	///
	/// \param texture the default texture of the component
	/// \param textureFocused the texture when the component is focused
	///
	////////////////////////////////////////////////////////////
	Focusable(sf::Texture const &texture, sf::Texture const &textureFocused);

	virtual ~Focusable();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
protected:
	////////////////////////////////////////////////////////////
	///
	/// \return whether the click should focus the component or not
	///
	/// \param button - the mouse's button
	/// \param x - the x coord
	/// \param y - the y coord
	///
	////////////////////////////////////////////////////////////
	virtual bool checkClickOn(int x, int y) const;

    ////////////////////////////////////////////////////////////
    ///
    /// \return whether the given coordinate is on the component or out
    ///
    /// \param x - the x coord
    /// \param y - the y coord
    ///
    ////////////////////////////////////////////////////////////
	virtual bool isCoordOnComponent(int x, int y) const;
	
	////////////////////////////////////////////////////////////
	///
	/// \brief Called when the component gain focus
	///
	////////////////////////////////////////////////////////////
	virtual void gainFocus();
	
	////////////////////////////////////////////////////////////
	///
	/// \brief Called when the component lost focus
	///
	////////////////////////////////////////////////////////////
	virtual void lostFocus();
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
public:
	////////////////////////////////////////////////////////////
	///
	/// \return whether the component is focused or not
	///
	////////////////////////////////////////////////////////////
	bool isFocused() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Set if the component is focused
	///
	/// \param focused - is focused
	///
	////////////////////////////////////////////////////////////
	void setFocused(bool focused);

	////////////////////////////////////////////////////////////
	///
	/// \return the texture when the component is focused
	///
	////////////////////////////////////////////////////////////
	const sf::Texture* getTextureFocused() const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Set the texture that is displayed when the component is displayed
	///
	/// \param textureFocused - the texture when the component is focused
	///
	////////////////////////////////////////////////////////////
	void setTextureFocused(const sf::Texture& textureFocused);
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	sf::Texture const *m_textureFocused;
	bool m_focused;
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* FOCUSABLE_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::Focusable
/// \brief The base class for all UI components that can be focused
/// \ingroup ui
///
////////////////////////////////////////////////////////////
