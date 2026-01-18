#pragma once
#include <string>

namespace util
{
	// TODO: Emote Constants

	std::string MsToMMSS(int64_t ms);
	std::string GradeToEmote(std::string grade);
	std::string FormatBeatmapStatistic(double value);
}