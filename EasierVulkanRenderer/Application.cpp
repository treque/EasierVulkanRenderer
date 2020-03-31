#include "Application.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "Constants.h"
#include "Initializers.h"
#include "VulkanInstance.h"

void Application::run()
{
	initWindow();
	initVulkan();
	mainLoop();
	cleanup();
}

Application::Application(VulkanInstance* instance)
{
	m_instance = instance;
}

void Application::initWindow()
{
	glfwInit();

	// to not create OpenGL context
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	// to disable resizable window
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	// create a window
	m_window = glfwCreateWindow(Constants::WIDTH, Constants::HEIGHT, "Vulkan", nullptr, nullptr);

}

void Application::initVulkan()
{

}

void Application::mainLoop()
{
	while (!glfwWindowShouldClose(m_window))
	{
		glfwPollEvents(); // checks for events like pressing the x button
	}
}

void Application::cleanup()
{
	glfwDestroyWindow(m_window);
	
	glfwTerminate();
}

