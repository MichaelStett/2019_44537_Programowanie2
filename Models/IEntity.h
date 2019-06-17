#ifndef IENTITY_H
#define IENTITY_H

#pragma once

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::string; 
using std::vector;

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			class IEntity
			{
			protected:
				string _name;
				vector<int> _values;
				int _length;
			public:
				explicit IEntity()
				{
					(*this)._name = "Name";
					(*this)._length = 5;
					cout << "Constructor IEntity" << endl;
				}

				virtual int Get(unsigned int index) const = 0;
				virtual int& Set(unsigned int index) = 0;
				virtual string& SetName() = 0;
				virtual string GetName() const = 0;
				virtual string ToString() = 0;
				virtual unsigned int ValuesLength() = 0;

				virtual ~IEntity()
				{
					cout << "Destructor IEntity" << endl;
				}
			};
		}
	}
}

#endif