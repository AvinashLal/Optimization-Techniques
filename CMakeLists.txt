cmake_minimum_required(VERSION 3.6)
project(cs124pa3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c headers.h kk_alg.c maxheap.c hill_climbing.c rand_sol_and_neighbor.c repeated_random.c simulated_annealing.c)
add_executable(cs124pa3 ${SOURCE_FILES})