#include "Listener.hpp"
#include <iostream>
#include <SFML/UI/SFMLUtils.hpp>
#include <locale>

Listener::Listener()
{
    //ctor
}

Listener::~Listener()
{
    //dtor
}

void Listener::onComponentEvent(const sf::ui::ComponentEvent &event)
{
	std::cout << "Listener" << std::endl;
	std::cout << "Component @" << event.source;
	switch (event.type)
	{
	case sf::ui::ComponentEvent::FocusGained:
		std::cout << " gain focus" << std::endl;
		break;
	case sf::ui::ComponentEvent::FocusLost:
		std::cout << " loose focus" << std::endl;
		break;	
	case sf::ui::ComponentEvent::ButtonClicked:
		// Pour tester quel button a ete clique :
		/*
		 * if (event.buttonClick.source == &button1)
		 * {
		 * 	// Bla Bla
		 * }
		 * else if (event.buttonClick.source == &button2)
		 * {
		 * // Bla Bla
		 * }
		 * else
		 * {
		 * std::cout << "Unknown button" << std::endl;
		 * }
		 */
		 std::cout << " has been clicked" << std::endl;
		 break;
	case sf::ui::ComponentEvent::KeyFieldSet:
		 std::cout << " has been set a new key : " << sf::String(sf::ui::SFMLUtils::keyToString(event.keyFieldSet.key)).toAnsiString() << std::endl;
		 break;
	case sf::ui::ComponentEvent::TextEntered:
		 std::cout << " has character \'" << sf::String(event.text.text).toAnsiString() << "\' entered at " << event.text.position << std::endl;
		 break;
	case sf::ui::ComponentEvent::TextDeleted:
		 std::cout << " has character \'" << sf::String(event.text.text).toAnsiString() << "\' deleted at " << event.text.position << std::endl;
		 break;
	case sf::ui::ComponentEvent::CheckBoxChanged:
		 std::cout << " has switched from " << (!event.checkBoxChange.selected ? "selected" : "unselected") << " to " << (event.checkBoxChange.selected ? "selected" : "unselected") << std::endl;
		 break;
	case sf::ui::ComponentEvent::FormattedValueEntered:
		 std::cout << " has a new formatted value entered : " << event.formattedValueEnter.format->toString().toAnsiString() << std::endl;
		 break;
	default:
		 std::cout << " has generated an unknown event" << std::endl;
		 break;
	}
}
