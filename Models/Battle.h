#ifndef BATTLE_H
#define BATTLE_H

#pragma once

#include "..\Models\IBattleService.h"
#include "..\Models\IEntity.h"
#include "..\Models\Enum.h"

using namespace MT::Project::Models::Common;

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			class Battle
				: public IBattleService
			{
			private:
				int damageFactor;
			public:
				
				Battle()
				{
					damageFactor = 10;
				}

				static int CalculateAttack(IEntity* o, IEntity* p) 
				{
					auto AttackValue = o->Get(Attack) - p->Get(Defense);

					if (AttackValue <= 0)
					{
						AttackValue = 1;
					}

					return AttackValue;
				}

				static int CalculateDefense(IEntity* o, IEntity* p)
				{
					auto DefenseValue = o->Get(Defense) - p->Get(Attack);

					if (DefenseValue <= 0)
					{
						DefenseValue = 1;
					}

					return DefenseValue;
				}

				static int CalculateSpeed(IEntity* o, IEntity* p)
				{
					auto SpeedValue = o->Get(Speed) - p->Get(Speed);

					if (SpeedValue <= 0)
					{
						SpeedValue = 1;
					}

					return SpeedValue;
				}

				static int CalculateReward()
				{

				}
			};
		}
	}
}

#endif