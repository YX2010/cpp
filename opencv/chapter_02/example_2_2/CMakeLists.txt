cmake_minimum_required(VERSION 3.10)
project(dispaly_picture)
set(OpenCV_DIR "/usr/local/share/opencv4/")

find_package(OpenCV 4.0 REQUIRED)

MACRO(add_example name)
    ADD_EXECUTABLE(${name} ${name}.cpp)
    TARGET_LINK_LIBRARIES(${name} ${OpenCV_LIBS})
ENDMACRO()

add_example(example2)