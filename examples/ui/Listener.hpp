#ifndef LISTENER_H
#define LISTENER_H

#include <SFML/UI.hpp>

class Listener : public sf::ui::ComponentObserver
{
    public:
        Listener();
        virtual ~Listener();

        virtual void onComponentEvent(const sf::ui::ComponentEvent &event);
    protected:
    private:
};

#endif // LISTENER_H
