#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <fstream>

#include "..\Models\Entity.h"
#include "..\Models\IPlayerService.h"

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
			template <int Tlength = 8>
			class Player final
				: public Entity, IPlayerService
			{
			private:
				const string SaveFile = "savefile.sav";
			public:
				explicit Player()
					: Entity()
				{
					_length = Tlength;
					_values.resize(_length);

					cout << "Constructor Player" << endl;
				}

				Player(vector<int> tab)
					: Entity(tab)
				{
					_length = Tlength;
					_values.resize(_length);
					cout << "Constructor Player parametrized" << endl;
				}

				string ToString() final
				{
					string temp;
					for (int i = _length; i < _length; i++)
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

				void SelectRace()
				{
					int pass{ 0 };
					do {
						cout << " 1. " << "Human"
							<< " 2. " << "Orc"
							<< " 3. " << "Elf"
							<< " 4. " << "Dwarf"
							<< " \n ";
						cout << "Answer: ";
						cin >> pass;
						switch (pass) {
						case 1:
							(*this) = Player({ 0, 5, 5, 5, 5, 0, 0 });
							break;
						case 2:
							(*this) = Player({ 0, 10, -5, 10, 0, 0, 0 });
							break;
						case 3:
							(*this) = Player({ 0, 10, 5, -5, 5, 0, 0 });
							break;
						case 4:
							(*this) = Player({ 0, 0, 0, 20, 0, 0, 0 });
							break;
						}
					} while (pass <= 0 || pass > 4);
				}

				void SelectClass()
				{
					int pass{ 0 };
					do {
						cout << " 1. " << "Mage"
							<< " 2. " << "Battlemage"
							<< " 3. " << "Worrior"
							<< " 4. " << "Acrobat"
							<< " 5. " << "Archer"
							<< " 6. " << "Bard"
							<< " \n ";
						cout << " Answer: ";
						cin >> pass;

						switch (pass) {
						case 1:
							(*this) = Player({ 1, 30, 70, 40, 75, 1, 0 });
							break;
						case 2:
							(*this) = Player({ 1, 50, 40, 60, 75, 1, 0 });
							break;
						case 3:
							(*this) = Player({ 1, 70, 0, 70, 60, 1, 0 });
							break;
						case 4:
							(*this) = Player({ 1, 80, 15, 0, 100, 1, 0 });
							break;
						case 5:
							(*this) = Player({ 1, 80, 5, 15, 80, 1, 0 });
							break;
						case 6:
							(*this) = Player({ 1, 80, 20, 20, 80, 2, 0 });
							break;
						}
					} while (pass <= 0 || pass > 6);
				}

				void SelectName()
				{
					cout << " What is your name? ";
					string pass;
					cin >> (*this).SetName();
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

					while (index < _length)
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

				unsigned int ValuesLength()
				{
					return _length;
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