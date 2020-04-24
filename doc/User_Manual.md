# Introduction

Elevator_Simulation is a software that operates any number of elevator in a commercial building with given number of floors.

# Installation

Please refer to [INSTALL.md](/devel/INSTALL.md) file for installation instructions.

# Usage

The user needs to provide the software with a text file containing the passenger request detail for the elevator. The text file is named input.txt and must be placed in the "data" folder. The relative path is data/input.txt. The maximum number of floors in this file should correspond to what the user enters later in the program.

To start the program in windows either click on elevator.exe or type elevator.exe in command line. For cygwin/unix type ./elevator to start execution.

The program will ask for the following parameters at the execution of Elevator_Simulation:

- Static or Dynamic version : Press 0 to select Static Version or 1 to select Dynaic version. (Only for realease 2 version of program.)

- Number of lifts : Specifies the number lifts in the building should be in the range of 1 to 100.

- Number of elevators: Specifies the number elevators in the building should be in thr range of 1 to 100.

- Input file should be placed in the right path.Change the input file if needed. In the data/ folder

In case of Dynamic version the program only simulates until 1999 iterations. This is due to limitations of console windows,causing the program to slow down due to printing of cli_update. There are additional inputs the user can give to the program after every 30th or 200th iteration.

- Add Passenger request : If needed the user can enter details of a passenger to the program. That will be added to the queue.

- Provide emergency stop in which the elevator will stop at next floor and remove all passengers. The user can then quit or continue the simulation.

- Enable realtime mode. In which each iteration is 1 second long and the program asks for input after every 30th iterations.

- Do not ask for input again and disable the realtime mode. So that the program can run without interuptions until completion.

- Exit the simulation.

Please note that the binary is located in project `root` folder. To start open terminal and type in root directory:

```
./elevator
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

Output files travel_log.txt and waiting_times.txt  will be generated and placed in [/data](/devel/data/) folder.

travel_log.txt - File that gives Passenger*ID,Elevator_ID,Passenger_In time,Passenger* Entry floor,Passenger*Out time,Passenger* Exit floor

waiting_times.txt - File that gives Average waiting time of Passengers and Maximum waiting time of a Passenger.
