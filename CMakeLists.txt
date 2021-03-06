cmake_minimum_required(VERSION 3.15)

project(Diceling CXX)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)
set(CMAKE_INSTALL_RPATH $ORIGIN)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS   ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(CHIRA_BUILD_TESTS           OFF CACHE BOOL "" FORCE)
set(CHIRA_BUILD_WITH_WARNINGS   OFF CACHE BOOL "" FORCE)
set(CHIRA_BUILD_EDITOR          OFF CACHE BOOL "" FORCE)
set(CHIRA_BUILD_MODEL_VIEWER    OFF CACHE BOOL "" FORCE)
set(CHIRA_BUILD_WITH_STEAMWORKS OFF CACHE BOOL "" FORCE)
add_subdirectory("${CMAKE_SOURCE_DIR}/libs/chiraEngine/")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "..." FORCE)
endif()

if(UNIX)
	set(QT_INCLUDE "/usr/include/x86_64-linux-gnu/qt5")
elseif(WIN32)
	# On Windows, the install dir must be specified, as it's not standardized
	if(DEFINED QT_BASEDIR)
		# Add it to the prefix path so find_package can find it
		list(APPEND CMAKE_PREFIX_PATH ${QT_BASEDIR})
		set(QT_INCLUDE ${QT_BASEDIR}/include)
		# CMake has an odd policy that links a special link lib for Qt on newer versions of CMake. Enable it so we don't get spammed, and I get to write less
		cmake_policy(SET CMP0020 NEW)
	else()
		message(FATAL_ERROR "--!@ Please define your QT install dir with -DQT_BASEDIR=C:/your/qt5/here")
	endif()
endif()	

message("Using ${QT_INCLUDE} as our Qt include dir")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(SRC
		# Dialogs
		dialogs/DicelingMainWindow.cpp
		dialogs/DicelingMainWindow.h
		dialogs/DicelingConfigHandler.cpp
		dialogs/DicelingConfigHandler.h
		dialogs/DicelingConfig.cpp
		dialogs/DicelingConfig.h
		# Widgets
		widgets/ChiraOpenGLWidget.cpp
		widgets/ChiraOpenGLWidget.h
		# Main
		Diceling.cpp
		)


configure_file("${CMAKE_CURRENT_SOURCE_DIR}/configs/config_defaults.json" "${CMAKE_BINARY_DIR}/configs/config_defaults.json")
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Network)

set(APP_ICON_RESOURCE_WINDOWS ${CMAKE_CURRENT_SOURCE_DIR}/res/appicon.rc)

if(UNIX)
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/libs/Qt/libQt5Core.so.5.15.2" "${CMAKE_BINARY_DIR}/libQt5Core.so" COPYONLY)
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/libs/Qt/libQt5Gui.so.5.15.2" "${CMAKE_BINARY_DIR}/libQt5Gui.so" COPYONLY)
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/libs/Qt/libQt5Widgets.so.5.15.2" "${CMAKE_BINARY_DIR}/libQt5Widgets.so" COPYONLY)
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/libs/Qt/libQt5Network.so.5.15.2" "${CMAKE_BINARY_DIR}/libQt5Network.so" COPYONLY)
	
	set(STEAM_API  "${CMAKE_CURRENT_SOURCE_DIR}/libs/Steam-Workshop-API/sdk/redistributable_bin/linux64/libsteam_api.so")
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/libs/Steam-Workshop-API/sdk/redistributable_bin/linux64/libsteam_api.so" "${CMAKE_BINARY_DIR}/libsteam_api.so" COPYONLY)
elseif(WIN32)
	# MinGW doesn't like this, but the steam api DLL is incompatible with it anyway
	set(STEAM_API  "${CMAKE_CURRENT_SOURCE_DIR}/libs/Steam-Workshop-API/sdk/redistributable_bin/win64/steam_api64.lib")
	configure_file("${CMAKE_CURRENT_SOURCE_DIR}/libs/Steam-Workshop-API/sdk/redistributable_bin/win64/steam_api64.dll" "${CMAKE_BINARY_DIR}/steam_api64.dll" COPYONLY)
endif()

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Credits.txt" "${CMAKE_BINARY_DIR}/Credits.txt" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/json/adjectives.json" "${CMAKE_BINARY_DIR}/json/adjectives.json" COPYONLY)

add_executable(${PROJECT_NAME} ${SRC} res/zoo_textures.qrc libs/theme/breeze.qrc ${APP_ICON_RESOURCE_WINDOWS})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Network ${STEAM_API} ChiraEngine ${OPENGL_LIBRARIES})

add_custom_target(copyEngineResources ALL
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/libs/chiraEngine/resources/engine/
		${CMAKE_BINARY_DIR}/resources/engine/)
add_dependencies(${PROJECT_NAME} copyEngineResources)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE "${QT_INCLUDE} ${QT_INCLUDE}/QtWidgets" "${QT_INCLUDE}/QtGui" "${QT_INCLUDE}/QtCore" "${QT_INCLUDE}/QtNetwork")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/libs/Steam-Workshop-API/sdk/public/steam")

if(WIN32)
	# Copy these to bundle them with the program in releases
	set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
	configure_file("${QT_BASEDIR}/bin/Qt5Core.dll"    "${CMAKE_BINARY_DIR}/Qt5Core.dll"    COPYONLY)
	configure_file("${QT_BASEDIR}/bin/Qt5Gui.dll"     "${CMAKE_BINARY_DIR}/Qt5Gui.dll"     COPYONLY)
	configure_file("${QT_BASEDIR}/bin/Qt5Widgets.dll" "${CMAKE_BINARY_DIR}/Qt5Widgets.dll" COPYONLY)
	configure_file("${QT_BASEDIR}/bin/Qt5Network.dll" "${CMAKE_BINARY_DIR}/Qt5Network.dll" COPYONLY)
	configure_file("${QT_BASEDIR}/plugins/platforms/qwindows.dll"         "${CMAKE_BINARY_DIR}/platforms/qwindows.dll"         COPYONLY)
	configure_file("${QT_BASEDIR}/plugins/platforms/qwindowsd.dll"        "${CMAKE_BINARY_DIR}/platforms/qwindowsd.dll"        COPYONLY)
endif()
