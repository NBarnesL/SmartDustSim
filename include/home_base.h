#ifndef HOME_BASE_H
#define HOME_BASE_H


using namespace std;

class home_base
{
    public:
        home_base();
        virtual ~home_base();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        double Getx() { return x; }
        void Setx(double val) { x = val; }
        double Gety() { return y; }
        void Sety(double val) { y = val; }

    protected:

    private:
        int id;
        double x;
        double y;
};

#endif // HOME_BASE_H
