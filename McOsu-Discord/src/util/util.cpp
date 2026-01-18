#include "util.h"
#include <format>

std::string util::MsToMMSS(int64_t ms)
{
    int totalSeconds = ms / 1000;
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    return std::format("{:02d}:{:02d}", minutes, seconds);
}

std::string util::GradeToEmote(std::string grade)
{
    if (grade == "XH")
    {
        return EmojiMap["XH"];
    }
    else if (grade == "X")
    {
        return EmojiMap["X_"];
    }
    else if (grade == "SH")
    {
        return EmojiMap["SH"];
    }
    else if (grade == "S")
    {
        return EmojiMap["S_"];
    }
    else if (grade == "A")
    {
        return EmojiMap["A_"];
    }
    else if (grade == "B")
    {
        return EmojiMap["B_"];
    }
    else if (grade == "C")
    {
        return EmojiMap["C_"];
    }
    else if (grade == "D")
    {
        return EmojiMap["D_"];
    }
    else if (grade == "F")
    {
        return EmojiMap["F_"];
    }

    return "";
}

std::string util::FormatBeatmapStatistic(double value)
{
    std::string s = std::format("{:.2f}", value);

    s.erase(s.find_last_not_of('0') + 1);

    if (!s.empty() && s.back() == '.') 
        s.pop_back();

    return s;
}