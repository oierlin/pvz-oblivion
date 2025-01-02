cmake_minimum_required(VERSION 3.16)

add_library(
  GameWorld
  STATIC
  GameWorld.hpp
  GameWorld.cpp
)

target_link_libraries(
  GameWorld
  GameObject
  Background
  PlantingSpot
  Sun
  Shovel
  Card
  CooldownMask
  Pea
  Explosion
  Zombie
)

target_include_directories(
  GameWorld
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/Background/
  ${CMAKE_SOURCE_DIR}/src/PlantingSpot/
  ${CMAKE_SOURCE_DIR}/src/Sun/
  ${CMAKE_SOURCE_DIR}/src/Shovel/
  ${CMAKE_SOURCE_DIR}/src/Card/
  ${CMAKE_SOURCE_DIR}/src/CooldownMask/
  ${CMAKE_SOURCE_DIR}/src/Pea/
  ${CMAKE_SOURCE_DIR}/src/Explosion/
  ${CMAKE_SOURCE_DIR}/src/Zombie/
)
