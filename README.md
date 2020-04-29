# MD5-message-digest-algorithm

## Project Statement
You must write a program in the C programming language that calculates
the MD5 hash digest of an input. The algorithm is specified in the Request
For Comments 1321 document supplied by the Internet Engineering Task
Force. The only pre-requisite is that your program performs the algorithm
— you are free to decide what input the algorithm should be performed on.
I suggest you allow the user to input some free text or a filename via the
command line.


## How to Run

This section is in place to provide instructions on how to clone, compile and run the project code. It will also will also detail how to create a linux subsystem on a windows operating system, as was performed for the development of this project and also how to install a C compiler on said system.

### Setting up environment  
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

### Clone, Compile, Run
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

