cmake_minimum_required(VERSION 3.16)

add_library(
  Explosion
  STATIC
  Explosion.hpp
  Explosion.cpp
)

target_link_libraries(
  Explosion
  GameObject
  GameWorld
)

target_include_directories(
  Explosion
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
