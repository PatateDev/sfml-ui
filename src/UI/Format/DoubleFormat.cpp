/*
* Copyright © 2013 mathdu07
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <SFML/UI/Format/DoubleFormat.h>
#include <cstdlib>
#include <sstream>

using namespace sf::ui;

DoubleFormat::DoubleFormat()
: m_value(0)
{

}
    
DoubleFormat::~DoubleFormat()
{
    
}

sf::String DoubleFormat::toString() const
{
    std::ostringstream stream;
    stream << m_value;
    return stream.str();
}

bool DoubleFormat::isAllowed(sf::String str) const
{
    return strtod(str.toAnsiString().c_str(), NULL) != 0 || str == "0" || str == "" || str == "-";
}

void DoubleFormat::parse(sf::String str) 
{
    setValue(strtod(str.toAnsiString().c_str(), NULL));
}

void DoubleFormat::setValue(double value)
{
    m_value = value;
}

double DoubleFormat::getValue() const
{
    return m_value;
}
