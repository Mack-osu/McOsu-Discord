#pragma once
#include <string>
#include <unordered_map>

namespace util
{
	std::string MsToMMSS(int64_t ms);
	std::string GradeToEmote(std::string grade);
	std::string FormatBeatmapStatistic(double value);

	inline std::unordered_map<std::string, std::string> EmojiMap;
}