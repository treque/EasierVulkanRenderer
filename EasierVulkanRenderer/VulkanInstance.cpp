#include "VulkanInstance.h"

//#include "Validation.h"
#include "Initializers.h"

#include <iostream>

VulkanInstance::VulkanInstance(VulkanConfiguration& vulkan_config)
{
	// validation
	//layers.push_back("VK_LAYER_LUNARG_standard_validation");
	//extensions.push_back("VK_EXT_debug_utils_extension");

	VkApplicationInfo application_info = Initializers::ApplicationInfo(vulkan_config);

	VkInstanceCreateInfo instance_info = Initializers::InstanceCreateInfo(application_info, layers, extensions);

	if (vkCreateInstance(&instance_info, NULL, &instance) != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create instance");
	}
}

VulkanInstance::~VulkanInstance()
{
	vkDestroyInstance(instance, NULL);
}

VkInstance& VulkanInstance::GetInstance()
{
	return instance;
}
