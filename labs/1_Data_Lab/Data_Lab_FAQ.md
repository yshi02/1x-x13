# FAQs about Data Lab (Lab 1)

Sorry it's been *a bit* late. But here are some important things to keep in mind when doing Datalab.

1. **READ THE WRITEUP**: Most questions not explicitly pertaining to solving the puzzles can be answered by reading the writeup and the header on bits.c thoroughly.

2. Datalab has multiple checkers that each test a different part of your solution

   + btest: Checks your solution against a large, but not exhaustive, set of test cases and edge cases. **Having a btest report no errors does not mean your code is correct!** btest also has some helpful flags which you can use to test individual functions with custom test cases. Run ./btest -h for more information about how to use btest.

   + dlc: A modified compiler that checks your solution for compliance with coding standards and legality. Running it can tell you how many ops you have for each function, whether your code uses any illegal operations, and if your code has any warnings that need to be addressed. Run ./dlc -h for more information about how to use dlc. Code that does not compile will not earn any points, so be sure to check with dlc!

   + bddcheck: Checks your solution exhaustively and generates "a genuine counterexample" if your solution is not fully comprehensive. This is the final authority on whether your solution is correct or not. **You will only earn correctness points if your code passes bddcheck!** Run ./bddcheck/check.pl -h for more information on how to use the bddchecker.

   + driver.pl: This is what Autolab uses to grade your submission. Be sure to run ./driver.pl before you submit to make sure that you are getting the points that you are expecting to earn! Note that the driver will not generate counterexamples. Instead, it will only tell you if your functions had any errors and how many points you earned. Use the bddchecker to find counterexamples.

3. Each problem has a "max ops" parameter; this is for scoring performance **only**. You will get 2 performance points per problem you solve under the max operation limit. Your correctness score will not be affected if you go over the operation limit.

4. Please do not discuss solutions in any way until after the deadline for the lab has passed. After you figure out a clever solution to a particularly hard problem, you may be tempted to share your genius with the world, but it's not worth committing an AIV over a problem you already solved.

   

**"That's cool and all but what if I can't figure out how to solve a problem?"**

Here are some tips and tricks if you are stuck. Note that not all of these tips will be applicable to every problem, but they can help you if you're not sure how to proceed.

1. Try to solve a simpler version of the problem first. See if you can reduce the problem down to a 1 bit or 1 byte case, then try to extend that to 2 bits/bytes and so on. 64 bit numbers are hard to visualize so it's helpful to first calculate all the possibilities for 2 or 4 bit numbers to build an intuition about what bit transformations need to be done and if those ideas can be generalized.
2. Work backwards from the solution. If you know what the answer is supposed to be, try to figure out if all the solutions have something in common. From there, you can potentially break up the problem into smaller subproblems that are easier to solve. For instance, if I knew the solution to a problem needed a particular bitmask at the end, then I can split up the problem into "how do I create the bitmask" and "how do I need to modify the input before masking".
3. Look at the scoreboard! This is not a joke; the scoreboard can be a legitimate source of information! If your solution seems to be getting nowhere or taking too many operations, sometimes it's helpful to see how many operations other students took. For instance, if the scoreboard claims that a problem can be done in 3 or 4 operations, and you know that at least 2 operations are absolutely necessary, then knowing that there are only a few operations left can help you refine your solution.
4. Take a break or work on a different problem. The questions are loosely ordered from easiest to hardest, but that doesn't mean that a higher point value problem is necessarily always harder than a lower value one. You may find insights while solving later problems that you can then apply to solve or optimize earlier problems.
5. Floating point numbers are hard to visualize and reason about, especially on edge cases like denormalized numbers. I found [this website](https://www.h-schmidt.net/FloatConverter/IEEE754.html) to be very helpful to visualize the bit distribution in a float and to see how the bits and corresponding value change after an operation has been applied.
6. Utilize the course resources! The course staff are here to help if you don't understand something fully. We can't give you the solutions (for obvious reasons) but we can definitely clarify your understanding of the problem and guide you towards figuring out the solution on your own!