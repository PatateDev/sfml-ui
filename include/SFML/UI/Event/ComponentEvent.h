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

#ifndef COMPONENT_EVENT_H
#define COMPONENT_EVENT_H

namespace sf
{
namespace ui
{
class Component;

class ComponentEvent
{
    //CONSTRUCTORS/DESTRUCTORS -------------------------------------------
public:
    /*
     * An event related to the source component
     * Params:
     *  source - the component that triggers this event
     */
    ComponentEvent(Component *source);

    virtual ~ComponentEvent();
    //--------------------------------------------------------------------
    
    //GETTERS/SETTERS ----------------------------------------------------
public:
    /*
     * Return the component that triggers this event
     */
    Component* getSource() const;
    //--------------------------------------------------------------------
    
    //FIELDS -------------------------------------------------------------
protected:
    Component *m_source;
    //--------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */

#endif // COMPONENT_EVENT_H
