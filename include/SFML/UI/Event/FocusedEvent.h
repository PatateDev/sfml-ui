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

#ifndef FOCUSEDEVENT_H_
#define FOCUSEDEVENT_H_

#include <SFML/UI/Event/ComponentEvent.h>

namespace sf
{
namespace ui
{

class FocusedEvent : public ComponentEvent
{
//CONSTRUCTORS - DESTRUCTOR -----------------------------------------------------------
public:
    /*
     * An event that is triggered each time a component change its focus status
     * Params:
     *  source - the component that triggers this event
     *  nowFocused - whether the component is focused or not currently
     */
    FocusedEvent(sf::ui::Component* source, bool nowFocused);

    virtual ~FocusedEvent();
//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------
public:
    /*
     * Returns if the component is focused
     */
    bool isFocused() const;

    /*
     * Returns is the component was focused before
     */
    bool wasFocused() const;
//-------------------------------------------------------------------------------------

//FIELDS ------------------------------------------------------------------------------
protected:
    const bool m_isFocused;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* FOCUSEDEVENT_H_ */
