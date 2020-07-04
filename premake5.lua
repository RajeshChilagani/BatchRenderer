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

group "Dependencies"
    include "OpenGL-Core/Vendor/glfw"
    include "OpenGL-Core/Vendor/Glad"
group ""


include "OpenGL-Core"
include "BatchRenderer"