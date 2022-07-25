find_package(Boost 1.74 REQUIRED system date_time)

set(BUILD_SHARED_LIBS ON)

add_library(sysml sysml.cpp)

target_link_libraries(sysml PRIVATE sfml-graphics )
