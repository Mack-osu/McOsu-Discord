#pragma once

#include <string>
#include <vector>

#include "bot/commands/CommandContext.h"
#include "bot/commands/CommandReply.h"

class Command
{
	public:
		Command() = default;
		~Command() = default;

		virtual void Handle(const CommandContext& ctx, CommandReply& reply) = 0;
	
		bool IsGlobal = false;
		std::string Name = "";
		std::string Description = "";
		std::vector<std::string> Aliases = {};
};