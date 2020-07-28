

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;
#comment for git
class Manager{ // Class Manager
    string managerName;
public:
    Manager(string managerName);
    void setManagerName(string managerName);
    string getManagerName();
};

Manager::Manager(string managerName) : managerName(managerName) {}
void Manager::setManagerName(string managerName) { this->managerName = managerName; }
string Manager::getManagerName() { return managerName; }

class Vehicle{ // Class Vehicle acts ass a superclass of class Car, Bus, and Airplane
    string model;
    string manufac;
    string managerName;
    int year;
    double price;
public:
    void setManufac(string manufac);
    void setModel(string model);
    void setYear(int year);
    void setPrice(double price);
    void setManagerName(string managerName);
    string getManufac();
    string getModel();
    int getYear();
    double getPrice();
    string getManagerName();
    Vehicle(string manufac, string model, int year, double price, string managerName);
};

Vehicle::Vehicle(string manufac, string model, int year, double price, string managerName) : manufac(manufac), model(model), year(year), price(price), managerName(managerName) {}
void Vehicle::setManufac(string manufac) { this->manufac = manufac; }
void Vehicle::setModel(string model) { this->model = model; }
void Vehicle::setYear(int year) { this->year = year; }
void Vehicle::setPrice(double price) { this->price = price; }
void Vehicle::setManagerName(string managerName) { this->managerName = managerName; }
string Vehicle::getManufac() { return manufac; }
string Vehicle::getModel() { return model; }
int Vehicle::getYear() { return year; }
double Vehicle::getPrice() { return price; }
string Vehicle::getManagerName() { return managerName; }

class Airplane : public Vehicle { // Class Airplane inherits Class Vehicle and Class Manager
public:
    Airplane(string manufac, string model, int year, double price, string managerName);
};

Airplane::Airplane(string manufac, string model, int year, double price, string managerName) : Vehicle(manufac, model, year, price, managerName) {}

class Bus : public Vehicle { // Class Bus inherits Class Vehicle and Class Manager
public:
    Bus(string manufac, string model, int year, double price, string managerName);
};

Bus::Bus(string manufac, string model, int year, double price, string managerName) : Vehicle(manufac, model, year, price, managerName) {}

class Car : public Vehicle { // Class Car inherits Class Vehicle and Class Manager
public:
    Car(string manufac, string model, int year, double price, string managerName);
};

Car::Car(string manufac, string model, int year, double price, string managerName) : Vehicle(manufac, model, year, price, managerName) {}


vector <Car> cars;                   //
vector <Bus> buss;                   //  Declaration of vector
vector <Airplane> airplanes;         //
vector <Manager> managers;           //

void initial(){ // Fucntion to initialize the vector / push all data into vector
    managers.push_back(Manager("Trevor"));
    managers.push_back(Manager("Michael"));
    managers.push_back(Manager("Hiccup"));
    managers.push_back(Manager("Tony"));
    managers.push_back(Manager("Franklin"));
    managers.push_back(Manager("Wazowski"));

    cars.push_back(Car("Bentley", "Mulsanne", 2013, 250000, managers[2].getManagerName()));
    cars.push_back(Car("Bugatti", "Veyron", 2014, 300000, managers[2].getManagerName()));
    cars.push_back(Car("Pagani", "Zonda", 2009, 200000, managers[3].getManagerName()));

    buss.push_back(Bus("Scania", "Touring", 2009, 200000, managers[1].getManagerName()));
    buss.push_back(Bus("Mercedes", "Tourismo", 2007, 160000, managers[0].getManagerName()));
    buss.push_back(Bus("Ford", "Transit", 2009, 14000, managers[0].getManagerName()));

    airplanes.push_back(Airplane("Boeing", "747", 2014, 340000, managers[4].getManagerName()));
    airplanes.push_back(Airplane("Boeing", "777", 2014, 100560, managers[4].getManagerName()));
    airplanes.push_back(Airplane("Airbus", "A318", 2013, 145000, managers[5].getManagerName()));
}

