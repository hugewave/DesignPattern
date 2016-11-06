/*
 * Example of 'Prototype' design pattern.
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
class CPrototype
{
public:
	virtual CPrototype* clone()=0;
	virtual void SetValue(int v)=0;
	virtual int GetValue()=0;
};

class CConcretePrototype :public CPrototype
{
public:
	int value;
public:
	CPrototype* clone() 
	{
		return new CConcretePrototype(*this);
	};
	
	void SetValue(int v)
	{
		value=v;
	};

	int GetValue()
	{
		return value;
	};

public:
	CConcretePrototype(int v):value(v){};
};

void main()
{
CPrototype* cp_protypeobj1=new CConcretePrototype(1);
CPrototype* cp_protypeobj2=cp_protypeobj1->clone();
cp_protypeobj1->SetValue(10);
int i=cp_protypeobj2->GetValue();
cout<<"Value in object1 is: "<<cp_protypeobj1->GetValue()<<endl;
cout<<"Value in object2 is: "<<cp_protypeobj2->GetValue()<<endl;
};