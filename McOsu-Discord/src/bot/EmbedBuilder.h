#pragma once
#include "dpp/dpp.h"
#include "domain/scores/ScoreData.hpp"

class EmbedBuilder
{
	public:
		static dpp::embed ScoreEmbed(const ScoreData& score, const std::string& avatarUrl);
};