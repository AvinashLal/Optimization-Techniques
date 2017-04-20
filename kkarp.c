# include "maxheap.c"

int main (int arg, char* argv[]){

//make sure the input is correct
    if(argc != 2){

        print("Make sure the input is of the form /kk inputfile")
                return 1;
    }

    //initialize heap to be used
    maxheap *heap = (maxheap *)malloc(sizeof(maxheap));
    heap->lst = NULL;
    heap->size = 0;

    //store input file
    char *infile = arg[1] ;

    File *f ;
    f = fopen(infile,'r') ;

    //checks if file is null
    if (f == NULL){
        printf("input file is NULL" )
        return 1
    }

    fgets()
    for (int i = 0; i < 15; i++) {
        insertNode(heap, i);
    }

    int64_t max = extractMax(heap);
    printf("%i",max) ;
}