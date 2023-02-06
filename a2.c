#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>

// you will need something here
pthread_t temp1, temp2;

void *search1(void *p)
{
  temp1 = pthread_self();
  char *arr = (char *)p;
  for (int i = 0; i < 4; i++)
  {
    if (arr[i] == 'b')
    {
      printf("\nfound BY 1!\n");
      pthread_cancel(temp2);
      pthread_exit(NULL);
    }
  }

  // search for b in arr[0] to arr[n/2]
  // print out that b was found
  // cancel thread2
}

void *search2(void *p)
{
  temp2 = pthread_self();
  char *arr = (char *)p;
  for (int i = 5; i < 9; i++)
  {
    sleep(20);
    if (arr[i] == 'b')
    {
      printf("\nfound BY 2!\n");
      pthread_cancel(temp1);
      pthread_exit(NULL);
    }
  }
}

int main()
{
  char arr[10] = {'a', 'c', 'b', 'a', 'f', 'p', 'n', 's', 'l', 'b'};
  pthread_t thread1, thread2;
  pthread_create(&thread1, NULL, search1, (void *)arr);
  pthread_create(&thread2, NULL, search2, (void *)arr);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  // initialize two thread variables
  // create two threads
  // wait for the threads to terminate

  return 0;
}