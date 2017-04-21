//
// Created by Alex on 4/20/2017.
//

#include "main.c"

#define MAX_ITER 25000

float T(int n);

int64_t simulated_annealing_std(int size, int64_t *sequence) {
    int64_t *S = gen_rand_sol_std(size);
    int64_t *S_double_prime = malloc(sizeof(int64_t) * size);
    memcpy(S_double_prime, S, sizeof(int64_t) * size);

    for (int i = 0; i < MAX_ITER; i++) {
        int64_t *S_prime = gen_rand_neigh_std(size, S);
        if (residue_std(size, S_prime, sequence) < residue_std(size, S, sequence)) {
            free(S);
            S = S_prime;
        } else {
            float prob = exp(-(residue_std(size, S_prime, sequence)-residue_std(size, S, sequence))/T(i));
            if (rand_val() <= prob) {
                free(S);
                S = S_prime;
            } else {
                free(S_prime);
            }
        }
        if (residue_std(size, S, sequence) < residue_std(size, S_double_prime, sequence)) {
            memcpy(S_double_prime, S, sizeof(int64_t) * size);
        }
        // printf("%d, %lld\n", i, residue_std(size, S, sequence));
    }
    int64_t residue = residue_std(size, S_double_prime, sequence);
    free(S_double_prime);
    return residue;
}


int64_t simulated_annealing_pp(int size, int64_t *sequence) {
    int64_t *S = gen_rand_sol_pp(size);
    int64_t *S_double_prime = malloc(sizeof(int64_t) * size);
    memcpy(S_double_prime, S, sizeof(int64_t) * size);

    for (int i = 0; i < MAX_ITER; i++) {
        int64_t *S_prime = gen_rand_neigh_pp(size, S);
        if (residue_pp(size, S_prime, sequence) < residue_pp(size, S, sequence)) {
            free(S);
            S = S_prime;
        } else {
            float prob = exp(-(residue_pp(size, S_prime, sequence)-residue_pp(size, S, sequence))/T(i));
            if (rand_val() <= prob) {
                free(S);
                S = S_prime;
            } else {
                free(S_prime);
            }
        }
        if (residue_pp(size, S, sequence) < residue_pp(size, S_double_prime, sequence)) {
            memcpy(S_double_prime, S, sizeof(int64_t) * size);
        }
        // printf("%d, %lld\n", i, residue_pp(size, S, sequence));
    }
    int64_t residue = residue_pp(size, S_double_prime, sequence);
    free(S_double_prime);
    return residue;
}


float T(int n) {
    float val = pow(10, 10)*pow(0.8, floor(n/300));
    return val;
}

