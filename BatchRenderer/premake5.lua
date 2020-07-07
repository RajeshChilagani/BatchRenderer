project "BatchRenderer"
    kind "ConsoleApp"
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

    includedirs
    {
        "../OpenGL-Core/Vendor/spdlog/include",
        "../OpenGL-Core/Source",
        "../OpenGL-Core/Vendor",
        "../OpenGL-Core/%{IncludeDir.Glad}",
        "../OpenGL-Core/%{IncludeDir.imgui}",
        "../OpenGL-Core/%{IncludeDir.glm}"
    }

    links
    {
        "OpenGL-Core"
    }

    filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLCORE_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
		optimize "on"