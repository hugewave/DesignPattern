/*
 * Example of 'State' design pattern.
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
#include "stdio.h"
#include <iostream>
using namespace std;

class CSubject
{
public:
	virtual void ToStateOne(){};
	virtual void ToStateTwo(){};
	virtual void Do(){};
};

class CState
{
public:
	virtual void Do(CSubject* cp_subject) {};
};

class CStateOne:public CState
{
public:
	void Do(CSubject* cp_subject)
	{
		cout<<"This is State One!"<<endl;
		cp_subject->ToStateTwo();	
	};
};

class CStateTwo:public CState
{
	void Do(CSubject* cp_subject)
	{
		cout<<"This is state Two!"<<endl;
		cp_subject->ToStateOne();
	};
};

class CConcreteSubject:public CSubject
{
private:
	CStateOne* cp_stateone;
	CStateTwo* cp_statetwo;
	CState* cp_state;

public:
	void Do()
	{
		cp_state->Do(this);
	};

public:
	void ToStateOne()
	{
		cp_state=cp_stateone;
	};

	void ToStateTwo()
	{
		cp_state=cp_statetwo;
	};

public:
	CConcreteSubject()
	{
		cp_stateone=new CStateOne();
		cp_statetwo=new CStateTwo();
		cp_state=cp_stateone;
	};

	~CConcreteSubject()
	{
		delete [] cp_stateone;
		delete [] cp_statetwo;
	};
};

void main()
{
	CSubject* cp_subject=new CConcreteSubject();
	cp_subject->Do();
	cp_subject->Do();
	cp_subject->Do();
	cp_subject->Do();
};