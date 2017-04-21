#include "headers.h"

#define sz 100
#define TENTOTWELVE 1000000000000

char * make_rand_outputfile(char *outputfile, int d);

int main(int argc, char *argv[]) {
    printf("%s\t| %s\t| %s\t |%s\n", "Algorithm", "Instance", "Residue", "Time Used");

    srand(clock()); // seeds random generator

    // for 100 instances
    for (int i = 0; i < 50; i++) {
        char filename[16];
        sprintf(filename, "file%d.txt", i);

        char* inputfile = make_rand_outputfile(filename, sz);

        // opens inputfile and checks for NULL
        FILE *fp;
        fp = fopen(inputfile, "r");
        if (fp == NULL)
            return -1;

        char temp[15];
        int64_t val;
        char *pEnd;

        // inserting the 100 values from the file into the heap
        int64_t array[sz];
        for (int i = 0; i < sz; i++) {
            if (fgets(temp, 15, fp) != NULL) {
                val = strtoull (temp, &pEnd, 10);
                array[i] = val;
            }
        }

        clock_t start, end;
        double cpu_time_used;


        start = clock();
        int64_t result1 = kk(sz, array);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%s\t|%-10d\t| %-6lld\t| %3f\t \n", "kk", i, result1, cpu_time_used);


        start = clock();
        result1 = repeated_random_std(sz, array);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%s\t|%-10d\t| %-6lld\t| %3f\t \n", "rr_std", i, result1, cpu_time_used);



        start = clock();
        result1 = hill_climbing_std(sz, array);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%s\t|%-10d\t| %-6lld\t| %3f\t \n", "hc_std", i, result1, cpu_time_used);



        start = clock();
        result1 = simulated_annealing_std(sz, array);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%s\t|%-10d\t| %-6lld\t| %3f\t \n", "sa_std", i, result1, cpu_time_used);



        start = clock();
        result1 = repeated_random_pp(sz, array);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%s\t|%-10d\t| %-6lld\t| %3f\t \n", "rr_pp", i, result1, cpu_time_used);



        start = clock();
        result1 = hill_climbing_pp(sz, array);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%s\t|%-10d\t| %-6lld\t| %3f\t \n", "hc_pp", i, result1, cpu_time_used);



        start = clock();
        result1 = simulated_annealing_pp(sz, array);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%s\t|%-10d\t| %-6lld\t| %3f\t \n", "sa_pp", i, result1, cpu_time_used);

    }

    return 0;
}

// makes a random number between 1 - 10^12
int64_t make_64bit_rand_number() {
    int64_t low = rand();
    int64_t high = rand();

    int64_t result = low | (high << 32);
    return (result % ((int64_t) TENTOTWELVE) + 1);
}

// makes random outfile of 100 integers in range [1, 2^62 - 1]
char * make_rand_outputfile(char *outputfile, int d) {
    FILE *fp;
    fp = fopen(outputfile, "w");
    if (fp == NULL) /* check that the file was actually opened */
        return NULL;

    for (int n = 0; n < sz; n++) {
        fprintf(fp, "%lld\n", make_64bit_rand_number());
    }

    fclose(fp);
    return outputfile;
}