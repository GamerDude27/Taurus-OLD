project "Glad"
	location "Glad"
	kind "StaticLib"
	language "C"

	targetdir ("Glad/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("Glad/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"Glad/include/glad/glad.h",
		"Glad/include/KHR/khrplatform.h",
		"Glad/src/glad.c",
	}

	includedirs
	{
		"Glad/include"
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/MT"