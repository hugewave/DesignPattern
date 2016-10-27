/*
 * Example of 'Simple Factory' design pattern.
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

class CProductA:public CProduct
{
	public:
	void Specification()
	{
		cout<<"I'm ProductA!"<<endl;
	};
};

class CProductB:public CProduct
{
	public:
	void Specification()
	{
		cout<<"I'm ProductB!"<<endl;
	};
};

class CFactory
{
public:
	CProduct* MakeProduct(char producttype)
	{
		CProduct* cp_product=NULL;
		switch (producttype)
		{
		case 'A':
			cp_product=new CProductA();
			break;
		case 'B':
			cp_product=new CProductB();
			break;
		default:
			break;
		}
		return cp_product;
	};
};

void main()
{
	vector<CProduct*> v_product;
	CFactory* cp_factory=new CFactory();
	CProduct* cp_product;
	cp_product=cp_factory->MakeProduct('A');
	v_product.push_back(cp_product);
	cp_product=cp_factory->MakeProduct('B');
	v_product.push_back(cp_product);
	vector<CProduct*>::iterator itr=v_product.begin();
	for(;itr!=v_product.end();itr++)
	{
		(*itr)->Specification();
	};
};
