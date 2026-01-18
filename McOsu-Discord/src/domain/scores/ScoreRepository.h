#pragma once
#include <optional>
#include <mutex>

#include "ScoreData.hpp"

class ScoreRepository 
{
    public:
        ScoreRepository() = default;
        ~ScoreRepository() = default;

        void Update(ScoreData data);
        std::optional<ScoreData> GetLatestScore() const;

    private:
        mutable std::mutex _mutex;
        std::optional<ScoreData> _latest;
};
