<<<<<<< HEAD
<<<<<<< HEAD
cmake_minimum_required(VERSION 3.7)
project(pa3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c)

add_executable(pa3 ${SOURCE_FILES})
=======
cmake_minimum_required(VERSION 3.6)
project(cs124pa3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c headers.h kk_alg.c kkarp.c maxheap.c hill_climbing.c rand_sol_and_neighbor.c repeated_random.c simulated_annealing.c)
add_executable(cs124pa3 ${SOURCE_FILES})
>>>>>>> a76f2671578cf2a8cca21351605630bcf8c4c236
=======
cmake_minimum_required(VERSION 3.6)
project(cs124pa3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c headers.h kk_alg.c maxheap.c hill_climbing.c rand_sol_and_neighbor.c repeated_random.c simulated_annealing.c kk.c)
add_executable(cs124pa3 ${SOURCE_FILES})
>>>>>>> a50af05a787e0cda623abac40bcb8ec6a5fc213b
