#ifndef PLAYER_H
#define PLAYER_H

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
				class Player final
					: public Entity
				{
				private:
					int Gold { 100 };
					int Exp { 0 };
					int ExpCap { 100 };
					int Level { 0 };
					vector<int> _pvalues;
				public:

					explicit Player()
						: Entity()
					{
						_pvalues.resize(_length);
						_pvalues.push_back(Gold);
						_pvalues.push_back(Exp);
						_pvalues.push_back(ExpCap);
						_pvalues.push_back(Level);

						cout << "Constructor Player" << endl;
					}

					Player(vector<int> tab)
						: Entity(tab)
					{
						cout << "Constructor Player parametrized" << endl;
					}

					string ToString()
					{
						string temp = " ";
						for (int i = 0; i < _length; i++)
							temp += to_string((*this)._pvalues[i]) + " ";

						return Entity::ToString() + temp;
					}

					Player& operator=(const Player &obj)
					{
						if (this != &obj)
						{
							(*this)._name = obj._name;

							for (int i = 0; i < _length; i++)
								(*this)._values[i] = obj._values[i];
						}
						return *this;
					}

					~Player()
					{
						cout << "Destructor Player" << endl;
					}
				};
			}
		}
	}
}

#endif