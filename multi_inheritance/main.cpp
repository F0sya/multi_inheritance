#include <iostream>
using namespace std;

class Wheels {
protected:
    int wheels_amount;
public:
    Wheels(int amount) : wheels_amount(amount) {};
    virtual ~Wheels() {
        cout << "Wheel destructor called" << endl;
    }
    virtual void print() const {
        cout << "Your car has " << wheels_amount << " wheels." << endl;
    }
};

class Fuel_tank {
protected:
    int volume;
public:
    Fuel_tank(int v) : volume(v) {};
    virtual ~Fuel_tank() {
        cout << "Fuel tank destructor called" << endl;
    }
    virtual void print() const {
        cout << "Your car fuel tank can contain " << volume << " gallons of fuel" << endl;
    }
};

class Engine {
protected:
    int cylinders;
public:
    Engine(int v_amount) : cylinders(v_amount) {}
    virtual ~Engine() {
        cout << "Engine destructor called" << endl;
    }
    virtual void print() const {
        cout << "Your car has " << cylinders << " cylinders." << endl;
    }
};

class Doors {
protected:
    int door_count;
public:
    Doors(int doors) : door_count(doors) {};
    virtual ~Doors() {
        cout << "Doors destructor called" << endl;
    }
    virtual void print() const {
        cout << "Your car has " << door_count << endl;
    }
};

class Car : virtual public Wheels, virtual public Engine, virtual public Doors, virtual public Fuel_tank {
protected:
public:
    Car(int wheels, int cylinders, int doors, int volume)
        : Wheels(wheels), Engine(cylinders), Doors(doors), Fuel_tank(volume) {}

    void print() const override {
        cout << "Your car has: "<< endl;
        Wheels::print();
        Engine::print();
        Doors::print();
        Fuel_tank::print();
    }
};

int main() {
    Car* mycar = new Car(4, 16, 2, 5);
    mycar->print();
    cout << endl << "<<------------------------------------------------>>" << endl << endl;
    delete mycar;
    return 0;
}