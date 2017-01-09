/*
 * Example of 'proxy' design pattern.
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
class CSubject
{
    public:
        virtual void Do()=0;
};

class CConcreteSubject:public CSubject
{
    public:
        void Do()
        {
            cout<<"Original subject's function."<<endl;
        };
};

class CProxySubject:public CSubject
{
    private:
        const static int threshold=10;
        int value;
    public:
        CConcreteSubject* cp_orisubject;
    public:
        CProxySubject(int v)
        {
            value=v;
            cp_orisubject=new CConcreteSubject();
        };

        void Do()
        {
            if(value>threshold)
                cout<<"Proxy subject's function."<<endl;
            else
                cp_orisubject->Do();
        };
};

int main()
{
    int param=5;
    CSubject* cp_subject=new CProxySubject(param);
    cp_subject->Do();
    param=20;
    cp_subject=new CProxySubject(param);
    cp_subject->Do();
};
