# FAQs about VSCode

A lot of you are using VSCode, and we do meet a lot of strange issues on VSCode. We will list some common issues here to help you quickly locate the original posts. We will update this as other issues come to light. (Note that all VSCode issues can be solved by switching to `vim`/`emacs`/etc.).

+ When you use VScode with some plugins to SSH to Shark Machines, it will create a “`.vscode-server`” folder in your home directory and create a lot of files there. The more you use, the larger the files are. If you find you cannot connect/git clone hanging/SSH failure/… Make sure you have enough space in AFS. You can delete this folder by “`rm -r .vscode-server`”. **Please be careful with the rm command as it can be very destructive!**

+ In Lab6 (Shell Lab), when you run trace 9, you will see “SSH reconnecting” on VSCode. You might think you wrote something wrong, but when you use other IDEs (e.g., CLion), or Terminals, you won’t see this strange message, and instead, you just see you fail to pass this trace. Is this a VSCode plugin error?

  Kind of. Make sure you aren’t killing the job id and rather the pid from the job list. Otherwise, you are killing important system processes. But unfortunately, we are still not sure why these processes will make VSCode-related services down while they can work in other IDEs.

+ If you find sometimes you cannot compile something, still the possibility that you are running out of quotas. You can verify this by using `fs quota`.