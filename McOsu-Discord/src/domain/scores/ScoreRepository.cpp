#include <iostream>

#include "ScoreRepository.h"

void ScoreRepository::Update(ScoreData score)
{
    if (score.schema != "mcosu.events.score.v1")
    {
        std::cerr << "Invalid score schema received: '" << score.schema << "', expected 'mcosu.events.score.v1'\n";
        return;
    }

    std::lock_guard lock(_mutex);
    _latest = std::move(score);
}

std::optional<ScoreData> ScoreRepository::GetLatestScore() const
{
    std::lock_guard lock(_mutex);
    return _latest;
}
