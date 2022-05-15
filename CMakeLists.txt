cmake_minimum_required(VERSION 3.20)
project(main)

include_directories("src/includes/")

set(SRC_LIST 
        src/myMain.cpp 
        src/myConstants.cpp 
        src/myFunction.cpp
        
        src/global_classes/Numbers.cpp
        src/global_classes/Point3D.cpp
        src/global_classes/Vector3D.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})