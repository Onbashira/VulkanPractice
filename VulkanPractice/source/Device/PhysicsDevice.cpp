#include "PhysicsDevice.h"



PhysicsDevice::PhysicsDevice()
{
}


PhysicsDevice::~PhysicsDevice()
{
}

VkResult PhysicsDevice::Initialize(VkInstance * instance)
{
	InitializePhysicalDevice(instance);
	if (!InitializePhysicalDevice(instance)) {
		return VkResult::VK_SUCCESS;
	}
	InitializeMemProps();
	InitializeQueueFamilyProps();

	return VkResult::VK_SUCCESS;
}

const VkPhysicalDevice * PhysicsDevice::GetDevicePtr(int index) const
{
	return &_device[index];
}

const VkPhysicalDeviceMemoryProperties * PhysicsDevice::GetMemPropPtr(int index) const
{
	return &_memoryProps[index];
}

std::vector<VkQueueFamilyProperties>& PhysicsDevice::GetQueueFamilyProps(int index)
{
	return _queueFamilyProps[index];
}

int PhysicsDevice::GetDeviceCount() const
{
	return _device.size();
}

int PhysicsDevice::GetDeviceQueueIndex(int deviceIndex, VkQueueFlagBits bits)
{
	//キューインデックスの取得
	if (deviceIndex > this->_queueFamilyProps.size()) {
		return -1;
	}
	for (int i = 0; i < _queueFamilyProps[deviceIndex].size(); ++i)
	{
		if (_queueFamilyProps[deviceIndex][i].queueFlags & bits)
		{
			return 1;
		}
	}
}

VkResult PhysicsDevice::InitializePhysicalDevice(VkInstance * instance)
{

	unsigned int devCount = 0;
	//デバイス数問い合わせ
	auto vkr = vkEnumeratePhysicalDevices(*instance, &devCount, nullptr);
	if (vkr != VkResult::VK_SUCCESS)
	{
		return vkr;
	}
	_device.resize(devCount);
	//デバイス取得
	vkr = vkEnumeratePhysicalDevices(*instance, &devCount, _device.data());
	if (vkr != VkResult::VK_SUCCESS)
	{
		return vkr;
	}


	return vkr;
}

void PhysicsDevice::InitializeMemProps()
{
	//各デバイスのメモリ情報の収集
	_memoryProps.resize(_device.size());
	for (int i = 0; i < _device.size(); ++i)
	{
		vkGetPhysicalDeviceMemoryProperties(_device[i], &_memoryProps[i]);
	}
}

void PhysicsDevice::InitializeQueueFamilyProps()
{
	//QueueFamilyの取得

	unsigned int propCount = 0;
	for (int i = 0; i < _device.size(); ++i)
	{
		//キューファミリの数の取得
		vkGetPhysicalDeviceQueueFamilyProperties(_device[i], &propCount, nullptr);
		_queueFamilyProps[i].resize(propCount);
		//取得
		vkGetPhysicalDeviceQueueFamilyProperties(_device[i], &propCount, _queueFamilyProps[i].data());
	}
}
