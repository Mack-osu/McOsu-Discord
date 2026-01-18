#include "bot.h"
#include "EmbedBuilder.h"

Bot::Bot(std::string token, ScoreRepository& scoreRepo)
    : _scoreRepo(scoreRepo), _bot(dpp::cluster(token, dpp::i_default_intents | dpp::i_message_content)), _commandHandler(_bot.me.id, _scoreRepo)
{

}

void Bot::Start()
{
    _bot.on_log(dpp::utility::cout_logger());

    _bot.on_ready([this](const dpp::ready_t& event)
        {
            _commandHandler.Init();

            if (dpp::run_once<struct register_bot_commands>())
                _bot.global_bulk_command_create(_commandHandler.GetSlashCommandDefinitions());
        });

    _bot.on_message_create([this](const dpp::message_create_t& event)
        {
            _commandHandler.OnMessageCreate(event);
        });

    _bot.on_slashcommand([this](const dpp::slashcommand_t& event)
        {
            _commandHandler.OnSlashCommand(event);
        });

    _bot.start(dpp::st_wait);
}
