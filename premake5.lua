workspace "BatchRenderer"
    architecture "x86"
    startproject "BatchRenderer"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Vendor/glfw/include"
IncludeDir["Glad"] = "Vendor/Glad/include"
IncludeDir["imgui"] = "Vendor/imgui"
IncludeDir["glm"] = "Vendor/glm"
IncludeDir["stb_image"] = "Vendor/stb_image"

group "Dependencies"
    include "OpenGL-Core/Vendor/glfw"
    include "OpenGL-Core/Vendor/Glad"
    include "OpenGL-Core/Vendor/imgui"
group ""


include "OpenGL-Core"
include "BatchRenderer"