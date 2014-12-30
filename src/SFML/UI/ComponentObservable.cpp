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

#include <SFML/UI/ComponentObservable.hpp>
#include <SFML/UI/ComponentEvent.hpp>

using namespace sf::ui;

ComponentObservable::ComponentObservable()
: m_observers()
{

}

ComponentObservable::~ComponentObservable()
{

}

void ComponentObservable::addObserver(ComponentObserver* observer)
{
    m_observers.insert(observer);
}

std::set<sf::ui::ComponentObserver*>::const_iterator ComponentObservable::getObserversBegin() const
{
    return m_observers.begin();
}

std::set<sf::ui::ComponentObserver*>::const_iterator ComponentObservable::getObserversEnd() const
{
    return m_observers.begin();
}

int ComponentObservable::countObservers()
{
    return m_observers.size();
}

void ComponentObservable::removeObserver(sf::ui::ComponentObserver* observer)
{
    m_observers.erase(observer);
}

void sf::ui::ComponentObservable::removeAllObservers()
{
    m_observers.clear();
}

void ComponentObservable::triggerEvent(const sf::ui::ComponentEvent &event)
{
    for (std::set<sf::ui::ComponentObserver*>::iterator it = m_observers.begin(); it != m_observers.end(); it++)
        (*it)->onComponentEvent(event);
}


