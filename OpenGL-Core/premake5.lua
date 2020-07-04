project "OpenGL-Core"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "Source/**.h",
        "Source/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "Source",
        "Vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}"
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    filter "system:windows"
		systemversion "latest"

		defines
		{
            "GLCORE_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }
    
    filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
		optimize "on"