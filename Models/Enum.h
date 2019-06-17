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
			namespace Common
			{
				enum Values
				{
					Level,
					Health,
					Attack,
					Defense,
					Speed,
					Luck,
					Gold,
					ExpPoints,
					ExpCap,
				};

				inline string ToString(Values v)
				{
					switch (v)
					{
					case Level:
						return "Level";
					case Health:
						return "Health";
					case Attack:
						return "Attack";
					case Defense:
						return "Defense";
					case Speed:
						return "Speed";
					case Gold:
						return "Gold";
					case Luck:
						return "Luck";
					case ExpPoints:
						return "ExpPoints";
					case ExpCap:
						return "ExpCap";
					default:
						assert(!"Invalid enum value");
						break;
					}
				}
			}
		}
	}
}

#endif