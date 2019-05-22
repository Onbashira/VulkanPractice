#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <vulkan/vk_layer.h>
#include <vulkan/vulkan_win32.h>
#include <vulkan/vulkan.h>

#pragma comment(lib,"vulkan-l.lib")

class VulkanAppBase
{
public:
	VulkanAppBase();
	virtual ~VulkanAppBase();

	bool Initialize(GLFWwindow* wnd,const char* appName);
	void Terminate();
	virtual void Prepare();
	virtual void Render();
protected:
	void DebugLayerInit();

};