void displayCar(){ // a display function to display all cars
    cout << "\t+---------------------------------------------------+" << endl;
    cout << "\t|                * * * C A R * * *                  |" << endl;
    cout << "\t+---------------------------------------------------+" << endl;
    cout << "\t|ID  Manufacturer  Model    Year  Price     Manager |" << endl;
    cout << "\t+---------------------------------------------------+" << endl;
    for(int i = 0; i < cars.size(); i++){
        cout << "\t #" << left << setw(2) << i+1;
        cout << " " << setw(13) << cars[i].getManufac();
        cout << " " << setw(8) << cars[i].getModel();
        cout << " " << setw(5) << cars[i].getYear();
        cout << " " << setw(9) << cars[i].getPrice();
        cout << " " << cars[i].getManagerName() << endl;
    }
}

void displayBus(){ // a display function to display all buses
    cout << "\t+---------------------------------------------------+" << endl;
    cout << "\t|                * * * B U S * * *                  |" << endl;
    cout << "\t+---------------------------------------------------+" << endl;
    cout << "\t|ID  Manufacturer  Model    Year  Price     Manager |" << endl;
    cout << "\t+---------------------------------------------------+" << endl;
    for(int i = 0; i < buss.size(); i++){
        cout << "\t #" << left << setw(2) << i+1;
        cout << " " << setw(13) << buss[i].getManufac();
        cout << " " << setw(8) << buss[i].getModel();
        cout << " " << setw(5) << buss[i].getYear();
        cout << " " << setw(9) << buss[i].getPrice();
        cout << " " << buss[i].getManagerName() << endl;
        }
}

void displayAirplane(){ // a display function to display all airplanes
    cout << "\t+---------------------------------------------------+" << endl;
    cout << "\t|           * * * A I R P L A N E * * *             |" << endl;
    cout << "\t+---------------------------------------------------+" << endl;
    cout << "\t|ID  Manufacturer  Model    Year  Price     Manager |" << endl;
    cout << "\t+---------------------------------------------------+" << endl;
    for(int i = 0; i < airplanes.size(); i++){
    cout << "\t #" << left << setw(2) << i+1;
    cout << " " << setw(13) << airplanes[i].getManufac();
    cout << " " << setw(8) << airplanes[i].getModel();
    cout << " " << setw(5) << airplanes[i].getYear();
    cout << " " << setw(9) << airplanes[i].getPrice();
    cout << " " << airplanes[i].getManagerName() << endl;
    }
}

void allVehicle(){ // a display function to display all vehicle sort by type
    displayCar();
    cout << endl;
    displayBus();
    cout << endl;
    displayAirplane();
    cout << "\t";
    system("pause");
    system("cls");
}

void allManagers(){ // a display function to display all managers and their vehicles (sorted by manager)
    for(int i = 0; i < managers.size(); i++){
        cout << "\t" << "Manager: " << managers[i].getManagerName() << endl;
            for(int j = 0; j < cars.size(); j++){
                if(cars[j].getManagerName() == managers[i].getManagerName()) // condition checking to sort manager
                    cout << left << "\t" << setw(10) << cars[j].getManufac() << setw(10) << cars[j].getModel() << setw(5) << cars[j].getYear() << "RM: " << cars[j].getPrice() << endl;
            }
            for(int j = 0; j < buss.size(); j++){
                if(buss[j].getManagerName() == managers[i].getManagerName()) // condition checking to sort manager
                    cout << left << "\t" << setw(10) << buss[j].getManufac() << setw(10) << buss[j].getModel() << setw(5) << buss[j].getYear() << "RM: " << buss[j].getPrice() << endl;
            }
            for(int j = 0; j < airplanes.size(); j++){
                if(airplanes[j].getManagerName() == managers[i].getManagerName()) // condition checking to sort manager
                    cout << left << "\t" << setw(10) << airplanes[j].getManufac() << setw(10) << airplanes[j].getModel() << setw(5) << airplanes[j].getYear() << "RM: " << airplanes[j].getPrice() << endl;
            }
            cout << endl;
    }
    cout << "\t";
    system("pause");
    system("cls");
}

