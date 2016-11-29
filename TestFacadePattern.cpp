/*
 * Example of 'Flyweight' design pattern.
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

class CSubsystem1
{
    public:
        void Do()
        {
            cout<<"Subsystem1!"<<endl;
        }
};

class CSubsystem2
{
    public:
        void Do()
        {
            cout<<"Subsystem2!"<<endl;
        }
};

class CFacade
{
    private:
        CSubsystem1* cp_subsystem1;
        CSubsystem2* cp_subsystem2;
    public:
        void Do()
        {
            cp_subsystem1->Do();
            cp_subsystem2->Do();
        }
    public:
        CFacade()
        {
            cp_subsystem1=new CSubsystem1();
            cp_subsystem2=new CSubsystem2();
        };

        ~CFacade()
        {
            delete [] cp_subsystem1;
            delete [] cp_subsystem2;
        };
};

int main()
{
    CFacade* cp_facade=new CFacade();
    cp_facade->Do();
    return 1;
};
