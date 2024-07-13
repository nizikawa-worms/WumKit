project(cgGL)
add_library(cgGL SHARED cgGL.cpp cgGL.def empty.h hook_macro.h)
set_property(TARGET cgGL PROPERTY CXX_STANDARD 23)
set_property(TARGET cgGL PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