void createManager(){ // a function to create a new manager with no vehicle
    string managerName; int m = 0;
    cout << "\tEnter new manager name: ";
    cin >> managerName;
    for(int i = 0; i < managers.size(); i++){
        if(managerName == managers[i].getManagerName()) // condition checking to avoid redundant data
            m++;
    }
    if (m == 0){
        managers.push_back(Manager(managerName));
        cout << "\n\tA new manager is created\n\t";
    }
    else{
        cout << "\n\tManager is already exist!\n\t";
    }
    system("pause");
    system("cls");
}

void destroyManager(){  // a function to delete manager from the system
    string managerName; int i;
    cout << "\t+--------------------------------+\n";
    cout << "\t| ID       Name                  |\n";
    cout << "\t+--------------------------------+\n";
    for(int i = 0; i < managers.size(); i++){           //display all managers
        cout << "\t  #" << i+1 << left << setw(7) << " " << managers[i].getManagerName() << endl;
    }
    cout << "\n\tEnter manager id to delete manager: ";
    cout << "\n\tYour input-> ";
    cin >> i;
    for (int n = 0; n < cars.size(); n++){
        if(managers[i-1].getManagerName() == cars[n].getManagerName()){ // condition checking to delete manager in vector cars
            cars[n].setManagerName(managerName = "N/A");
        }
    }
    for (int n = 0; n < buss.size(); n++){
        if(managers[i-1].getManagerName() == buss[n].getManagerName()){ // condition checking to delete manager in vector buss
            buss[n].setManagerName(managerName = "N/A");
        }
    }
    for (int n = 0; n < airplanes.size(); n++){
        if(managers[i-1].getManagerName() == airplanes[n].getManagerName()){ // condition checking to delete manager in vector airplanes
            airplanes[n].setManagerName(managerName = "N/A");
        }
    }
    managers.erase(managers.begin() + (i-1)); // delete the manager from the vector managers
    cout << "\n\tA manager is deleted from the system.\n\t";
    system("pause");
    system("cls");
}

void createVehicle(){ // a function to create a new vehicle with no manager assigned to it
    string manufac, model, managerName;
    int year, select;
    double price;
    cout << "\tSelect which vehicle you want to create: " << endl;
    cout << "\t[ 1 ] - Car" << "\n\t[ 2 ] - Bus" << "\n\t[ 3 ] - Airplane" << "\n\t[ 4 ] - Back" << endl;
    cout << "\n\tYour input-> ";
    cin >> select;

    switch(select){
        case 1 :    system("cls");
                    cout << "\tEnter manufacturer of car: ";
                    cin >> manufac;
                    cout << "\tEnter model of car: ";
                    cin >> model;
                    cout << "\tEnter year of car: ";
                    cin >> year;
                    cout << "\tEnter price of car: ";
                    cin >> price;
                    cars.push_back(Car(manufac, model, year, price, managerName = "N/A")); // push all the data into the vector cars with "N/A" means no manager is assigned yet
                    cout << "\tA new car is inserted into the system." << endl << "\t";
                    system("pause");
                    system("cls");
                    break;
        case 2 :    system("cls");
                    cout << "\tEnter manufacturer of bus: ";
                    cin >> manufac;
                    cout << "\tEnter model of bus: ";
                    cin >> model;
                    cout << "\tEnter year of bus: ";
                    cin >> year;
                    cout << "\tEnter price of bus: ";
                    cin >> price;
                    buss.push_back(Bus(manufac, model, year, price, managerName = "N/A")); // push all the data into the vector buss with "N/A" means no manager is assigned yet
                    cout << "\tA new bus is inserted into the system." << endl << "\t";
                    system("pause");
                    system("cls");
                    break;
        case 3 :    system("cls");
                    cout << "\tEnter manufacturer of airplane: ";
                    cin >> manufac;
                    cout << "\tEnter model of airplane: ";
                    cin >> model;
                    cout << "\tEnter year of airplane: ";
                    cin >> year;
                    cout << "\tEnter price of airplane: ";
                    cin >> price;
                    airplanes.push_back(Airplane(manufac, model, year, price, managerName = "N/A")); // push all the data into the vector airplanes with "N/A" means no manager is assigned yet
                    cout << "\tA new airplane is inserted into the system." << endl << "\t";
                    system("pause");
                    system("cls");
                    break;
        case 4 :    system("cls"); // back to main menu
                    break;
    }
}

