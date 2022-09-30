# FAQs about Cache Lab (Lab 4)

1. In the trace file, the numbers are in **hex**.

   For example, if you see an address  `10`, it is a 64-bit hexadecimal address. Just think of it as `0x00000010`.

2. You are writing a **simulator**. That means there's no actual data for you to move in and out of your cache. You just need to write a simulator that simulates the hardware behavior of a real cache.

3. We are doing the same mapping system as in class! Evictions happen on a cache miss where all lines are full. In this case, some line would be selected for eviction, and the new line would be put in its place.

4. A load instruction loads the data of the address from memory into the cache. A store instruction will write that address back into memory. The cache behavior will mostly be the same with both instructions, but be sure to handle the number of dirty **bytes** depending on the type of instruction.

5. What is the point of `SIZE` field in tracefile when the cache simulator just ignores it?

   It’s up to you to decide if the information is necessary for your implementation. They are ignored in the sense that if the user requested more bytes than what we can fit in a cache line, we require multiple cache lines and may have multiple hits/misses. However, in the trace files, we never ask for more bytes than what can fit inside a singular cache line. Then, you can consider it to only count the result of the first cache line that the address refers to.

6. The precondition of evicting a cache line is that every line in that set is valid (occupied). If there is an empty line, you should not evict anything. If every line in the set is occupied, and you are loading/storing using an address where the tag bits do not match with any other line in the set, then you will have to evict the least recently used line from the set. So as you are programming in `csim.c`, make sure you think about how you keep track of the LRU line of each cache for evictions. **Evictions do happen in both loads and stores**. The main difference between those instructions is how you handle dirty bytes.

7. Remember the number of set bits and block offset bits are set with the command line arguments: `-s` and `-b`. Every other bit in the address will be the tag bits.

8. The cache treats all lines/blocks in a set as equal. When a cache is searching for potentially cached data, it first tries to check the valid bits of the cache lines. If a cache line is not marked as valid, then it does not even look at the tags of that line. If a cache line is marked as valid and has a tag that matches your tag, then you get a cache hit. In the event no tag matches it finds victim using the eviction policy (eg LRU) and replaces it with new block.

9. Refer to the `csim_stats_t` struct declaration in `cachelab.h` for the kind of values that your cache simulator needs to report at the end of a run. For your convenience, a copy of the declaration is pasted below:

   ```c
   /**
    * @brief Struct representing simulation statistics for a trace
    */
   typedef struct {
       unsigned long hits;            /* number of hits */
       unsigned long misses;          /* number of misses */
       unsigned long evictions;       /* number of evictions */
       unsigned long dirty_bytes;     /* number of dirty bytes in cache at end */
       unsigned long dirty_evictions; /* number of evictions of dirty lines */
   } csim_stats_t;
   ```

10. How you calculate `dirty_bytes` and `dirty_evictions` should be different. One is the number of bytes, the other is the number of evictions. When calculating `dirty_bytes`, try to think about what hardware does. Does hardware know what blocks in a line are dirty or does it simply treats a whole line as dirty? How will this difference affect the way of calculating `dirty_bytes`?

11. What is the difference between the action of a data load and a data store?

    Both of them will access the cache before hitting memory. For hit, miss and evicts, they behave identical. The difference is how they set/reset dirty bits.

**We will keep giving you more FAQs for the remaining parts.**



## Welcome! Treat yourself with some caches, if you'd like.