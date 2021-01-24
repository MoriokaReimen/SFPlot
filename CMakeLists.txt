cmake_minimum_required(VERSION 3.0)
project(SFPlot)

###################################################################
# Option Setting
option(ENABLE_SAMPLE "build sample program.(Default:OFF)" OFF)
option(ENABLE_DOC "build Doxygen Doc.(Default:OFF)" OFF)

###################################################################
# import SFML library
find_package(SFML 2.5.1 COMPONENTS system window graphics)
if (SFML_FOUND)
    message(STATUS "SFML found.")
    message(STATUS "SFML_INCLUDE_DIRS: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
else()
    message(STATUS "SFML is not found in the system")
    message(STATUS "Assume SFML is contained in build structure.")
endif ()

###################################################################
# Configure document generation
if(ENABLE_DOC)
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile.in)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
endif(ENABLE_DOC)

###################################################################
# Configure general build settings
set(CMAKE_CXX_STANDARD 17)

###################################################################
# Configure build for SFGraphing library
file(GLOB SFPLOT_SRC src/*.cpp)
add_library(SFPlot STATIC ${SFPLOT_SRC} )
target_link_libraries(SFPlot PUBLIC sfml-graphics sfml-window sfml-system)
target_include_directories(SFPlot PUBLIC include/)

###################################################################
# Configure build for Sample program
if(ENABLE_SAMPLE)
file(GLOB SAMPLE_SRC sample/*.cpp)
add_executable(plot ${SAMPLE_SRC})
target_link_libraries(plot SFPlot)
endif()
