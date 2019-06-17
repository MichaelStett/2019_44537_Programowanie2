#ifndef IBATTLESERVICE_H
#define IBATTLESERVICE_H

#pragma once

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			class IBattleService
			{
			public:
				virtual int CalculateAttack(IEntity* o, IEntity* p) = 0;
				virtual int CalculateDefense(IEntity* o, IEntity* p) = 0;
				virtual bool CalculateSpeed(IEntity* o, IEntity* p) = 0;
				virtual int CalulateReward(IEntity* o, IEntity* p) = 0;
			};
		}
	}
}

#endif