#include <stdio.h>
#include <pthread.h>

void* Thread1(void * arg){
  long sum = 0;
  
  for (long i = 0 ; i < 1000000000 ; i++ ){
    sum += 1;
  }
  printf("Thread 1 completed! \n");
  return NULL;
}

void* Thread2(void * arg){
  long sum = 0;
  
  for (long i = 0 ; i < 5000000 ; i++){
    sum += 1;
  }
  printf("Thread 2 completed! \n");
  return NULL;
}

int main()
{
  pthread_t thread1, thread2;
  
  pthread_create(&thread1, NULL, Thread1, NULL);
  pthread_create(&thread2, NULL, Thread2, NULL);
  
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
}

// References:
// https://www.cs.emory.edu/~cheung/Courses/355/Syllabus/91-pthreads/intro-threads.html
// https://web.engr.oregonstate.edu/~mjb/cs575/Handouts/pthreads.1pp
// https://docs.oracle.com/cd/E19120-01/open.solaris/816-5137/tlib-1/index.html
// https://www.w3resource.com/c-programming-exercises/c-snippets/conversion-specifier-for-formatting-long-with-printf-in-c.php