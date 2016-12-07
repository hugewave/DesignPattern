/*
 * Example of 'Decorator' design pattern.
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

class IComponent
{
    public:
        virtual void func()=0;
};

class CConcreteComponent:public IComponent
{
    public:
        void func()
        {
            cout<<"General func!"<<endl;
        }
};

class CDecorator:public IComponent
{
    public:
        IComponent* cp_component;
    public:
        CDecorator(IComponent* p_component)
        {
            cp_component=p_component;
        };
};

class CConcreteDecorator:public CDecorator
{
    public:
        CConcreteDecorator(IComponent* p_component):CDecorator(p_component)
    {};
    public:
        void func()
        {
            cp_component->func();
            cout<<"Exteded func!"<<endl;
        }
};

int main()
{
    IComponent* cp_oricomponent=new CConcreteComponent();
    IComponent* cp_decoratecomponent=new CConcreteDecorator(cp_oricomponent);
    cp_oricomponent->func();
    cp_decoratecomponent->func();
    return 1;
};
