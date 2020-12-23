#include <iostream>
#include <random>
#include <ctime>
#include <list>
#include <fstream>
#include <cstdlib>


#include "dust.h"
#include "flechette.h"
#include "target.h"
#include "home_base.h"
using namespace std;

int main()
{
    default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));

    uniform_real_distribution<double> xdist(0,200);
    uniform_real_distribution<double>ydist(0,200);
    uniform_real_distribution<double> tdist(1,5);


    list<dust>Dlist;
    list<dust>::iterator Ditr;
    dust * Dptr;

    list<flechette>Flist;
    list<flechette>::iterator Fitr;
    flechette * Fptr;

    target tar;

    fstream fout;
   // fout.open("point_data.txt",ios::out);
    fstream comfout;





    int N=10000;
    double x, y;
    double type;
    int id=0;
    int outputcounter=1;

///Dust Generation
    for(int i=0; i<N; i++)
    {
        id++;
        x = xdist(*gptr);
        y = ydist(*gptr);
        type = tdist(*gptr);
        Dptr = new dust;
        Dptr->Setx(x);
        Dptr->Sety(y);
        Dptr->Setid(id);
        Dptr->Settype(type);
        Dlist.push_back(*Dptr);

        //cout<<x<<","<<y<<endl;

    }


    Ditr = Dlist.begin();
    while(Ditr!=Dlist.end())
    {
        //Ditr->displayID();
       // Ditr->display();
        Ditr++;
    }

///Flechette Generation
normal_distribution<double> fydist(100,5);
    id=0;
    for(int i=0; i<200; i++)
    {
        id++;
        x = xdist(*gptr);
        y = fydist(*gptr);
        Fptr = new flechette;
        Fptr->Setx(x);
        Fptr->Sety(y);
        Fptr->Setid(id);
        Flist.push_back(*Fptr);

        //cout<<x<<","<<y<<endl;

    }
    Fitr = Flist.begin();
    while(Fitr!=Flist.end())
    {
    //Fitr->displayID();
    //   Fitr->display();
        Fitr++;
    }


    tar.randomset();

    /// The target must travel
        int ir_x=0;
        int ir_y=0;
        int distance=0;
        int num_flags=0;

            cout<<"\nYtravel list: ";
            while (tar.Gety()<200)
            {

                tar.Sety(tar.Gety()+tar.Getspeed());
                num_flags=0;

            /// Dust Detects Target
                Ditr = Dlist.begin();
                    while(Ditr!=Dlist.end())
                    {

                        ir_x=Ditr->Getx();
                        ir_y=Ditr->Gety();
                        distance =sqrt(pow(tar.Gety()-ir_y, 2) + pow(tar.Getx()-ir_x,2)) ;
                        if(distance<25 && Ditr->Gettype()==tar.Gettype()){
                            Ditr->setFlag(1);
                            num_flags++;
                        }
                        Ditr++;
                    }

            ///Flechettes Detect Dust

                //For each flechette, collect the location (x/y) of the dust in range
                //For each flechette,
                Fitr = Flist.begin();
                int i=0;
                int c=1;
                    while (Fitr!=Flist.end())
                    {

                        Ditr = Dlist.begin();
                            //cout<<"Starting "<<i<<" list of dust."<<endl;
                            c=1;
                            while(Ditr!=Dlist.end())
                                {
                                    //dust in range
                                    ir_x=Ditr->Getx();
                                    ir_y=Ditr->Gety();


                                    distance =sqrt(pow(Fitr->Gety()-ir_y, 2) + pow(Fitr->Getx()-ir_x,2));

                                    if(distance<10&&Ditr->getFlag()==1)
                                    {

                                                x = Ditr->Getx();
                                                y = Ditr->Gety();
                                                type = Ditr->Gettype();
                                                Fitr->Sptr = new dust;
                                                Fitr->Sptr->Setx(x);
                                                Fitr->Sptr->Sety(y);
                                                Fitr->Sptr->Settype(type);
                                                Fitr->Slist.push_back(Fitr->Sptr);

                                                //cout<<x<<","<<y<<endl;


                                    }
                                    Ditr++;
                                }
                                    Fitr++;
                                   // i++;
                                   // cout<<"I've finished for "<<i<<" flechettes."<<endl;
                    }


                cout<<"At the end of the step, there were "<<num_flags<<" dust that detect type "<<tar.Gettype()<<endl;

                //cout<<endl<<endl<<"Target Located at: "<<Getx()<<", "<<Gety()<<" and is of type "<<Gettype()<<" going at a rate of "<<Getspeed()<<" units";

                ///Home base processes all data at each step


    fout.open("point_data.txt",ios::out);

                    Ditr=Dlist.begin();
                        while(Ditr!=Dlist.end())
                        {
                            if(Ditr->getFlag()==1){
                            ir_x=Ditr->Getx();
                            ir_y=Ditr->Gety();
                            if(Ditr!=Dlist.begin()){fout<<endl;}
                            fout<<ir_x<<" "<<ir_y;
                            }
                            Ditr++;

                        }
                    fout.close();



                    comfout.open("command.txt",ios::out);

                    comfout<<"set xlabel \"x location\""<<endl;
                    comfout<<"set ylabel \"y location\""<<endl;

                    comfout<<"set xrange [0:200]"<<endl;
                    comfout<<"set yrange [0:200]"<<endl;

                    comfout<<"set view equal xyz"<<endl;
                    comfout<<"set terminal windows"<<endl;


                    comfout<<"plot \"point_data.txt\"  ps var pt 3  with points "<<endl;
                    comfout<<"pause -1"<<endl;
                    comfout<<"set terminal png font arial 14 size 800,600"<<endl;
                    comfout<<"set output 'output"<<outputcounter<<".png'"<<endl;
                    comfout<<"replot"<<endl;

                    comfout.close();


                        system("gnuplot command.txt");
                        ///reset

                        Ditr=Dlist.begin();
                        while(Ditr!=Dlist.end())
                        {
                            if(Ditr->getFlag()==1){
                            Ditr->setFlag(0);

                            }
                            Ditr++;
                        }
                        outputcounter++;



            }






    return 0;
}
