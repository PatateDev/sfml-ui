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

#include <SFML/UI/PasswordField.hpp>
#include <SFML/UI/Model/AsciiNoSpaceTextFieldModel.hpp>

using namespace sf::ui;

PasswordField::PasswordField()
: TextField(), m_password()
{
    setModel(new AsciiNoSpaceTextFieldModel);
}

PasswordField::PasswordField(sf::Texture const &texture, sf::Texture const &textureFocused)
: TextField(texture, textureFocused), m_password()
{
    setModel(new AsciiNoSpaceTextFieldModel);
}

PasswordField::PasswordField(sf::Texture const &texture, sf::Texture const &textureFocused, sf::Font const &font)
: TextField(texture, textureFocused, font), m_password()
{
    setModel(new AsciiNoSpaceTextFieldModel);
}

PasswordField::~PasswordField()
{

}
	
bool PasswordField::insertText(sf::Uint32 text, unsigned int index)
{
    if (TextField::insertText(text, index))
    {
        m_password.insert(index, text);
        replaceTextDisplayed();
        return true;
    }
    else
    {
        return false;
    }
}
	
bool PasswordField::deleteText(unsigned int index)
{
    if (TextField::deleteText(index))
    {
        m_password.erase(index);
        replaceTextDisplayed();
        return true;
    }
    else
    {
        return false;
    }
}
	
void PasswordField::replaceTextDisplayed()
{
    sf::String text;
    
    for (size_t i = 0; i < m_password.getSize(); i++)
    {
        text.insert(i, sf::String(L"•"));
    }
    
    m_text.setString(text);
}

const sf::String& PasswordField::getPassword() const
{
    return m_password;
}

void PasswordField::setPassword(sf::String const &password)
{
    m_password = password;
    replaceTextDisplayed();
}
