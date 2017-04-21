#include "headers.h"
#define sz 100

void printheap(maxheap *heap);

int main(int argc, char *argv[]) {

    // checks that user enters right number of arguments
    if (argc != 2) {
        printf("Must be in form ./kk inputfile");
        return 1;
    }

    // seeds random generator
    srand(clock());
    maxheap *heap = (maxheap *)malloc(sizeof(maxheap));

    heap->lst = NULL;
    heap->size = 0;

    // stores 2nd command line argument in inputfile variable
    char *inputfile = argv[1];
    // inputfile = make_rand_outputfile((char *)"inputfile.txt", sz);

    // opens inputfile and checks for NULL
    FILE *fp;
    fp = fopen(inputfile, "r");
    if (fp == NULL)
        return -1;

    char temp[15];
    int64_t val;
    char *pEnd;

    // inserting the 100 values from the file into the heap
    for (int i = 0; i < sz; i++) {
        if (fgets(temp, 15, fp) != NULL)
        {
            val = strtoull (temp, &pEnd, 10);
            insertNode(heap, val);
        }

    }

    // extracts the two biggest elements in the heap, calculates the difference
    // re-inserts the differential into the heao
    // if size = 1, parent node is residue value which we return
    while (heap->size > 1) {
        int64_t max1 = extractMax(heap);
        int64_t max2 = extractMax(heap);
        int64_t diff = llabs(max2 - max1);
        insertNode(heap, diff);
    }

    int64_t residue = extractMax(heap);
    printf("%lld\n", residue);
    free(heap);
    free(heap->lst);
    fclose(fp);

    return 0;
}

// prints values stored in heap
void printheap(maxheap *heap) {
    for (int i = 0; i < sz; i++) {
        printf("%lld ",heap->lst[i].value);
    }
    printf("\nSize is:%d\n", heap->size);

}