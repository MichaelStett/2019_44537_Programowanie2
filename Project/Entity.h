#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

#include "IEntity.h"

using std::cout;
using std::endl;
using std::to_string;

using std::string;
using std::vector;

namespace MT
{
	namespace Project
	{
		namespace Database
		{
			namespace Models
			{
				class Entity :
					public IEntity
				{
				protected:
					string _name;
					vector<int> _values;
					const int _length = 4;
				public:
					explicit Entity()
					{
						(*this)._name = "Name";
						_values.resize(_length);

						cout << "Constructor Entity" << endl;
					}

					Entity(vector<int> tab)
						: Entity()
					{
						_values.swap(tab);

						cout << "Constructor Entity parametrized" << endl;
					}

					// Copy Constructor
					Entity(const Entity& obj)
						: Entity()
					{
						(*this)._name = obj._name;
						for (int i = 0; i < _length; i++)
							(*this)._values[i] = obj._values[i];

						cout << "Copied Entity" << endl;
					}

					virtual ~Entity()
					{
						cout << "Destructor Entity" << endl;
					}

					int Get(size_t index) const final
					{
						return (*this)._values[index];
					}

					int& Set(size_t index) final
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

					// polymorphic class suppresses copying
					Entity& operator=(const Entity&) = delete;

					int& operator[](int index)
					{
						assert(0 <= index && _length > index);
						return _values[index];
					}
				};
			}
		}
	}
}

#endif