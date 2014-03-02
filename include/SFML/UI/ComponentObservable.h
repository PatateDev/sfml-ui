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

#ifndef COMPONENTOBSERVABLE_H_
#define COMPONENTOBSERVABLE_H_

#include <vector>
#include <SFML/UI/ComponentObserver.h>

namespace sf
{
namespace ui
{
class ComponentEvent;

class ComponentObservable
{
//CONSTRUCTORS - DESTRUCTOR -----------------------------------------------------------
public:
    ComponentObservable();
    virtual ~ComponentObservable();
//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------
public:
    /*
     * Add an observer
     * Returns the index of the observer
     */
    int addObserver(sf::ui::ComponentObserver* observer);

    /*
     * Returns the observer at the given index
     */
    const sf::ui::ComponentObserver* getObserver(int index) const;

    /*
     * Returns the number of observers
     */
    int countObservers();

    /*
     * Remove the observer at the given index
     */
    void removeObserver(int index);

    /**
     * Remove all the observers
     */
    void removeAllObservers();

protected:
    /**
     * Triggers the event and notify all observers
     * Params:
     *  event - the event to push
     */
    void triggerEvent(sf::ui::ComponentEvent &event);
//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//FIELDS ------------------------------------------------------------------------------
protected:
    std::vector<sf::ui::ComponentObserver*> m_observers;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* COMPONENTOBSERVABLE_H_ */
