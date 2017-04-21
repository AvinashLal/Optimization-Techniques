//
// Created by Alex on 4/20/2017.
//

#ifndef CS124PA3_HEADERS_H

#define CS124PA3_HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "main.c"
#include "maxheap.c"
#include "kkarp.c"
#include "kk_alg.c"
#include "hill_climbing.c"
#include "rand_sol_and_neighbor.c"
#include "repeated_random.c"
#include "simulated_annealing.c"



float rand_val();

int64_t kk(int size, int64_t* arr);

int64_t *gen_rand_sol_std(int size);

int64_t *gen_rand_neigh_std(int size, int64_t* soln);

int64_t residue_std(int size, int64_t* S, int64_t* sequence);

int64_t *gen_rand_sol_pp(int size);

int64_t *gen_rand_neigh_pp(int size, int64_t* soln);

int64_t residue_pp(int size, int64_t* P, int64_t* A);

#endif //CS124PA3_HEADERS_H