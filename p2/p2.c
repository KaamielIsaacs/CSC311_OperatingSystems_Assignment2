#include <stdio.h>
#include <pthread.h>
#include <time.h>

double exec_time1, exec_time2, total_exec_time, average_exec_time;

void* Thread1(void * arg){
  long *shared_data = (long*)arg;
  printf("Thread 1: %ld \n", *shared_data);
  clock_t start1, end1;
  long sum = 0;
  
  start1 = clock();
  
  for (long i = 0 ; i < 1000000000 ; i++ ){
    sum += 1;
  }
  end1 = clock();
  exec_time1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
  printf("Thread 1 took %lf seconds to execute \n" , exec_time1);
  return NULL;
}

void* Thread2(void * arg){
  long *shared_data = (long*)arg;
  printf("Thread 2: %ld \n", *shared_data);
  clock_t start2, end2;
  long sum = 0;
  
  start2 = clock();
  
  for (long i = 0 ; i < 5000000 ; i++){
    sum += 1;
  }
  end2 = clock();
  exec_time2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
  printf("Thread 2 took %lf seconds to execute \n", exec_time2);
  return NULL;
}

int main()
{
  pthread_t thread1, thread2;
  long shared_data1 = 1;
  pthread_create(&thread1, NULL, Thread1, &shared_data1);
  
  long shared_data2 = 2;
  pthread_create(&thread2, NULL, Thread2, &shared_data2);
  
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  
  total_exec_time = exec_time1 + exec_time2;
  average_exec_time = total_exec_time / 2;
  
  printf("Thread 1 and Thread 2 took %lf seconds to execute \n" , total_exec_time);
  printf("Average time taken was %lf \n" , average_exec_time);
}

// References:
// https://www.cs.emory.edu/~cheung/Courses/355/Syllabus/91-pthreads/intro-threads.html
// https://web.engr.oregonstate.edu/~mjb/cs575/Handouts/pthreads.1pp
// https://docs.oracle.com/cd/E19120-01/open.solaris/816-5137/tlib-1/index.html
// https://www.w3resource.com/c-programming-exercises/c-snippets/conversion-specifier-for-formatting-long-with-printf-in-c.php
// https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
//https://www.youtube.com/watch?v=Yb6pc_OU5x8
