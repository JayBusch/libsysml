find_package(Boost 1.74 REQUIRED system date_time)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

set(BUILD_SHARED_LIBS ON)

add_library(sysml sysml.cpp)

target_link_libraries(sysml PRIVATE sfml-graphics )
