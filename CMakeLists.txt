cmake_minimum_required(VERSION 3.10)
project(wxCheckboxThemeTest)

set(wxWidgets_ROOT_DIR "c:/cpp/cppLibraries/wxWidgets_static")
set(wxWidgets_LIB_DIR "${wxWidgets_ROOT_DIR}/lib/gcc_x64_lib")
set(wxWidgets_CONFIGURATION "mswu")
set(wxWidgets_INCLUDE_DIRS 
    "${wxWidgets_ROOT_DIR}/include/wx/msw" 
    "${wxWidgets_LIB_DIR}mswu/" 
    "${CMAKE_SOURCE_DIR}"
)

set (CMAKE_CXX_FLAGS "-mwindows")

set(SOURCE_FILES
    src/main.cpp
    src/wxCheckboxThemeTest.cpp
    src/app.manifest
    ../wxThemer/src/wxThemer.cpp
    ../wxThemer/src/wxThemerCheckBox.cpp
)

find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

include_directories(${PROJECT_SOURCE_DIR}/../wxThemer/include ${PROJECT_SOURCE_DIR}/include)

add_executable(wxCheckboxThemeTest ${SOURCE_FILES})

target_link_libraries(wxCheckboxThemeTest ${wxWidgets_LIBRARIES} dwmapi)

# Assuming you are using MSYS2/MinGW or Visual Studio:
if (WIN32)
    add_custom_command(TARGET wxCheckboxThemeTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E
            env "PATH=$ENV{PATH}"
            mt.exe -manifest \"${CMAKE_SOURCE_DIR}/src/app.manifest\" -outputresource:\"$<TARGET_FILE:${PROJECT_NAME}>\";
        COMMENT "Embedding manifest..."
    )
endif()