cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(MyProject)

add_subdirectory(libs)
find_package(Vulkan REQUIRED)

### You need this section and what is above for your project. The rest is for individual checking. ###
### Don't forget that there is a CMakeLists.txt in libs ! ###

set( SOURCE_FILE src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_include_directories(${PROJECT_NAME} PRIVATE ${Vulkan_INCLUDE_DIRS} libs/glfw/include)
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan glm glfw)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)

# /-- ###  DELETE BELOW FOR YOUR OWN PROJECT  ### \-- #

### TEST VULKAN is correctly linked ###
project(VulkanTest)
add_executable(${PROJECT_NAME} src/checkVulkan.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan )


### TEST GLFW is correctly linked ###
project(GLFWTest)
add_executable(${PROJECT_NAME} src/checkGLFW.cpp)
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE libs/glfw/include)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)

### TEST GLM is correctly linked ###
project(GLMTest)
add_executable(${PROJECT_NAME} src/checkGLM.cpp)
target_link_libraries(${PROJECT_NAME} glm)

### GLFW and Vulkan!
project(GLFWVulkanTest)
add_executable(${PROJECT_NAME} src/checkGLMVulkan.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE libs/glfw/include)
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE)