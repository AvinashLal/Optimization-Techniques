//
// Created by Alex on 4/20/2017.
//

#include "main.c"

#define MAX_ITER 25000

int64_t hill_climbing_std(int size, int64_t *sequence) {
    int64_t *S = gen_rand_sol_std(size);
    for (int i = 0; i < MAX_ITER; i++) {
        int64_t *S_prime = gen_rand_neigh_std(size, S);
        if (residue_std(size, S_prime, sequence) < residue_std(size, S, sequence)) {
            free(S);
            S = S_prime;
        } else {
            free(S_prime);
        }
        // printf("%d, %lld\n", i, residue_std(size, S, sequence));

    }
    int64_t residue = residue_std(size, S, sequence);
    free(S);
    return residue;
}

int64_t hill_climbing_pp(int size, int64_t *sequence) {
    int64_t *S = gen_rand_sol_pp(size);
    for (int i = 0; i < MAX_ITER; i++) {
        int64_t *S_prime = gen_rand_neigh_pp(size, S);
        if (residue_pp(size, S_prime, sequence) < residue_pp(size, S, sequence)) {
            free(S);
            S = S_prime;
        } else {
            free(S_prime);
        }
        // printf("%d, %lld\n", i, residue_pp(size, S, sequence));
    }
    int64_t residue = residue_pp(size, S, sequence);
    free(S);
    return residue;
}