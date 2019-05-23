#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <map>

class PhysicalDevice;
class LogicalDevice
{
public:

private:
	VkDevice _device;
public:
	LogicalDevice();
	~LogicalDevice();
	VkResult Initialize(PhysicalDevice* pPhysicalDevice);
};

