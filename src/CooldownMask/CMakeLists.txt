cmake_minimum_required(VERSION 3.16)

add_library(
  CooldownMask
  STATIC
  CooldownMask.hpp
  CooldownMask.cpp
)

target_link_libraries(
  CooldownMask
  GameObject
  GameWorld
  Card
)

target_include_directories(
  CooldownMask
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Card/
)
