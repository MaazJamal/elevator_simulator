# Introduction

Elevator_Simulation is a software that operates any number of elevator in a commercial building with given number of floors.

# Installation

Please refer to [INSTALL.md](https://github.com/MaazJamal/elevator_simulator/blob/devel/INSTALL.md) file for installation instructions.

# Usage

The user needs to provide the software with a text file containing the passenger request detail for the elevator. The text file is named input.txt and must be placed in the "data" folder. The relative path is data/input.txt. The maximum number of floors in this file should correspond to what the user enters later in the program.

To start the program in windows either click on elevator.exe or type elevator.exe in command line. For cygwin/unix type ./elevator to start execution.

The program will ask for the following parameters at the execution of Elevator_Simulation:

- Static or Dynamic version : Press 0 to select Static Version or 1 to select Dynaic version. (Only for realease 2 version of program.)

- Number of lifts : Specifies the number lifts in the building should be in the range of 1 to 100.

- Number of elevators: Specifies the number elevators in the building should be in thr range of 1 to 100.

- Input file should be placed in the right path.Change the input file if needed. In the data/ folder

In case of Dynamic version

- Add Passenger request : If needed pass passenger request manually in the same format as Input file.

- Decide on the simulation when encountered a emergency stop condition. Press 1 to continue simulation or 0 to terminate the simulation.

Please note that the binary is located in project `root` folder

```
.elevator
```

for windows

```
elevator.exe
```

# Testing

Unit testing is done for each functions defined in the software. The test cases can be run using the command below:

```
./tests
```

for windows

```
tests.exe
```

Note: You must have compiled the tests.exe program as well.

# Output Generation

Below output files will be generated and placed [here](https://github.com/MaazJamal/elevator_simulator/blob/devel/data/)

Output file 1 - File that gives Passenger*ID,Elevator_ID,Passenger_In time,Passenger* Entry floor,Passenger*Out time,Passenger* Exit floor

Output file 2 - File that gives Average waiting time of Passengers and Maximum waiting time of a Passenger.
