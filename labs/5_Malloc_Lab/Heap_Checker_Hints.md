# Hint for Heap Checker

Some of you are not having Heap Checker and in previous semesters, some TAs will reject to read and debug your code if you are having no comments and no Heap Checker. It is really important to have one, especially when you suffer a lot from Segmentation Fault!

A typical Checker checks almost everything and you should assert() it almost everywhere. In such a way, once you find it failed to pass something, you know after which function, something might break, for example, `block->prev->next` is not `block` itself after an insertion.

Start from here:

```c
bool mm_checkheap(int line) {
    dbg_printf("\n[line %d] Checking...\n", line);

    /* Check each block’s address alignment */
    block = heap_start;
    while (block != epilogue) {
        if (get_size(block) % dsize != 0) {
            dbg_printf("[line %d]: payload size %lu not aligned.\n", line, get_size(block));
            return false;
        }
        block = find_next(block);
    }
}
```

Some other important points are:

- Check heap boundaries
- Check each block’s header and footer: Check header matches footer
- Check size > minimum size
- Check all next/previous pointers are consistent
- Count free blocks by iterating through every block and traversing free list by pointers and seeing if they match.

Remember to call it almost everywhere when debugging:

```
void *malloc(size_t size) {
    dbg_requires(mm_checkheap(__LINE__));
    //...
    dbg_ensures(mm_checkheap(__LINE__));
    split_block(block, size);
    dbg_ensures(mm_checkheap(__LINE__));
    //...
}
```

So if this line fails, you know something is broken in `split_block` and if you find the error is caused by `block->prev->next != block` (or another example, a `block` which is allocated but is in the free list), you know what to do.