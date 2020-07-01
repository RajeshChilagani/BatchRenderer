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

group "Dependencies"
    include "OpenGL-Core/Vendor/glfw"
group ""


include "OpenGL-Core"
include "BatchRenderer"