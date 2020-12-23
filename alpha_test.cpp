
#include <iostream>
#include <list>
using namespace std;
#include "alpha.h"

int main()
{
    alpha A1;
    A1.setID(33);
    A1.display();

    alpha * aptr;
    alpha * curr = NULL;
    alpha * head = NULL;
    alpha * last1 = NULL;
    int N;
    cout<<"how many alphas?"<<endl;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        if(head == NULL){head = new alpha;
                         head->setID(100+i);
                         curr = head;
                         last1 = head;}
     /*   else{  curr=new alpha;
                curr->setID(100+i);
                curr->setNext(head);
                head = curr;}  ///push front collection
                */
     else{  curr=new alpha;
                curr->setID(100+i);
                last1->setNext(curr);
                last1 = curr;}   ///push back
    }

    cout<<"contents:"<<endl;
    curr=head;
    while(curr!=NULL)
    {
        curr->display();
        curr = curr->getNext();
    }
    delete head;




    ///now for the list template.
    cout<<"using the template"<<endl;
    list<alpha>Alist;
    list<alpha>::iterator aitr;
    for(int i=0; i<N; i++)
    {
        aptr = new alpha;
        aptr->setID(10+i);
        Alist.push_front(*aptr);
    }

    aitr = Alist.begin();
    while(aitr!=Alist.end())
    {
        aitr->display();
        aitr++;
    }
    return 0;
}
