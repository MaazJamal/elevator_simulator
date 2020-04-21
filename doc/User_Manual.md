# Introduction

Elevator_Simulation is a software that operates any number of elevator in a commercial building with given number of floors.

# Installation

Please refer to [INSTALL.md](https://github.com/MaazJamal/elevator_simulator/blob/devel/INSTALL.md) file for installation instructions.

# Usage

The user needs to input the software with a text file containing the passenger request detail for the elevator.

The following parameters are to be given after the execution file Elevator_Simulation:

- Static or Dynamic version : Press 0 to select Static Version or 1 to select Dynaic version.

- Number of lifts : Specifies the number lifts in the building should be in thr range of 1 to 100.

- Number of elevators: Specifies the number elevatorsin the building should be in thr range of 1 to 100.

- Input file should be placed in the right path.Change the input file if needed.

In case of Dynamic version

- Add Passenger request : If needed pass passenger request manually in the same format as Input file.

- Decide on the simulation when encountered a emergency stop condition. Press 1 to continue simulation or 0 to terminate the simulation.



Please note that the binary is located within `bin` folder

```
./bin/elevator_simulation -e
```

# Testing

Unit testing is done for each functions defined in the software. The test cases can be run using the command below:

```
./bin/elevator_simulation -t
```

# Help

User can run the below command to know the details about input parameters.

```
./bin/elevator_simulation -h
```

# Output Generation
Below output files will be generated and placed here (https://github.com/MaazJamal/elevator_simulator/tree/devel/data)

Output file 1 - File that gives Passenger_ID,Elevator_ID,Passenger_In time,Passenger_ Entry floor,Passenger_Out time,Passenger_ Exit floor

Output file 2 - File that gives Average waiting time of Passengers and Maximum waiting time of a Passenger.

```
make clean && make
```

Then run the `elevator_simulation` binary again
