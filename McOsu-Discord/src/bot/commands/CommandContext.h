#pragma once

#include "domain/scores/ScoreRepository.h"
#include "dpp/dpp.h"

struct CommandContext
{
	public:
		CommandContext(const ScoreRepository& scoreRepo);
		CommandContext() = delete;
		~CommandContext() = default;

		const ScoreRepository& ScoreRepo;
		std::optional<const dpp::message_create_t*> MessageCreateEvent = std::nullopt;
		std::optional<const dpp::slashcommand_t*> SlashCommandEvent = std::nullopt;
};