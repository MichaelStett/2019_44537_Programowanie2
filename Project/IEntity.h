#ifndef IENTITY_H
#define IENTITY_H

#pragma once

#include <iostream>

using std::cout;
using std::endl;

using std::string;

namespace MT
{
	namespace Project
	{
		namespace Database
		{
			namespace Models
			{
				class IEntity
				{
				public:
					explicit IEntity()
					{
						cout << "Constructor IEntity" << endl;
					}

					virtual int Get(size_t index) const = 0;
					virtual int& Set(size_t index) = 0;
					virtual string& SetName() = 0;
					virtual string GetName() const = 0;
					virtual string ToString() = 0;

					virtual ~IEntity()
					{
						cout << "Destructor IEntity" << endl;
					}
				};
			}
		}
	}
}

#endif