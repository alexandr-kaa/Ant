#include "AntManager.h"
namespace AntJourney {
	AntManager::AntManager(Position pos)
	{
		m_ants.emplace_back(std::make_unique<Ant>(pos, m_set));
	}

	size_t AntManager::GetSize()
	{
		return m_set.size();
	}

	void AntManager::Run()
	{
		while (m_ants.size()) {
			auto& workAnt = m_ants.front();
			m_ants.splice(m_ants.end(), workAnt->ProduceChildren());
			m_ants.pop_front();
		}
	}
}
