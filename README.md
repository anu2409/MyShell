```
NAME : SHASHANK SHEKHAR
ID   : 1001767592
CSE 3320 : OPERATING SYSTEMS
```
---

##### Code can be found at

```
https://github.com/anu2409/MyShell
```

##### How to run the code

```
    1. Go to the Makefile folder.
    2. make all
    3. ./oscode (run the file)
    4. make clean (remove the executable)
```

#### List of functions
 - `void` init_WelcomePage();
 ```
 1. Prints the welcome message.
 2. Prints the timestap.
 3. Calls list_Directories() and list_FilesInDirectories()
 ```
 - `void` list_Directories();

 ```
  List all the directories available.
 ```
 - `void` list_FilesInDirectory();
 ```
  List all the files present in the current directory.
 ```
 - `void` getAllOperations();
 ```
 Get the list of all available options.

    - Display
    - Edit
    - Run Executable File
    - Change Directory
    - Sort Directory
    - Move Directory
    - Remove File
    - Quit
 ```
 - `void` edit_Directory();
 ```
 1. Open the file in a text editor.
 2. Default editor : gedit.
 3. Alternatives : nano, source, pico, vim, code (VS code).
 ```
 - `void` run_File();
 ```
 1. Run the executable file.
 2. USAGE : ./filename
 ```
 - `void` remove_File();
```
Remove the file from the current directory.
```
 - `void` move_Directory();
```
Move the file from source to destination folder.
```
---