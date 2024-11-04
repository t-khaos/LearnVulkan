set_project("LearnVulkan")
set_arch("x64")
set_warnings("all")
set_languages("c++20")

add_rules("mode.debug", "mode.release")
add_rules("plugin.vsxmake.autoupdate")
add_requires("vulkansdk", "glfw", "glm", "stb")

target("Runtime")
    set_default(true)
    set_kind("static")
    add_includedirs("Runtime/Source")
    add_headerfiles("Runtime/Source/**.h")
    add_headerfiles("Runtime/Source/**.hpp")
    add_files("Runtime/Source/**.cpp")
    add_packages("vulkansdk", "glfw", "glm", "stb")
target_end()

target("Editor")
    set_default(true)
    set_kind("binary")
    add_deps("Runtime")
    add_includedirs("Runtime/Source")
    add_includedirs("Editor/Source")
    add_headerfiles("Editor/Source/**.h")
    add_headerfiles("Editor/Source/**.hpp")
    add_files("Editor/Source/**.cpp")
    add_packages("vulkansdk", "glfw", "glm", "stb")
target_end()