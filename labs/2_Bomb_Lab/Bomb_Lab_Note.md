# Notes about Lab2 (Bomb Lab)

Bomb lab has been released. Here are some notes about this special Lab. Ideally, you should **read this before doing the lab**, as you will be dealing with **a real binary bomb** that could explode!



1. Every bomb is **unique**. Each time you download a new bomb, you will get a brand new bomb. If you accidentally downloaded more than one bomb, then please be sure to only work on one bomb (which one does not matter, you could pick the one with a better looking number :-).

2. The bomb can **ONLY** be run on a Shark machine (**ONLY** the Shark machines (shark.ics.cs.cmu.edu). Andrew Unix Machine and other CMU-provided machines are **NOT** Shark machines). If you try to defuse it on your local machine, **IT WILL FAIL!**

3. You don’t need to submit the lab explicitly. Every time you enter your keys, Shark will send the keys to AutoLab and AutoLab will decide whether you defused a phase or exploded. You will get your score immediately.

4. **Once a bomb BOOM, it BOOMs! Once a bomb BOOM, it BOOM! Once a bomb BOOM, it BOOM!** NO Ctrl-Z. NO recovery. NO requests on regrading. But you can continue trying on the same bomb. No need to get a new one.

5. Each explosion is -0.5 points and the scores for this lab will be rounded - so it’s possible to get a full score with 1 explosion.

6. In the book, the `sar` should take 2 operands, k and D, and `sar k D` means D=D>>Ak. In the `objdump -d`that `sar` may take only one operand: in this case it means **arithmetic** right shift by 1.

7. In some phases, the answer may not be unique. There might be several answers for a phase, each of them is acceptable.

8. How to start defusing then?

   - You should figure out the 6 phases by looking at the assembly code and the memory.
   - Let’s say the first password is “123”, and you should try looking at the assembly code (something like mov, cmp) as well as the memory storage (maybe there is a number stored at 0x00100), to find out the password “123” and input it to defuse the bomb.

9. I am submitting a defusing string that contains an apostrophe and the Autolab backend silently explodes. What gives?

   + Please don’t submit defusing strings that contain apostrophes. There is a known bug in the backend AutoGrader that causes it to get confused by strings that contain apostrophes. In each of these cases, there is an alternate solution that doesn’t contain apostrophes.

10. How do I get to the secret phase?

    What secret phase? Never heard about that.

10. How much bonus will I get when I defuse the secret phase?

    Never heard about that. Maybe you can find something interesting.

11. Why the secret phase makes my bomb BOOM?

    The bomb should be defused first before you input the… wait!! Where did you find that “secret”?

12. **WARNING**: Do **NOT** use TUI mode. Although the TUI mode is very convenient, it has been known to accidentally set off students’ bombs during Bomblab (but is fine for future labs like Malloc Lab). The course staff is not responsible if your bomb goes off due to the TUI, and will **NOT** remove the explosion from Autolab. **Once a bomb BOOM, it BOOM!**

13. GDB Cheat Sheets: [GDB Ref-Card]() and [GDB Cheat Sheet](); x86 Cheat Sheet: [x86-cheat-sheet](https://cdn-uploads.piazza.com/paste/kc3x75jp8r34hc/71b828298961150b9460609999031a48f0522d8f8dc05b4e7d15b34df59d6b53/x86-cheat-sheet.pdf)

14. **Read every word in your write-up before you start** - It is a bomb. Don’t be kidding. Once a bomb BOOM, it BOOM!



### Welcome to the bomb squad!



