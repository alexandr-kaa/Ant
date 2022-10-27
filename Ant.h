#pragma once
#include <tuple>
#include <set>
#include <list>
#include <memory>

namespace AntJourney {

	using Position = std::tuple<uint64_t, uint64_t>;
	using PositionSet = std::set<Position>;
	class IAnt;
	using AntList = std::list<std::unique_ptr<IAnt>>;

	class IAnt {
	public:
		virtual ~IAnt() = default;
		virtual bool CanMove(const Position& pos) const = 0;
		virtual uint64_t SumCoord(const Position& pos) const = 0;
		virtual AntList ProduceChildren() = 0;
	};

	class Ant : public IAnt
	{
	public:
		Ant(const Position&, PositionSet&);
		bool CanMove(const Position&) const override;
		uint64_t SumCoord(const Position&) const override;
		AntList ProduceChildren() override;
	private:
		Position m_pos;
		static constexpr uint8_t kCriticalDigitSum = 25;
		PositionSet& m_externalSet;
	};
}

