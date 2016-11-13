/*
 * Example of 'Chain Of Responsibility' design pattern.
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
using namespace std;
class CHandler
{
    public:
        CHandler* cp_nexthandler;
    public:
        void SetNextHandler(CHandler* p_handler)
        {
            cp_nexthandler=p_handler;
        }
        virtual void Do(int value)=0;
    public:
        CHandler ()
        {cp_nexthandler=NULL;}
};

class CConcreteHandler1:public CHandler
{
    public:
        void Do(int value)
        {
            if(value<10)
                cout<<"Handler1 processes the request, value:"<<value<<endl;
            else
                cp_nexthandler->Do(value);
        }
};

class CConcreteHandler2:public CHandler
{
    public:
        void Do(int value)
        {
            if(value<20)
                cout<<"Handler2 processes the request, value:"<<value<<endl;
            else
                cp_nexthandler->Do(value);
        }
};

class CConcreteHandler3:public CHandler
{
    public:
        void  Do(int value)
        {
            cout<<"Handler3 processes the request, value:"<<value<<endl;
        }
};

int main()
{
    CHandler* cp_handler1=new CConcreteHandler1();
    CHandler* cp_handler2=new CConcreteHandler2();
    CHandler* cp_handler3=new CConcreteHandler3();
    cp_handler1->SetNextHandler(cp_handler2);
    cp_handler2->SetNextHandler(cp_handler3);
    int  value=70;
    cp_handler1->Do(value);

    return 1;
};
