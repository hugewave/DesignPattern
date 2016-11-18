/*
 * Example of 'Memento' design pattern.
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

class CMemento
{
    public:
        string m_state;
    public:
        string GetState()
        {
            return m_state;
        };

        void SetState(string state)
        {
            m_state=state;
        };

    public:
        CMemento(string state)
        {
            SetState(state);
        };
};

class CObject
{
    public:
        string m_state;
    public:
        void SetState(string state)
        {
            m_state=state;
        };

        string GetState()
        {
            return m_state;
        };

        void LoadMemento(CMemento* p_memento)
        {
            SetState(p_memento->GetState());
        };

        void SetMemento(CMemento* p_memento)
        {
            p_memento->SetState(m_state);
        };

        CMemento CreateMemento()
        {
            return CMemento(m_state);
        };
};

int main()
{
    CMemento* cp_memento=new CMemento("Hello Cat!");
    CObject* cp_obj=new CObject();
    cp_obj->LoadMemento(cp_memento);
    cout<<cp_obj->GetState()<<endl;
    cp_obj->SetState("Hello Dog!");
    cp_obj->SetMemento(cp_memento);
    cout<<cp_memento->GetState()<<endl;
    CMemento mem=cp_obj->CreateMemento();
    cout<<mem.GetState()<<endl;
    return 1;
};
