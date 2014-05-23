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

#include <SFML/UI/Format/UnsignedLongFormat.h>
#include <cstdlib>
#include <sstream>

using namespace sf::ui;

UnsignedLongFormat::UnsignedLongFormat()
: m_value(new sf::Uint64(0))
{

}
    
UnsignedLongFormat::~UnsignedLongFormat()
{
    if (m_value)
    {
        delete m_value;
        m_value = 0;
    }
}

sf::String UnsignedLongFormat::toString() const
{
    std::ostringstream stream;
    stream << *m_value;
    return stream.str();
}

bool UnsignedLongFormat::isAllowed(sf::String str) const
{
    return strtoul(str.toAnsiString().c_str(), NULL, 10) != 0 || str == "0" || str == "";
}

void UnsignedLongFormat::parse(sf::String str) 
{
    setValue(new sf::Uint64(strtoul(str.toAnsiString().c_str(), NULL, 10)));
}

void UnsignedLongFormat::setValue(void* value)
{
    if (m_value != value)
    {
        if (m_value)
        {
            delete m_value;
            m_value = 0;
        }
        
        m_value = static_cast<sf::Uint64*>(value);
    }
}

const void* UnsignedLongFormat::getValue() const
{
    return m_value;
}
