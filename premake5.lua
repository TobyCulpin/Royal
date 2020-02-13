workspace "Royal"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
	startproject "Sandbox"
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Royal/vendor/GLFW/include"
IncludeDir["Glad"] = "Royal/vendor/Glad/include"
IncludeDir["ImGui"] = "Royal/vendor/imgui"
IncludeDir["glm"] = "Royal/vendor/glm"

group "Dependencies"

	include "Royal/vendor/GLFW"
	include "Royal/vendor/Glad"
	include "Royal/vendor/imgui"
	
group ""


project "Glad"
	filter "system:linux"
		buildoptions ("-fPIC")


project "ImGui"
	filter "system:linux"
		buildoptions ("-fPIC")


project "Royal"
	location "Royal"
	kind "SharedLib"
	language "C++"
	staticruntime "off"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	
	
	
	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
	
		pchheader "rlpch.h"
		pchsource "Royal/src/rlpch.cpp"
	

		defines
		{
			"RL_PLATFORM_WINDOWS",
			"RL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}
		
		links
		{
			"GLFW",
			"Glad",
			"ImGui",
			"opengl32.lib"
		}
	
	
	filter "system:linux"
		cppdialect "C++17"
		systemversion "latest"
	
		pchheader "rlpch.h"	

		defines
		{
			"RL_PLATFORM_LINUX",
			"RL_BUILD_SO",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}
		
		links
		{
			"GLFW",
			"Glad",
			"ImGui",
			"GL"
		}
	
	
	filter "configurations:Debug"
		defines "RL_DEBUG"
		runtime "Debug"
		symbols "On"
		
	filter "configurations:Release"
		defines "RL_RELEASE"
		runtime "Release"
		optimize "On"
		
	filter "configurations:Dist"
		defines "RL_DIST"
		runtime "Release"
		optimize "On"
		


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Royal/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Royal"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"RL_PLATFORM_WINDOWS"
		}
		
	
	filter "system:linux"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"RL_PLATFORM_LINUX"
		}
		
		
	filter "configurations:Debug"
		defines "RL_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RL_RELEASE"
		runtime "Release"
		optimize "On"
	
	filter "configurations:Dist"
		defines "RL_DIST"
		runtime "Release"
		optimize "On"
	
	

	
