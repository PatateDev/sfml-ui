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

#ifndef LONG_SEQUENCE_H
#define LONG_SEQUENCE_H

#include <SFML/UI/Format/Sequence.h>
#include <SFML/UI/Format/LongFormat.h>

namespace sf
{
namespace ui
{

class LongSequence : public Sequence
{
//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    LongSequence(sf::Int64 initialValue, sf::Int64 min, sf::Int64 max, sf::Int64 step = 1);

    virtual ~LongSequence();
//--------------------------------------------------------------------

//GETTERS/SETTERS ----------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return the next value of the sequence, need to be deleted then
    ///
    ////////////////////////////////////////////////////////////
    virtual void* getNext() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the previous value of the sequence, need to be deleted then
    ///
    ////////////////////////////////////////////////////////////
    virtual void* getPrevious() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the value
    ///
    ////////////////////////////////////////////////////////////
    virtual const void* getValue() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the current value
    ///
    /// \param value the new value, automatically deleted when needed
    ///
    ////////////////////////////////////////////////////////////
    virtual void setValue(void* value);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format of the sequence's values
    ///
    ////////////////////////////////////////////////////////////
    virtual const Format& getFormat() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format of the sequence's values
    ///
    ////////////////////////////////////////////////////////////
    virtual Format& getFormat();
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the minimum value of the sequence
    ///
    ////////////////////////////////////////////////////////////
    sf::Int64 getMinimum() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the minimum value of the sequence
    ///
    /// \param min the new minimum
    ///
    ////////////////////////////////////////////////////////////
    void setMinimum(sf::Int64 min);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the maximum value of the sequence
    ///
    ////////////////////////////////////////////////////////////
    sf::Int64 getMaximum() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the maximum value of the sequence
    ///
    /// \param max the new maximum
    ///
    ////////////////////////////////////////////////////////////
    void setMaximum(sf::Int64 max);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the step of the sequence
    ///
    ////////////////////////////////////////////////////////////
    sf::Int64 getStep() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the step value of the sequence
    ///
    /// \param step the new step
    ///
    ////////////////////////////////////////////////////////////
    void setStep(sf::Int64 step);
//--------------------------------------------------------------------

//FIELDS -------------------------------------------------------------
protected:
    LongFormat m_format;
    sf::Int64 m_min, m_max, m_step;
//--------------------------------------------------------------------
};

}
}
#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::LongSequence
/// \brief A sequence of long (sf::Int64) numbers, with limits (min & max)
/// \ingroup ui
///
////////////////////////////////////////////////////////////
