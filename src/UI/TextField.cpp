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

#include <SFML/UI/TextField.h>
#include <SFML/UI/SFMLUtils.h>
#include <SFML/UI/Model/DefaultTextFieldModel.h>
#include <SFML/UI/Event/TextEnteredEvent.h>
#include <SFML/UI/Event/TextDeletedEvent.h>

using namespace sf::ui;

TextField::TextField()
: Focusable(),
  m_text(), m_cursor(0), m_cursorShape(),
  m_maxLength(-1), m_canBeEmpty(true)
{
	m_model = new DefaultTextFieldModel;
	m_cursorShape.setFillColor(sf::Color::Black);
}

TextField::TextField(const sf::Texture& texture, const sf::Texture& textureFocused, sf::String const &text)
: Focusable(texture, textureFocused),
  m_text(), m_cursor(text.getSize()), m_cursorShape(),
  m_maxLength(-1), m_canBeEmpty(true)
{
	setText(text);
	m_model = new DefaultTextFieldModel;
	m_cursorShape.setFillColor(sf::Color::Black);
}

TextField::TextField(const sf::Texture& texture, const sf::Texture& textureFocused, const sf::Font& font, sf::String text)
: Focusable(texture, textureFocused),
  m_text(text, font), m_cursor(text.getSize()), m_cursorShape(),
  m_maxLength(-1), m_canBeEmpty(true)
{
	m_model = new DefaultTextFieldModel;
	m_cursorShape.setFillColor(sf::Color::Black);
}

TextField::~TextField()
{
	delete m_model;
}

void TextField::updateFixed(sf::Time delta)
{

}

void TextField::updateEvent(const sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (checkClickOn(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y))
			setFocused(true);
		else if (event.mouseButton.button == sf::Mouse::Left && !isCoordOnComponent(event.mouseButton.x, event.mouseButton.y)
					&& !(m_text.getString().getSize() == 0 && !m_canBeEmpty))
			setFocused(false);

		m_sprite.setTexture(*(m_focused ? m_textureFocused : m_texture), false);
		break;
	case sf::Event::KeyPressed:
		if (!m_focused)
			break;

		switch(event.key.code)
		{
		case sf::Keyboard::Return:
			if (m_text.getString().getSize() == 0 && !m_canBeEmpty)
				break;

			setFocused(false);
			m_cursor = m_text.getString().getSize();
			m_sprite.setTexture(*m_texture, false);
			break;
		case sf::Keyboard::Left:
			if (m_cursor > 0)
				m_cursor--;

			break;
		case sf::Keyboard::Right:
			if (m_cursor < m_text.getString().getSize())
				m_cursor++;

			break;
		case sf::Keyboard::BackSpace:

			if (m_cursor != 0 && m_text.getString().getSize() > 0)
			{
			    deleteText(m_cursor - 1);
			    m_cursor--;
			}

			break;
		case sf::Keyboard::Delete:

			if (m_cursor < m_text.getString().getSize())
			{
			    deleteText(m_cursor);
			}

			break;
		default:
			break;
		}
		updateCoord();

		break;
	case sf::Event::TextEntered:
	{
		sf::Uint32 text = event.text.unicode;
		if (m_maxLength != -1 && m_text.getString().getSize() >= static_cast<unsigned int>(m_maxLength))
			break;

		if (m_model->isCharAllowed(text) && m_focused)
		{
		    insertText(text, m_cursor);
		    updateCoord();
		}

		break;
	}
	default:
		break;
	}
}

void TextField::insertText(sf::Uint32 text, unsigned int index)
{
    sf::String string = m_text.getString();
	string.insert(index, text);
	m_text.setString(string);
	m_cursor++;
	TextEnteredEvent textEvent(this, text, index);
	triggerEvent(textEvent);
}

void TextField::deleteText(unsigned int index)
{
    sf::String str = m_text.getString();
    TextDeletedEvent textEvent(this, str[index], index);
    str.erase(index);
    m_text.setString(str);
    triggerEvent(textEvent);
}

void TextField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	Focusable::draw(target, states);
	target.draw(m_text);
	if (m_focused)
		target.draw(m_cursorShape);
}

void TextField::updateCoord()
{
	sf::Vector2f pos(m_sprite.getPosition()), size(SFMLUtils::getLocalSize(m_text));

	m_text.setOrigin(0, size.y/2.f);
	m_text.setPosition(pos.x + 5, pos.y + m_sprite.getGlobalBounds().height/2.f);

	m_cursorShape.setSize(sf::Vector2f(1, size.y));
	m_cursorShape.setOrigin(1, m_cursorShape.getSize().y/2.f);
	m_cursorShape.setPosition(m_text.getPosition());

	for (unsigned int i = 0; i < m_cursor; i++)
	{
		float x;
		x = static_cast<float>(m_text.getFont()->getGlyph(m_text.getString()[i], m_text.getCharacterSize(), false).advance);

		if (i != 0)
			x += static_cast<float>(m_text.getFont()->getKerning(m_text.getString()[i - 1], m_text.getString()[i], m_text.getCharacterSize()));
		else
			x += static_cast<float>(m_text.getFont()->getKerning(0, m_text.getString()[i], m_text.getCharacterSize()));

		m_cursorShape.move(x , 0);
	}
}

const TextFieldModel* TextField::getModel() const
{
	return m_model;
}

void TextField::setModel(TextFieldModel* model)
{
	if (model != m_model && model != 0)
	{
		delete m_model;
		m_model = model;
	}
}

const sf::String& TextField::getText() const
{
	return m_text.getString();
}

void TextField::setText(const sf::String& text)
{
	m_text.setString(text);
	
	if (m_cursor > m_text.getString().getSize())
	{
	    m_cursor = m_text.getString().getSize();
	    updateCoord();
	}
}

const sf::Font* TextField::getFont() const
{
	return m_text.getFont();
}

void TextField::setFont(const sf::Font& font)
{
	m_text.setFont(font);
}

unsigned int TextField::getFontSize() const
{
	return m_text.getCharacterSize();
}

void TextField::setFontSize(unsigned int size)
{
	m_text.setCharacterSize(size);
}

sf::Color TextField::getFontColor() const
{
	return m_text.getColor();
}

void TextField::setFontColor(sf::Color color)
{
	m_text.setColor(color);
}

unsigned int TextField::getCursor() const
{
	return m_cursor;
}

void TextField::setCursor(unsigned int cursor)
{
	if (cursor <= m_text.getString().getSize())
		m_cursor = cursor;
}

int TextField::getMaxLength() const
{
	return m_maxLength;
}

void TextField::setMaxLength(int maxLength)
{
	m_maxLength = (maxLength > 0 ? maxLength : -1);
}

bool TextField::canBeEmpty() const
{
	return m_canBeEmpty;
}

void TextField::setCanBeEmpty(bool canBeEmpty)
{
	m_canBeEmpty = canBeEmpty;
}
