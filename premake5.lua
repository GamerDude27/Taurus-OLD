workspace "Taurus"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Taurus/dependencies/GLFW/GLFW/include"
IncludeDir["Glad"] = "Taurus/dependencies/Glad/Glad/include"
IncludeDir["ImGui"] = "Taurus/dependencies/imgui/imgui"

group "Dependencies"
	include "Taurus/dependencies/GLFW"
	include "Taurus/dependencies/Glad"
	include "Taurus/dependencies/imgui"
group ""

--
-- Taurus project  
--
project "Taurus"
	location "Taurus"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tauruspch.h"
	pchsource "Taurus/src/tauruspch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/dependencies/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TAURUS_PLATFORM_WINDOWS",
			"TAURUS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "TAURUS_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "TAURUS_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distribution"
		defines "TAURUS_DISTRIBUTION"
		buildoptions "/MD"
		optimize "On"

--
-- Sandbox project 
--
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Taurus/src",
		"Taurus/dependencies/spdlog/include"
	}

	links
	{
		"Taurus"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TAURUS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TAURUS_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "TAURUS_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distribution"
		defines "TAURUS_DISTRIBUTION"
		buildoptions "/MD"
		optimize "On"
