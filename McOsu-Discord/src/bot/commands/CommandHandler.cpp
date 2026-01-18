#include "CommandHandler.h"
#include "domain/commands/RecentScoreCommand.h"
#include "CommandReply.h"
#include "PrefixReply.hpp"
#include "SlashReply.hpp"

CommandHandler::CommandHandler(dpp::snowflake botId, const ScoreRepository& scoreRepo)
	: _botId(botId), _scoreRepository(scoreRepo) {}

void CommandHandler::Init()
{
	_commands.push_back(std::make_unique<RecentScoreCommand>());
}

std::vector<dpp::slashcommand> CommandHandler::GetSlashCommandDefinitions()
{
	std::vector<dpp::slashcommand> commands;

	for (auto& command : _commands)
	{
		commands.emplace_back(command->Name, command->Description, _botId);
	}

	return commands;
}

void CommandHandler::OnSlashCommand(const dpp::slashcommand_t& event)
{
	std::string commandName = event.command.get_command_name();

	for (auto& command : _commands)
	{
		std::vector<std::string> aliases = command->Aliases;
		if (command->Name == commandName || std::find(aliases.begin(), aliases.end(), commandName) != aliases.end())
		{
			CommandContext ctx(_scoreRepository);
			ctx.SlashCommandEvent = &event;
			SlashReply reply(event);

			command->Handle(ctx, reply);
		}
	}
}

void CommandHandler::OnMessageCreate(const dpp::message_create_t& event)
{
	std::string msg = event.msg.content;

	if (!msg.starts_with('<'))
		return;

	size_t spacePos = msg.find(' ');
	std::string commandName = msg.substr(1, spacePos == std::string::npos ? std::string::npos : spacePos - 1);
	std::transform(commandName.begin(), commandName.end(), commandName.begin(),
		[](unsigned char c) { return std::tolower(c); });

	for (auto& command : _commands)
	{
		std::vector<std::string> aliases = command->Aliases;

		if (command->Name == commandName || std::find(aliases.begin(), aliases.end(), commandName) != aliases.end())
		{
			CommandContext ctx(_scoreRepository);
			ctx.MessageCreateEvent = &event;

			PrefixReply reply(event);

			command->Handle(ctx, reply);
		}
	}
}
