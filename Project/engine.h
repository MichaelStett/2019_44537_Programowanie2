#ifndef ENGINE_H
#define ENGINE_H

#pragma once

#include "..\Database\Context.h"
#include "..\Models\Battle.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ostream;

using namespace MT::Project::Database;
using namespace MT::Project::Models;

namespace MT
{
	namespace Project
	{
		namespace Engine
		{
			class Game
			{
			private:
				Context<3> dbContext;
				vector<IEntity*> entities;
				Player<>* player;
				
			public:
				Game()
				{

					Initialize(dbContext);
					Initialize(entities);
					Initialize(player);

					ViewEntities();

					cout << Battle::CalculateAttack(entities[0], entities[1]) << endl;
					cout << Battle::CalculateDefense(entities[0], entities[1]) << endl;
					cout << Battle::CalculateSpeed(entities[0], entities[1]) << endl;

					// Adaptor funkcji ???
					/*std::for_each(
						entities.begin(),
						entities.end(),
						&IEntity::ToString);*/

					cout << endl;
				}

				void Initialize(Context<3> &c)
				{
					cout << "db Size: " << c.Size() << endl;

					c.LoadFromFile();
				}

				void ViewEntities()
				{
					// Lambda
					std::for_each(
						entities.begin(),
						entities.end(),
						[](IEntity* e)
						{
							cout << (*e).ToString() << endl;
						}
					);
				}

				void Initialize(vector<IEntity*> &v)
				{
					vector<IEntity*> foo;
					foo.push_back(new Enemy<>({ 1, 100, 10, 20, 15 }));
					foo.push_back(new Enemy<>({ 2, 100, 15, 10, 15 }));
					foo.push_back(new Enemy<>({ 3, 100, 20, 30, 15 }));

					(*foo[0]).SetName() = "Enemy 1";
					(*foo[1]).SetName() = "Enemy 2";
					(*foo[2]).SetName() = "Enemy 3";

					// Adaptor iteratorów 
					std::copy(
						foo.begin(),
						foo.end(),
						std::back_inserter(v)
					);
				}
				
				void Initialize(Player<>* &p)
				{
					player = new Player<>();
					if (!(*player).LoadFromFile())
					{
						(*player).SelectClass();
						(*player).SelectRace();
						(*player).SelectName();
					}
				}

				void Main()
				{
					cout << "Welcome " << endl;

					cout << "Arena " << endl;
					cout << "Market " << endl;
					cout << "Save&Exit " << endl;
					int switchChoice;
					cin >> switchChoice;
					switch (switchChoice)
					{
					case 1:
						cout << "Arena " << endl;
						break;
					case 2:
						cout << "Market " << endl;
						break;
					case 3:
						cout << "Save&Exit " << endl;
						break;
					default:
						cout << "Invalid input" << endl;
						break;
					}
				}

				~Game()
				{
					cout << "Goodbye! " << endl;
				}
			};
		}
	}
}

#endif