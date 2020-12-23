#ifndef TARGET_H
#define TARGET_H

#include<iostream>
#include <random>
#include <ctime>

using namespace std;

class target
{
    public:
        target();
        virtual ~target();

        int Gettype() { return type; }
        void Settype(int val) { type = val; }
        double Getx() { return x; }
        void Setx(double val) { x = val; }
        double Gety() { return y; }
        void Sety(double val) { y = val; }
        double Getspeed() { return speed; }
        void Setspeed(double val) { speed = val; }
        void randomset(){
        default_random_engine * tptr;
        tptr = new default_random_engine(time(NULL));


        uniform_real_distribution<double>targetxcord(0,200);
        uniform_real_distribution<double>randspeed(8,12);
        uniform_real_distribution<double> tdist(1,5);

        speed= randspeed(*tptr);
        x=targetxcord(*tptr);
        type=tdist(*tptr);
        }
        /*void travel(){
            cout<<"\nYtravel list: ";
            while (Gety()<200)
            {
                Sety(Gety()+Getspeed());

                cout<<endl<<endl<<"Target Located at: "<<Getx()<<", "<<Gety()<<" and is of type "<<Gettype()<<" going at a rate of "<<Getspeed()<<" units";
            }}
        */





    protected:

    private:
        double type;
        double x;
        double y=0;
        double speed;


};

#endif // TARGET_H
