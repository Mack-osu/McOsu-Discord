#pragma once

#include "Command.h"

class RecentScoreCommand : public Command
{
	public:
		RecentScoreCommand();
		~RecentScoreCommand() = default;

	protected:
		void Handle(const CommandContext& ctx, CommandReply& reply) override;

	private:
};