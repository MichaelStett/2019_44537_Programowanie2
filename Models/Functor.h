#ifndef FUNCTOR_H
#define FUNCTOR_H

#pragma once

#include "..\Models\IFunctor.h"
#include "..\Models\IEntity.h"

namespace MT
{
	namespace Project
	{
		namespace Models
		{
			class Add final
				: public IFunctor
			{
			private:
				int value;
			public:
				Add(int x = 0) : value{ x } {}

				virtual void operator()(IEntity* &obj)
				{
					for (unsigned int i = 0; i < (*obj).ValuesLength(); i++)
						(*obj).Set(i) += value;
				}
			};

			class Sub final
				: public IFunctor
			{
			private:
				int value;
			public:
				Sub(int x = 0) : value{ x } {}

				virtual void operator()(IEntity* &obj)
				{
					for (unsigned int i = 0; i < (*obj).ValuesLength(); i++)
						(*obj).Set(i) -= value;
				}
			};

			void operation(IEntity* &obj, IFunctor* func)
			{
				(*func)(obj);
			}
		}
	}
}

#endif