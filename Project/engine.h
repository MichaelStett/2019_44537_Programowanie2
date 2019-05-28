#ifndef ENGINE_H
#define ENGINE_H

#pragma once

#include "Functor.h"
#include "Database.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::ostream;

using namespace MT::Project::Functor;
using namespace MT::Project::Database;
using namespace MT::Project::Database::Enum;
using namespace MT::Project::Database::Models;

namespace MT
{
	namespace Project
	{
		namespace Engine
		{
			ostream& operator << (ostream& out, const pair<size_t, size_t>& c) {
				out << "<" << c.first << "," << c.second << ">";
				return out;
			}

			class Game
			{
			private:
				Context<2> dbContext;
				vector<IEntity*> entities;
				pair<size_t, size_t> coords;
			public:


				// zrobi e jak player ma levelup to functor zwieksza wartos values przeciwnikow w database
				//
				//

				Game()
				{
					auto statsEnemy = vector<int>{ 10, 20, 30, 40 };
					entities.push_back(new Player);
					entities.push_back(new Enemy(statsEnemy));

					/*
					cout << "db Size: " << dbContext.Size() << endl;

					dbContext.Set({ 1, 0 }, 0, 5); // on <1,0> for zero change value to 5

					coords = { 0, 0 };
					dbContext.Set(coords, 3, 5);

					entities[0]->SetName() = "Player";
					entities[1]->SetName() = "Enemy";

					ViewContext();
					*/

					cout << "Player: " << (*entities[0]).ToString() << endl;
					cout << "Enemy: " << (*entities[1]).ToString() << endl;

					std::for_each(
						entities.begin(),
						entities.end(),
						[this](IEntity* obj) {
						operation(obj, new Add(5));
					});

					std::for_each(
						entities.begin(),
						entities.end(),
						Add(5)
					);

					//operation((*entities[0]), new Add(3));
					//operation((*entities[1]), new Add(5));

					cout << "Player: " << (*entities[0]).ToString() << endl;
					cout << "Enemy: " << (*entities[1]).ToString() << endl;
				}



				void Main()
				{
					cout << "Welcome " << endl;

					int choice = 0;
					cout << "Arena " << endl;
					cout << "Market " << endl;
					cout << "Save&Exit " << endl;

					cin >> choice;
					if (choice == 1)
					{
						cout << "Arena " << endl;
					}
					else if (choice == 2)
					{
						cout << "Market " << endl;
					}
					else if (choice == 3)
					{
						cout << "Save&Exit " << endl;
					}
					else
					{
						cout << "Invalid input" << endl;
					}
				}

				void ViewContext()
				{
					for (coords.first = 0; coords.first < dbContext.Size(); coords.first++)
					{
						for (coords.second = 0; coords.second < dbContext.Size(); coords.second++)
						{
							for (int i = 0; i <= 3; i++)
							{
								cout << coords
									<< " on " << ToString(static_cast<Values>(i))
									<< " = " << dbContext.Get(coords, i) << endl;
							}
						}
						cout << endl;
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