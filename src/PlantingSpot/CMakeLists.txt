cmake_minimum_required(VERSION 3.16)

add_library(
  PlantingSpot
  STATIC
  PlantingSpot.hpp
  PlantingSpot.cpp
)

target_link_libraries(
  PlantingSpot
  GameObject
  GameWorld
)

target_include_directories(
  PlantingSpot
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
)
