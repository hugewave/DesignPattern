/*
 * Example of 'Visitor' design pattern.
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

class CConcreteElementA;
class CConcreteElementB;

class CVisitor
{
public:
    virtual void visit(CConcreteElementA* cp_elementA)=0;
    virtual void visit(CConcreteElementB* cp_elementB)=0;
};


class CElement
{
    public:
        virtual void accept(CVisitor* p_visitor)=0;
};

class CConcreteElementA:public CElement
{
public:
    void accept(CVisitor* p_visitor)
    {
         p_visitor->visit(this);
    }
};

class CConcreteElementB:public CElement
{
public:
    void accept(CVisitor* p_visitor)
    {
         p_visitor->visit(this);
    }
};

class CConcreteVisitor:public CVisitor
{
public:
    void visit(CConcreteElementA* cp_elementA)
    {
     cout<<"Special func for elementA"<<endl;
    };

    void visit(CConcreteElementB* cp_elementB)
    {
     cout<<"Special func for elementB"<<endl;
    };
};

int main()
{
    vector<CElement*> vp_element;
    CVisitor* cp_visitor=new  CConcreteVisitor();
    vp_element.push_back(new CConcreteElementA());
    vp_element.push_back(new CConcreteElementB());
    for(auto &e:vp_element)
        e->accept(cp_visitor);
    return 1;
};

