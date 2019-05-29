#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <fstream>

#include "..\Models\Entity.h"

using std::cin;
using std::cout;
using std::endl;
using std::to_string;
using std::string;
using std::ifstream;

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			class Player final
				: public Entity
			{
			private:
				const string SaveFile = "savefile.sav";
			public:
				explicit Player()
					: Entity()
				{
					_values.resize(_length * 2);
					
					cout << "Constructor Player" << endl;
				}

				Player(vector<int> tab)
					: Entity(tab)
				{
					_values.resize(_length * 2);
					cout << "Constructor Player parametrized" << endl;
				}

				string ToString()
				{
					string temp;
					for (int i = _length; i < _length * 2; i++)
						temp += to_string((*this)._values[i]) + " ";

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

				bool LoadFromFile() {
					struct stat buffer;
					if (stat(SaveFile.c_str(), &buffer) == 0)
					{
						cout << " Save found. Do you want to load it? [Y]es / [N]o" << endl << " "; \
							char choice{ 0 };
						cin >> choice;
						if (tolower(choice) == 'y')
						{
							LoadCharacter(SaveFile);
							cout << " Save sucessfully loaded!";
							return true;
						}
						else 
						{
							cout << " Ok! Sorry to bother";
							return false;
						}
					}
					else 
					{
						return false;
					}
				}

				void LoadCharacter(string SaveFile) 
				{
					ifstream File;

					File.open(SaveFile);
					int index = -1;

					while (index < 8)
					{
						if (index == -1)
						{
							File >> _name;
						}
						else
						{
							File >> _values[index];
						}
						index++;
					}

					File.close();
				}

				~Player()
				{
					cout << "Destructor Player" << endl;
				}
			};
		}
	}
}

#endif