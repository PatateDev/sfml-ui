#include <SFML/UI.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

void buttonFunction()
{
	std::cout << "Button fired" << std::endl;
}

int main(int argc, char*argv[])
{
	std::cout << "Testing sfml-ui lib" << std::endl;
	std::cout << "Current Version : " << SFML_UI_VERSION_MAJOR << "." << SFML_UI_VERSION_MINOR << "." << SFML_UI_VERSION_PATCH << std::endl;


	std::cout << "Creating window" << std::endl;
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Test SFML-UI");
	sf::Event event;

	std::cout << "Creating label text" << std::endl;
	sf::Font font;
	font.loadFromFile("sansation.ttf");
	sf::ui::Label text(font, "A text label");
	text.setFontColor(sf::Color::Black);
	text.move(200, 200);

	std::cout << "Creating label image" << std::endl;
	sf::Texture lblImg;
	lblImg.loadFromFile("hello_world.png");
	sf::ui::Label image(lblImg);
	image.move(window.getSize().x/2 - image.getSize().x/2, 300);

	std::cout << "Creating button" << std::endl;
	sf::Texture buttonImg;
	buttonImg.loadFromFile("button.png");
	sf::Texture buttonFocImg;
	buttonFocImg.loadFromFile("button_focused.png");
	sf::Texture buttonFirImg;
	buttonFirImg.loadFromFile("button_fired.png");
	sf::ui::Button button(buttonImg, buttonFocImg, buttonFirImg);
	button.setFont(font);
	button.setFontSize(30);
	button.setText("Button");
	button.move(window.getSize().x/2 - button.getSize().x/2, 240);
	button.setFontColor(sf::Color::Black);

	std::cout << "Creating check boxes" << std::endl;
	sf::Texture checkboxImg;
	checkboxImg.loadFromFile("checkbox.png");
	sf::Texture checkboxSelImg;
	checkboxSelImg.loadFromFile("checkbox_selected.png");
	sf::ui::CheckBox checkbox(checkboxImg, checkboxSelImg), checkbox2(checkboxImg, checkboxSelImg), checkbox3(checkboxImg, checkboxSelImg);
	checkbox.setFont(font);
	checkbox.setText("A checkbox");
	checkbox.setFontColor(sf::Color::Black);
	checkbox.setFontSize(15);
	checkbox.move(0, 210);
	checkbox2.setFont(font);
	checkbox2.setText("Another checkbox");
	checkbox2.setFontColor(sf::Color::Black);
	checkbox2.setFontSize(15);
	checkbox2.move(0, 230);
	checkbox3.setFont(font);
	checkbox3.setText("A last checkbox");
	checkbox3.setFontColor(sf::Color::Black);
	checkbox3.setFontSize(15);
	checkbox3.move(0, 250);
	
	std::cout << "Creating a CheckBoxGroup" << std::endl;
	sf::ui::CheckBoxGroup group;
	group.addCheckBox(checkbox);
	group.addCheckBox(checkbox2);
	group.addCheckBox(checkbox3);

	std::cout << "Creating key field (does nothing in Android)" << std::endl;
	sf::ui::KeyField keyfield(buttonImg, buttonFocImg, font, sf::Keyboard::A);
	keyfield.setFontSize(30);
	keyfield.move(0, 280);
	keyfield.setFontColor(sf::Color::Black);

	std::cout << "Creating text field" << std::endl;
	sf::ui::TextField textfield(buttonImg, buttonFocImg, font, "A field");
	textfield.setFontSize(30);
	textfield.move(0, 380);
	textfield.setFontColor(sf::Color::Black);
	textfield.setCanBeEmpty(false);
	textfield.setMaxLength(16);
	
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

		window.clear(sf::Color::White);
		window.draw(text);
		window.draw(image);
		window.draw(button);
		window.draw(checkbox);
		window.draw(checkbox2);
		window.draw(checkbox3);
		window.draw(keyfield);
		window.draw(textfield);
		window.display();
	}

	return EXIT_SUCCESS;
}
