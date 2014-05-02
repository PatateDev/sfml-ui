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
#include <SFML/UI/Event/FormattedValueEnteredEvent.h>

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

void FormattedTextField::lostFocus()
{
    TextField::lostFocus();
    
    updateValue();
}

void FormattedTextField::updateValue()
{
    if (m_format)
    {
        m_format->parse(getText());
        setText(m_format->toString());
        
        FormattedValueEnteredEvent event(this, *m_format, m_format->getValue());
        triggerEvent(event);
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
        
        FormattedValueEnteredEvent event(this, *m_format, m_format->getValue());
        triggerEvent(event);
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
