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
        return "<:XH:1457844432861790298>";
    }
    else if (grade == "X")
    {
        return "<:X_:1457844424565592188>";
    }
    else if (grade == "SH")
    {
        return "<:SH:1457844416474644724>";
    }
    else if (grade == "S")
    {
        return "<:S_:1457844407649697792>";
    }
    else if (grade == "A")
    {
        return "<:A_:1457844356084928791>";
    }
    else if (grade == "B")
    {
        return "<:B_:1457844372618874890>";
    }
    else if (grade == "C")
    {
        return "<:C_:1457844381238432038>";
    }
    else if (grade == "D")
    {
        return "<:D_:1457844391157825537>";
    }
    else if (grade == "F")
    {
        return "<:F_:1457844399722467349>";
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
