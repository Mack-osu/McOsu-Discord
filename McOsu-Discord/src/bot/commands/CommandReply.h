#pragma once

#include "dpp/dpp.h"

class CommandReply 
{
    public:
        CommandReply() = default;
        virtual ~CommandReply() = default;

        virtual void Send(const dpp::message& msg) = 0;
};
