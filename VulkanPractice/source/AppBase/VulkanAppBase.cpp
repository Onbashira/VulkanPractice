#include "VulkanAppBase.h"
#include <vector>


VulkanAppBase::VulkanAppBase()
{
}


VulkanAppBase::~VulkanAppBase()
{
}

bool VulkanAppBase::Initialize(GLFWwindow * wnd, const char * appName)
{
	return false;
}

void VulkanAppBase::Terminate()
{
}

void VulkanAppBase::Prepare()
{
}

void VulkanAppBase::Render()
{
}

void VulkanAppBase::DebugLayerInit()
{
	const char* appName = "Hello Vulkan";
	std::vector<const char*> extensions;

	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = appName;
	appInfo.pEngineName = appName;
	appInfo.apiVersion = VK_API_VERSION_1_1;
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);

	//レイヤ、検証レイヤの有効化
	const char* layers[] = { "VK_LAYER_LUNARG_standard_validation" };


}
