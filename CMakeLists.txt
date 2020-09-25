cmake_minimum_required(VERSION 3.13)

project(ProtobufBenchmarks)

add_executable(ProtobufBenchmarks
    Src/main.cpp
)

target_include_directories(ProtobufBenchmarks
    PRIVATE
        Inc
)

target_link_libraries(ProtobufBenchmarks
    PRIVATE
        -static-libgcc
        -static-libstdc++
        protobuf::libprotobuf-lite
)

option(protobuf_BUILD_TESTS "Build tests" OFF)
option(protobuf_BUILD_PROTOC_BINARIES "Build libprotoc and protoc" ON)
option(protobuf_BUILD_SHARED_LIBS "Build shared libraries" OFF)
add_subdirectory(Lib/protobuf/cmake)

# Compile with C++17
target_compile_features(ProtobufBenchmarks PRIVATE cxx_std_17)
set_target_properties(ProtobufBenchmarks PROPERTIES CXX_EXTENSIONS OFF)

# Enable compile warnings.
target_compile_options(ProtobufBenchmarks PUBLIC -Wall -Wextra)
