/*
 * Example of 'Strategy' design pattern.
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

class CStrategy
{
public:
    virtual void execute()=0;
};

class CConcreteStrategy1:public CStrategy
{
    public:
        void execute()
        {
            cout<<"Special func1!"<<endl;
        };
};

class CConcreteStrategy2:public CStrategy
{
    public:
        void execute()
        {
            cout<<"Special func2!"<<endl;
        };
};

class CContext
{
    public:
        CStrategy* cp_strategy;
    public:
        void SetStrategy(CStrategy* p_strategy)
        {
            cp_strategy=p_strategy;
        }
        void execute()
        {
            cp_strategy->execute();
        };
    public:
        CContext(CStrategy* p_strategy)
        {
            SetStrategy(p_strategy);
        };
};

int main()
{
    CStrategy* cp_strategy1=new CConcreteStrategy1();
    CStrategy* cp_strategy2=new CConcreteStrategy2();
    CContext* cp_context=new CContext(cp_strategy1);
    cp_context->execute();
    cp_context->SetStrategy(cp_strategy2);
    cp_context->execute();
    return 1;
};
