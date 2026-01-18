#include "RecentScoreCommand.h"
#include "bot/EmbedBuilder.h"

RecentScoreCommand::RecentScoreCommand()
{
	IsGlobal = true;

	Name = "mcrecent";
	Description = "Shows a user's recent McOsu score";
	Aliases = {"mcrs"};
}

void RecentScoreCommand::Handle(const CommandContext& ctx, CommandReply& reply)
{
	auto latestScore = ctx.ScoreRepo.GetLatestScore();

	std::string avatarUrl;

	if (ctx.MessageCreateEvent)
		avatarUrl = ctx.MessageCreateEvent.value()->msg.author.get_avatar_url();
	else if (ctx.SlashCommandEvent)
		avatarUrl = ctx.SlashCommandEvent.value()->command.get_issuing_user().get_avatar_url();

	if (latestScore.has_value())
		reply.Send(EmbedBuilder::ScoreEmbed(latestScore.value(), avatarUrl));
	else
		reply.Send(dpp::message("no recent scores found :c"));
}
