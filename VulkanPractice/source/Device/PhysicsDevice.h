#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <map>

class PhysicsDevice
{
private:

	std::vector<VkPhysicalDevice> _device;
	std::vector<VkPhysicalDeviceMemoryProperties> _memoryProps;
	std::map<int,std::vector<VkQueueFamilyProperties>> _queueFamilyProps;


public:
	PhysicsDevice();
	~PhysicsDevice();

	VkResult Initialize(VkInstance* instance);
	const VkPhysicalDevice * GetDevicePtr(int index = 0)const;
	const VkPhysicalDeviceMemoryProperties * GetMemPropPtr(int index = 0)const;
	std::vector<VkQueueFamilyProperties>& GetQueueFamilyProps(int index = 0);

	int  GetDeviceCount()const;

	int GetDeviceQueueIndex(int deviceIndex, VkQueueFlagBits bits);

private:

	VkResult InitializePhysicalDevice(VkInstance* instance);
	void InitializeMemProps();
	void InitializeQueueFamilyProps();

};

