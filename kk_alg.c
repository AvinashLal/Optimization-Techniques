//
// Created by Alex on 4/20/2017.
//

#include "headers.h"

int64_t kk(int size, int64_t* arr) {
    maxheap *heap = (maxheap *)malloc(sizeof(maxheap));

    heap->lst = NULL;
    heap->size = 0;

    for (int i = 0; i < size; i++) {
        insertNode(heap, arr[i]);
    }

    // extracts the two biggest elements in the heap, calculates the difference
    // re-inserts the differential into the heap
    // if size = 1, parent node is residue value which we return
    while (heap->size > 1) {
        int64_t max1 = extractMax(heap);
        int64_t max2 = extractMax(heap);
        int64_t diff = llabs(max2 - max1);
        insertNode(heap, diff);
    }

    int64_t residue = extractMax(heap);
    free(heap);
    free(heap->lst);
    return residue;
}
