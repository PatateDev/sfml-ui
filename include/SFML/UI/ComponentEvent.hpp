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

#ifndef COMPONENT_EVENT_H_
#define COMPONENT_EVENT_H_

#include <SFML/Window.hpp>
#include <SFML/UI/Format/Format.hpp>

#include <SFML/UI/Component.hpp>
#include <SFML/UI/Focusable.hpp>
#include <SFML/UI/AbstractButton.hpp>
#include <SFML/UI/CheckBox.hpp>
#include <SFML/UI/TextField.hpp>
#include <SFML/UI/FormattedTextField.hpp>
#include <SFML/UI/KeyField.hpp>

namespace sf
{
namespace ui
{

class ComponentEvent
{
public:
	////////////////////////////////////////////////////////////
	///
	/// \brief An event that is triggered each time a button is fired
	///
	////////////////////////////////////////////////////////////
	struct ButtonClickedEvent
	{
		AbstractButton* 	source;
		sf::Mouse::Button	button;
		int 			x;
		int			y;
	};

	////////////////////////////////////////////////////////////
	///
	/// \brief An event that is triggered each time a button is fired, touched (on mobile OSs)
	///
	////////////////////////////////////////////////////////////
	struct ButtonTouchedEvent
	{
		AbstractButton*		source;
		unsigned int		finger;
		int			x;
		int			y;
	};

	////////////////////////////////////////////////////////////
    	///
    	/// \brief An event that is triggered each time a check box switch from unselected to selected, and vice-versa
    	///
    	////////////////////////////////////////////////////////////
	struct CheckBoxChangeEvent
	{
		CheckBox*		source;
		bool			selected;
	};


	////////////////////////////////////////////////////////////
    	///
    	/// \brief An event that is triggered each time a component change its focus status
	///
    	////////////////////////////////////////////////////////////
	struct FocusedEvent
	{
		Focusable*		source;
		bool			focused;
	};

	////////////////////////////////////////////////////////////
   	///
    	/// \brief An event related to a formatted value entered (e.g on sf::ui::FormattedTextField)
    	///
	////////////////////////////////////////////////////////////
	struct FormattedValueEnteredEvent
	{
		FormattedTextField*	source;
		Format*			format;
	};

	////////////////////////////////////////////////////////////
    	///
    	/// \brief An event that is triggered each time a key is set
   	/// Triggered only with KeyField
    	///
    	////////////////////////////////////////////////////////////
	struct KeyFieldSetEvent
	{
		KeyField*		source;
		sf::Keyboard::Key	key;
	};

	////////////////////////////////////////////////////////////
   	///
    	/// \brief An event that is triggered each time a text is entered/deleted
    	/// Triggered only with TextField
   	///
    	////////////////////////////////////////////////////////////
	struct TextEvent
	{
		TextField*		source;
		sf::Uint32		text;
		unsigned int		position;
	};

	////////////////////////////////////////////////////////////
	///
	/// \brief Enumeration of component events
	///
	////////////////////////////////////////////////////////////
	enum ComponentEventType
	{
		ButtonClicked,
		ButtonTouched,
		CheckBoxChanged,
		FocusGained,
		FocusLost,
		FormattedValueEntered,
		KeyFieldSet,
		TextEntered,
		TextDeleted
	};

	ComponentEventType type;
	Component* source;

	union
	{
		ButtonClickedEvent		buttonClick;
		ButtonTouchedEvent		buttonTouch;
		CheckBoxChangeEvent		checkBoxChange;
		FocusedEvent			focus;
		FormattedValueEnteredEvent	formattedValueEnter;
		KeyFieldSetEvent		keyFieldSet;
		TextEvent			text;
	};

};


}
}

#endif

////////////////////////////////////////////////////////////
///
/// \class sf::ui::ComponentEvent
/// \brief An event generate by a component
/// \ingroup ui
///
////////////////////////////////////////////////////////////
