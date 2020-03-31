#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>

#include "Application.h"
#include "VulkanConfiguration.h"
#include "VulkanInstance.h"


const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

VulkanInstance* instance;

int main()
{

	VulkanConfiguration vulkan_config;
	vulkan_config.application_name = "Vulkan Renderer";
	vulkan_config.application_version = VK_MAKE_VERSION(1, 0, 0);

	instance = new VulkanInstance(vulkan_config);

	Application app(instance);

	try
	{
		app.run();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}