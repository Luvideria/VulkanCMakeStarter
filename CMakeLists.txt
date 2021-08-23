cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(MyProject)

add_subdirectory(libs)
find_package(Vulkan REQUIRED)

set( SOURCE_FILE src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_include_directories(${PROJECT_NAME} PRIVATE ${Vulkan_INCLUDE_DIRS} libs/glfw/include)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glm glfw stb)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)
