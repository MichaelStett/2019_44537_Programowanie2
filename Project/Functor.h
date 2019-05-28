#ifndef FUNCTOR_H
#define FUNCTOR_H

#pragma once
#include "Database.h"

#include <iostream>

using std::cout;

using namespace MT::Project::Database::Models;

namespace MT
{
	namespace Project
	{
		namespace Functor
		{
			class IFunctor
			{
			public:
				IFunctor() {};
				virtual void operator()(IEntity* &one) = 0;
			};

			class Add :
				public IFunctor
			{
			private:
				int value;
			public:
				Add(int x = 0) : value{ x } {}

				virtual void operator()(IEntity* &one)
				{
					for (size_t i = 0; i < 4; i++)
						one->Set(i) += value;
				}
			};

			class Sub :
				public IFunctor
			{
			private:
				int value;
			public:
				Sub(int x = 0) : value{ x } {}

				virtual void operator()(IEntity* &one)
				{
					for (size_t i = 0; i < 4; i++)
						one->Set(i) -= value;
				}
			};

			void operation(IEntity* &one, IFunctor* func) {
				(*func)(one);
			}
		}
	}
}

#endif