#ifndef DUST_H
#define DUST_H
#include <iostream>
#include<target.h>
using namespace std;

class dust: public target
{
    public:
        dust();
        dust(double a, double b);
        virtual ~dust();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        double Getx() { return x; }
        void Setx(double val) { x = val; }
        double Gety() { return y; }
        void Sety(double val) { y = val; }
        double Gettype(){return type;}
        void Settype(int val){type = val;}
        void display(){ cout<<"("<<x<<", "<<y<<")"<<endl;}
        void displayID(){cout<<"ID no. "<<id<<" of type "<<type<<" ";}
        void setFlag(int val){ signalflag = val;}
        int getFlag(){ return signalflag;}
        //void dustdetection(target tar, list<dust>Dlist, list<dust>::iterator Ditr);


    protected:

    private:
        int id;
        double type;
        int signalflag=0;
        double x;
        double y;
};

#endif // DUST_H
