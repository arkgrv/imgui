// ImGui Renderer for: Vulkan
// This needs to be used along with a Platform Binding (e.g. GLFW, SDL, Win32, custom..)

// Missing features:
//  [ ] User texture binding. Changes of ImTextureID aren't supported by this binding! See https://github.com/ocornut/imgui/pull/914

// You can copy and use unmodified imgui_impl_* files in your project. See main.cpp for an example of using this.
// If you use this binding you'll need to call 5 functions: ImGui_ImplXXXX_Init(), ImGui_ImplXXX_CreateFontsTexture(), ImGui_ImplXXXX_NewFrame(), ImGui_ImplXXXX_Render() and ImGui_ImplXXXX_Shutdown().
// If you are new to ImGui, see examples/README.txt and documentation at the top of imgui.cpp.
// https://github.com/ocornut/imgui

#include <vulkan/vulkan.h>

#define IMGUI_VK_QUEUED_FRAMES 2

struct ImGui_ImplVulkan_InitInfo
{
    const VkAllocationCallbacks*    Allocator;
    VkPhysicalDevice                PhysicalDevice;
    VkDevice                        Device;
    VkRenderPass                    RenderPass;
    VkPipelineCache                 PipelineCache;
    VkDescriptorPool                DescriptorPool;
    void                            (*CheckVkResultFn)(VkResult err);
};

IMGUI_API bool        ImGui_ImplVulkan_Init(ImGui_ImplVulkan_InitInfo *init_data);
IMGUI_API void        ImGui_ImplVulkan_Shutdown();
IMGUI_API void        ImGui_ImplVulkan_NewFrame();
IMGUI_API void        ImGui_ImplVulkan_Render(VkCommandBuffer command_buffer);

// Called by Init/NewFrame/Shutdown
IMGUI_API void        ImGui_ImplVulkan_InvalidateFontUploadObjects();
IMGUI_API void        ImGui_ImplVulkan_InvalidateDeviceObjects();
IMGUI_API bool        ImGui_ImplVulkan_CreateFontsTexture(VkCommandBuffer command_buffer);
IMGUI_API bool        ImGui_ImplVulkan_CreateDeviceObjects();
