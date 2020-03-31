#pragma once

class GLFWwindow;
class VulkanInstance;

class Application
{
public:
	void run();
	Application(VulkanInstance* instance);

private:

	GLFWwindow* m_window = nullptr; // a declarer global?
	VulkanInstance* m_instance;

	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();
};