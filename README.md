# Pthreads Concurrent Execution and Timing

This project explores the fundamental concepts of multithreading in C using the **POSIX Threads (pthreads)** library. It consists of two stages (represented by the two code blocks provided): a basic demonstration of thread creation, and an enhanced version that includes execution time measurement and basic argument passing.

## Project Overview

The core goal of this project is to run two distinct, CPU-bound tasks concurrently using threads and then measure the individual and aggregate execution time to observe the performance of concurrent processing.

### Task 1: Basic Threading (Conceptual)

The first stage introduced the basic structure for creating and managing threads.

| Component | Description |
| :--- | :--- |
| **`Thread1`** | Performs a large loop (1 billion iterations) to simulate a long task. |
| **`Thread2`** | Performs a small loop (5 million iterations) to simulate a short task. |
| **`main()`** | Uses `pthread_create` to start both threads and `pthread_join` to wait for their completion, ensuring the main program does not exit prematurely. |

### Task 2: Timing, Data Passing, and Results

The final code snippet builds on the first by implementing timing and passing initial data to each thread.

| Feature | Implementation Details |
| :--- | :--- |
| **Execution Timing** | The `clock()` function from `<time.h>` is used within both `Thread1` and `Thread2` to capture the start and end time of their respective summation loops. The duration is converted to seconds using `CLOCKS_PER_SEC`. |
| **Data Passing** | Simple `long` variables (`shared_data1`, `shared_data2`) are passed to the thread functions via the `arg` parameter in `pthread_create`, allowing each thread to receive an identifier or initial value. |
| **Result Calculation** | The `main()` function retrieves the thread execution times (stored in global variables `exec_time1` and `exec_time2`) and calculates the `total_exec_time` and `average_exec_time`. |
| **Output** | Prints the thread ID/data, individual thread execution times, the total aggregated execution time, and the average time. |

-----

## How to Compile and Run

The pthreads library is external and must be explicitly linked during compilation.

### Prerequisites

You need a C compiler (like GCC) installed on your system.

### Compilation

Use the `-pthread` flag to ensure the pthreads library is linked correctly.

```bash
# Assuming the final C code is saved as 'pthreads_timing.c'
gcc -o pthreads_app pthreads_timing.c -pthread
```

### Execution

Run the compiled executable.

```bash
./pthreads_app
```

-----

## Expected Output Structure

The output will show the two threads starting (with their passed data), performing their work concurrently, and then reporting their completion and timing. Finally, the main thread will print the aggregated time metrics.

```
Thread 1: 1 
Thread 2: 2 
Thread 2 took X.XXXXXX seconds to execute 
Thread 1 took Y.YYYYYY seconds to execute 
Thread 1 and Thread 2 took Z.ZZZZZZ seconds to execute 
Average time taken was A.AAAAAA 
```

*(Note: The order of "Thread 1 completed" and "Thread 2 completed" messages may vary due to the concurrent nature of threads.)*

-----

## References

  * [Introduction to Pthreads](https://www.cs.emory.edu/~cheung/Courses/355/Syllabus/91-pthreads/intro-threads.html)
  * [Pthreads Handouts](https://web.engr.oregonstate.edu/~mjb/cs575/Handouts/pthreads.1pp)
  * [Oracle Documentation on Threads](https://docs.oracle.com/cd/E19120-01/open.solaris/816-5137/tlib-1/index.html)
  * [Measuring Time Taken by a Program in C](https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/)
  * [YouTube: C Threads and Concurrency Example](https://www.youtube.com/watch?v=Yb6pc_OU5x8)
