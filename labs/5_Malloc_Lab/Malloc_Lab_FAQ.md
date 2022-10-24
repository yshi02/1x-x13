# FAQs about Malloc Lab (Lab 5)

**Your textbook gives you a simple implementation of malloc()! Refer to textbook section 9, chapter 9.9.12.**

**Your textbook gives you a simple implementation of malloc()! Refer to textbook section 9, chapter 9.9.12.**

**Your textbook gives you a simple implementation of malloc()! Refer to textbook section 9, chapter 9.9.12.**

<u>***READ EVERY SINGLE LINE OF CODE THERE BEFORE ANYTING!***</u>



Here goes the FAQs:

+ How does one tackle this lab in an appropriate manner? I find most things quite difficult to comprehend, even with the roadmap.
  + Take time to digest the helper functions. there are a lot, but they are commented very well and if you understand what all the helpers are doing, you’ll find it much easier to code afterward.
  + Make frequent use of dbg-asserts and dbg-printfs. While the program is executing, if there are any glaring issues you want to know about them immediately. Think about what should be true at any time, and put a dbg-assert to make sure it is true. This will help you catch a lot of bugs!
  + Make a good print_heap function and a good print_free_list function. Here are some things you may want to print:
    + address of current block
    + footers and headers (what are stored in the footers and headers?)
    + next/prev pointers (if you've upgraded to explicit list)

+ In the writeup for checkheap, it says we have to check previous/next allocate/free bit consistency. What does it mean exactly?

  + Consistency can mean a few things here.

    Make sure that if you have a free block, you don’t have another free block in the previous/next blocks

    Along with this make sure that your headers and footers have the same allocation value. Something is seriously wrong if your header/footer don’t agree with each other.

    If you have both header and footer in your block, then if the header says it is an allocated block, then the footer should say it is allocated as well. That’s what we say “free bit consistency” or “header and footer matching each other”.

    The same logic applies here: the size of the header should be equal to the size of the footer.

    If you store “prev is allocated” in some bit in your header, then when you find block A has a “prev allocated” true, and when you actually get the previous block of A, the free bit there should be false, and that’s what we say “previous allocate consistency”.

+ Will our highest score be kept or the last one?

  + The latest.

+ I am trying to check whether two blocks equal to the same one. Can this be done by checking whether the block pointers equal to the same one like this? If not, how should I check if two blocks are the same?

  + ```
    (void*) block1 != (void*) block2
    ```

    This will check if the pointers block1 and block2 point to the same address; it means nothing for the values of block1 and block2. If you want to check if the pointers point to the same address, you don’t need to cast to void*, and if you want to know if the values the pointers are pointing to (the contents of blockX) are the same you need to write your own function.

+ What does 16Byte (double-word) aligned mean?

  + 16-byte and doubleword are the same thing; a word is 8 bytes, so a doubleword is 2*word=16 bytes. Block address is the address of the struct block, which starts with the header, so yes, it’s the address of the header.

    Only the payload needs to be 16-byte aligned.

    The prologue and epilogue are not allocated at any random address. Remember that though the prologue and epilogue are word_t, they are both part of dummy blocks. So the dummy blocks containing the prologue and epilogue would be aligned to 16 themselves. Therefore, there would not need to be any padding between the header and payload.

    The 16 byte alignment for a block is due to the fact that the payload size must be a multiple of 16, and the size of header+footer is 16. Therefore, the overall block must be aligned to 16, since the size is (some multiple of 16)+16.

+ ERROR: mem_sbrk failed. Ran out of memory. Why do I see this?

  + This means your malloc implementation keeps requesting for more heap spaces. It has requested so many such that it drains all VMs on the machine. Check you find_fit function and try to find out why it consistently cannot find a fit even after requesting so much memory on the heap.

+ I am confused on the contract functions. What does the && "message" do? Are we supposed to replace this with a statement that effectively represents the text? Or does this text just describe what the getsize(block) != 0 is doing?
  + The string will always evaluate to true. If the first condition is true as well you'll see the entire thing printed out which is the point. If get_size(block) is 0, it means that find_next had been called on the last block of the heap which is the epilogue (it could also be the prologue but heap_start takes care of that).
