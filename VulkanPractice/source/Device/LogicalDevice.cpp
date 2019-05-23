#include "LogicalDevice.h"



LogicalDevice::LogicalDevice()
{
}


LogicalDevice::~LogicalDevice()
{
}

VkResult LogicalDevice::Initialize(PhysicalDevice* pPhysicalDevice)
{

	VkDeviceCreateInfo dci = {};
	dci.sType = VkStructureType::VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	dci.pNext = nullptr;


	return VkResult();
}
