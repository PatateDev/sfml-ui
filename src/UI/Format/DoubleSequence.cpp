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

#include <SFML/UI/Format/DoubleSequence.h>

using namespace sf::ui;

DoubleSequence::DoubleSequence(double initialValue, double min, double max, double step)
: Sequence(),
  m_format(), m_min(min), m_max(max), m_step(step)
{
    m_format.setValue(initialValue);
}

DoubleSequence::~DoubleSequence()
{

}

void DoubleSequence::next()
{
    double value = m_format.getValue() + m_step;
    setValue(value > m_max ? m_max : value);
}

void DoubleSequence::previous()
{
    double value = m_format.getValue() - m_step;
    setValue(value < m_min ? m_min : value);
}

double DoubleSequence::getValue() const
{
    return m_format.getValue();
}
    
void DoubleSequence::setValue(double value)
{
    m_format.setValue(value);
}
    
const Format& DoubleSequence::getFormat() const
{
    return m_format;
}
    
Format& DoubleSequence::getFormat()
{
    return m_format;
}

double DoubleSequence::getMinimum() const
{
    return m_min;
}

void DoubleSequence::setMinimum(double min)
{
    m_min = min;
}

double DoubleSequence::getMaximum() const
{
    return m_max;
}

void DoubleSequence::setMaximum(double max)
{
    m_max = max;
}

double DoubleSequence::getStep() const
{
    return m_step;
}

void DoubleSequence::setStep(double step)
{
    m_step = step;
}
