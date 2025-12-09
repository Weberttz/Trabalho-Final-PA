cmake_minimum_required(VERSION 3.26)
project(Batalha-Naval C)

add_executable(batalha-naval
    ../src/main.c
    ../src/jogo.c
    ../src/navios.c
    ../src/salvar.c
    ../src/tabuleiro.c
)

target_include_directories(batalha-naval PRIVATE ../include)
