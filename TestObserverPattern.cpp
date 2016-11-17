/*
 * Example of 'Observer' design pattern.
 * Copyright (C) 2016 Leo Wang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <set>
using namespace std;
class CSubject;

class CObserver
{
public:
    virtual void Update(CSubject* p_subject)=0;
    virtual void GetState()=0;
};

class CSubject
{
    public:
        string msg;
        set<CObserver*>  observersets;
    public:
        void AddObserver(CObserver* p_observer)
        {
            observersets.insert(p_observer);
        };

        void DetachObserver(CObserver* p_observer)
        {
            observersets.erase(p_observer);
        };

        void Update(string& newmsg)
        {
            msg=newmsg;
            for(auto &e:observersets)
            {
                e->Update(this);
            }
        };

        string Getmsg()
        {
             return msg;
        };
};

class CConcreteObserver:public CObserver
{
 public:
     string msg;
     public:
     void Update(CSubject* p_subject)
     {
         msg=p_subject->Getmsg();
     };

     void GetState()
     {
          cout<<msg<<endl;
     }
};

int main()
{
    CSubject* cp_subject=new CSubject();
    CObserver* cp_observer1=new CConcreteObserver();
    CObserver* cp_observer2=new CConcreteObserver();
    cp_subject->AddObserver(cp_observer1);
    cp_subject->AddObserver(cp_observer2);
    string msg="hello Observer Pattern!";
    cp_subject->Update(msg);
    cp_observer1->GetState();
    cp_observer2->GetState();
};
