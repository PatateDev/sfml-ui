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

#include <SFML/UI/KeyField.hpp>
#include <SFML/UI/SFMLUtils.hpp>
#include <SFML/UI/Event/KeyfieldSetEvent.hpp>
#include <iostream>

using namespace sf::ui;

KeyField::KeyField(sf::Keyboard::Key key)
: Focusable(),
  m_text(), m_key(key)
{
	setKeys();
}

KeyField::KeyField(const sf::Texture& texture, const sf::Texture& textureFocused, const sf::Font& font, sf::Keyboard::Key key)
: Focusable(texture, textureFocused),
  m_text(SFMLUtils::keyToString(key), font), m_key(key)
{
	setKeys();
}

KeyField::~KeyField()
{

}

void KeyField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Focusable::draw(target, states);
	target.draw(m_text, states);
}

void KeyField::updateEvent(const sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		sf::Vector2f pos(event.mouseButton.x, event.mouseButton.y);

		if (event.mouseButton.button != sf::Mouse::Left)
			break;

		setFocused(m_sprite.getGlobalBounds().contains(pos));

		break;
	}
	case sf::Event::KeyReleased:
	{
		sf::Keyboard::Key key = event.key.code;

		if (m_focused && isKeyAllowed(key))
		{
		    KeyfieldSetEvent keyfieldEvent(this, key);
			m_key = key;
			m_text.setString(SFMLUtils::keyToString(m_key));
			updateCoord();
			setFocused(false);
			triggerEvent(keyfieldEvent);
		}
		else if (key == sf::Keyboard::Escape)
			setFocused(false);

		break;
	}
	default:
		break;
	}

	m_sprite.setTexture(*(m_focused ? m_textureFocused : m_texture), false);
}

void KeyField::updateFixed(sf::Time delta)
{

}

void KeyField::updateCoord()
{
	sf::FloatRect spriteBounds(m_sprite.getGlobalBounds());
	sf::Vector2f pos(m_sprite.getPosition()), size(SFMLUtils::getLocalSize(m_text));

	m_text.setOrigin(size.x/2.f, size.y/2.f);
	m_text.setPosition(pos.x + spriteBounds.width/2.f, pos.y + spriteBounds.height/2.f);
}

