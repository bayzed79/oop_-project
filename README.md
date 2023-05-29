# oop_-project name: Vehicle repair and maintainance system
## Description
This project is a vehicle repair and maintainance  system. It allows users to interact with a rental shop, where they can rent vehicles, return vehicles, display available vehicles, and repair vehicles.
## Features

1. Vehicle Management: The project allows users to manage vehicles by adding them to the rental shop. The rental shop stores vehicles using polymorphism, as it can hold objects of different types derived from the base Vehicle class.

2. Vehicle Display: Users can view the available vehicles in the rental shop. The system provides options to display all vehicles or only the available ones.

3. Vehicle Rental: Users can rent a vehicle from the rental shop. The system checks the availability of the chosen vehicle and marks it as unavailable for the rental period.

4. Vehicle Return: Users can return a rented vehicle to the rental shop. The system verifies if the vehicle was previously rented and updates its availability status accordingly.

5. Vehicle Repair: Users can request to repair a vehicle in the rental shop. The system marks the vehicle as available and performs any necessary repairs or maintenance.

6. Different Vehicle Types: The project supports different types of vehicles, including cars, motorcycles, and micro buses. Each vehicle type has its own specific attributes and behaviors.

7. User Interface: The project provides a menu-driven interface for users to interact with the rental shop. Users can select options from the menu to perform various operations, such as renting, returning, and repairing vehicles.

## OOP features used for implementation
class 
object
inheritance 
polymorphism 
Encapsulation
Abstraction
Constructor
Exception Handling 
Virtual function 
....

## How to operate the system

To operate the vehicle rental system, you can follow these steps:

1. When you run the program, you will be presented with a menu of options.

2. Use the menu options to perform different operations:

   a. Option 1: Display Available Vehicles
      This option will display the vehicles that are currently available for rent in the rental shop.

   b. Option 2: Rent a Vehicle
      Choose this option to rent a vehicle. Enter the index of the vehicle you want to rent. If the vehicle is available, it will be rented, and its availability status will be updated.

   c. Option 3: Return a Vehicle
      Select this option to return a previously rented vehicle. Enter the index of the vehicle you want to return. If the vehicle was rented, it will be marked as available again.

   d. Option 4: Repair a Vehicle
      This option allows you to request the repair of a vehicle. Enter the index of the vehicle you want to repair. If the vehicle is currently unavailable, it will be marked as available and repaired.

   e. Option 5: Exit
      Choose this option to exit the program and end the rental shop operation.

3. After performing each operation, the program will display the corresponding output or messages. For example, when renting a vehicle, it will show the rented vehicle's details. If an error occurs, such as trying to rent an unavailable vehicle, an error message will be displayed.

4. You can continue operating the system by selecting different options from the menu as per your requirements.

Note: The program assumes that you are familiar with the index-based selection of vehicles. Each vehicle added to the rental shop is assigned an index, starting from 0. When prompted to enter an index, make sure to enter a valid index within the range of the available vehicles.

By following these steps, you can operate the vehicle rental system and perform various operations such as displaying available vehicles, renting vehicles, returning vehicles, and requesting vehicle repairs.
