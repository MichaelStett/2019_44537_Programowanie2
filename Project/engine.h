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
					do {
						cout << "---Welcome---" << endl;

						cout << "1. Arena " << endl;
						cout << "2. Market " << endl;
						cout << "3. Save&Exit " << endl;
						int switchChoice;
						cin >> switchChoice;
						switch (switchChoice)
						{
						case 1:
							cout << "Arena " << endl;
							ChooseOpponent();
							break;
						case 2:
							cout << "Market is currently closed!" << endl;
							break;
						case 3:
							player->SaveCharacter();
							cout << "Saved! " << endl;
							system("pause");
							exit(0);
							break;
						default:
							cout << "Invalid input" << endl;
							break;
						}
					} while (true);
				}

				void ChooseOpponent()
				{
					auto choose = 0;

					cout << "Choose opponent: " << endl;
					cout << "1. " << entities[0]->ToString() << endl;
					cout << "2. " << entities[1]->ToString() << endl;
					cout << "3. " << entities[2]->ToString() << endl;
					cin >> choose;

					switch (choose)
					{
					case 1:
						Arena(player, entities[0]);
						break;
					case 2:
						Arena(player, entities[1]);
						break;
					case 3:
						Arena(player, entities[2]);
						break;
					default:
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
								Battle::CalculateAttack(p, e) - Battle::CalculateDefense(e, p)
							};
							

							if (damage <= 0)
							{
								damage = 10 * Battle::GetRandom();
							}
							e->Set(Health) -= damage;
							cout << p->GetName() << " dealt " << damage << endl;

							if (e->Get(Health) <= 0) {
								return true;
							}

							damage =
							{
								Battle::CalculateAttack(e, p) - Battle::CalculateDefense(p, e)
							};

							if (damage <= 0)
							{
								damage = 10 * Battle::GetRandom();
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
								Battle::CalculateAttack(e, p) - Battle::CalculateDefense(p, e)
							};

							if (damage <= 0)
							{
								damage = 10 * Battle::GetRandom();
							}
							p->Set(Health) -= damage;
							cout << e->GetName() << " dealt " << damage << endl;

							if (p->Get(Health) <= 0) {
								return false;
							}

							damage =
							{
								Battle::CalculateAttack(p, e) - Battle::CalculateDefense(e, p)
							};

							if (damage <= 0)
							{
								damage = 10 * Battle::GetRandom();
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