#pragma once
#include "Ant.h"
namespace AntJourney {
	class AntManager
	{
	public:
		explicit AntManager(Position pos);
		size_t GetSize();
		void Run();
	private:
		PositionSet m_set;
		AntList m_ants;
	};
}
