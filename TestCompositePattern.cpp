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
#include <vector>
using namespace std;

class CComponent
{
    public:
        virtual void Do()=0;
};

class CConcreteComponentA:public CComponent
{
    public:
        void Do()
        {
            cout<<"ComponentA Do!"<<endl;
        };
};

class CConcreteComponentB:public CComponent
{
    public:
        void Do()
        {
            cout<<"ComponentB Do!"<<endl;
        };
};

class CComposite:public CComponent
{
    public:
        vector<CComponent*> v_components;
    public:
        void Add(CComponent* p_component)
        {
            v_components.push_back(p_component);
        };

        void Do()
        {
            for(auto &component:v_components)
            {
                component->Do();
            }
        };
};

int main()
{
    CComponent* cp_componentA=new CConcreteComponentA();
    CComponent* cp_componentB=new CConcreteComponentB();
    CComposite* cp_composite=new CComposite();
    CComponent* cp_components=cp_composite;
    cp_composite->Add(cp_componentA);
    cp_composite->Add(cp_componentB);
    cp_componentA->Do();
    cp_componentB->Do();
    cp_composite->Do();
    return 1;
}
