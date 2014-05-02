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

#include <SFML/UI/Format/LongSequence.h>

using namespace sf::ui;

LongSequence::LongSequence(sf::Int64 initialValue, sf::Int64 min, sf::Int64 max, sf::Int64 step)
: Sequence(),
  m_format(), m_min(min), m_max(max), m_step(step)
{
    m_format.setValue(new sf::Int64(initialValue));
}

LongSequence::~LongSequence()
{

}

void* LongSequence::getNext() const
{
    sf::Int64 value = *((sf::Int64*)m_format.getValue()) + m_step;
    return new sf::Int64(value > m_max ? m_max : value);
}

void* LongSequence::getPrevious() const
{
    sf::Int64 value = *((sf::Int64*)m_format.getValue()) - m_step;
    return new sf::Int64(value < m_min ? m_min : value);
}
    
const void* LongSequence::getValue() const
{
    return m_format.getValue();
}
    
void LongSequence::setValue(void* value)
{
    m_format.setValue(value);
}
    
const Format& LongSequence::getFormat() const
{
    return m_format;
}
    
Format& LongSequence::getFormat()
{
    return m_format;
}

sf::Int64 LongSequence::getMinimum() const
{
    return m_min;
}

void LongSequence::setMinimum(sf::Int64 min)
{
    m_min = min;
}

sf::Int64 LongSequence::getMaximum() const
{
    return m_max;
}

void LongSequence::setMaximum(sf::Int64 max)
{
    m_max = max;
}

sf::Int64 LongSequence::getStep() const
{
    return m_step;
}

void LongSequence::setStep(sf::Int64 step)
{
    m_step = step;
}
