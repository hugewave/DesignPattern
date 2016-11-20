/*
 * Example of 'Interpreter' design pattern.
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
class CContext
{
    public:
        string m_msg;
    public:
        void SetMsg(string msg)
        {
            m_msg=msg;
        };
        string GetMsg()
        {
            return m_msg;
        }
    public:
        CContext(string msg)
        {
            SetMsg(msg);
        };
};

class CInterpreter
{
    public:
        void ReplaceMsg(string& msg,string original,string target)
        {
            int pos=0;
            while((pos=msg.find(original,pos))!=string::npos)
            {
                msg.replace(pos,original.length(),target);
                pos+=target.length();
            }
        };

        void Interpreter(string& msg)
        {
            ReplaceMsg(msg,GetOriginal(),GetTarget());
        };

    public:
        virtual string GetOriginal()=0;
        virtual string GetTarget()=0;
};

class CInterpreterA:public CInterpreter
{
    public:
        string GetOriginal()
        {
            return "A";
        };
        string GetTarget()
        {
            return "a";
        };
};

class CInterpreterB:public CInterpreter
{
    public:
        string GetOriginal()
        {
            return "B";
        };
        string GetTarget()
        {
            return "b";
        };
};

int main()
{
    string msg="ABABAB";
    CContext* cp_context=new CContext(msg);
    cout<<cp_context->GetMsg()<<endl;
    vector<CInterpreter*> v_interpreter;
    v_interpreter.push_back(new CInterpreterA());
    v_interpreter.push_back(new CInterpreterB());
    for(auto &e:v_interpreter)
    {
         e->Interpreter(cp_context->m_msg);
    };
    cout<<cp_context->GetMsg()<<endl;
    return 1;
};
