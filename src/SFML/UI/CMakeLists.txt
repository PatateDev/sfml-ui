
set(INCROOT ${PROJECT_SOURCE_DIR}/include/SFML/UI)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/SFML/UI)

# all source files
set(SRC
    ${SRCROOT}/AbstractButton.cpp
    ${INCROOT}/AbstractButton.hpp
    ${SRCROOT}/Button.cpp
    ${INCROOT}/Button.hpp
    ${SRCROOT}/CheckBox.cpp
    ${INCROOT}/CheckBox.hpp
    ${SRCROOT}/CheckBoxGroup.cpp
    ${INCROOT}/CheckBoxGroup.hpp
    ${SRCROOT}/Component.cpp
    ${INCROOT}/Component.hpp
    ${INCROOT}/ComponentEvent.hpp
    ${SRCROOT}/ComponentObservable.cpp
    ${INCROOT}/ComponentObservable.hpp
    ${SRCROOT}/ComponentObserver.cpp
    ${INCROOT}/ComponentObserver.hpp
    ${SRCROOT}/Focusable.cpp
    ${INCROOT}/Focusable.hpp
    ${SRCROOT}/FormattedTextField.cpp
    ${INCROOT}/FormattedTextField.hpp
    ${SRCROOT}/IText.cpp
    ${INCROOT}/IText.hpp
    ${SRCROOT}/KeyField.cpp
    ${INCROOT}/KeyField.hpp
    ${SRCROOT}/Label.cpp
    ${INCROOT}/Label.hpp
    ${SRCROOT}/PasswordField.cpp
    ${INCROOT}/PasswordField.hpp
    ${SRCROOT}/SFMLUtils.cpp
    ${INCROOT}/SFMLUtils.hpp
    ${SRCROOT}/TextField.cpp
    ${INCROOT}/TextField.hpp
)
source_group("" FILES ${SRC})

# format sources
set(FORMAT_SRC
    ${SRCROOT}/Format/DoubleFormat.cpp
    ${INCROOT}/Format/DoubleFormat.hpp
    ${SRCROOT}/Format/Format.cpp
    ${INCROOT}/Format/Format.hpp
    ${SRCROOT}/Format/LongFormat.cpp
    ${INCROOT}/Format/LongFormat.hpp
    ${SRCROOT}/Format/UnsignedLongFormat.cpp
    ${INCROOT}/Format/UnsignedLongFormat.hpp
)
source_group("format" FILES ${FORMAT_SRC})

# model sources
set(MODEL_SRC
    ${SRCROOT}/Model/AlphaNumericTextFieldModel.cpp
    ${INCROOT}/Model/AlphaNumericTextFieldModel.hpp
    ${SRCROOT}/Model/AlphaTextFieldModel.cpp
    ${INCROOT}/Model/AlphaTextFieldModel.hpp
    ${SRCROOT}/Model/AsciiNoSpaceTextFieldModel.cpp
    ${INCROOT}/Model/AsciiNoSpaceTextFieldModel.hpp
    ${SRCROOT}/Model/AsciiTextFieldModel.cpp
    ${INCROOT}/Model/AsciiTextFieldModel.hpp
    ${SRCROOT}/Model/BlacklistTextFieldModel.cpp
    ${INCROOT}/Model/BlacklistTextFieldModel.hpp
    ${SRCROOT}/Model/DefaultTextFieldModel.cpp
    ${INCROOT}/Model/DefaultTextFieldModel.hpp
    ${SRCROOT}/Model/NumericTextFieldModel.cpp
    ${INCROOT}/Model/NumericTextFieldModel.hpp
    ${SRCROOT}/Model/TextFieldModel.cpp
    ${INCROOT}/Model/TextFieldModel.hpp
    ${SRCROOT}/Model/WhitelistTextFieldModel.cpp
    ${INCROOT}/Model/WhitelistTextFieldModel.hpp
)
source_group("model" FILES ${MODEL_SRC})

# find external libraries
find_package(SFML 2.2 COMPONENTS graphics window system REQUIRED)
if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML not found !")
endif()

include_directories(${SFML_INCLUDE_DIR})

# build the list of external libraries to link
list(APPEND UI_EXT_LIBS ${SFML_LIBRARIES})

# define the sfml-ui target
sfml_add_library(sfml-ui
                 SOURCES ${SRC} ${FORMAT_SRC} ${MODEL_SRC}
                 EXTERNAL_LIBS ${UI_EXT_LIBS})
