#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include <string>

using namespace std;

class Truck
{
protected:
    int ID;
    string model;
    double tankVolume;
    double loadCapacity;
    double averageSpeed;
    int year;
    Truck() : ID(NextID++) { model = "URAL"; tankVolume = 300.0; loadCapacity = 10.0;
        averageSpeed = 60.0; year = 2014; ++count; }
    Truck(string model) : Truck() { this->model = model; }
    Truck(string model, double tankVolume) : Truck(model) { this->tankVolume = tankVolume; }
    Truck(string model, double tankVolume, double loadCapacity) : Truck(model, tankVolume) { this->loadCapacity = loadCapacity; }
    Truck(string model, double tankVolume, double loadCapacity, double averageSpeed) : Truck(model, tankVolume, loadCapacity) { this->averageSpeed = averageSpeed; }
    Truck(string model, double tankVolume, double loadCapacity, double averageSpeed, int year) : Truck(model, tankVolume, loadCapacity, averageSpeed) { this->year = year; }
    Truck(const Truck& T);



public:
    static int NextID;
    static int count;
    //CompositeTrucks* getComposite() { return nullptr; }
    virtual ~Truck() { --count; }
    virtual string getClassType() = 0;

    string get_model() const { return model; }
    double get_tankValue() const { return tankVolume; }
    double get_loadCapacity() const { return loadCapacity; }
    double get_averageSpeed() const { return averageSpeed; }
    int get_year() const { return year; }
    int get_ID() const { return ID; }

    void set_model(const string& model) { this->model = model; }
    void set_tankValue(double tankVolume) { this->tankVolume = tankVolume; }
    void set_loadCapacity(double loadCapacity) { this->loadCapacity = loadCapacity; }
    void set_averageSpeed(double averageSpeed) { this->averageSpeed = averageSpeed; }
    void set_year(int year) { this->year = year; }

    Truck& operator =(const Truck& T);
    bool operator ==(const Truck& T) const;
    friend ostream& operator <<(ostream& out, const Truck& T);
};

#endif