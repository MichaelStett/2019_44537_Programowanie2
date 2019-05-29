#ifndef ENUM_H
#define ENUM_H

#pragma once

#include <iostream>
#include <cassert>

using std::string;

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			enum EnemiesValues
			{
				Health,
				Attack,
				Defense,
				Level
			};

			inline string ToString(EnemiesValues v)
			{
				switch (v) {
				case Health:
					return "Health";
				case Attack:
					return "Attack";
				case Defense:
					return "Defense";
				case Level:
					return "Level";
				default:
					assert(!"Invalid enum value");
					break;
				}
			}
		}
	}
}

#endif