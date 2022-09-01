# Log in to Shark Machines Without Password

A lot of students have asked how to log in to Shark without a password.

If you are tired of having to enter a password every time you log in to Shark, the easiest way is **to download a terminal that remembers your password** (and enters it for you), such as *termius* (https://termius.com/).

Many of you have tried to do this by setting *SSH pub-key authentication*. Unfortunately, however, **CMU machines use Kerberos, so they disable the pub key authentication**. The only way to gain access is through Kerberos authentication.

Kerberos is a way of authentication that works based on tickets. When you try to login via SSH, your Andrew ID and password are sent to the central Kerberos Ticket Granting Service (TGS). Once you are authenticated, the server will send you back a ticket that you can use to access the file system (the *afs*, Andrew File System).

This ticket is usually valid for a certain amount of time (for CMU, it is often 24 hours). After that period has passed, a new ticket is required. So, this requires **re-typing** in your password and **re-authenticating**.

Same for the domain: Once you logged into CMU machines, you are on your own “cell”, say “/afs/andrew.cmu.edu”. If you need to visit “/afs/cs.cmu.edu” you will need to get another ticket using “aklog”.

If you are interested in how it works for logging in without a password, continue reading. Otherwise, **THINK TWICE** if you really need this since each time you input your password won’t take more than 10 seconds but the configuration may cost you 10 hours.

------

We will use `krb5` to automate the requesting of tickets and passing your ticket via SSH in order to log in.

- Install the krb5 package. Google it.
- Add the following lines to your `~/.bashrc`, and then `source ~/.bashrc`

```
export PATH=/usr/local/opt/krb5/sbin:$PATH
export PATH=/usr/local/opt/krb5/bin:$PATH
run code snippet
Visit Manage Class to disable runnable code snippets×
```

- Get krb5 configurations to your local machine.

```
scp <YOUR_ANDREW_ID>@unix.andrew.cmu.edu:/etc/krb5.conf /etc/krb5.conf
```

- Comment out this line: `#default_ccache_name = KEYRING:persistent:%{uid}`.
- Create a keytab using `kutil`.

```
add_entry -password -p <YOUR_ANDREW_ID>@ANDREW.CMU.EDU -k 1 -e aes256-cts-hmac-sha1-96
write_kt keytab
```

- Get your ticket.

```
kinit -k -t ~/keytab <YOUR_ANDREW_ID>@ANDREW.CMU.EDU
```

- SSH into the machines by passing your ticket as an option.

```
ssh -o GSSAPIAuthentication=yes -o GSSAPIDelegateCredentials=yes <YOUR_ANDREW_ID>@unix.andrew.cmu.edu
```

- Now you will be automatically logged in without having to present your password.
- This works better with scripts and aliases and configuring your `.ssh/config` file. Do it yourself.

------

In order to help more students with their course study. We will **NOT** spend time supporting you with the configuration of Kerberos because it is beyond the course content too much.

However, for basic SSH issues, for example, if you need some software configurations on “letting my terminal remember my password”, feel free to ask us.