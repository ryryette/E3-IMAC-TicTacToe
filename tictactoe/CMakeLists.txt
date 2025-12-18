cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(SUJET01)

# --------------------------------------------
# Version de base : un exécutable par fichier 
# --------------------------------------------

# On indique que l'on veut créer un exécutable "ex01" compilé à partir du fichier td01_ex01.cpp
add_executable(main src/main.cpp)
# On indique que l'on veut créer un exécutable "ex01" compilé à partir du fichier td01_ex01.cpp
add_executable(PLayer src/Player.cpp)