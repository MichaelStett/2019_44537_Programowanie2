#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include <iostream>
#include <string>
#include <cassert>

#include "..\Models\Entity.h"

using std::cout;
using std::endl;
using std::to_string;
using std::string;

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			template <int Tlength = 5>
			class Enemy final
				: public Entity
			{
			public:
				explicit Enemy()
					: Entity()
				{
					_values.resize(Tlength);
					cout << "Constructor Enemy" << endl;
				}

				Enemy(vector<int> tab)
					: Entity(tab)
				{
					_values.resize(Tlength);
					cout << "Constructor Enemy parametrized" << endl;
				}

				Enemy(const Enemy& obj)
					: Enemy()
				{
					(*this)._name = obj._name;
					for (int i = 0; i < _length; i++)
						(*this)._values[i] = obj._values[i];

					cout << "Copied Enemy" << endl;
				}

				string ToString() final
				{
					string temp;
					for (int i = _length; i < Tlength; i++)
						temp += to_string((*this)._values[i]) + " | ";

					return Entity::ToString() + temp;
				}

				Enemy& operator=(const Enemy &obj)
				{
					if (this != &obj)
					{
						(*this)._name = obj._name;

						for (int i = 0; i < _length; i++)
							(*this)._values[i] = obj._values[i];
					}
					return *this;
				}

				size_t ValuesLength()
				{
					return _values.size();
				}

				~Enemy()
				{
					cout << "Destructor Enemy" << endl;
				}
			};
		}
	}
}

#endif