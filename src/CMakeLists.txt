find_package(Boost 1.74 REQUIRED system date_time unit_test_framework )

find_package(SDL2 REQUIRED)

find_package(pegtl)

set(BUILD_SHARED_LIBS ON)

add_library(sysml sysml.cpp )


target_link_libraries(sysml PRIVATE 
	SDL2 ${SDL2_LIBRARIES} 
	taocpp::pegtl
 )

enable_testing()

add_executable(
  sysml_test
  sysml_test.cpp
)


target_link_libraries(
  sysml_test
  sysml
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
