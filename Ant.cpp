#include "Ant.h"

namespace AntJourney {

	Ant::Ant(const Position& pos, PositionSet& set) : m_pos(pos), m_externalSet(set)
	{
	}

	bool Ant::CanMove(const Position& pos) const
	{
		return SumCoord(pos) < kCriticalDigitSum && m_externalSet.find(pos) == m_externalSet.end();
	}

	uint64_t Ant::SumCoord(const Position& pos) const
	{
		auto [x, y] = pos;
		auto sum = [](uint64_t coord)->auto {
			uint64_t total = 0;
			while (coord > 0) {
				total += coord % 10;
				coord /= 10;
			}
			return total;
		};
		return sum(x) + sum(y);
	}

	AntList Ant::ProduceChildren()
	{
		AntList res;
		auto [x, y] = m_pos;
		for (const Position& pos : std::list<Position>{ {x + 1,y},{x - 1,y},{x,y + 1},{x,y - 1} }) {
			if (CanMove(pos)) {
				res.emplace_back(std::make_unique<Ant>(pos, m_externalSet));
				m_externalSet.insert(pos);
			}
		}
		return res;
	}
}