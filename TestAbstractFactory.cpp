/*
 * Example of 'Abstract Factory' design pattern.
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
class CProduct
{
public:
	virtual void Specification(){};
};

class CProductA1:public CProduct
{
public:
	void Specification()
	{
		cout<<"I'm ProductA1!"<<endl;
	};
};

class CProductA2:public CProduct
{
public:
	void Specification()
	{
		cout<<"I'm ProductA2!"<<endl;
	};
};

class CProductB1:public CProduct
{
public:
	void Specification()
	{
		cout<<"I'm ProductB1!"<<endl;
	};
};

class CProductB2:public CProduct
{
public:
	void Specification()
	{
		cout<<"I'm ProductB2!"<<endl;
	};
};

class CFactory
{
public:
	virtual CProduct* MakeProductA()=NULL;
	virtual CProduct* MakeProductB()=NULL;
};

class CFactoryA:public CFactory
{
public:
	CProduct* MakeProductA()
	{
		return new CProductA1();
	};

	CProduct* MakeProductB()
	{
		return new CProductB1();
	};
};

class CFactoryB:public CFactory
{
public:
	CProduct* MakeProductA()
	{
		return new CProductA2();
	};

	CProduct* MakeProductB()
	{
		return new CProductB2();
	};
};

void main()
{
	vector<CProduct*> v_product;
	CFactory* cp_factoryA=new CFactoryA();
	CFactory* cp_factoryB=new CFactoryB();
	CProduct* cp_product;
	cp_product=cp_factoryA->MakeProductA();
	v_product.push_back(cp_product);
	cp_product=cp_factoryA->MakeProductB();
	v_product.push_back(cp_product);
	cp_product=cp_factoryB->MakeProductA();
	v_product.push_back(cp_product);
	cp_product=cp_factoryB->MakeProductB();
	v_product.push_back(cp_product);
	vector<CProduct*>::iterator itr=v_product.begin();
	for(;itr!=v_product.end();itr++)
	{
		(*itr)->Specification();
	};
};
