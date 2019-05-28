#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include <iostream>
#include <string>
#include <cassert>

#include "Entity.h"

using std::cout;
using std::endl;
using std::to_string;
using std::string;

namespace MT
{
	namespace Project
	{
		namespace Database
		{
			namespace Models
			{
				class Enemy final
					: public Entity
				{
				private:
					int variable = 15;
				public:
					explicit Enemy()
						: Entity()
					{
						cout << "Constructor Enemy" << endl;
					}

					Enemy(vector<int> tab)
						: Entity(tab)
					{
						cout << "Constructor Enemy parametrized" << endl;
					}

					string ToString()
					{
						return Entity::ToString() + to_string((*this).variable);
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

					~Enemy()
					{
						cout << "Destructor Enemy" << endl;
					}
				};
			}
		}
	}
}

#endif