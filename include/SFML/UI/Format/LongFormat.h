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

#ifndef INT_FORMAT_H
#define INT_FORMAT_H

#include <SFML/UI/Format/Format.h>

namespace sf
{
namespace ui
{

class LongFormat : public Format
{
//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Creates an integer format
    ///
    ////////////////////////////////////////////////////////////
    LongFormat();
    
    virtual ~LongFormat();
//--------------------------------------------------------------------

//METHODS ------------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \return the string with the value in this format
    ///
    ////////////////////////////////////////////////////////////
    virtual sf::String toString() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return if the given string matches with this format
    ///
    /// \param str the string to test
    ///
    ////////////////////////////////////////////////////////////
    virtual bool isAllowed(sf::String str) const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief parse the string to this format, and update the value
    ///
    /// \param str the string parsed
    ///
    ////////////////////////////////////////////////////////////
    virtual void parse(sf::String str);

//--------------------------------------------------------------------

//GETTERS/SETTERS ----------------------------------------------------
public:    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Set the value for this format
    /// The given value is automatically deleted by the format class
    /// Warning : giving value which is not a sf::Int64 can lead to bugs, memory leak ...
    ///
    /// \param value the new value
    ///
    ////////////////////////////////////////////////////////////
    virtual void setValue(void* value);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \brief The value returned should be copy into a full object,
    /// or a primitive type, as the pointer is deleted when the
    /// value is changed (with the function parse for example)
    ///
    /// \return the value of the last string parsed as pointer to a sf::Int64
    ///
    ////////////////////////////////////////////////////////////
    virtual const void* getValue() const;
//--------------------------------------------------------------------

//FIELDS -------------------------------------------------------------
protected:
    sf::Int64 *m_value;
//--------------------------------------------------------------------
};

}
}
#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::LongFormat
/// \brief Format to parse long (stored as sf::Int64*)
/// \ingroup ui
///
////////////////////////////////////////////////////////////
