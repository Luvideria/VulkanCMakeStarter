//#define GLFW_INCLUDE_VULKAN
#include <vulkan/vulkan.h>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(){
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
    std::cout << "available extensions:\n";

    for (const auto& extension : extensions) {
        std::cout << '\t' << extension.extensionName << '\n';
    }
    
    std::cout<< std::endl << "If you got there, it's a good sign that Vulkan is correctly linked"<<std::endl;
    return 0;
}