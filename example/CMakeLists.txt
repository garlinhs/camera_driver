cmake_minimum_required(VERSION 3.0.2)

project(camera_driver_example VERSION 1.0.0)


find_package(OpenCV 4 REQUIRED)
find_package(camera_driver REQUIRED)

if(camera_driver_FOUND)
    message ("camera_driver package found")
else()
    message (FATAL_ERROR "Cannot find camera_driver package")
endif()

include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
  ${camera_driver_INCLUDE_DIRS}
)

# Add an executable
add_executable(camera_driver_example main.cpp)

# link against the boost libraries
target_link_libraries(camera_driver_example
    ${OpenCV_LIBS}
    /usr/local/lib/libcamera_driver.so
)