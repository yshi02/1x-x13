# C Programming Lab (Lab 0) FAQs

Here are some common problems people encounter while doing C Programming Lab. Ctrl+F is your friend!

**Note, Anything code-related can only be discussed via private threads.**

- If you get full credit by `make test` but get 0.0 on AutoLab, make sure your run `make format` before submission.
- If you get full credit locally but 0.0 on AutoLab, you can click on the 0.0 to see details.
- If you see “Permission Denied” when trying to run any of the executables, use `chmod +x <executable_name>` to give yourself the permissions necessary (remember the principle of least privilege!)
- Some traces tell you that you have a memory leak, or you still have allocated blocks after running, please check again and again on your `free()`, especially when an error happens.
- Even if you handled action B, remember that sometimes it is necessary to keep track of action A, and handle it, if action B fails.
- A lot of students forget to add the string terminator `\0`, which may result in a `...XXXXXX` error. It has NOTHING to do with the buffer you thought. Check if you added the terminator CORRECTLY.
- Always be careful when `q` is NULL or `q->head` is NULL or the string buffer is NULL.
- List has cycle? You also need to assign a value to `newh->next` when `q->head` is NULL. By the way, you only need to take care of the tail when inserting the head into an empty queue. And please consider the situation that malloc returns NULL as the hint describes.
- When copying, think again and again what do you need. `strcpy`? `strncpy`? `memcpy`? Thought about it? Think about it again…
- Did you really `free`-ed everything? Check carefully.