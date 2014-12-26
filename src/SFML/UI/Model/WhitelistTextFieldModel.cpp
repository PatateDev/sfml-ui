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

#include <SFML/UI/Model/WhitelistTextFieldModel.hpp>

using namespace sf::ui;

WhitelistTextFieldModel::WhitelistTextFieldModel()
{

}

WhitelistTextFieldModel::~WhitelistTextFieldModel()
{

}

bool WhitelistTextFieldModel::isCharAllowed(sf::Uint32 c) const
{
	return m_whitelist.find(c) != m_whitelist.end();
}

void WhitelistTextFieldModel::addCharAllowed(sf::Uint32 c)
{
	m_whitelist.insert(c);
}

void WhitelistTextFieldModel::rmCharAllowed(sf::Uint32 c)
{
	m_whitelist.erase(c);
}

std::vector<sf::Uint32> WhitelistTextFieldModel::getCharsAllowed() const
{
	std::vector<sf::Uint32> allowed;

	for (std::set<sf::Uint32>::iterator it = m_whitelist.begin(); it != m_whitelist.end(); it++)
		allowed.push_back(*it);

	return allowed;
}
