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

#ifndef DOUBLE_SEQUENCE_H
#define DOUBLE_SEQUENCE_H

#include <SFML/UI/Format/Sequence.hpp>
#include <SFML/UI/Format/DoubleFormat.hpp>

namespace sf
{
namespace ui
{

class DoubleSequence : public Sequence
{
//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    DoubleSequence(double initialValue, double min, double max, double step = 1.0);

    virtual ~DoubleSequence();
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
    double getValue() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the current value
    ///
    /// \param value the new value
    ///
    ////////////////////////////////////////////////////////////
    void setValue(double value);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format of the sequence's values
    ///
    ////////////////////////////////////////////////////////////
    const Format& getFormat() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format of the sequence's values
    ///
    ////////////////////////////////////////////////////////////
    Format& getFormat();
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the minimum value of the sequence
    ///
    ////////////////////////////////////////////////////////////
    double getMinimum() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the minimum value of the sequence
    ///
    /// \param min the new minimum
    ///
    ////////////////////////////////////////////////////////////
    void setMinimum(double min);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the maximum value of the sequence
    ///
    ////////////////////////////////////////////////////////////
    double getMaximum() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the maximum value of the sequence
    ///
    /// \param max the new maximum
    ///
    ////////////////////////////////////////////////////////////
    void setMaximum(double max);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the step of the sequence
    ///
    ////////////////////////////////////////////////////////////
    double getStep() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief sets the step value of the sequence
    ///
    /// \param step the new step
    ///
    ////////////////////////////////////////////////////////////
    void setStep(double step);
//--------------------------------------------------------------------

//FIELDS -------------------------------------------------------------
protected:
    DoubleFormat m_format;
    double m_min, m_max, m_step;
//--------------------------------------------------------------------
};

}
}
#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::DoubleSequence
/// \brief A sequence of doubles numbers, with limits (min & max)
/// \ingroup ui
///
////////////////////////////////////////////////////////////
