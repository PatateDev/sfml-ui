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

#include <SFML/UI/SFMLUtils.h>

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
