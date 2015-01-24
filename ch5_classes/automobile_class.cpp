/**
 * automobile_class.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective:
 *      Create a class to store data for an autombile. The class
 *      will have 3 pieces of data: manufacturer name, model name, 
 *      and year. Provide get/set methods for each data member as 
 *      well as a support method to print out a formatted string 
 *      of all the data.
 */
#include <iostream>
#include <string>
using namespace std;

class Automobile {
    public:
        Automobile()
            :make(""), model(""), year(0) { }
        Automobile(string newMake, string newModel, int newYear)
            :make(newMake), model(newModel), year(newYear) { }
        //Make
        string getmake() { return make; }
        void setmake(string newMake);
        //Model
        string getmodel() { return model; }
        void setmodel(string newModel);
        //Year
        int getyear() { return year; }
        void setyear(int newYear);

        void formatprint();
    private:
        string make;
        string model;
        int year;
        bool isValid();
};

void Automobile::setmake(string newMake)
{
    if (newMake.length() > 0) {
        make = newMake;
    }
}

void Automobile::setmodel(string newModel)
{
    if (newModel.length() > 0) {
        model = newModel;
    }
}

void Automobile::setyear(int newYear)
{
    if (newYear >= 1908 && newYear <= 2015) {
        year = newYear;
    }
}

bool Automobile::isValid()
{
    if ((make.length() > 0 && model.length() > 0) &&
            (year >= 1908 && year <= 2015)) {
        return true;
    } else {
        return false;
    }
}

void Automobile::formatprint()
{
    if (isValid()) {
        cout << year << " " << make << " " << model << '\n';
    } else {
        cout << "Error: invalid automobile object\n";
    }
}

int main()
{
    Automobile modelt{"Ford","Model T", 1908};
    modelt.formatprint();

    return 0;
}
