#ifndef IFUNCTOR_H
#define IFUNCTOR_H

#pragma once

#include "..\Models\IEntity.h"

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			namespace Common
			{
				class IFunctor
				{
				public:
					IFunctor() {};
					virtual void operator()(IEntity*& i) = 0;
					virtual void operator()(int& v) = 0;
				};
			}
		}
	}
}

#endif