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

#include <SFML/UI/FormattedTextField.h>

using namespace sf::ui;

FormattedTextField::FormattedTextField(Format* format)
: TextField(),
  m_format(format)
{

}

FormattedTextField::FormattedTextField(sf::Texture const &texture, sf::Texture const &textureFocused, Format* format, sf::String const &text)
: TextField(texture, textureFocused, text),
  m_format(format)
{

}

FormattedTextField::FormattedTextField(sf::Texture const &texture, sf::Texture const &textureFocused, sf::Font const &font, Format* format, sf::String text)
: TextField(texture, textureFocused, font, text),
  m_format(format)
{

}

FormattedTextField::~FormattedTextField()
{
    if (m_format)
    {
        delete m_format;
    }
}

bool FormattedTextField::insertText(sf::Uint32 text, unsigned int index)
{    
    if (m_format)
    {
        sf::String string = m_text.getString();
	    string.insert(index, text);
	    
	    if (m_format->isAllowed(string))
	    {
	        return TextField::insertText(text, index);
	    }
	    else
	    {
	        return false;
	    }
	}
	else
	{
	    return TextField::insertText(text, index);
	}
}

bool FormattedTextField::deleteText(unsigned int index)
{
    if (m_format)
    {
        sf::String string = m_text.getString();
	    string.erase(index);
	    
	    if (m_format->isAllowed(string))
	    {
	        return TextField::deleteText(index);
	    }
	    else
	    {
	        return false;
	    }
	}
	else
	{
	    return TextField::deleteText(index);
	}
}

const void* FormattedTextField::getValue() const
{
    if (m_format)
    {
        return m_format->getValue();
    }
    else
    {
        return 0;
    }
}

void FormattedTextField::setValue(void* value)
{
    if (m_format)
    {
        m_format->setValue(value);
        setText(m_format->toString());
    }
}

const Format* FormattedTextField::getFormat() const
{
    return m_format;
}
    
void FormattedTextField::setFormat(Format *format)
{
    if (m_format != format)
    {
        if (!m_format)
        {
            delete m_format;
            m_format = 0;
        }
        
        m_format = format;
    }
}

void FormattedTextField::setText(sf::String const &text)
{
    if (m_format)
    {
        m_format->parse(text);
        TextField::setText(m_format->toString());
        
        if (text == "")
        {
            m_cursor = m_text.getString().getSize();
        }
    }
    else
    {
        TextField::setText(text);
    }
}
