# Copyright 2023 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.20)

if(NOT DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE INTERNAL "Default to Debug Build")
endif(NOT DEFINED CMAKE_BUILD_TYPE)

project(project_name.elf VERSION 0.0.1 LANGUAGES CXX)

find_package(libhal-lpc40xx REQUIRED CONFIG)

add_executable(${PROJECT_NAME} main.cpp newlib.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} PRIVATE libhal::lpc4078)
arm_cortex_post_build(${PROJECT_NAME})
