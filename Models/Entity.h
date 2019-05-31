#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

#include "..\Models\IEntity.h"

using std::cout;
using std::endl;
using std::to_string;

using std::string;
using std::vector;

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			class Entity :
				public IEntity
			{
			protected:
			public:
				explicit Entity()
				{
					cout << "Constructor Entity" << endl;
				}

				Entity(vector<int> tab)
					: Entity()
				{
					_values.swap(tab);

					cout << "Constructor Entity parametrized" << endl;
				}

				virtual ~Entity()
				{
					cout << "Destructor Entity" << endl;
				}

				int Get(unsigned int index) const final
				{
					return (*this)._values[index];
				}

				int& Set(unsigned int index) final
				{
					return (*this)._values[index];
				}

				string& SetName() final
				{
					return _name;
				}

				string GetName() const final
				{
					return (*this)._name;
				}

				string ToString() override
				{
					string temp = " ";
					for (int i = 0; i < _length; i++)
						temp += to_string((*this)._values[i]) + " ";

					return (*this)._name + " " + temp;
				}

				int& operator[](int index)
				{
					assert(0 <= index && (*this)._length > index);
					return _values[index];
				}
			};
		}
	}
}

#endif