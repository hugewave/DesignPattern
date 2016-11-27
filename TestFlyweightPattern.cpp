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
#include <map>
using namespace std;
class CFlyweight
{
    public:
        virtual void Do(string exstate)=0;
};

class CConcreteFlyweight:public CFlyweight
{
    private:
        string m_instate;
        string m_id;
    public:
        CConcreteFlyweight(string id)
        {
            m_instate="Instate is invariable in general.";
            m_id=id;
        };

    public:
        void Do(string exstate)
        {
            cout<<m_instate<<endl;
            cout<<"Exstate is "<<exstate<<endl;
        };
};

class CFlyweightFactory
{
    public:
        map<string,CFlyweight*>  flyweights;
    public:
        CFlyweight* GetFlyweight(string id)
        {
            CFlyweight* p_flyweight;
            auto it=flyweights.find(id);
            if(it==flyweights.end())
            {
                p_flyweight=new CConcreteFlyweight(id);
                flyweights[id]=p_flyweight;
            }
            else
            {
                 p_flyweight=it->second;
            };
            return p_flyweight;
        };
};

int main()
{
    CFlyweightFactory* cp_factory=new CFlyweightFactory();
    CFlyweight* cp_flyweight1=cp_factory->GetFlyweight("A");
    CFlyweight* cp_flyweight2=cp_factory->GetFlyweight("B");
    CFlyweight* cp_flyweight3=cp_factory->GetFlyweight("A");
    cp_flyweight1->Do("Hello world!");
    cp_flyweight1->Do("Hello China!");
    cp_flyweight1->Do("Hello America!");
    return 1;
};
