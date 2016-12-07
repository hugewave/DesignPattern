/*
 * Example of 'Template' design pattern.
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
#include <iomanip>
using namespace std;

template <class T>
class CAlgorithm
{
    public:
        T add(T a,T b)
        {
            return a+b;
        };
};

int main()
{
    CAlgorithm<int> c_algint;
    CAlgorithm<float> c_algfloat;
    cout<<"3 add 5 is "<<c_algint.add(3,5)<<endl;
    cout<<"3.1 add 5.1 is "<<c_algfloat.add(3.1,5.1)<<endl;
    return 1;
};