void destroyVehicle(){ // a function to delete vehicle from the system
    int select;
    cout << "\tSelect what you want to delete: " << endl;
    cout << "\t[ 1 ] - Car" << "\n\t[ 2 ] - Bus" << "\n\t[ 3 ] - Airplane" << "\n\t[ 4 ] - Back" << endl;
    cout << "\n\tYour input-> ";
    cin >> select;

    switch(select){
        case 1 :    system("cls");
                    displayCar();
                    int i;
                    cout << "\n\tEnter car id to delete car: " << endl; // ask user which car to delete by asking car id
                    cout << "\tYour input-> ";
                    cin >> i;
                    cars.erase(cars.begin() + (i-1)); // i - 1 because i already + 1
                    cout << "\n\tA car is deleted from the system." << endl << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 2 :    system("cls");
                    displayBus();
                    cout << "\n\tEnter bus id to delete bus: " << endl; // ask user which bus to delete by asking bus id
                    cout << "\tYour input-> ";
                    cin >> i;
                    buss.erase(buss.begin() + (i-1)); // i - 1 because i already + 1
                    cout << "\n\tA bus is deleted from the system." << endl << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 3 :    system("cls");
                    displayAirplane();
                    cout << "\n\tEnter airplanes id to delete car: " << endl; // ask user which airplane to delete by asking airplane id
                    cout << "\tYour input-> ";
                    cin >> i;
                    airplanes.erase(airplanes.begin() + (i-1)); // i - 1 because i already + 1
                    cout << "\n\tAn airplane is deleted form the system." << endl << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 4 :    system("cls"); // Back to main menu
                    break;
    }
}

void updateVehicle(){ // a function to update or assign manager to a vehicle according to the type of the vehicle. e.g car, bus or airplane
    int select, i, m = 0;
    string managerName;
    cout << "\tSelect which vehicle to update: " << "\n\t[ 1 ] - Car" << "\n\t[ 2 ] - Bus" << "\n\t[ 3 ] - Airplane" << "\n\t[ 4 ] - Back" << endl;
    cout << "\n\tYour input-> ";
    cin >> select;
    switch(select){
        case 1 :    system("cls");
                    displayCar();
                    cout << "\n\tEnter car id to change manager name: " << endl; //user need to enter the id of the car to edit the manager name
                    cout << "\tYour input-> ";
                    cin >> i;
                    cout << "\tEnter new manager's name: ";
                    cin >> managerName;
                    for(int i = 0; i < managers.size(); i++){
                        if(managerName == managers[i].getManagerName()) //condition checking to avoid redundant data
                            m++;
                        }
                    if (m == 0){
                        cars[i-1].setManagerName(managerName);
                        managers.push_back(Manager(managerName));
                    }
                    else{
                        cars[i-1].setManagerName(managerName);
                    }
                    cout << "\n\tA car has been updated with new manager name " << managerName << endl << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 2 :    system("cls");
                    displayBus();
                    cout << "\n\tEnter bus id to change manager's name: " << endl; //user need to enter the id of the bus to edit the manager name
                    cout << "\tYour input-> ";
                    cin >> i;
                    cout << "\tEnter new manager's name: ";
                    cin >> managerName;
                    for(int i = 0; i < managers.size(); i++){
                        if(managerName == managers[i].getManagerName()) //condition checking to avoid redundant data
                            m++;
                        }
                    if (m == 0){
                        buss[i-1].setManagerName(managerName);
                        managers.push_back(Manager(managerName));
                    }
                    else{
                        buss[i-1].setManagerName(managerName);
                    }
                    cout << "\n\tA bus has been updated with new manager name " << managerName << endl << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 3 :    system("cls");
                    displayAirplane();
                    cout << "\n\tEnter airplane id to change manager's name: " << endl; //user need to enter the id of the airplane to edit the manager name
                    cout << "\tYour input-> ";
                    cin >> i;
                    cout << "\tEnter new manager's name: ";
                    cin >> managerName;
                    for(int i = 0; i < managers.size(); i++){
                        if(managerName == managers[i].getManagerName()) //condition checking to avoid redundant data
                            m++;
                        }
                    if (m == 0){
                        airplanes[i-1].setManagerName(managerName);
                        managers.push_back(Manager(managerName));
                    }
                    else{
                        airplanes[i-1].setManagerName(managerName);
                    }
                    cout << "\n\tAn airplane has been updated with new manager name " << managerName << endl << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 4 :    system("cls");
                    break;
    }
}

