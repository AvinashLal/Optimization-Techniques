#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//code used to implement this heap was influenced by robin thomas. The code for his heap can be found here https://github.com/robin-thomas/max-heap/blob/master/maxHeap.c

//define node structure
typedef struct node {
    int v ;
} node ;


//define maximum heap structure
typedef struct maxheap {
    int size ;
    node *lst ;
} maxheap ;


//functions to find children and parent of a given node
#define lchild(x) 2 * x + 1
#define rchild(x) 2 * x + 2
#define parent(x) (x - 1) / 2


//function to swap two nodes in the heap
void swap(node *n1, node *n2) {
    node temp = *n1 ;
    *n1 = *n2 ;
    *n2 = temp ;
}


//function used to insert into the heap
void insertNode(maxheap *heap, int64_t input) {

    // allocate space
    heap->lst = (node *)realloc(heap->lst, (heap->size + 1) * sizeof(node)) ;

    // initialize the node as input
    node node;
    node.v = input;

    // Positioning the node at the right position in the max heap
    int n = (heap->size)++ ;
    while(n && node.v > heap->lst[parent(n)].v) {
        heap->lst[n] = heap->lst[parent(n)] ;
        n = parent(n);
    }

    heap->lst[n] = node;
}

//function used to maintain heap property
void heapify(maxheap *heap, int i) {
    int largest = (lchild(i) < heap->size && heap->lst[lchild(i)].v > heap->lst[i].v) ? lchild(i) : i ;
    if(rchild(i) < heap->size && heap->lst[rchild(i)].v > heap->lst[largest].v) {
        largest = rchild(i) ;
    }
    if(largest != i) {
        swap(&(heap->lst[i]), &(heap->lst[largest])) ;
        heapify(heap, largest) ;
    }
}

int64_t extractMax(maxheap *heap) {
    if(heap->size) {
        int64_t v = heap->lst[0].v;
        heap->lst[0] = heap->lst[--(heap->size)] ;
        heap->lst = (node *)realloc(heap->lst, heap->size * sizeof(node)) ;
        heapify(heap, 0) ;
        return v;
    } else {
        printf("\nMaximum Heap is empty!\n") ;
        free(heap->lst) ;
        return -1;
    }
}