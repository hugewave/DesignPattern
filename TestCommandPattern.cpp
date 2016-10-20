/*
 * Example of 'Command' design pattern.
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

class CReceiver
{
public:
	void DoFunctionA()
	{
		cout<<"Do function A!"<<endl;
	};

	void DoFunctionB()
	{
		cout<<"Do function B!"<<endl;
	};
};

class CCommand
{
public:
	CReceiver* cp_receiver;
public:
	virtual void Do(){};
public:
	CCommand(CReceiver* c_receiver)
	{
		cp_receiver=c_receiver;
	};
};

class CConcreteCommandA:public CCommand
{
public:
	void Do()
	{
		cp_receiver->DoFunctionA();
	};
public:
	CConcreteCommandA(CReceiver* c_receiver):CCommand(c_receiver){};
};

class CConcreteCommandB:public CCommand
{
public:
	void Do()
	{
		cp_receiver->DoFunctionB();
	};
public:
	CConcreteCommandB(CReceiver* c_receiver):CCommand(c_receiver){};
};

class CInvoker
{
public:
	vector<CCommand*> v_cmd;
public:
	void AddCommand(CCommand* p_cmd)
	{
		v_cmd.push_back(p_cmd);
	};

	void Execute()
	{
		vector<CCommand*>::iterator it;
		it=v_cmd.begin();
		for(;it!=v_cmd.end();it++)
		{
			(*it)->Do();
		};
	};
};

void main()
{
	CInvoker* cp_invoker=new CInvoker();
	CReceiver* cp_receiver=new CReceiver();
	CCommand* cp_command;
	cp_command=new CConcreteCommandA(cp_receiver);
	cp_invoker->AddCommand(cp_command);
	cp_command=new CConcreteCommandB(cp_receiver);
	cp_invoker->AddCommand(cp_command);
	cp_invoker->Execute();
};