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

#ifndef UNSIGNED_LONG_SEQUENCE_H
#define UNSIGNED_LONG_SEQUENCE_H

#include <SFML/UI/Format/Sequence.h>
#include <SFML/UI/Format/UnsignedLongFormat.h>

namespace sf
{
namespace ui
{

class UnsignedLongSequence : public Sequence
{
//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    UnsignedLongSequence(sf::Uint64 initialValue, sf::Uint64 min, sf::Uint64 max, sf::Uint64 step = 1);

    virtual ~UnsignedLongSequence();
//--------------------------------------------------------------------

//GETTERS/SETTERS ----------------------------------------------------
public:
   ////////////////////////////////////////////////////////////
    ///
    /// \brief set to the next value of the sequence
    ///
    ////////////////////////////////////////////////////////////
    virtual void next();
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief set the previous value of the sequence
    ///
    ////////////////////////////////////////////////////////////
    virtual void previous();
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the value
    ///
    ////////////////////////////////////////////////////////////
    sf::Uint64 getValue() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the current value
    ///
    /// \param value the new value
    ///
    ////////////////////////////////////////////////////////////
    void setValue(sf::Uint64 value);
    
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
    sf::Uint64 getMinimum() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the minimum value of the sequence
    ///
    /// \param min the new minimum
    ///
    ////////////////////////////////////////////////////////////
    void setMinimum(sf::Uint64 min);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the maximum value of the sequence
    ///
    ////////////////////////////////////////////////////////////
    sf::Uint64 getMaximum() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the maximum value of the sequence
    ///
    /// \param max the new maximum
    ///
    ////////////////////////////////////////////////////////////
    void setMaximum(sf::Uint64 max);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the step of the sequence
    ///
    ////////////////////////////////////////////////////////////
    sf::Uint64 getStep() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the step value of the sequence
    ///
    /// \param step the new step
    ///
    ////////////////////////////////////////////////////////////
    void setStep(sf::Uint64 step);
//--------------------------------------------------------------------

//FIELDS -------------------------------------------------------------
protected:
    UnsignedLongFormat m_format;
    sf::Uint64 m_min, m_max, m_step;
//--------------------------------------------------------------------
};

}
}
#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::UnsignedLongSequence
/// \brief A sequence of unsigned long (sf::Uint64) numbers, with limits (min & max)
/// \ingroup ui
///
////////////////////////////////////////////////////////////
