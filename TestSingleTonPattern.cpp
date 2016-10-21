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
#include <stdio.h>
#include <iostream>
using namespace std;

class CSingleTon
{
public:
	int m_value;
	void SetValue(int value)
	{
		m_value=value;
	};

	int GetValue()
	{
		return m_value;
	};
private:
	static CSingleTon* cp_inst;
	CSingleTon(){m_value=0;};
public:
	static CSingleTon* Instance();
	static void Destroy()
	{
		if(cp_inst!=NULL)
			delete cp_inst;
		cp_inst=NULL;
	};
};

CSingleTon* CSingleTon::cp_inst=NULL;

CSingleTon* CSingleTon::Instance()
{
	if(cp_inst==NULL)
	{
		cp_inst=new CSingleTon();
	}
	
	return cp_inst;
};

void main()
{
	CSingleTon* cp_inst1=CSingleTon::Instance();
	int v1=cp_inst1->GetValue();
	int v2=1;
	cp_inst1->SetValue(v2);
	CSingleTon* cp_inst2=CSingleTon::Instance();
	int v3=cp_inst2->GetValue();
	cout<<"v1 is "<<v1<<endl;
	cout<<"v2 is "<<v2<<endl;
	cout<<"v3 is "<<v3<<endl;
	CSingleTon::Destroy();
};