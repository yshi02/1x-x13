# Evaluating Throughput Tips

Hey Everyone!

Here's a tip that helped me when evaluating performance of my malloc implementations.

Theres this handy tool called perf that’s included inside the shark machines that you can use to your benefits. In order to use it simply run.

```
perf record ./mdriver
```

and simply run it as normal until completion.

Afterwards you’ll see that perf.data will be inside your directory. Open it with

```
perf report
```

And you can see which parts of the code are slowing down your implementation so you don’t waste time improving parts that won’t speed up your implementation.

Just make sure you delete the perf.data file afterwards because it takes up a lot of space.

Good luck!