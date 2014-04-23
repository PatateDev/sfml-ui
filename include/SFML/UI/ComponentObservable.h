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

#include <set>
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
    ////////////////////////////////////////////////////////////
    ///
    /// \brief The default constructor
    ///
    ////////////////////////////////////////////////////////////
    ComponentObservable();
    
    virtual ~ComponentObservable();
//-------------------------------------------------------------------------------------

//METHODS -----------------------------------------------------------------------------
public:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Add an observer
    ///
    ////////////////////////////////////////////////////////////
    void addObserver(sf::ui::ComponentObserver* observer);

    ////////////////////////////////////////////////////////////
    ///
    /// \return the begin of the observers' iterator
    ///
    ////////////////////////////////////////////////////////////
    std::set<sf::ui::ComponentObserver*>::const_iterator getObserversBegin() const;
    
    ////////////////////////////////////////////////////////////
    ///
    /// \return the end of the observers' iterator
    ///
    ////////////////////////////////////////////////////////////
    std::set<sf::ui::ComponentObserver*>::const_iterator getObserversEnd() const;

    ////////////////////////////////////////////////////////////
    ///
    /// \return the number of observers
    ///
    ////////////////////////////////////////////////////////////
    int countObservers();

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Remove the observer at the given index
    ///
    /// \param observer the observer to remove
    ///
    ////////////////////////////////////////////////////////////
    void removeObserver(sf::ui::ComponentObserver* observer);

    ////////////////////////////////////////////////////////////
    ///
    /// \brief Remove all the observers
    ///
    ////////////////////////////////////////////////////////////
    void removeAllObservers();

protected:
    ////////////////////////////////////////////////////////////
    ///
    /// \brief Triggers the event and notify all observers
    ///
    /// \param event - the event to push
    ///
    ////////////////////////////////////////////////////////////
    void triggerEvent(sf::ui::ComponentEvent &event);
//-------------------------------------------------------------------------------------

//GETTERS - SETTERS -------------------------------------------------------------------

//-------------------------------------------------------------------------------------

//FIELDS ------------------------------------------------------------------------------
protected:
    std::set<sf::ui::ComponentObserver*> m_observers;
//-------------------------------------------------------------------------------------
};

} /* namespace ui */
} /* namespace sf */
#endif /* COMPONENTOBSERVABLE_H_ */

////////////////////////////////////////////////////////////
///
/// \class sf::ui::ComponentObservable
/// \brief The class who call the observers
/// \ingroup ui
///
////////////////////////////////////////////////////////////
