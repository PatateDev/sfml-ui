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

#include <SFML/UI/Format/UnsignedLongSequence.h>

using namespace sf::ui;

UnsignedLongSequence::UnsignedLongSequence(sf::Uint64 initialValue, sf::Uint64 min, sf::Uint64 max, sf::Uint64 step)
: Sequence(),
  m_format(), m_min(min), m_max(max), m_step(step)
{
    m_format.setValue(initialValue);
}

UnsignedLongSequence::~UnsignedLongSequence()
{

}

void UnsignedLongSequence::next()
{    
    sf::Uint64 value = m_format.getValue() + m_step;
    setValue(value > m_max ? m_max : value);
}

void UnsignedLongSequence::previous()
{
    if (m_format.getValue() < m_step)
    {
        setValue(0);
    }
    else
    {
        sf::Uint64 value = m_format.getValue() - m_step;
        setValue(value < m_min ? m_min : value);
    }
    
}
    
sf::Uint64 UnsignedLongSequence::getValue() const
{
    return m_format.getValue();
}
    
void UnsignedLongSequence::setValue(sf::Uint64 value)
{
    m_format.setValue(value);
}
    
const Format& UnsignedLongSequence::getFormat() const
{
    return m_format;
}
    
Format& UnsignedLongSequence::getFormat()
{
    return m_format;
}

sf::Uint64 UnsignedLongSequence::getMinimum() const
{
    return m_min;
}

void UnsignedLongSequence::setMinimum(sf::Uint64 min)
{
    m_min = min;
}

sf::Uint64 UnsignedLongSequence::getMaximum() const
{
    return m_max;
}

void UnsignedLongSequence::setMaximum(sf::Uint64 max)
{
    m_max = max;
}

sf::Uint64 UnsignedLongSequence::getStep() const
{
    return m_step;
}

void UnsignedLongSequence::setStep(sf::Uint64 step)
{
    m_step = step;
}
