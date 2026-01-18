#pragma once

#include "CommandReply.h"

class SlashReply : public CommandReply
{
public:
	SlashReply(const dpp::slashcommand_t& event)
		: _event(event) {}

	void Send(const dpp::message& msg) override
	{
		_event.reply(msg);
	}

private:
	const dpp::slashcommand_t& _event;
};