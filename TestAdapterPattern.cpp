/*
 * Example of 'SingleTon' design pattern.
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
class CTarget
{
public:
	virtual void GeneralFunc()
	{
		cout<<"General function!"<<endl;
	};
};

class CAdaptee
{
public:
	void SpecialFunc()
	{
		cout<<"Special function!"<<endl;
	};
};

class CAdapter:public CTarget
{
public:
	CAdaptee* cp_adaptee;
public:
	CAdapter(CAdaptee* p_adaptee)
	{
		cp_adaptee=p_adaptee;
	};
public:
	void GeneralFunc()
	{
		cp_adaptee->SpecialFunc();	
	};
};

void main()
{
	CTarget* cp_target=new CTarget();
	CAdaptee* cp_adaptee=new CAdaptee();
	CTarget* cp_adapt=new CAdapter(cp_adaptee);
	cp_target->GeneralFunc();
	cp_adapt->GeneralFunc();
};

