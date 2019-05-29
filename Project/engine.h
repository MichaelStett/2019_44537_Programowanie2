#ifndef ENGINE_H
#define ENGINE_H

#pragma once

#include "..\Models\Functor.h"
#include "..\Database\Context.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

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
			ostream& operator << (ostream& out, const pair<unsigned int, unsigned int>& c)
			{
				out << "<" << c.first << "," << c.second << ">";
				return out;
			}

			class Game
			{
			private:
				Context<3> dbContext;
				vector<IEntity*> entities;
				int switchChoice;
			public:
				// zrobić że jak player ma levelup to functor zwieksza wartos values przeciwnikow w database
				//
				//

				Game()
				{
					auto statsEnemy = vector<int>{ 10, 20, 30, 40 };
					auto x = new Player();
					x->LoadFromFile();
					entities.push_back(x);
					entities.push_back(new Enemy(statsEnemy));
					
					cout << "db Size: " << dbContext.Size() << endl;

					dbContext.Set({ 1, 0 }, 0, 5); // on <1,0> for zero change value to 5

					(*entities[0]).SetName() = "Player";
					(*entities[1]).SetName() = "Enemy";

					dbContext.ViewContext();
					dbContext.LoadFromFile();
					dbContext.ViewContext();

					cout << (*entities[0]).ToString() << endl;
					cout << (*entities[1]).ToString() << endl;

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

					vector<IEntity*> foo;
					foo.push_back(new Player());
					foo.push_back(new Enemy());

					vector<IEntity*>::iterator it = foo.begin() + 1;

					std::copy(
						foo.begin(),
						foo.end(), 
						std::back_inserter(entities));


					vector<IEntity*>::const_iterator c_it;

					cout << endl;
					for (c_it = entities.begin(); c_it != entities.end(); c_it++) {
						cout << (*(*c_it)).ToString() << endl;
					}
					cout << endl;

					//operation((*entities[0]), new Add(3));
					//operation((*entities[1]), new Add(5));

					cout << "Player: " << (*entities[0]).ToString() << endl;
					cout << "Enemy: " << (*entities[1]).ToString() << endl;
				}

				void Main()
				{
					cout << "Welcome " << endl;

					cout << "Arena " << endl;
					cout << "Market " << endl;
					cout << "Save&Exit " << endl;

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