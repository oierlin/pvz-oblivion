cmake_minimum_required(VERSION 3.16)

add_library(
  Card
  STATIC
  Card.hpp
  Card.cpp
)

target_link_libraries(
  Card
  GameObject
  GameWorld
  Plant
)

target_include_directories(
  Card
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/Plant/
)
