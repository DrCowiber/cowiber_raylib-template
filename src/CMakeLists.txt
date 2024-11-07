file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS *.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS *.hpp)
file(GLOB_RECURSE LIB_CPP CONFIGURE_DEPENDS ../global-includes/imgui/*.cpp ../global-includes/rlimgui/*.cpp)

target_include_directories(${PROJECT_NAME}
	PUBLIC ../global-includes/imgui_BACKENDS
	PUBLIC ../global-includes/imgui
	PUBLIC ../global-includes/rlimgui
)


target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES} ${LIB_HEADERS} ${LIB_CPP})