SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
cmake_minimum_required(VERSION 3.5.1)
project(subproject4)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS})

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  sensor_msgs
)

catkin_package(
  CATKIN_DEPENDS
  roscpp
  std_msgs
  geometry_msgs
  sensor_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS} /include
)

add_executable(velocity_restriction src/velocity_restriction.cpp)
target_link_libraries(velocity_restriction ${catkin_LIBRARIES})
add_library(velocity_restriction_lib src/velocity_restriction.cpp)

# add_executable(kalman_filter src/kalman_filter.cpp)
# target_link_libraries(kalman_filter ${catkin_LIBRARIES})
add_library(kalman_filter_lib src/velocity_restriction.cpp)


add_executable(velocity_correction src/main.cpp)
target_link_libraries(velocity_correction velocity_restriction_lib kalman_filter_lib ${catkin_LIBRARIES})