void swapVehicle(){ // a function to swap vehicle between manager
    int select;
    cout << "\tSelect your options: " << endl;
    cout << "\n\t[ 1 ] - Swap Car <=> Car" << "\n\n\t[ 2 ] - Swap Bus <=> Bus" << "\n\n\t[ 3 ] - Swap Airplane <=> Airplane"<< "\n\n\t[ 4 ] - Swap Car <=> Bus" << "\n\n\t[ 5 ] - Swap Car <=> Airplane" << "\n\n\t[ 6 ] - Swap Bus <=> Airplane" << "\n\n\t[ 7 ] - Back";
    cout << "\n\n\tYour input-> ";
    cin >> select;
    switch(select){
        case 1 :    system("cls");
                    displayCar();
                    cout << "\n\tSelect first car id to swap vehicle: ";
                    int i;
                    cin >> i;
                    cout << "\tSelect second car id to swap vehicle: ";
                    int m;
                    cin >> m;
                    cars.push_back(Car(cars[i-1].getManufac(), cars[i-1].getModel(), cars[i-1].getYear(), cars[i-1].getPrice(), cars[m-1].getManagerName())); // swap using data structure approach
                    cars.push_back(Car(cars[m-1].getManufac(), cars[m-1].getModel(), cars[m-1].getYear(), cars[m-1].getPrice(), cars[i-1].getManagerName()));
                    cars.erase(cars.begin() + (m-1));
                    cars.erase(cars.begin() + (i-1)); cout << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 2 :    system("cls");
                    displayBus();
                    cout << "\n\tSelect first bus id to swap vehicle: ";
                    cin >> i;
                    cout << "\tSelect second bus id to swap vehicle: ";
                    cin >> m;
                    buss.push_back(Bus(buss[i-1].getManufac(), buss[i-1].getModel(), buss[i-1].getYear(), buss[i-1].getPrice(), buss[m-1].getManagerName())); // swap using data structure approach
                    buss.push_back(Bus(buss[m-1].getManufac(), buss[m-1].getModel(), buss[m-1].getYear(), buss[m-1].getPrice(), buss[i-1].getManagerName()));
                    buss.erase(buss.begin() + (m-1));
                    buss.erase(buss.begin() + (i-1)); cout << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 3 :    system("cls");
                    displayAirplane();
                    cout << "\n\tSelect first airplane id to swap vehicle: ";
                    cin >> i;
                    cout << "\tSelect second airplane id to swap vehicle: ";
                    cin >> m;
                    airplanes.push_back(Airplane(airplanes[i-1].getManufac(), airplanes[i-1].getModel(), airplanes[i-1].getYear(), airplanes[i-1].getPrice(), airplanes[m-1].getManagerName())); // swap using data structure approach
                    airplanes.push_back(Airplane(airplanes[m-1].getManufac(), airplanes[m-1].getModel(), airplanes[m-1].getYear(), airplanes[m-1].getPrice(), airplanes[i-1].getManagerName()));
                    airplanes.erase(airplanes.begin() + (m-1));
                    airplanes.erase(airplanes.begin() + (i-1)); cout << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 4 :    system("cls");
                    displayCar();
                    cout << endl;
                    displayBus();
                    cout << "\n\tSelect car id to swap vehicle: ";
                    cin >> i;
                    cout << "\tSelect bus id to swap vehicle: ";
                    cin >> m;
                    cars.push_back(Car(cars[i-1].getManufac(), cars[i-1].getModel(), cars[i-1].getYear(), cars[i-1].getPrice(), buss[m-1].getManagerName()));
                    buss.push_back(Bus(buss[m-1].getManufac(), buss[m-1].getModel(), buss[m-1].getYear(), buss[m-1].getPrice(), cars[i-1].getManagerName()));
                    buss.erase(buss.begin() + (m-1));
                    cars.erase(cars.begin() + (i-1)); cout << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 5 :    system("cls");
                    displayCar();
                    cout << endl;
                    displayAirplane();
                    cout << "\n\tSelect car id to swap vehicle: ";
                    cin >> i;
                    cout << "\tSelect airplane id to swap vehicle: ";
                    cin >> m;
                    cars.push_back(Car(cars[i-1].getManufac(), cars[i-1].getModel(), cars[i-1].getYear(), cars[i-1].getPrice(), airplanes[m-1].getManagerName()));
                    airplanes.push_back(Airplane(airplanes[m-1].getManufac(), airplanes[m-1].getModel(), airplanes[m-1].getYear(), airplanes[m-1].getPrice(), cars[i-1].getManagerName()));
                    airplanes.erase(airplanes.begin() + (m-1));
                    cars.erase(cars.begin() + (i-1)); cout << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 6 :    system("cls");
                    displayBus();
                    cout << endl;
                    displayAirplane();
                    cout << "\n\tSelect bus id to swap vehicle: ";
                    cin >> i;
                    cout << "\tSelect airplane id to swap vehicle: ";
                    cin >> m;
                    buss.push_back(Bus(buss[i-1].getManufac(), buss[i-1].getModel(), buss[i-1].getYear(), buss[i-1].getPrice(), airplanes[m-1].getManagerName()));
                    airplanes.push_back(Airplane(airplanes[m-1].getManufac(), airplanes[m-1].getModel(), airplanes[m-1].getYear(), airplanes[m-1].getPrice(), buss[i-1].getManagerName()));
                    airplanes.erase(airplanes.begin() + (m-1));
                    buss.erase(buss.begin() + (i-1)); cout << "\t";
                    system("pause");
                    system("cls");
                    break;

        case 7 :    system("cls"); // back to main menu
                    break;
    }
}

