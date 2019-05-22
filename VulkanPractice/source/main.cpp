#include "../source/AppBase/VulkanAppBase.h"

const  int WINDOW_WIDTH = 1280;
const  int WINDOW_HEIGHT = 720;
const char* APP_TITLE = "VulkanPractice";


void main() {
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, 0);
	auto wnd = glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT, APP_TITLE,nullptr,nullptr);
	VulkanAppBase app;
	app.Initialize(wnd, APP_TITLE);
	while (glfwWindowShouldClose(wnd) == GLFW_FALSE)
	{
		glfwPollEvents();
		app.Render();

	}

	app.Terminate();
	glfwTerminate();


}