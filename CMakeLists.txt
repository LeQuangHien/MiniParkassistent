cmake_minimum_required(VERSION 3.10)
project(MiniParkassistent)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(MiniParkassistent
    main.cpp
    src/distance_sensor.cpp
)

target_link_libraries(MiniParkassistent wiringPi pthread)