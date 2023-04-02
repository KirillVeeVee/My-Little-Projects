cmake_minimum_required(VERSION 3.24)
project(SFML_Tanks)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "./lib/SFML-2.5.1/lib/cmake/SFML")

add_executable(SFML_Tanks main.cpp game/ResourceHolder.h game/SceneNode.cpp game/SceneNode.h game/Entity.cpp game/Entity.h game/TankHullEntity.cpp game/TankHullEntity.h game/TankTurretEntity.cpp game/TankTurretEntity.h game/SpriteNode.cpp game/SpriteNode.h game/ResourceIdentifiers.h game/World.cpp game/World.h game/Game.cpp game/Game.h game/Command.h game/Command.cpp game/CommandQueue.cpp game/CommandQueue.h game/Player.cpp game/Player.h game/EntityData.cpp game/EntityData.h game/TankEntity.cpp game/TankEntity.h game/TextNode.cpp game/TextNode.h game/Utility.cpp game/Utility.h game/Projectile.cpp game/Projectile.h)

target_link_libraries(SFML_Tanks sfml-graphics)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)