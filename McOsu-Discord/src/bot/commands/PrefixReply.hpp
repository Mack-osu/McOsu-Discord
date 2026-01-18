#pragma once

#include "CommandReply.h"

class PrefixReply : public CommandReply
{
	public:
		PrefixReply(const dpp::message_create_t& event)
			: _event(event) {}

		void Send(const dpp::message& msg) override
		{
			_event.reply(msg);
		}

	private:
		const dpp::message_create_t& _event;
};