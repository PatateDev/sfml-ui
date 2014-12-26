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

#include <SFML/UI/SFMLUtils.hpp>

using namespace sf::ui;

SFMLUtils::SFMLUtils()
{

}

SFMLUtils::~SFMLUtils()
{


}

//From http://en.sfml-dev.org/forums/index.php?topic=7174
sf::Vector2f SFMLUtils::getLocalSize(const sf::Text& text)
{
	if (text.getFont() == 0)
		return sf::Vector2f(0, 0);

    const sf::String str = text.getString() + '\n';

    float maxLineWidth = 0.f;
    float lineWidth = 0.f;
    unsigned int lines = 0;

    for (sf::String::ConstIterator itr = str.begin(); itr != str.end(); ++itr)
    {
        if (*itr == '\n')
        {
            ++lines;
            maxLineWidth = std::max(maxLineWidth, lineWidth);
            lineWidth = 0.f;
        }
        else
        {
            lineWidth += text.getFont()->getGlyph(*itr, text.getCharacterSize(), text.getStyle() & sf::Text::Bold).advance;
        }
    }

    const float lineHeight = static_cast<float>(text.getFont()->getLineSpacing(text.getCharacterSize()));
    return sf::Vector2f(maxLineWidth, lines * lineHeight);
}

sf::String SFMLUtils::keyToString(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::A:
		return "A";
	case sf::Keyboard::B:
		return "B";
	case sf::Keyboard::C:
		return "C";
	case sf::Keyboard::D:
		return "D";
	case sf::Keyboard::E:
		return "E";
	case sf::Keyboard::F:
		return "F";
	case sf::Keyboard::G:
		return "G";
	case sf::Keyboard::H:
		return "H";
	case sf::Keyboard::I:
		return "I";
	case sf::Keyboard::J:
		return "J";
	case sf::Keyboard::K:
		return "K";
	case sf::Keyboard::L:
		return "L";
	case sf::Keyboard::M:
		return "M";
	case sf::Keyboard::N:
		return "N";
	case sf::Keyboard::O:
		return "O";
	case sf::Keyboard::P:
		return "P";
	case sf::Keyboard::Q:
		return "Q";
	case sf::Keyboard::R:
		return "R";
	case sf::Keyboard::S:
		return "S";
	case sf::Keyboard::T:
		return "T";
	case sf::Keyboard::U:
		return "U";
	case sf::Keyboard::V:
		return "V";
	case sf::Keyboard::W:
		return "W";
	case sf::Keyboard::X:
		return "X";
	case sf::Keyboard::Y:
		return "Y";
	case sf::Keyboard::Z:
		return "Z";
	case sf::Keyboard::Num0:
		return "0";
	case sf::Keyboard::Num1:
		return "1";
	case sf::Keyboard::Num2:
		return "2";
	case sf::Keyboard::Num3:
		return "3";
	case sf::Keyboard::Num4:
		return "4";
	case sf::Keyboard::Num5:
		return "5";
	case sf::Keyboard::Num6:
		return "6";
	case sf::Keyboard::Num7:
		return "7";
	case sf::Keyboard::Num8:
		return "8";
	case sf::Keyboard::Num9:
		return "9";
	case sf::Keyboard::Numpad0:
		return "N0";
	case sf::Keyboard::Numpad1:
		return "N1";
	case sf::Keyboard::Numpad2:
		return "N2";
	case sf::Keyboard::Numpad3:
		return "N3";
	case sf::Keyboard::Numpad4:
		return "N4";
	case sf::Keyboard::Numpad5:
		return "N5";
	case sf::Keyboard::Numpad6:
		return "N6";
	case sf::Keyboard::Numpad7:
		return "N7";
	case sf::Keyboard::Numpad8:
		return "N8";
	case sf::Keyboard::Numpad9:
		return "N9";
	case sf::Keyboard::Up:
		return "Up";
	case sf::Keyboard::Down:
		return "Down";
	case sf::Keyboard::Left:
		return "Left";
	case sf::Keyboard::Right:
		return "Right";
	case sf::Keyboard::RAlt:
		return "rAlt";
	case sf::Keyboard::RControl:
		return "rCtrl";
	case sf::Keyboard::RShift:
		return "rShift";
	case sf::Keyboard::LAlt:
		return "Alt";
	case sf::Keyboard::LControl:
		return "Ctrl";
	case sf::Keyboard::LShift:
		return "Shift";
	case sf::Keyboard::Space:
		return "Space";
	case sf::Keyboard::Menu:
		return "Menu";
	case sf::Keyboard::Tab:
		return "Tab";
	case sf::Keyboard::Escape:
		return "Esc";
	case sf::Keyboard::Tilde:
		return "~";
	case sf::Keyboard::LBracket:
		return "[";
	case sf::Keyboard::RBracket:
		return "]";
	case sf::Keyboard::Add:
		return "+";
	case sf::Keyboard::Subtract:
		return "-";
	case sf::Keyboard::Multiply:
		return "*";
	case sf::Keyboard::Divide:
		return "/";
	case sf::Keyboard::Equal:
		return "=";
	case sf::Keyboard::Dash:
		return "-";
	case sf::Keyboard::BackSpace:
		return "Back";
	case sf::Keyboard::Return:
		return "Return";
	case sf::Keyboard::Slash:
		return "/";
	case sf::Keyboard::BackSlash:
		return "\\";
	case sf::Keyboard::Comma:
		return ",";
	case sf::Keyboard::SemiColon:
		return ";";
	case sf::Keyboard::Period:
		return ".";
	case sf::Keyboard::Quote:
		return  "'";
	case sf::Keyboard::PageUp:
		return "PgUp";
	case sf::Keyboard::PageDown:
		return "PgDown";
	case sf::Keyboard::Insert:
		return "Insert";
	case sf::Keyboard::Delete:
		return "Del";
	case sf::Keyboard::Home:
		return "Home";
	case sf::Keyboard::End:
		return "End";
	case sf::Keyboard::F1:
		return "F1";
	case sf::Keyboard::F2:
		return "F2";
	case sf::Keyboard::F3:
		return "F3";
	case sf::Keyboard::F4:
		return "F4";
	case sf::Keyboard::F5:
		return "F5";
	case sf::Keyboard::F6:
		return "F6";
	case sf::Keyboard::F7:
		return "F7";
	case sf::Keyboard::F8:
		return "F8";
	case sf::Keyboard::F9:
		return "F9";
	case sf::Keyboard::F10:
		return "F10";
	case sf::Keyboard::F11:
		return "F11";
	case sf::Keyboard::F12:
		return "F12";
	case sf::Keyboard::F13:
		return "F13";
	case sf::Keyboard::F14:
		return "F14";
	case sf::Keyboard::F15:
		return "F15";
	default:
		return "";
	}
}
