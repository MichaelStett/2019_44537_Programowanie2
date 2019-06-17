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

					cout << endl;

					Main();

					cout << endl;
				}

				void Initialize(Context<3> & c)
				{
					cout << "db Size: " << c.Size() << endl;

					c.LoadFromFile();
				}

				void Initialize(vector<IEntity*>& v)
				{
					vector<IEntity*> foo;
					foo.push_back(new Enemy<>({ 1, 100, 10, 20, 15 }));
					foo.push_back(new Enemy<>({ 2, 100, 15, 10, 15 }));
					foo.push_back(new Enemy<>({ 3, 100, 20, 30, 15 }));

					(*foo[0]).SetName() = "Enemy";
					(*foo[1]).SetName() = "Enemy";
					(*foo[2]).SetName() = "Enemy";

					// Adaptor iteratorów 
					std::copy(
						foo.begin(),
						foo.end(),
						std::back_inserter(v)
					);
				}

				void Initialize(Player<>*& p)
				{
					player = new Player<>();
					if (!(*player).LoadFromFile())
					{
						(*player).SelectClass();
						(*player).SelectRace();
						(*player).SelectName();
					}
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
						Arena(player, entities[0]);
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

				bool Battle(Player<>* &p, IEntity* &e) {
					bool Prio = Battle::CalculateSpeed(p, e);
					int damage;
	
					while (true) 
					{
						cout << p->ToString() << endl;
						cout << e->ToString() << endl;
						if (Prio) {
							damage =
							{
								Battle::CalculateDefense(e, p) - Battle::CalculateAttack(p, e)
							};
							

							if (damage <= 0)
							{
								damage = 1;
							}
							e->Set(Health) -= damage;
							cout << p->GetName() << " dealt " << damage << endl;

							if (e->Get(Health) <= 0) {
								return true;
							}

							damage =
							{
								Battle::CalculateDefense(p, e) - Battle::CalculateAttack(e, p)
							};

							if (damage <= 0)
							{
								damage = 1;
							}
							p->Set(Health) -= damage;
							cout << e->GetName() << " dealt " << damage << endl;
							

							if (p->Get(Health) <= 0) {
								return false;
							}
						}
						else
						{
							damage =
							{
								Battle::CalculateDefense(p, e) - Battle::CalculateAttack(e, p)
							};

							if (damage <= 0)
							{
								damage = 1;
							}
							p->Set(Health) -= damage;
							cout << e->GetName() << " dealt " << damage << endl;

							if (p->Get(Health) <= 0) {
								return false;
							}

							damage =
							{
								Battle::CalculateDefense(e, p) - Battle::CalculateAttack(p, e)
							};

							if (damage <= 0)
							{
								damage = 1;
							}
							e->Set(Health) -= damage;
							cout << p->GetName() << " dealt " << damage << endl;

							if (e->Get(Health) <= 0) {
								return true;
							}
						}
					}
				}

				void Arena(Player<>* &p, IEntity* &e)
				{
					if (Battle(p, e))
					{
						cout << "You won! " << endl;
						p->Set(Gold) = Battle::CalculateReward(p, e);
						p->Set(ExpPoints) = Battle::CalculateReward(p, e);

						if (p->Get(ExpPoints) > p->Get(ExpCap))
						{
							cout << "You leveled up!" << endl;
							p->Set(Health) = 100;
							p->LevelUp();
						}
					}
					else
					{
						cout << " You died :( " << endl;
						system("exit");
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