# FAQs about Attack Lab (Lab 3)

There are some questions frequently asked and are in private posts, so for your convenience, we extract some of them and put them together.

+ Phase 3 works when I run it but AutoLab doesn’t give me points.

  This usually happens if your solution “works” but results in a SEGV or BUSV, etc.

  Remember that GDB sets all uninitialized memory to 0 by default. If you did not null terminate your string then your attack will be more likely to fail.

  Your answer is correct but it is too long. AutoLab ignores your answer.

+ The difference between phase 2 and phase 3.

  From the writeup- “When functions hexmatch and strncmp are called, they push data onto the stack, overwriting portions of memory that held the buffer used by getbuf. As a result, you will need to be careful where you place the string representation of your cookie.”

  Make sure your string is not getting overwritten by hexmatch or strncmp!

  A hint is, you may start with something like “move”, then followed by some padding or function/stack address, and finanlly end with the string representation.

+ How do I add breakpoints on instructions inside a function?

  `(gdb) b *ADDR` or `(gdb) b *(phase_x+OFFSET)`.

  For example, in this following disassembly:

  ```
  Dump of assembler code for function main:
     0x000000000040052d <+0>:	push   %rbp
     0x000000000040052e <+1>:	mov    %rsp,%rbp
     0x0000000000400531 <+4>:	mov    $0x4005e0,%edi
     0x0000000000400536 <+9>:	callq  0x400410 <puts@plt>
     0x000000000040053b <+14>:	mov    $0x0,%eax
     0x0000000000400540 <+19>:	pop    %rbp
     0x0000000000400541 <+20>:	retq   
  End of assembler dump.
  ```

  If you want to set a breakpoint on `callq 400401 <puts@plt>`, you could either do `b *0x400536` or `b *(main+9)`.

+ How do I find gadgets?

  Use the provided instruction sheet in the lab writeup. Try to find matches in the disassembly. Be aware that a valid instruction could start anywhere (in the start, middle, and end of an existing instruction), span more than one line, and could contain some `nop`s.