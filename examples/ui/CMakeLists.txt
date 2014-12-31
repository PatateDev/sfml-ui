
set(SRCROOT ${PROJECT_SOURCE_DIR}/examples/ui)

# all source files
set(SRC ${SRCROOT}/Main.cpp ${SRCROOT}/Listener.cpp ${SRCROOT}/Listener.hpp)

# define the pong target
sfml_add_example(ui GUI_APP
                 SOURCES ${SRC}
                 DEPENDS sfml-ui sfml-graphics sfml-window sfml-system)
