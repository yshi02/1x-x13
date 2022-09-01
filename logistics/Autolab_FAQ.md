# FAQs about AutoLab and related questions

**Hi everyone, there are some general questions frequently asked by you, and I am trying to answer these questions in this post so that you don’t need to post repeatedly to ask.**

1. What is Lab and do we need to go to the lab to write code?

   No. Labs are your homework (assignments). Just download it from AutoLab, read the instructions (handout, writeup, and/or road map if provided), complete the tasks yourself and make sure you submit it to AutoLab before the due date.

2. What is AutoLab, how to download/install it?

   It is a website of CMU. You don’t need to download/install it. You can download your labs there, and upload/submit your solutions back to AutoLab. AutoLab will automatically run your solution and give you feedback/scores. See https://autolab.andrew.cmu.edu/ for details.

3. Can’t have access to AutoLab.

   Professors are working on that. Please wait for a few days and try again. If that doesn’t work, please contact the professor/TAs.

4. No lab on AutoLab.

   It might not be released yet. Follow Piazza more often and you will be notified when labs are released.

5. Do I need a Linux environment?

   Linux is not a must in most cases in FCS/ICS.

   Most of the code can be done in any IDE (Code::blocks, CLion, VS Code) using Windows or even in notepad (Sublime, Notepad++), and you can test it easily. You can run it locally and just upload your solution to AutoLab, which is a Linux environment.

   For some specific points (basically Bomb Lab and Malloc Lab), a Linux environment is required. We will provide you with such an environment, called a Shark machine, and all you need to do is to log in and start your work. We will tell you how to use it in a few days (or maybe weeks) later.

   If you do need a local Linux environment, you can try to install TDM-GCC (for Win10), or Virtual Linux environment such as WSL or VMWare, or Docker, or you can install a dual-system on your laptop. We hope we can give you more information about these if you are not familiar with those technologies.

6. Is it a must to use Shark?

   No. See the FAQ above. You can use your local environment.

   We recommend Shark because it provides you with the same environment as that of the auto-grader. We also notice the Internet connection to Shark is not stable and some of you are more willing to use the local environment, so it is totally fine.

   BUT! For some specific point (basically Bomb Lab), you must complete the whole lab using Shark. You will be given details when that comes to you.

7. Can I submit more than once to AutoLab?

   Sure. You can have unlimited tries for most labs. Just modify your code, upload it and you will see the latest results.

   For some specific point (basically Bomb Lab), you should be careful: Every time you submit the wrong answer, the Bomb will BOOM! And you will lose your score.

8. The code works on my local machine but not on AutoLab.

   Everything is based on AutoLab’s results. Not your local results.

   You can always click on the score to go to the details page, where AutoLab’s results are displayed.

9. What is the due date?

   It will be shown in AutoLab and also the course website (https://www.cs.cmu.edu/~18213/). Be sure to submit your solution before that date.

   If something unexpected happens, we might change the due date but if not, you still need to follow that due date shown. We will tell you when the due date is changed.

10. What is grace day?

    Turn to your hand-book to see the definition.

    Generally, the purpose of grace days is so that you can quickly give yourself a 1-day extension, for any reason you choose. This includes out-of-town trips, health issues, lack of time, WiFi problems, car trouble, etc. Grace days are not intended solely as a time-management tool, but a convenient way to give yourself an extension.

    Note that different lab has different MAX grace days. You cannot use more grace days beyond that limit even though you have more grace days available. And note that for some labs, you are not allowed to use grace days. As is listed (and will be updated) on the website.

11. Is there a recitation today/next week? What is the time schedule? Any course resources?

    Professor will tell you about the overview of this course in your first lecture.

    Basically, Piazza and the course website are all you need (https://www.cs.cmu.edu/~18213/).

    You can click “Schedule” to see the course schedule and “Labs” to see the deadlines of labs. When something changed, you will also be notified in Piazza. So please follow Piazza from time to time.

12. Will we need to modify the makefile for the coding running on a local environment?

    The tasks won’t force you to modify the Makefile, but you can modify it for debugging purposes or you want to make it work in your local environment.

    You can read https://www.cs.cmu.edu/~15131/f17/topics/makefiles/compiling-code/ if you want to know something about the Makefile. Not an in-depth tutorial but sufficient I think.

    Remember that you will still need to submit your solution to the auto-grader so you shouldn’t expect that you can bypass something and get full scores by modifying your Makefile locally.

13. **Autolab is available on Shark machines as a commandline tool.**

    You can download your assignments on Shark machines by `autolab download <coursecode>:<assignment-name>`. The `<coursecode>` is usually something like 18213-f22. You could find it on the web page of Autolab or in `.labname.mk` which will be in any lab directories you downloaded. The `<assignment-name>` can be found by `autolab asmts <coursecode>`.