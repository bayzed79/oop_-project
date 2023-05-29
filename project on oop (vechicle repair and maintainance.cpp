#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

namespace RentalSystem {
    // Base class for vehicles
    class Vehicle {
    protected:
        string make;
        string model;
        int year;
        bool isAvailable;
    public:
        Vehicle(string make, string model, int year) : make(make), model(model), year(year), isAvailable(true) {}

        void setMake(string make) {
            this->make = make;
        }

        void setModel(string model) {
            this->model = model;
        }

        void setYear(int year) {
            this->year = year;
        }

        string getMake() const {
            return make;
        }

        string getModel() const {
            return model;
        }

        int getYear() const {
            return year;
        }

        bool getAvailability() const {
            return isAvailable;
        }

        void setAvailability(bool availability) {
            isAvailable = availability;
        }

        virtual void displayInfo() const = 0;

        virtual void repair() {
            cout << "Repairing " << make << " " << model << endl;
           
            isAvailable = true;
        }

        virtual void rent() {
            if (isAvailable) {
                cout << "Renting " << make << " " << model << endl;
                isAvailable = false;
            }
            else {
                throw runtime_error("Sorry, the vehicle is not available for rent.");
            }
        }

        virtual void returnVehicle() {
            if (!isAvailable) {
                cout << "Returning " << make << " " << model << endl;
                isAvailable = true;
            }
            else {
                cout << "The vehicle is already available." << endl;
            }
        }

        virtual ~Vehicle() {}
    };

    // Derived class for cars
    class Car : public Vehicle {
    private:
        int numDoors;
    public:
        Car(string make, string model, int year, int numDoors) : Vehicle(make, model, year), numDoors(numDoors) {}

        void setNumDoors(int numDoors) {
            this->numDoors = numDoors;
        }

        int getNumDoors() const {
            return numDoors;
        }

        void displayInfo() const override {
            cout << "Car: " << make << " " << model << ", Year: " << year << ", Doors: " << numDoors << endl;
        }

        void repair() override {
            Vehicle::repair();
            
            numDoors = 4;
        }

        virtual ~Car() {}
    };

    // Derived class for motorcycles
    class Motorcycle : public Vehicle {
    private:
        bool hasSidecar;
    public:
        Motorcycle(string make, string model, int year, bool hasSidecar) : Vehicle(make, model, year), hasSidecar(hasSidecar) {}

        void setHasSidecar(bool hasSidecar) {
            this->hasSidecar = hasSidecar;
        }

        bool getHasSidecar() const {
            return hasSidecar;
        }

        void displayInfo() const override {
            cout << "Motorcycle: " << make << " " << model << ", Year: " << year;
            if (hasSidecar)
                cout << ", Has Sidecar";
            cout << endl;
        }

        void repair() override {
            Vehicle::repair();
            
            hasSidecar = false;
        }

        virtual ~Motorcycle() {}
    };

    // Derived class for micro buses
    class MicroBus : public Vehicle {
    private:
        int seatingCapacity;
    public:
        MicroBus(string make, string model, int year, int seatingCapacity) : Vehicle(make, model, year), seatingCapacity(seatingCapacity) {}

        void setSeatingCapacity(int seatingCapacity) {
            this->seatingCapacity = seatingCapacity;
        }

        int getSeatingCapacity() const {
            return seatingCapacity;
        }

        void displayInfo() const override {
            cout << "Micro Bus: " << make << " " << model << ", Year: " << year << ", Seating Capacity: " << seatingCapacity << endl;
        }

        void repair() override {
            Vehicle::repair();
            
            seatingCapacity = 15;
        }

        virtual ~MicroBus() {}
    };

    // Rental shop class
    template<typename T>
    class RentalShop {
    private:
        vector<T*> vehicles;
    public:
        void addVehicle(T* vehicle) {
            vehicles.push_back(vehicle);
        }

        void displayAvailableVehicles() const {
            cout << "Available Vehicles: " << endl;
            for (const auto& vehicle : vehicles) {
                if (vehicle->getAvailability()) {
                    vehicle->displayInfo();
                }
            }
        }

        void displayAllVehicles() const {
            cout << "All Vehicles: " << endl;
            for (const auto& vehicle : vehicles) {
                vehicle->displayInfo();
            }
        }

        void rentVehicle(int index) {
            try {
                if (index >= 0 && index < vehicles.size()) {
                    vehicles.at(index)->rent();
                }
                else {
                    throw out_of_range("Invalid vehicle index.");
                }
            }
            catch (const exception& ex) {
                cerr << "Error: " << ex.what() << endl;
            }
        }

        void returnVehicle(int index) {
            try {
                if (index >= 0 && index < vehicles.size()) {
                    vehicles.at(index)->returnVehicle();
                }
                else {
                    throw out_of_range("Invalid vehicle index.");
                }
            }
            catch (const exception& ex) {
                cerr << "Error: " << ex.what() << endl;
            }
        }

        T* getVehicle(int index) {
            if (index >= 0 && index < vehicles.size()) {
                return vehicles.at(index);
            }
            else {
                throw out_of_range("Invalid vehicle index.");
            }
        }

        virtual ~RentalShop() {
            for (const auto& vehicle : vehicles) {
                delete vehicle;
            }
        }
    };
}

using namespace RentalSystem;

int main() {
    RentalShop<Vehicle> shop;

    // Creating car, motorcycle, and microbus objects
    Car car1("Ford", "Mustang", 2020, 2);
    Car car2("Toyota", "Corolla", 2018, 4);
    Car car3("Honda","Vezel",2022,4);
    Car car4("Audi","e-tron(EV)",2023,4);

    Motorcycle motorcycle1("Harley-Davidson", "Sportster", 2022, false);
    Motorcycle motorcycle2("Honda", "Hornet", 2022, false);
    Motorcycle motorcycle3("Suzuki","Gixxer",2023,false);

    MicroBus microBus1("Mercedes-Benz", "Sprinter", 2019, 12);
    MicroBus microBus2("Ford", "Transit", 2020, 15);
    MicroBus microBus3("Toyota","Super-GL",2019,10);

    // Adding vehicles to the rental shop
    shop.addVehicle(&car1);
    shop.addVehicle(&car2);
    shop.addVehicle(&car3);

    shop.addVehicle(&motorcycle1);
    shop.addVehicle(&motorcycle2);
    shop.addVehicle(&motorcycle3);

    shop.addVehicle(&microBus1);
    shop.addVehicle(&microBus2);
    shop.addVehicle(&microBus3);

    int choice;
    while (true) {
        cout << "Welcome to the Rental Shop!" << endl;
        cout << "1. Display available vehicles" << endl;
        cout << "2. Rent a vehicle" << endl;
        cout << "3. Return a vehicle" << endl;
        cout << "4. Repair a vehicle" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                shop.displayAvailableVehicles();
                break;
            case 2:
                int rentIndex;
                cout << "Enter the index of the vehicle you want to rent: ";
                cin >> rentIndex;
                shop.rentVehicle(rentIndex);
                break;
            case 3:
                int returnIndex;
                cout << "Enter the index of the vehicle you want to return: ";
                cin >> returnIndex;
                shop.returnVehicle(returnIndex);
                break;
            case 4:
                int repairIndex;
                cout << "Enter the index of the vehicle you want to repair: ";
                cin >> repairIndex;
                try {
                    shop.getVehicle(repairIndex)->repair();
                }
                catch (const exception& ex) {
                    cerr << "Error: " << ex.what() << endl;
                }
                break;
            case 5:
                cout << "Thank you for using the Rental Shop. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }
}
