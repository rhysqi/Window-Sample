#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vulkan/vulkan.h>
#include <X11/Xlib.h>

// Function to handle resizing of the window
void handleResize(Display* display, Window window, XEvent* event) {
    // Handle window resize here
}

int main() {
    // Initialize Vulkan instance
    VkInstance instance;

    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan Window";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS) {
        fprintf(stderr, "Failed to create Vulkan instance\n");
        return EXIT_FAILURE;
    }

    // Initialize X11 display and window
    Display* display = XOpenDisplay(NULL);
    if (!display) {
        fprintf(stderr, "Failed to open X11 display\n");
        vkDestroyInstance(instance, NULL);
        return EXIT_FAILURE;
    }

    int screen = DefaultScreen(display);
    Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0, 800, 600, 0, 0, WhitePixel(display, screen));

    XSelectInput(display, window, StructureNotifyMask);
    XMapWindow(display, window);

    // Main loop
    while (1) {
        XEvent event;
        XNextEvent(display, &event);

        switch (event.type) {
            case ConfigureNotify:
                handleResize(display, window, &event);
                break;
        }
    }

    // Cleanup
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    vkDestroyInstance(instance, NULL);

    return EXIT_SUCCESS;
}
