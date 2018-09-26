add_executable(scratch main.cpp ../include/PID.h PID.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
