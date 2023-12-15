cmake_minimum_required(VERSION 3.21)
project(WordsCounter C)

set(CMAKE_C_STANDARD 11)
enable_language(ASM_NASM)

add_executable(WordsCounter main.c count_spaces.asm count_words.asm test.asm)
