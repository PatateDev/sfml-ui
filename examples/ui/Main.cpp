#include <SFML/UI.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Listener.hpp"

void buttonFunction()
{
	std::cout << "Button fired" << std::endl;
}

int main(int argc, char*argv[])
{
	std::cout << "SFML Version : " << SFML_VERSION_MAJOR << "." << SFML_VERSION_MINOR << std::endl;
	std::cout << "Testing sfml-ui lib" << std::endl;
	std::cout << "Current Version : " << SFML_UI_VERSION_MAJOR << "." << SFML_UI_VERSION_MINOR << "." << SFML_UI_VERSION_PATCH << std::endl;


	std::cout << "Creating window" << std::endl;
	sf::RenderWindow window(sf::VideoMode(640, 420), "Test SFML-UI", sf::Style::Close);
	sf::Event event;

	std::cout << "Creating label text" << std::endl;
	sf::Font font;
	font.loadFromFile("resources/FreeSans.ttf");
	sf::ui::Label text(font, "A text label");
	text.setFontColor(sf::Color::Black);
	text.move(200, 0);
	std::cout << "Label text size : " << text.getSize().x << ";" << text.getSize().y << std::endl;

	std::cout << "Creating label image" << std::endl;
	sf::Texture lblImg;
	lblImg.loadFromFile("resources/hello_world.png");
	sf::ui::Label image(lblImg);
	image.move(window.getSize().x/2 - image.getSize().x/2, 100);
	std::cout << "Label image size : " << image.getSize().x << ";" << image.getSize().y << std::endl;

	std::cout << "Creating button" << std::endl;
	sf::Texture buttonImg;
	buttonImg.loadFromFile("resources/button.png");
	sf::Texture buttonFocImg;
	buttonFocImg.loadFromFile("resources/button_focused.png");
	sf::Texture buttonFirImg;
	buttonFirImg.loadFromFile("resources/button_fired.png");
	sf::ui::Button button(buttonImg, buttonFocImg, buttonFirImg);
	button.setFont(font);
	button.setFontSize(30);
	button.setText("Button");
	button.move(window.getSize().x/2 - button.getSize().x/2, 40);
	button.setFontColor(sf::Color::Black);

	std::cout << "Creating check boxes" << std::endl;
	sf::Texture checkboxImg;
	checkboxImg.loadFromFile("resources/checkbox.png");
	sf::Texture checkboxSelImg;
	checkboxSelImg.loadFromFile("resources/checkbox_selected.png");
	sf::ui::CheckBox checkbox(checkboxImg, checkboxSelImg), checkbox2(checkboxImg, checkboxSelImg), checkbox3(checkboxImg, checkboxSelImg);
	checkbox.setFont(font);
	checkbox.setText("A checkbox");
	checkbox.setFontColor(sf::Color::Black);
	checkbox.setFontSize(15);
	checkbox.move(0, 10);
	checkbox2.setFont(font);
	checkbox2.setText("Another checkbox");
	checkbox2.setFontColor(sf::Color::Black);
	checkbox2.setFontSize(15);
	checkbox2.move(0, 30);
	checkbox3.setFont(font);
	checkbox3.setText("A last checkbox");
	checkbox3.setFontColor(sf::Color::Black);
	checkbox3.setFontSize(15);
	checkbox3.move(0, 50);
	
	std::cout << "Creating a CheckBoxGroup" << std::endl;
	sf::ui::CheckBoxGroup group;
	group.addCheckBox(checkbox);
	group.addCheckBox(checkbox2);
	group.addCheckBox(checkbox3);

	std::cout << "Creating key field" << std::endl;
	sf::ui::KeyField keyfield(buttonImg, buttonFocImg, font, sf::Keyboard::A);
	keyfield.setFontSize(30);
	keyfield.move(0, 80);
	keyfield.setFontColor(sf::Color::Black);

	std::cout << "Creating text field" << std::endl;
	sf::ui::TextField textfield(buttonImg, buttonFocImg, font, "Another text field");
	textfield.setFontSize(30);
	textfield.move(0, 180);
	textfield.setFontColor(sf::Color::Black);
	textfield.setCanBeEmpty(false);
	textfield.setMaxLength(16);
	
    std::cout << "Creating password field" << std::endl;
	sf::ui::PasswordField pwfield(buttonImg, buttonFocImg, font);
	pwfield.setFontSize(30);
	pwfield.move(0, 240);
	pwfield.setFontColor(sf::Color::Black);
	pwfield.setMaxLength(16);
	
	std::cout << "Creating Formatted TextField" << std::endl;
	sf::ui::FormattedTextField intfield(buttonImg, buttonFocImg, font, new sf::ui::LongFormat, "0");
	intfield.setFontSize(30);
	intfield.move(0, 300);
	intfield.setFontColor(sf::Color::Black);
	intfield.setMaxLength(16);
	intfield.setText("-128");
	
	sf::ui::FormattedTextField doublefield(buttonImg, buttonFocImg, font, new sf::ui::DoubleFormat, "0.0");
	doublefield.setFontSize(30);
	doublefield.move(0, 350);
	doublefield.setFontColor(sf::Color::Black);
	doublefield.setMaxLength(16);
	doublefield.setText("3.14");
	
	sf::ui::FormattedTextField ulongfield(buttonImg, buttonFocImg, font, new sf::ui::UnsignedLongFormat, "0");
	ulongfield.setFontSize(30);
	ulongfield.move(300, 350);
	ulongfield.setFontColor(sf::Color::Black);
	ulongfield.setMaxLength(16);
	ulongfield.setText("256");

	std::cout << "Creating listener" << std::endl;
	Listener listener;
	textfield.addObserver(&listener);
	button.addObserver(&listener);
	keyfield.addObserver(&listener);
	intfield.addObserver(&listener);
    doublefield.addObserver(&listener);
	ulongfield.addObserver(&listener);
/*	checkbox.addObserver(&listener);
	checkbox2.addObserver(&listener);
	checkbox3.addObserver(&listener);*/
	
	while (window.isOpen())
	{
		window.waitEvent(event);

		if (event.type == sf::Event::Closed)
			window.close();

		text.updateEvent(event);
		image.updateEvent(event);
		button.updateEvent(event);
		checkbox.updateEvent(event);
		checkbox2.updateEvent(event);
		checkbox3.updateEvent(event);
		keyfield.updateEvent(event);
		textfield.updateEvent(event);
		pwfield.updateEvent(event);
		intfield.updateEvent(event);
		doublefield.updateEvent(event);
		ulongfield.updateEvent(event);

		window.clear(sf::Color::White);
		window.draw(text);
		window.draw(image);
		window.draw(button);
		window.draw(checkbox);
		window.draw(checkbox2);
		window.draw(checkbox3);
		window.draw(keyfield);
		window.draw(textfield);
		window.draw(pwfield);
		window.draw(intfield);
		window.draw(doublefield);
		window.draw(ulongfield);
		window.display();
	}

	return EXIT_SUCCESS;
}
