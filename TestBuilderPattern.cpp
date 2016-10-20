/*
 * Example of `builder' design pattern.
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

class CPartA
{
public:
	int m_quality; 
};

class CPartB
{
public:
	int m_quality; 
};

class CProduct
{
public:
	CPartA* cp_partA;
	CPartB* cp_partB;
public:
	void Specification()
	{
		cout<<"This Product's quality:"<<endl;
		cout<<"PartA's quality is !"<<cp_partA->m_quality<<endl;
		cout<<"PartB's quality is !"<<cp_partB->m_quality<<endl;
	};
};

class CBuilder
{
public:
	virtual CPartA* BuildPartA()=0;
	virtual CPartB* BuildPartB()=0;
};

class CGoodProductBuilder:public CBuilder
{
public:
	CPartA* BuildPartA()
	{
		CPartA* cp_partA=new CPartA();
		cp_partA->m_quality=100;
		return cp_partA;
	};

	CPartB* BuildPartB()
	{
		CPartB* cp_partB=new CPartB();
		cp_partB->m_quality=100;
		return cp_partB;
	};
};

class CBadProductBuilder:public CBuilder
{
public:
	CPartA* BuildPartA()
	{
		CPartA* cp_partA=new CPartA();
		cp_partA->m_quality=0;
		return cp_partA;
	};

	CPartB* BuildPartB()
	{
		CPartB* cp_partB=new CPartB();
		cp_partB->m_quality=0;
		return cp_partB;
	};

};

class CDirector
{
public:
	CBuilder* cp_builder;
	
public:
	void SetBuilder(CBuilder* p_builder)
	{
		cp_builder=p_builder;
	};

	CProduct* GetProduct()
	{
		CProduct* cp_product=new CProduct();
		cp_product->cp_partA=cp_builder->BuildPartA();
		cp_product->cp_partB=cp_builder->BuildPartB();
		return cp_product;
	}
};



void main()
{
	CProduct* cp_product;
	CDirector c_director;
	CBuilder * cp_goodbuilder=new CGoodProductBuilder();
	c_director.SetBuilder(cp_goodbuilder);
	cp_product=c_director.GetProduct();
	cp_product->Specification();

	CBuilder* cp_badbuilder=new CBadProductBuilder();
	c_director.SetBuilder(cp_badbuilder);
	cp_product=c_director.GetProduct();
	cp_product->Specification();
};