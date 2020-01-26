workspace "Royal"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Royal"
	location "Royal"
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
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"RL_PLATFORM_WINDOWS",
			"RL_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "RL_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "RL_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "RL_DIST"
		optimize "On"
		

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
		"Royal/vendor/spdlog/include",
		"Royal/src"
	}

	links
	{
		"Royal"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"RL_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "RL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RL_DIST"
		optimize "On"