# Notes about Malloc Lab (Lab 5)

**Your textbook gives you a simple implementation of malloc()! Refer to textbook section 9, chapter 9.9.12.**

**Your textbook gives you a simple implementation of malloc()! Refer to textbook section 9, chapter 9.9.12.**

**Your textbook gives you a simple implementation of malloc()! Refer to textbook section 9, chapter 9.9.12.**

<u>***READ EVERY SINGLE LINE OF CODE THERE BEFORE ANYTING!***</u>

------

**The code in your textbook should guarantee a full credit of checkpoint** (or at least, near to the full credit, because you have to modify some logic). Though the final submission asks you for high utilization and throughput, you can also find some clues in your textbook (refer to the part of the footless and segregated list).

------

Here is a general overview of the stages your code will go through for malloclab:

+ Implicit lists
  + The only thing you need to modify to make implicit lists work is coalesce block. The slides are really helpful for this, since there is a good diagram for it. Once again, make good use of existing helper functions.
+ Explicit lists
  + The only difference between implicit and explicit is that you are now managing a free list. Think about how having an actual free list might modify any of your existing functions. Specifically, anything that either allocates or frees a block will now have to deal with either removing or adding to the free list. I recommend making removeFree and insertFree functions, since this is functionality you will need to repeat over and over.
+ Segregated Lists
  + The only difference between explicit and seglists is that you now have many free lists! It’s just like explicit list but you now have a whole bunch. Once again, you will have to modify and functions that involve adding or removing from the free list, since you will now have to find the correct bucket for the given block size. I recommend creating a function that finds the correct bucket size to put your block in. Once you find the correct bucket, the functionality is almost the same as explicit lists, except for the fact that if you can’t find a block big enough in the correct bucket you will need to move onto the next biggest bucket.
+ More Optimization
  + Footer Elimination
    + As the name suggests, eliminate footers where appropriate. Hint: in which kind of block the footer can be eliminated?
  + Mini Block
    + Try to make your malloc implementation support mini blocks that are only 16B large. Hint: make sure you implemented footer elimination before this.
  + There are even more optimizations. Ask your TAs when you find you are spending a lot of time optimizing your malloc implementation.

------

There is a comment in the coalesce block which says

> We also discourage you from looking at the malloc code in CS:APP and K&R, which make heavy use of macros and which we no longer consider to be good style.

This comment focuses on the macros, and we still encourage you to refer to the textbook to have a clear roadmap of the memory allocator. Anyways, the code there helps you a lot.

Though the code is not the same as our lab, the textbook gives you a clear road on how we design the memory allocator and why we need to design it in such a way. It also gives you a step-by-step tutorial on the implementation (with beautiful figures) so it is a good starting point when you have no clues.

------

assert, ensures, requires

For this lab, and more generally, this 213/613 course, they are the same.

If you’ve taken 15-122 previously, you are expected to know the difference. Or otherwise, you can take them as an alias of “assert”, meaning checking if something is true or not.

In case you are interested, here is a short answer. For more details, you can refer to 15-122 course slides.

- @requires: Something that the caller needs to make sure is true before calling the function.
- @ensures: If the caller satisfies all `@requires` statements, the function must make all `@ensures` statements true.
- @assert: Assert statements are useful if at some point in your function you want to be sure that a certain condition holds.

------

Time for the most wonderful of the labs — comment your code well!
