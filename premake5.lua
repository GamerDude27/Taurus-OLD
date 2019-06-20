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

--
-- Taurus project  
--
project "Taurus"
	location "Taurus"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/dependencies/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TAURUS_PLATFORM_WINDOWS",
			"TAURUS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "TAURUS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TAURUS_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "TAURUS_DISTRIBUTION"
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
		symbols "On"

	filter "configurations:Release"
		defines "TAURUS_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "TAURUS_DISTRIBUTION"
		optimize "On"