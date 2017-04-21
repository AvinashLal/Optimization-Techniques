//
// Created by Alex on 4/20/2017.
//

#include "main.c"

// generates a rand value in [0,1]
float rand_val() {
    return (float)rand() / (float)RAND_MAX ;
}

// get random solution for standard representation
int64_t *gen_rand_sol_std(int size) {
    int64_t* S = (int64_t *)malloc(sizeof(int64_t) * size);
    for (int i = 0; i < size; i++) {
        S[i] = rand() % 2 == 0 ? 1: -1;
    }
    return S;
}

// get random neighbor for standard representation
int64_t *gen_rand_neigh_std(int size, int64_t* soln) {
    int64_t* neighbor = (int64_t *)malloc(sizeof(int64_t) * size);
    for (int i = 0; i < size; i++) {
        neighbor[i] = soln[i];
    }

    int64_t id1 = rand() % size;
    int64_t id2 = rand() % size;

    // ensures indices are different
    if (id1 == id2) {
        if (id1 == 0){
            id2 = 1;
        }
        else {
            id2 = id1 - 1;
        }
    }

    int64_t newval1 = (-1) * soln[id1];
    int64_t newval2 = rand() % 2 == 0 ? soln[id2]: (-1) * soln[id2];
    neighbor[id1] = newval1;
    neighbor[id2] = newval2;

    return neighbor;
}

// calculates the residue for standard representation
int64_t residue_std(int size, int64_t* S, int64_t* sequence) {
    int64_t residue = 0;
    for (int i = 0; i < size; i++) {
        residue += S[i] * sequence[i];
    }
    return llabs(residue);
}

// get random solution for prepartitioning representation
int64_t *gen_rand_sol_pp(int size) {
    int64_t* S = (int64_t *)malloc(sizeof(int64_t) * size);
    for (int i = 0; i < size; i++) {
        S[i] = rand() % size;
    }
    return S;
}

// get random neighbor for prepartitioning representation
int64_t *gen_rand_neigh_pp(int size, int64_t* soln) {
    int64_t* neighbor = (int64_t *)malloc(sizeof(int64_t) * size);
    for (int64_t i = 0; i < size; i++) {
        neighbor[i] = soln[i];
    }
    int64_t i = rand() % size;
    int64_t j = rand() % size;
    while (neighbor[i] == j) {
        i = rand() % size;
    }
    neighbor[i] = j;
    return neighbor;
}

// calculates the residue for standard representation
int64_t residue_pp(int size, int64_t* P, int64_t* A) {
    int64_t* A_prime = (int64_t *)malloc(sizeof(int64_t) * size);
    for (int i = 0; i < size; i++) {
        A_prime[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        A_prime[P[i]] += A[i];
    }
    return kk(size, A_prime);
}