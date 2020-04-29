# Introduction
This project was created as part of the Theory of Algorithms module in the 4th year of the Computing in Software Development taught at GMIT. The project statement was the we, the students, develop a program, written in the C programming language, that calculates the MD5 hash digest of a given input. The construction of the MD5 algorithm is outlined in the RFC 1321 document created by the Internet Engineering Task Force[1]. This request for this report was created as a late addition due the Covid_19 outbreak and aims to provide an overview of the project and to include instructions on how the program should be compiled and run, instructions on how to run the test suite included in the program, an overview of the algorithm used in the program code and a section on the complexity of the MD5 algorithm itself.

The repository contains:   

* Overview.md, which is this file.
* README.md, which is a file written in the markdown language which contains comprehensive information on how to install and run the code. It also contains a breakdown of the research involved in the original projects development.
* Video Tutorials(folder) which contains snippets of code provided via online lecture videos provided by the lecturer.
* Test(folder), this folder contains .txt files which are used as part of the testing of file input to the MD5 algorithm.
* md5.c, which is a c file used locally, exclusively for testing purposes.
* main.c, which is the file that contains the MD5 algorithm and a main method, both written in the C language, this is the file which must be compiled to run the MD5 algorithm


# Run
This section is in place to provide instructions on how to clone, compile and run the project code. It will also will also detail how to create a linux subsystem on a windows operating system, as was performed for the development of this project and also how to install a C compiler on said system.

## Setting up environment  
* Open Powershell and select the "Run as an Administrator" option.
* From here enter the following comman into the Powershell terminal  
```Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux```
* After this command has finished running you will be forced to reboot your devide.
* Follow this link, to get the free Ubuntu subsytsem installed on you Windows OS, [here](https://www.microsoft.com/en-ie/p/ubuntu-2004-lts/9n6svws3rx71?activetab=pivot:overviewtab)
* From here select the "Get" option to be taken to the Microsoft store and from the Microsoft store select the "Install" option.
* After the installation a linux terminal window will open, from here follow the commands presented in the terminal to set up your linux environment.
* After the environment has been set up, enter the following command to install a C compiler  
``` sudo apt install gcc ```

## Clone, Compile, Run
* From the Ununtu subsystem, enter the following line to clone the repository  
``` Git Clone https://github.com/CookeRichard94/MD5-message-digest-algorithm ```
* From here, change directory to the project by entering the following command  
``` cd MD5-message-digest-algorithm/ ```
* To compile the project code  
``` gcc -lm -Wall -o md5 main.c ```
* To run the code and to hash an input string, enter the following command   
``` ./md5 "Your string here" ```
* To run the code and to hash the contents of a file, enter the following command  
``` ./md5 file.txt ```

# Test 

# Algorithm

# Complexity

# References
