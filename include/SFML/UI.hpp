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

#ifndef UI_HPP_
#define UI_HPP_

#define SFML_UI_VERSION_MAJOR 0
#define SFML_UI_VERSION_MINOR 3
#define SFML_UI_VERSION_PATCH 1
#define SFML_UI_VERSION_REVISION SFML_UI_VERSION_PATCH

#include <SFML/Graphics.hpp>

#include <SFML/UI/Component.h>
#include <SFML/UI/ComponentObservable.h>
#include <SFML/UI/ComponentObserver.h>
#include <SFML/UI/Label.h>
#include <SFML/UI/Focusable.h>
#include <SFML/UI/AbstractButton.h>
#include <SFML/UI/Button.h>
#include <SFML/UI/CheckBox.h>
#include <SFML/UI/KeyField.h>
#include <SFML/UI/TextField.h>
#include <SFML/UI/CheckBoxGroup.h>
#include <SFML/UI/PasswordField.h>
#include <SFML/UI/FormattedTextField.h>

#include <SFML/UI/Event/ComponentEvent.h>
#include <SFML/UI/Event/FocusedEvent.h>
#include <SFML/UI/Event/ButtonClickedEvent.h>
#include <SFML/UI/Event/KeyfieldSetEvent.h>
#include <SFML/UI/Event/TextEnteredEvent.h>
#include <SFML/UI/Event/TextDeletedEvent.h>
#include <SFML/UI/Event/CheckBoxChangeEvent.h>
#include <SFML/UI/Event/FormattedValueEnteredEvent.h>

#include <SFML/UI/Model/TextFieldModel.h>
#include <SFML/UI/Model/BlacklistTextFieldModel.h>
#include <SFML/UI/Model/DefaultTextFieldModel.h>
#include <SFML/UI/Model/WhitelistTextFieldModel.h>
#include <SFML/UI/Model/AlphaNumericTextFieldModel.h>
#include <SFML/UI/Model/AsciiTextFieldModel.h>
#include <SFML/UI/Model/AsciiNoSpaceTextFieldModel.h>
#include <SFML/UI/Model/NumericTextFieldModel.h>

#include <SFML/UI/Format/Format.h>
#include <SFML/UI/Format/LongFormat.h>
#include <SFML/UI/Format/UnsignedLongFormat.h>
#include <SFML/UI/Format/DoubleFormat.h>
#include <SFML/UI/Format/Sequence.h>
#include <SFML/UI/Format/LongSequence.h>
#include <SFML/UI/Format/UnsignedLongSequence.h>

#endif /* UI_HPP_ */

////////////////////////////////////////////////////////////
///\file UI.hpp
///\ingroup ui
///\brief Main header which include all UI's header
////////////////////////////////////////////////////////////
