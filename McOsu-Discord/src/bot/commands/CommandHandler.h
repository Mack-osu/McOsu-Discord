#pragma once

#include <vector>
#include <memory>

#include "domain/commands/Command.h"
#include "dpp/dpp.h"

class CommandHandler
{
	public:
		CommandHandler(dpp::snowflake botId, const ScoreRepository& scoreRepo);
		CommandHandler() = default;
		~CommandHandler() = default;
		void Init();
		std::vector<dpp::slashcommand> GetSlashCommandDefinitions();
		void OnSlashCommand(const dpp::slashcommand_t& event);
		void OnMessageCreate(const dpp::message_create_t& event);


	private:
		const dpp::snowflake _botId;
		const ScoreRepository& _scoreRepository;
		std::vector<std::unique_ptr<Command>> _commands;

};