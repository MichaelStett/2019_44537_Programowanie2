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
				virtual int CalculateAttack() = 0;
				virtual int CalculateDefense() = 0;
				virtual int CalculateSpeed() = 0;

				// Player only
				virtual int CalulateReward() = 0;
			};
		}
	}
}

#endif