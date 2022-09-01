# Easy Set-Up for 18213/613

If you're wondering how to set up for 213, here is a guide from 122:

https://drive.google.com/drive/folders/1BWtuvo9BPkO6OQDUVEclBKJ5GPYAetNm?usp=sharing

(note: you'll need to be logged in to your Andrew account to access the file. I won't be approving requests from external email addresses)



The first doc uses the SSH targets in VSCode, I think the slideshow method using SFTP is more foolproof. 

If you use that method, use the the SFTP extension by Natizyskunk in VSCode, not the one listed, and edit the SFTP file as in the followup in (7) (you can set the host to your favorite shark or as written in here).



Notes to make while following these instructions: 

1) Name your folder 18213 (or 18613), instead of "15122". For obvious reasons.

2) Where it says YOURANDREWID@unix.blahblahblah, instead use YOURANDREWID@<some shark extension>. You can pick your favorite shark here: https://www.cs.cmu.edu/~18213/labmachines.html

None of them are better than the others, I went by which shark I thought was the cutest and it served me well

3) There's no need for the c0 extension. You can install the C/C++ extension, and C/C++ Extension pack (both by Microsoft), or any other extension you research and think would be helpful. 

4) Suppose you follow all these instructions and then go through the semester and make subfolders, so you have something like ~/blahblah/.../Desktop/18213/Lab0 . Note that if you go into VSCode and open up the Lab0 folder and start editing, this WILL NOT automatically save your edits to the shark machine, and you may lose your work. Even if you only want to access Lab0, you should always first open the 18213 folder in VSCode, and then click through your Lab0 files from the panel inside VSCode. I speak from experience :/ If you've had to enter your password opening the folder/VSCode, you should be good to go.

5) If you have something in the server that you need downloaded locally, or vice versa, right click on the panel and click "sync remote to local" or "sync local to remote". The former is most helpful when you un-tar the files in the terminal and then want to actually access the files. 

6) I personally don't like using the VSCode terminal to run things. As the semester goes on, there is sometimes lag that occurs when everyone runs a bunch of stuff through VSCode by SSHing into Shark machines. This isn't a huge issue, but I prefer having a terminal set up elsewhere. For other Windows users, I use MobaXterm (not necessarily the best one). To set up a shark terminal, download MobaXterm, click "Session" in the top left corner, and click SSH. In "remote host", either type some chosen shark (e.g. "hammerheadshark.ics.cs,cmu.edu") or "shark.ics.cs.cmu.edu". The first one would always log you into hammerhead, the second will randomly choose a shark everytime you log in. You can specify username so you don't have to type that in everytime. The first time you type in your password, you can also choose to save that (not sure if it works for the shark.ics login, since it changes your machine everytime you open the terminal. Now, when you open MobaXterm/try to create a new tab, your host should be in the panel on the left, and you can just click it to start working. I like to move and unbox my files in here, and run code, but actually code in VSCode. VSCode and your terminal don't need to be on the same shark to work at the same time, as long as you hit save when you edit in VSCode (you can also check if these changes have actually made their way to the server by using vim to see the file from your terminal). If this is confusing, please ask follow-up questions! I have no idea how to do this for Macs but I'm sure another TA can help out with this :) 

7) Here's the how you can set up the SFTP extension:

   It should be all set, unless you changed anything major on your computer/editor. (except SFTP file transfer)
   First make sure you have the SFTP extension by Natizyskunk installed in VSCode.
   I would recommend making within your local 18213 folder a sub-folder to contain just your code, so you won't use AFS storage space on other course materials.
   To set up file transfer between your local machine and the sharks, open your local 18213 code folder through VSCode, use Shift+Cmd+p and type SFTP. Select SFTP: Config. It should open up a file in the editor named sftp.json.
   Paste the following into the file, overriding what's already there:

   ```
   {  
       "name": "18213",  
       "host": "shark.ics.cs.cmu.edu",  
       "protocol": "sftp",  
       "port": 22,  
       "username": "andrewID",  
       "remotePath": "private/18213",  
       "uploadOnSave": true,  
       "downloadOnOpen": true,  
       "ignore": [  
           ".vscode",  
           ".git",  
           ".DS_Store",  
           "admin"  
       ]  
   }  
   ```

   **Keep the quotation marks in place for the following changes, replacing only the text inside**:
   Replace the host field with a specific shark if you have a favorite shark
   Replace the username field with your andrewID
   Replace the remotePath field with the path for the 18213 folder you create on the shark machines
   You should be all set from here.



Note that this is not the only set-up configuration possible for this class, and something else/more advanced may work better for you, so if you know what you want to do, go offffff! Have fun! Just remember, you will need to test your code on Shark machines in later labs as opposed to locally (it will matter!), so make sure whatever you do, it works!