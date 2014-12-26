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

#include <SFML/UI/Model/BlacklistTextFieldModel.hpp>

using namespace sf::ui;

BlacklistTextFieldModel::BlacklistTextFieldModel()
{

}

BlacklistTextFieldModel::~BlacklistTextFieldModel()
{

}

bool BlacklistTextFieldModel::isCharAllowed(sf::Uint32 c) const
{
	return m_blacklist.find(c) == m_blacklist.end();
}

void BlacklistTextFieldModel::addCharDenied(sf::Uint32 c)
{
	m_blacklist.insert(c);
}

void BlacklistTextFieldModel::rmCharDenied(sf::Uint32 c)
{
	m_blacklist.erase(c);
}

std::vector<sf::Uint32> sf::ui::BlacklistTextFieldModel::getCharsDenied() const
{
	std::vector<sf::Uint32> blacklist;

	for (std::set<sf::Uint32>::iterator it = m_blacklist.begin(); it != m_blacklist.end(); it++)
		blacklist.push_back(*it);

	return blacklist;
}
