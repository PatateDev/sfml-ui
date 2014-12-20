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

#ifndef DOUBLE_FORMAT_H
#define DOUBLE_FORMAT_H

#include <SFML/UI/Format/Format.h>

namespace sf
{
namespace ui
{

class DoubleFormat : public Format
{
//CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Creates a double format
    ///
    ////////////////////////////////////////////////////////////
    DoubleFormat();
    
    virtual ~DoubleFormat();
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
    /// \param value the new value
    ///
    ////////////////////////////////////////////////////////////
    void setValue(double value);
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the value of the last string parsed as a double
    ///
    ////////////////////////////////////////////////////////////
    double getValue() const;
//--------------------------------------------------------------------

//FIELDS -------------------------------------------------------------
protected:
    double m_value;
//--------------------------------------------------------------------
};

}
}
#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::DoubleFormat
/// \brief Format to parse double
/// \ingroup ui
///
////////////////////////////////////////////////////////////
