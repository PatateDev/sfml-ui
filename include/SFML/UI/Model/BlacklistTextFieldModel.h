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

#ifndef BLACKLISTTEXTFIELDMODEL_H_
#define BLACKLISTTEXTFIELDMODEL_H_

#include <SFML/UI/Model/TextFieldModel.h>
#include <set>
#include <vector>

namespace sf
{
namespace ui
{

class BlacklistTextFieldModel : public TextFieldModel
{
public:
	//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
	/*
	 * Creates a text field model that denies character present in the blacklist
	 * Note that the blacklist is empty in this class
	 */
	BlacklistTextFieldModel();
	virtual ~BlacklistTextFieldModel();
	//--------------------------------------------------------------------

	//METHODS ------------------------------------------------------------
	/*
	 * Returns if the given character is denied for the text field
	 * Params:
	 * 	c - the character to check
	 */
	virtual bool isCharAllowed(sf::Uint32 c) const;

	/*
	 * Adds a character to the blacklist
	 * Params:
	 * 	c - the character to deny
	 */
	void addCharDenied(sf::Uint32 c);

	/*
	 * Removes a character to the blacklist
	 * Params:
	 * 	c - the character to allow
	 */
	void rmCharDenied(sf::Uint32 c);
	//--------------------------------------------------------------------

	//GETTERS/SETTERS ----------------------------------------------------
	/*
	 * Returns all of the chars blacklisted
	 */
	std::vector<sf::Uint32> getCharsDenied() const;
	//--------------------------------------------------------------------

	//FIELDS -------------------------------------------------------------
protected:
	std::set<sf::Uint32> m_blacklist;
	//--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* BLACKLISTTEXTFIELDMODEL_H_ */
