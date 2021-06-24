# os-project
CSCI 3300 - Operating Systems - Programming Project

<hr>
This project is an implementation of the banker's algorithm in C++.

This repository contains the source files and the information required to compile the source code into a binary executable file to run the program 

The program is written in C++, any C++ compiler can complie and successfully build the program to be run. 

Recommended is GCC from the GNU Project. 
GCC is only available on linux distributions, however it can be installed on Windows using MinGW or Cygwin projects. To compile with GCC, run the following command on the CLI:
```bash 
gcc banker.cpp -o banker
```

Otherwise on Windows, one can download Microsoft Visual C++ which comes with a C++ compiler. To compile using Visual C++ compiler CL, run the following in the command prompt:
```cmd
cl banker.cpp
```

On MacOS, XCode can compile C++ or Clang C++ can be installed. To compile with Clang, run the following command in the terminal:
```
clang banker.cpp
```

This will output an binary executable file in the current working directory. Running the executable will allow you to interact with the program
