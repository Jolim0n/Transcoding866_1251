# Transcoding866_1251
Transcoding a text line into a line. From system 866 to 1251 and vice versa.
# Build with Visual Studio 17 and Build with CMake.

# How to launch
## If you have Linux:
You can simply run the CMakeLists.txt file through the command line.
[CMake for Windows and Linux](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

```
sudo apt-get install cmake
sudo apt-get install cmake-gui
git clone https://github.com/Jolim0n/Transcoding866_1251.git
cd Transcoding866_1251
cmake .
cmake --build .
```
## If you have Windows:
+ Open a command line.
+ Enter the path to the СMake folder where the project will be deployed.
### For example: 
```
cd C:\Users\User\source\repos\eremenko\eremenko\Cmake
cmake .
cmake --build .
```
Project will build.
## To start a project you need:
+ make a configuration file. For example: "conf.txt"
+ In this file, write the input and output files. For example : 
```
code1251->866 in.txt out.txt
code866->1251 in2.txt out2.txt
```
+ In the source files write lines in the correct systems. For example transcoding from 1251 to 866.
### ![in](https://user-images.githubusercontent.com/55711116/83777987-c2b06e80-a692-11ea-9537-5b8bc04c71d4.jpg)
+ For example transcoding from 866 to 1251.
### ![in2](https://user-images.githubusercontent.com/55711116/83777989-c3e19b80-a692-11ea-9dae-1dacde3ff3d5.jpg)
+ and the output files must also be in the correct encodings.
### ![out](https://user-images.githubusercontent.com/55711116/83777991-c3e19b80-a692-11ea-9a6f-0020f417136f.jpg)
### ![out2](https://user-images.githubusercontent.com/55711116/83777992-c47a3200-a692-11ea-83e5-f67dc062b03a.jpg)

# Program algorithm development.
+ Check what is passed to the command line, if any
+ If is equal to «/? »Withdraw help on the program.
+ If the second - read the name of the task file from the file.
+ Open the "task" file (If it does not open, display the error and close the program).
+ For each line from the file, execute:
  + Break the line into three words: the second and third word - the names of input and output files.
  + If the first word is equal to "code866-> 1251" then execute algorithm 1.
  + If the first word is equal to "code1251-> 866" then execute algorithm 2.
  + Otherwise output an error about the incorrect task file format.
+ Algorithm №1:
  + Opens input and output files (output error if failed).
  + For all read lines from the input file, recode the line according to the algorithm №3, recode the line, write to the output file and close the program.
+ Algorithm №2:
  + Opens input and output files (output error if failed).
  + For all read lines from the input file, recode the line according to the algorithm №3, recode the line, write to the output file, close the program.
+ Algorithm № 3
  + On the input line in encoding 866. On the output line in encoding 1251.
  + To increase the efficiency of transcoding, you can pre-create index tables. For example: TAB866_125 [character_code_in_866] = character_code_in_1251.
And then use this table - the complexity of the algorithm O (1)
For each character of the input string in 866 [S] get the recoded character as the value of TAB866_1251 [code_S]
# Code 866 system
### ![866](https://user-images.githubusercontent.com/55711116/83778533-83365200-a693-11ea-9c33-eeec005af130.gif)
# Code 1251 system
### ![1251](https://user-images.githubusercontent.com/55711116/83778539-84677f00-a693-11ea-9c68-d867759e7fd1.png)
# Author
+ Made by: [Kosinsky Denis](https://www.linkedin.com/in/denys-kosinskiy-025a391aa/)
