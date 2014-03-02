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

#include <SFML/UI/ComponentObservable.h>

using namespace sf::ui;

ComponentObservable::ComponentObservable()
: m_observers()
{

}

ComponentObservable::~ComponentObservable()
{

}

int ComponentObservable::addObserver(ComponentObserver* observer)
{
    int index = m_observers.size();
    m_observers.push_back(observer);

    return index;
}

const ComponentObserver* ComponentObservable::getObserver(int index) const
{
    return m_observers[index];
}

int ComponentObservable::countObservers()
{
    return m_observers.size();
}

void ComponentObservable::removeObserver(int index)
{
    m_observers.erase(m_observers.begin() + index);
}

void sf::ui::ComponentObservable::removeAllObservers()
{
    m_observers.clear();
}

void ComponentObservable::triggerEvent(sf::ui::ComponentEvent &event)
{
    for (int i = 0; i < m_observers.size(); i++)
        m_observers[i]->onComponentEvent(event);
}