void mainDisplay(){ // a function to display main menu of the system
    cout << "\t ********************************************" << endl;
    cout << "\t*   MIGHTY RUDUN VEHICLE MANAGEMENT SYSTEM   *" << endl;
    cout << "\t ********************************************" << endl;
    cout << "\t +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << endl;
    cout << "\t |   [ 1 ] - List All Vehicles              |" << endl;
    cout << "\t |   [ 2 ] - List All Managers              |" << endl;
    cout << "\t |   [ 3 ] - Create Manager                 |" << endl;
    cout << "\t |   [ 4 ] - Delete Manager                 |" << endl;
    cout << "\t |   [ 5 ] - Create Vehicle                 |" << endl;
    cout << "\t |   [ 6 ] - Delete Vehicle                 |" << endl;
    cout << "\t |   [ 7 ] - Update/Assign Manager          |" << endl;
    cout << "\t |   [ 8 ] - Swap Vehicle                   |" << endl;
    cout << "\t |   [ 9 ] - Credit                         |" << endl;
    cout << "\t |   [ANY] - EXIT                           |" << endl;
    cout << "\t +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << endl << endl;
    cout << "\t Hello, what do you want to do?\n";
    cout << "\t Your selection-> ";
}

void credit(){
    cout << "\tA big gratitude to those who help me to complete this assignment: \n\n";
    system("pause");
    system("cls");
}



int main(){ // main function
    initial();
    int select;
    do{
        mainDisplay();
        cin >> select;
        switch(select){
            case 1 :    system("cls");
                        allVehicle();
                        break;
            case 2 :    system("cls");
                        allManagers();
                        break;
            case 3 :    system("cls");
                        createManager();
                        break;
            case 4 :    system("cls");
                        destroyManager();
                        break;
            case 5 :    system("cls");
                        createVehicle();
                        break;
            case 6 :    system("cls");
                        destroyVehicle();
                        break;
            case 7 :    system("cls");
                        updateVehicle();
                        break;
            case 8 :    system("cls");
                        swapVehicle();
                        break;
            case 9 :    system("cls");
                        credit();
                        break;
        }
    } while (select >= 1 && select <= 9);
}
