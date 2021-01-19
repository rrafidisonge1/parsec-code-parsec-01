 cmake_minimum_required(VERSION 2.8)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
    endif(COMMAND cmake_policy)

#Déclaration du projet
project(camera_test)

#link_directories(/usr/lib/arm-linux-gnueabihf/)

#set(CUDA_TOOLKIT_ROOT_DIR "/usr/local/cuda")
#set(OpenCV_DIR "/usr/local/lib/OpenCV/")
#set(OpenCV_DIR "/usr/share/OpenCV/")
set(ROOT_DIR${CMAKE_CURRENT_SOURCE_DIR}/)

find_package(OpenCV REQUIRED)# COMPONENTS opencv_core opencv_imgproc opencv_imgcodecs PATHS /usr/lib NO_DEFAULT_PATH CONFIG)
find_package(CUDA REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)


cuda_add_executable(camera_test ../main_TK1.cpp my_lib.cpp )

target_link_libraries(camera_test Qt5::Widgets)
target_link_libraries(camera_test Qt5::Core)
target_link_libraries(camera_test opencv_core opencv_highgui opencv_imgproc ) # OpenCV::opencv_highgui  opencv_imgcodecs opencv_video opencv_videoio)
