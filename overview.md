# Introduction

This project was created as part of the Theory of Algorithms module in the 4th year of the Computing in Software Development taught at GMIT. The project statement was the we, the students, develop a program, written in the C programming language, that calculates the MD5 hash digest of a given input. The construction of the MD5 algorithm is outlined in the RFC 1321 document created by the Internet Engineering Task Force[1]. This request for this report was created as a late addition due the Covid_19 outbreak and aims to provide an overview of the project and to include instructions on how the program should be compiled and run, instructions on how to run the test suite included in the program, an overview of the algorithm used in the program code and a section on the complexity of the MD5 algorithm itself.

## The repository contains:   

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
* From here enter the following command into the Powershell terminal  
```Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux```
* After this command has finished running you will be forced to reboot your device.
* Follow this link, to get the free Ubuntu subsystem installed on you Windows OS, [here](https://www.microsoft.com/en-ie/p/ubuntu-2004-lts/9n6svws3rx71?activetab=pivot:overviewtab)
* From here select the "Get" option to be taken to the Microsoft store and from the Microsoft store select the "Install" option.
* After the installation a linux terminal window will open, from here follow the commands presented in the terminal to set up your linux environment.
* After the environment has been set up, enter the following command to install a C compiler  
``` sudo apt install gcc ```  
* To confirm that the C compiler has been installed, enter the following command  
``` gcc --version ```

## Clone, Compile, Run
* From the Ubuntu subsystem, enter the following line to clone the repository  
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

*** THE COMMAND, PROBABLY -t, PLUS WHAT IS OUTPUT( SOMETHING LIKE IF INPUT = A, OUTPUT SHOULD = WHATEVER THE HASH IS ***

# Algorithm
The MD5 message-digest algorithm is a hashing algorithm, released in 1992, that takes in a an input message of arbitrary length and outputs a 128-bit message-digest of the input[1]. It has been designed such that it is infeasible that any two different inputs will produce the same message-digest. 
### Example
 Input ``` Hello world ``` produces output ``` 3e25960a79dbc69b674cd4ec67a72c62 ```  
 Input ``` hello world ``` produces output ``` 5eb63bbbe01eeed093cb22bb8f5acdc3 ```

The core purpose of the MD5 algorithm is that it is used to ensure data integrity. This means that data remains consistent and can be proven to be non-altered. I found [this video](https://www.youtube.com/watch?v=33QT7xohUvI&t=)[2] to have been helpful in accurately displaying how even the most minute change will have a profound effect on the hash digest produced by the algorithm and how obvious the algorithm allows data tampering to be exposed. In cases such as when a file is compressed and sent to another machine this "figerprint" security is important in ensuring data itegrity.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=33QT7xohUvI&t=" target="_blank"><img src="http://img.youtube.com/vi/33QT7xohUvI/0.jpg" 
alt="MD5 Hash Tutorial - What the MD5 hash means and how to use it to verify file integrity." width="240" height="180" border="10" /></a>
   
**The MD5 Algorithm is performed in 5 steps**

## Step 1. Append Padding Bits
The padding of the input message is extending it so that when it's length(in bits) when divided by 512, leaves a remainder of 448. This padding operation is always performed even if the initial length of the input message is 448 bits. The padding will be at least 1 bit and at most 512. This padding is performed by appending a single "1" bit to the input message and then adding additional "0" bits until the new length of the message is 448, modulo 448.  


****** CODE SNIPPET HERE ******
## Step 2. Append Length  
A 64 bit representation of the initial length of the input message is appended to the result of the previos steps padding process. After this has occured the length of the message is now exactly 512 bits, this now allows the message to be structured into 16, 32-bit words.  

****** CODE SNIPPET HERE ******
## Step 3. Initialize MD Buffer


****** CODE SNIPPET HERE ******
## Step 4. Process Message in 16-Word Blocks  


****** CODE SNIPPET HERE ******
## Step 5. Output  


****** CODE SNIPPET HERE ******
# Complexity

# References
[1] [Rivest, R., 1992. RFC1321: The MD5 message-digest algorithm.](https://www.ietf.org/rfc/rfc1321.txt)  
[2] [MD5 Hash Tutorial - What the MD5 hash means and how to use it to verify file integrity](https://www.youtube.com/watch?v=33QT7xohUvI&t=)    
[3]  
[4]  
[5]  
[6]  
[7]  
[8]  
[9]  
[10]  
