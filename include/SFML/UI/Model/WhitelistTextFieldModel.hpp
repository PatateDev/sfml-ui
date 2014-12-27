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

#ifndef WITHELISTTEXTFIELDMODEL_H_
#define WITHELISTTEXTFIELDMODEL_H_

#include <SFML/UI/Model/TextFieldModel.hpp>
#include <set>
#include <vector>

namespace sf
{
namespace ui
{

class WhitelistTextFieldModel : public TextFieldModel
{
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
	////////////////////////////////////////////////////////////
	///
	/// \brief Creates a text field model that allows only character present in the whitelist
	/// Notice that the whitelist is empty in this class
	///
	////////////////////////////////////////////////////////////
	WhitelistTextFieldModel();
	
	virtual ~WhitelistTextFieldModel();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
public:
	////////////////////////////////////////////////////////////
	///
	/// \return if the given character is allowed for the text field
	///
	/// \param c the character to check
	///
	////////////////////////////////////////////////////////////
	virtual bool isCharAllowed(sf::Uint32 c) const;

	////////////////////////////////////////////////////////////
	///
	/// \brief Add a character to the whitelist
	///
	/// \param c the character to allow
	///
	////////////////////////////////////////////////////////////
	void addCharAllowed(sf::Uint32 c);

	////////////////////////////////////////////////////////////
	///
	/// \brief Remove a character to the whitelist
	///
    /// \param c the character to disallow
	///
	////////////////////////////////////////////////////////////
	void rmCharAllowed(sf::Uint32 c);
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return all of the chars whitelisted
    ///
    ////////////////////////////////////////////////////////////
	std::vector<sf::Uint32> getCharsAllowed() const;
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	std::set<sf::Uint32> m_whitelist;
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* WHITELISTTEXTFIELDMODEL_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::WhitelistTextFieldModel
/// \brief A textfield model that allows some chars
/// \ingroup ui
///
////////////////////////////////////////////////////////////
