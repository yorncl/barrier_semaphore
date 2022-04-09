I tried to implement a barrier api with semaphores in C.
It seems to work.

# Build and run

```
make && ./barrier
```

You should see this kind of output 
```
Thread 0
Thread 1
Thread 2
Thread 3
Thread 0
Thread 1
Thread 2
Thread 3
Thread 0
...
```
4 threads are created, each calling `sleep(n)` with `i` being the thread's number (from 0 to 3);
The threads should be blocking at the `barrier_wait(barrier_t*)` call. 
