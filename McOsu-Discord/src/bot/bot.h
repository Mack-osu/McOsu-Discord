#pragma once
#include <string>
#include <dpp/dpp.h>

#include "domain/scores/ScoreRepository.h"
#include "commands/CommandHandler.h"

class Bot 
{
    public:
        Bot() = delete;
        ~Bot() = default;
        Bot(std::string token, ScoreRepository& scoreRepo);

        void Start();

    private:
        dpp::cluster _bot;
        ScoreRepository& _scoreRepo;
        CommandHandler _commandHandler;
};
