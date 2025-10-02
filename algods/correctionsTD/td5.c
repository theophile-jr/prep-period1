#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int begin; 
  int end;   
  int size;
  int *array;  
} Queue;

Queue * Init(int size);

void EnQueue(Queue * q, int value);

int DeQueue(Queue * q, int * val);

void Destroy(Queue * q);


int main(void) 
{
  char lecture[100];
  int val;
  Queue * q;
  q = Init(100);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"queue")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      EnQueue(q,val);
    } else if (strcmp(lecture,"dequeue")==0) {
      if(DeQueue(q,&val))
      {
        printf("%d\r\n",val);
      }
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(q);
  return 0;
}

Queue * Init(int size)
{
  Queue * q;
  q = (Queue *) malloc(sizeof(Queue));
  q->array = (int*) malloc(sizeof(int)*size);
  q->size = size;
  q->begin = 0;
  q->end = 0;
  return q;
}

void EnQueue(Queue * q, int value)
{
   if ((q->end+1)%q->size != q->begin) {
      q->array[q->end] = value;
      q->end = (q->end+1)%q->size;
   }
}

int DeQueue(Queue * q, int *res)
{
   if (q->begin == q->end) {
      return 0;
   }
   else {
      *res = q->array[q->begin];
      q->begin = (q->begin+1)%q->size;
      return 1;
   }
}

void Destroy(Queue * q)
{
   free(q->array);
   free(q);
}

