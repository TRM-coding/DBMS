set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(DBMS LANGUAGES CXX)


add_library(DBMSlib
    ${CMAKE_CURRENT_SOURCE_DIR}/src/commanddecoding.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/table.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tablemanager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TableStream.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/user.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/usermanage.cpp
<<<<<<< HEAD
    ${CMAKE_CURRENT_SOURCE_DIR}/src/operator.cpp
=======
>>>>>>> refs/remotes/origin/main
)

target_compile_definitions(DBMSlib PRIVATE DBMSROOTDIR="${CMAKE_CURRENT_SOURCE_DIR}")


target_include_directories(DBMSlib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(DBMSlib
    PUBLIC
    cxx_std_20
)

add_executable(DBMS
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)



target_link_libraries(DBMS DBMSlib)