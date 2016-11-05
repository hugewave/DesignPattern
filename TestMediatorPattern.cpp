/*
 * Example of 'Mediator' design pattern.
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
#include <string>
#include <map>
#include <iostream>
using namespace std;

class IMediator
{
public:
	virtual void Send(const string& colleagueid,const string& msg)=0;
};

class IColleague
{
public:
	string s_id;
	IMediator* cp_mediator;
public:
	string getid()
	{return s_id;};

	void RegistMediator(IMediator* p_mediator)
	{
		cp_mediator=p_mediator;
	};
	
	virtual void Send(const string& colleadgeid,const string& msg){};
	virtual void Receive(const string& msg){};

public:
	IColleague(const string& id)
	{
		s_id=id;
	};
};

class CConcreteColleagueA:public IColleague
{
public:
	CConcreteColleagueA(const string& id):IColleague(id)
	{};

public:
	void Send(const string& colleadgeid,const string& msg)
	{
		cout<<s_id+" Calling "+colleadgeid<<endl;
		cp_mediator->Send(colleadgeid,msg);	
	};

	void Receive(const string& msg)
	{
		cout<<s_id+" Received msg: "+msg<<endl;
	};
};

class CConcreteColleagueB:public IColleague
{
public:
	CConcreteColleagueB(const string& id):IColleague(id)
	{};
public:
	void Send(const string& colleadgeid,const string& msg)
	{
		cout<<s_id+" Calling "+colleadgeid<<endl;
		cp_mediator->Send(colleadgeid,msg);	
	};

	void Receive(const string& msg)
	{
		cout<<s_id+" Received msg: "+msg<<endl;
	};
};

class CConcreteColleagueC:public IColleague
{
public:
	CConcreteColleagueC(const string& id):IColleague(id)
	{};
public:
	void Send(const string& colleadgeid,const string& msg)
	{
		cout<<s_id+" Calling "+colleadgeid<<endl;
		cp_mediator->Send(colleadgeid,msg);	
	};

	void Receive(const string& msg)
	{
		cout<<s_id+" Received msg: "+msg<<endl;
	};
};

class CConcreteMediator:public IMediator
{
public:
	map<string,IColleague*> m_colleagues;
public:
	bool IsRegisted(string id)
	{
		return m_colleagues.find(id)!=m_colleagues.end();
	};

	void Register(IColleague& colleague)
	{
		if(!IsRegisted(colleague.getid()))
		{
			colleague.RegistMediator(this);
			m_colleagues[colleague.getid()]=&colleague;	
		};

	};

	void Send(const string& colleagueid,const string& msg)
	{
		if(IsRegisted(colleagueid))
		{
			m_colleagues[colleagueid]->Receive(msg);
		};
	};
};

void main(void)
{
	CConcreteMediator c_mediator;
	CConcreteColleagueA c_colleageA("A");
	CConcreteColleagueB c_colleageB("B");
	CConcreteColleagueC c_colleageC("C");
	c_mediator.Register(c_colleageA);
	c_mediator.Register(c_colleageB);
	c_mediator.Register(c_colleageC);
	c_colleageA.Send("B","Message from A to B!");
	c_colleageA.Send("C","Message from A to C!");
};