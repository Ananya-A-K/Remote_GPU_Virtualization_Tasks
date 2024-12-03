cmake_minimum_required(VERSION 3.5)

project(HelloWorld)

find_package(gRPC REQUIRED)
find_package(Protobuf REQUIRED)

include_directories(${Protobuf_INCLUDE_DIRS} ${gRPC_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)

add_executable(server server.cpp helloworld.pb.cc helloworld.grpc.pb.cc)
add_executable(client client.cpp helloworld.pb.cc helloworld.grpc.pb.cc)

target_link_libraries(server ${gRPC_LIBRARIES} ${Protobuf_LIBRARIES})
target_link_libraries(client ${gRPC_LIBRARIES} ${Protobuf_LIBRARIES})
