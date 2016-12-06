/*
 * Example of 'Composite' design pattern.
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

class CImplement
{
    public:
        virtual void GeneralFunc()=0;
};

class CConcreteImplementA:public CImplement
{
    public:
        void GeneralFunc()
        {
            cout<<"General func type A!"<<endl;
        };
};

class CConcreteImplementB:public CImplement
{
    public:
        void GeneralFunc()
        {
            cout<<"General func type B!"<<endl;
        };
};

class CAbstract
{
    public:
        CImplement* cp_impl;
    public:
        virtual void SpecialFunc()=0;
    public:
        CAbstract(CImplement* p_impl)
        {
            cp_impl=p_impl;
        };
};

class CConcreteAbstract:public CAbstract
{
    public:
        void SpecialFunc()
        {
            cout<<"Special func!"<<endl;
            cp_impl->GeneralFunc();
        }
    public:
        CConcreteAbstract(CImplement* p_impl):CAbstract(p_impl)
    {};
};

int main()
{
    CImplement* cp_impA=new CConcreteImplementA();
    CImplement* cp_impB=new CConcreteImplementB();
    CAbstract* cp_abstractA=new CConcreteAbstract(cp_impA);
    CAbstract* cp_abstractB=new CConcreteAbstract(cp_impB);
    cp_impA->GeneralFunc();
    cp_impB->GeneralFunc();
    cp_abstractA->SpecialFunc();
    cp_abstractB->SpecialFunc();
    return 1;
};
