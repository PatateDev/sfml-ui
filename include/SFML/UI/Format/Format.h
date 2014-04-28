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

#ifndef FORMAT_H
#define FORMAT_H

#include <SFML/System.hpp>

namespace sf
{
namespace ui
{

class Format
{
//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    virtual ~Format();
//--------------------------------------------------------------------

//METHODS ------------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return the string with the value in this format
    ///
    ////////////////////////////////////////////////////////////
    virtual sf::String toString() const = 0;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return if the given string matches with this format
    ///
    /// \param str the string to test
    ///
    ////////////////////////////////////////////////////////////
    virtual bool isAllowed(sf::String str) const = 0;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief parse the string to this format, and update the value
    ///
    /// \param str the string parsed
    ///
    ////////////////////////////////////////////////////////////
    virtual void parse(sf::String str) = 0;

//--------------------------------------------------------------------

//GETTERS/SETTERS ----------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief The value returned should be copy into a full object,
    /// or a primitive type, as the pointer is deleted when the
    /// value is changed (with the function parse for example)
    ///
    /// \return the value of the last string parsed
    ///
    ////////////////////////////////////////////////////////////
    virtual const void* getValue() const = 0;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Set the value for this format
    /// The given value is automatically deleted by the format class
    ///
    /// \param value the new value
    ///
    ////////////////////////////////////////////////////////////
    virtual void setValue(void* value) = 0;
//--------------------------------------------------------------------

//FIELDS -------------------------------------------------------------

//--------------------------------------------------------------------
};

}
}
#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::Format
/// \brief The abstract class that defines format of various 
/// types, such as ints, double, objects ...
/// \ingroup ui
///
////////////////////////////////////////////////////////////
