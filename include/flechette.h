#ifndef FLECHETTE_H
#define FLECHETTE_H
#include <iostream>
#include <list>
#include <dust.h>

using namespace std;

class flechette : public dust
{
    public:
        flechette();
        virtual ~flechette();

        double Getx() { return x; }
        void Setx(double val) { x = val; }
        double Gety() { return y; }
        void Sety(double val) { y = val; }
        int Getid() { return id; }
        void Setid(int val) { id = val; }
        void display(){ cout<<"("<<x<<", "<<y<<")"<<endl;}
        void displayID(){cout<<"ID no. "<<id<<" ";}

        list<dust*>Slist;
        list<dust*>::iterator Sitr;
        dust * Sptr;

    protected:

    private:
        double x;
        double y;
        int id;


};

#endif // FLECHETTE_H
