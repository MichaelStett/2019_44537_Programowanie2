#ifndef DATABASE_H
#define DATABASE_H

#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

#include "Enum.h"
#include "IEntity.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

using std::cout;
using std::endl;
using std::pair;
using std::vector;

using namespace MT::Project::Database::Models;

namespace MT
{
	namespace Project
	{
		namespace Database
		{
			template <const size_t size = 3>
			class Context
			{
			private:
				vector<vector<Entity>> matrix;
			public:
				Context() {
					if (size <= 1) { assert(!"Wrong size of Database"); }
					cout << "Constructor Context" << endl;

					matrix.resize(size);
					for (int i = 0; i < size; i++)
						matrix[i].resize(size);
				}

				void Set(const pair <size_t, size_t>& coords, size_t index, int value) {
					matrix[coords.first][coords.second].Set(index) = value;
				}

				int Get(const pair <size_t, size_t>& coords, size_t index) {
					return matrix[coords.first][coords.second].Get(index);
				}

				size_t Size() { return size; }

				~Context() {
					cout << "Destructor Context " << endl;
				}
			};
		}
	}
}

#endif