void KeyField::setKeys()
{
	m_keysAllowed.insert(sf::Keyboard::A);
	m_keysAllowed.insert(sf::Keyboard::B);
	m_keysAllowed.insert(sf::Keyboard::C);
	m_keysAllowed.insert(sf::Keyboard::D);
	m_keysAllowed.insert(sf::Keyboard::E);
	m_keysAllowed.insert(sf::Keyboard::F);
	m_keysAllowed.insert(sf::Keyboard::G);
	m_keysAllowed.insert(sf::Keyboard::H);
	m_keysAllowed.insert(sf::Keyboard::I);
	m_keysAllowed.insert(sf::Keyboard::J);
	m_keysAllowed.insert(sf::Keyboard::K);
	m_keysAllowed.insert(sf::Keyboard::L);
	m_keysAllowed.insert(sf::Keyboard::M);
	m_keysAllowed.insert(sf::Keyboard::N);
	m_keysAllowed.insert(sf::Keyboard::O);
	m_keysAllowed.insert(sf::Keyboard::P);
	m_keysAllowed.insert(sf::Keyboard::Q);
	m_keysAllowed.insert(sf::Keyboard::R);
	m_keysAllowed.insert(sf::Keyboard::S);
	m_keysAllowed.insert(sf::Keyboard::T);
	m_keysAllowed.insert(sf::Keyboard::U);
	m_keysAllowed.insert(sf::Keyboard::V);
	m_keysAllowed.insert(sf::Keyboard::W);
	m_keysAllowed.insert(sf::Keyboard::X);
	m_keysAllowed.insert(sf::Keyboard::Y);
	m_keysAllowed.insert(sf::Keyboard::Z);
	m_keysAllowed.insert(sf::Keyboard::Num0);
	m_keysAllowed.insert(sf::Keyboard::Num1);
	m_keysAllowed.insert(sf::Keyboard::Num2);
	m_keysAllowed.insert(sf::Keyboard::Num3);
	m_keysAllowed.insert(sf::Keyboard::Num4);
	m_keysAllowed.insert(sf::Keyboard::Num5);
	m_keysAllowed.insert(sf::Keyboard::Num6);
	m_keysAllowed.insert(sf::Keyboard::Num7);
	m_keysAllowed.insert(sf::Keyboard::Num8);
	m_keysAllowed.insert(sf::Keyboard::Num9);
	m_keysAllowed.insert(sf::Keyboard::Numpad0);
	m_keysAllowed.insert(sf::Keyboard::Numpad1);
	m_keysAllowed.insert(sf::Keyboard::Numpad2);
	m_keysAllowed.insert(sf::Keyboard::Numpad3);
	m_keysAllowed.insert(sf::Keyboard::Numpad4);
	m_keysAllowed.insert(sf::Keyboard::Numpad5);
	m_keysAllowed.insert(sf::Keyboard::Numpad6);
	m_keysAllowed.insert(sf::Keyboard::Numpad7);
	m_keysAllowed.insert(sf::Keyboard::Numpad8);
	m_keysAllowed.insert(sf::Keyboard::Numpad9);
	m_keysAllowed.insert(sf::Keyboard::Up);
	m_keysAllowed.insert(sf::Keyboard::Down);
	m_keysAllowed.insert(sf::Keyboard::Left);
	m_keysAllowed.insert(sf::Keyboard::Right);
	m_keysAllowed.insert(sf::Keyboard::LControl);
	m_keysAllowed.insert(sf::Keyboard::LAlt);
	m_keysAllowed.insert(sf::Keyboard::LShift);
	m_keysAllowed.insert(sf::Keyboard::RControl);
	m_keysAllowed.insert(sf::Keyboard::RAlt);
	m_keysAllowed.insert(sf::Keyboard::RShift);
	m_keysAllowed.insert(sf::Keyboard::Tab);
	m_keysAllowed.insert(sf::Keyboard::Tilde);
	m_keysAllowed.insert(sf::Keyboard::Slash);
	m_keysAllowed.insert(sf::Keyboard::BackSlash);
	m_keysAllowed.insert(sf::Keyboard::Space);
	m_keysAllowed.insert(sf::Keyboard::LBracket);
	m_keysAllowed.insert(sf::Keyboard::RBracket);
	m_keysAllowed.insert(sf::Keyboard::BackSpace);
	m_keysAllowed.insert(sf::Keyboard::Return);
	m_keysAllowed.insert(sf::Keyboard::Comma);
	m_keysAllowed.insert(sf::Keyboard::SemiColon);
	m_keysAllowed.insert(sf::Keyboard::Dash);
	m_keysAllowed.insert(sf::Keyboard::Period);
	m_keysAllowed.insert(sf::Keyboard::Quote);
	m_keysAllowed.insert(sf::Keyboard::Add);
	m_keysAllowed.insert(sf::Keyboard::Subtract);
	m_keysAllowed.insert(sf::Keyboard::Multiply);
	m_keysAllowed.insert(sf::Keyboard::Divide);
	m_keysAllowed.insert(sf::Keyboard::F1);
	m_keysAllowed.insert(sf::Keyboard::F2);
	m_keysAllowed.insert(sf::Keyboard::F3);
	m_keysAllowed.insert(sf::Keyboard::F4);
	m_keysAllowed.insert(sf::Keyboard::F5);
	m_keysAllowed.insert(sf::Keyboard::F6);
	m_keysAllowed.insert(sf::Keyboard::F7);
	m_keysAllowed.insert(sf::Keyboard::F8);
	m_keysAllowed.insert(sf::Keyboard::F9);
	m_keysAllowed.insert(sf::Keyboard::F10);
	m_keysAllowed.insert(sf::Keyboard::F11);
	m_keysAllowed.insert(sf::Keyboard::F12);
	m_keysAllowed.insert(sf::Keyboard::F13);
	m_keysAllowed.insert(sf::Keyboard::F14);
	m_keysAllowed.insert(sf::Keyboard::F15);
}

const sf::String& KeyField::getText() const
{
	return m_text.getString();
}

void KeyField::setText(const sf::String& text)
{
	std::cerr << "You should not set a keyfield's text : " << text.toAnsiString(std::locale()) << std::endl;
}

const sf::Font* KeyField::getFont() const
{
	return m_text.getFont();
}

void KeyField::setFont(const sf::Font& font)
{
	m_text.setFont(font);
}

unsigned int KeyField::getFontSize() const
{
	return m_text.getCharacterSize();
}

void KeyField::setFontSize(unsigned int size)
{
	m_text.setCharacterSize(size);
}

sf::Color KeyField::getFontColor() const
{
	return m_text.getColor();
}

const std::set<sf::Keyboard::Key>& KeyField::getAllowedKeys() const
{
	return m_keysAllowed;
}

void KeyField::addKey(sf::Keyboard::Key key)
{
	m_keysAllowed.insert(key);
}

bool KeyField::isKeyAllowed(sf::Keyboard::Key key) const
{
	return m_keysAllowed.find(key) != m_keysAllowed.end();
}

void KeyField::removeKey(sf::Keyboard::Key key)
{
	m_keysAllowed.erase(key);
}

void KeyField::setFontColor(sf::Color color)
{
	m_text.setColor(color);
}
