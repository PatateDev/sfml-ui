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

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <SFML/UI/Format/Format.hpp>

namespace sf
{
namespace ui
{

class Sequence
{
//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    virtual ~Sequence();
//--------------------------------------------------------------------

//GETTERS/SETTERS ----------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief set to the next value of the sequence
    ///
    ////////////////////////////////////////////////////////////
    virtual void next() = 0;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief set the previous value of the sequence
    ///
    ////////////////////////////////////////////////////////////
    virtual void previous() = 0;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format of the sequence's values
    ///
    ////////////////////////////////////////////////////////////
    virtual const Format& getFormat() const = 0;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the format of the sequence's values
    ///
    ////////////////////////////////////////////////////////////
    virtual Format& getFormat() = 0;
//--------------------------------------------------------------------
};

}
}
#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::Sequence
/// \brief The parent class that defines any logical sequence
/// like numbers, percents, dates ...
/// \ingroup ui
///
////////////////////////////////////////////////////////////
