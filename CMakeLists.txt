cmake_minimum_required(VERSION 3.10)
project(olxserverdb)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread ")
add_subdirectory(server)
add_subdirectory(client)
include_directories("include")
add_executable(${PROJECT_NAME} main.c olxserverdb.c olxusersdb.c)
target_link_libraries(${PROJECT_NAME} server client)