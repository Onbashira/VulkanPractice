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
	//�L���[�C���f�b�N�X�̎擾
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
	//�f�o�C�X���₢���킹
	auto vkr = vkEnumeratePhysicalDevices(*instance, &devCount, nullptr);
	if (vkr != VkResult::VK_SUCCESS)
	{
		return vkr;
	}
	_device.resize(devCount);
	//�f�o�C�X�擾
	vkr = vkEnumeratePhysicalDevices(*instance, &devCount, _device.data());
	if (vkr != VkResult::VK_SUCCESS)
	{
		return vkr;
	}


	return vkr;
}

void PhysicsDevice::InitializeMemProps()
{
	//�e�f�o�C�X�̃��������̎��W
	_memoryProps.resize(_device.size());
	for (int i = 0; i < _device.size(); ++i)
	{
		vkGetPhysicalDeviceMemoryProperties(_device[i], &_memoryProps[i]);
	}
}

void PhysicsDevice::InitializeQueueFamilyProps()
{
	//QueueFamily�̎擾

	unsigned int propCount = 0;
	for (int i = 0; i < _device.size(); ++i)
	{
		//�L���[�t�@�~���̐��̎擾
		vkGetPhysicalDeviceQueueFamilyProperties(_device[i], &propCount, nullptr);
		_queueFamilyProps[i].resize(propCount);
		//�擾
		vkGetPhysicalDeviceQueueFamilyProperties(_device[i], &propCount, _queueFamilyProps[i].data());
	}
}
