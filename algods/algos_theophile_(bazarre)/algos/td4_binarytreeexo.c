#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int allocated; /* current allcoation of array */
    int filled;    /* number of items present in the binheap */
    int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size
 * it also fill allocated (size) and intializes
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);


int main(void)
{
    char lecture[100];
    int val;
    BinaryHeap *heap;
    heap = Init(10);

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"bye")!=0) {
        if (strcmp(lecture,"insert")==0) {
            fscanf(stdin,"%99s",lecture);
            val = strtol(lecture,NULL,10);
            InsertValue(heap,val);
        } else if (strcmp(lecture,"extract")==0) {
            if(ExtractMax(heap,&val))
            {
                printf("%d\r\n",val);
            }
        }
        fscanf(stdin,"%99s",lecture);
    }
    Destroy(heap);
    return 0;
}

BinaryHeap * Init(int size)
{
    BinaryHeap *heap;
    heap = malloc(sizeof(BinaryHeap));
    heap->allocated = size;
    heap->filled = 0;
    heap->array = malloc(sizeof(int)*size);
    return heap;
}

void InsertValue(BinaryHeap *heap, int value)
{
    /* put your insert code here */
    if (heap->filled == heap->allocated) {
        heap->allocated *= 2;
        heap->array = realloc(heap->array,sizeof(int) * heap->allocated);
    }
    heap->array[heap->filled] = value;
    int i = heap->filled++;
    while (i > 0 && heap->array[i] > heap->array[(i-1)/2]) {
        int temp = heap->array[i];
        heap->array[i] = heap->array[(i-1)/2];
        heap->array[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}

int ExtractMax(BinaryHeap * heap, int *res)
{
    /* put your extraction code here */
    if (heap->filled == 0) {
        return 0;
    }
    *res = heap->array[0];
    heap->filled--;
    if (heap->filled == 0) {
        return 1;
    }

    heap->array[0] = heap->array[heap->filled];

    int i = 0;
    while (1) {
        int left  = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < heap->filled && heap->array[left] > heap->array[largest]) {
            largest = left;
        }
        if (right < heap->filled && heap->array[right] > heap->array[largest]) {
            largest = right;
        }

        if (largest == i) break;

        int tmp = heap->array[i];
        heap->array[i] = heap->array[largest];
        heap->array[largest] = tmp;

        i = largest;
    }

    return 1;
}

void Destroy(BinaryHeap * heap)
{
    if (heap) {
        free(heap->array);
        free(heap);
    }
}
