workspace "LSEG Coding Challenge"
	configurations {"Debug", "Release"}
project "LSEG Coding Challenge"
	location "LSEG Coding Challenge"
	kind "ConsoleApp"
	language "C++"
	targetdir "bin/%{cfg.buildcfg}"

	files {"LSEG Coding Challenge//**.h" , "LSEG Coding Challenge//**.cpp"}

	filter "configurations::Debug"
		defines{"DEBUG"}
		symbols "On"
	filter "configurations::Release"
		defines{"NDEBUG"}
		optimize "On"
