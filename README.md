# PC Desktop Cleaner
## program in C++ (Linux OS)
## Problem Description:-
1. First problem to find top 10 biggest files from a Directory/whole system.
2. And second one is to move the files from a source directory to folders according to their extensions in to destination directory.
## Functions Descriptions:-
For first problem :-
  ## scan_f()
      This function scan all the folders exiting in given directory and send the information of 
      files to put() function.  
  ## put() 
      This function insert the information of files into a vector of size 10 according to increasing 
      order of size of files and by insertion sort it add the files in vector.          
For second problem-
  ## Desk()
      Desk() function scan all folders from source directory and find the files and then send the 
      path of files to move_file() function.
  ## move_file()
      move_file() function move files to folders according to their extensions into the destination
      directory and delete files from source directory.               
## How to use:-
1. For first problem terminal ask the path of Directory or path of home. Not any final output is showing in terminal.
2. For second problem teminal ask two path, source directory path and destination directory path. From main i am showing 
  all the information of files name and size of file.
