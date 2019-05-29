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
			class IFunctor
			{
			public:
				IFunctor() {};
				virtual void operator()(IEntity* &one) = 0;
			};
		}
	}
}

#endif