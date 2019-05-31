#ifndef IPLAYERSERVICE_H
#define IPLAYERSERVICE_H

#pragma once

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			class IPlayerService
			{
			public:
				virtual void SelectRace() = 0;
				virtual void SelectClass() = 0;
				virtual void SelectName() = 0;
				virtual bool LoadFromFile() = 0;
			};
		}
	}
}

#endif