# Concurrent B-Link-Tree Indexes Research

This repository implements concurrent B-Tree database indexes in pure ANSI C with no external dependencies. This repository comes with a full library of data structures, including a strings implementation, vector implementation, and stack implementation. The thread pool for actually running the code concurrently consists of one header file and one source file, which implements binary semaphores and a thread pool which takes jobs through a queue.

The B-Link-Tree indexes implemented here are combine the ideas of Lehman and Yao's efficient locking scheme as well as Lanin and Shasha's symmetric algorithm for deletion, making the trees implemented here similar to indexes used in PostgreSQL or other enterprise relational database management systems.

To run the code, `git clone` the repository, then `cd` into the folder. Run `mkdir build && cd build` and then `cmake ..`, `make`, and run the executable. 
