#include "EmbedBuilder.h"
#include "util/util.h"

#include <format>

// TODO: display rate change
dpp::embed EmbedBuilder::ScoreEmbed(const ScoreData& score, const std::string& avatarUrl)
{
    dpp::embed embed;

    // Name
    std::string authorLine = 
        score.player.name;

    // Artist - Title [Difficulty] [SR★]
    std::string titleLine = 
        score.beatmap.artist + " - "
        + score.beatmap.title + " ["
        + score.beatmap.difficulty + "] ["
        + std::format("{:.2f}", score.difficulty.stars_total) + "★]";

    std::string titleUrl = 
        "https://osu.ppy.sh/beatmaps/" +
        std::to_string(score.beatmap.beatmap_id);

    // S +NM 975,231 99.15%  4133x/4295x  3x 2sb
    std::string gradeLine = 
        util::GradeToEmote(score.score.grade)
        + "** +" + (score.mods.string.empty() ? "NM" : score.mods.string) + score.mods.experimental
        + "\u2007\u2007"
        + std::format(std::locale("en_US.UTF-8"), "{:L}", score.score.value)
        + "\u2007\u2007"
        + std::format("{:.2f}", score.score.accuracy * 100) + "%"
        + "\u2007\u2007"
        + std::to_string(score.score.combo.max) + "x/" + std::to_string(score.score.combo.map_max) + "x"
        + "\u2007\u2007"
        + (score.score.hits.miss > 0 ? std::to_string(score.score.hits.miss) + util::EmojiMap["miss"] + " " : "")
        + (score.score.hits.slider_breaks > 0 ? std::to_string(score.score.hits.slider_breaks) + "sb**\n" : "**\n");

    // 351.73/420.20PP (386.36pp) • {622/8/0/1}
    std::string ppLine =
        "**" + std::format("{:.2f}", score.score.pp) + "**/"
        + std::format("{:.2f}", score.score.pp_max) + "PP "
        + (score.score.hits.miss == 0 && score.score.hits.slider_breaks == 0 ? "" : "~~(" + std::format("{:.2f}", score.score.pp_fc) + "pp)~~")
        + " • {"
        + std::to_string(score.score.hits.n300) + "/"
        + std::to_string(score.score.hits.n100) + "/"
        + std::to_string(score.score.hits.n50) + "/"
        + std::to_string(score.score.hits.miss) + "}\n";

    // 01:54 • CS: 5 AR: 9.67 OD: 9.11 HP: 7 • :BPM: 217.5
    std::string statsLine =
        "`" + util::MsToMMSS(score.beatmap.length_ms) + "` • " +
        "`CS: " + util::FormatBeatmapStatistic(score.difficulty.cs) + "  "
        "AR: " + util::FormatBeatmapStatistic(score.difficulty.ar) + "  "
        "OD: " + util::FormatBeatmapStatistic(score.difficulty.od) + "  "
        "HP: " + util::FormatBeatmapStatistic(score.difficulty.hp) + "` • "
        + util::EmojiMap["bpm"] + "**" + std::to_string(score.beatmap.bpm_common) + "**\n";

    embed
        .set_color(0x1F8B4C)
        .set_author( authorLine, "", avatarUrl)
        .set_title(titleLine)
        .set_url(titleUrl)
        .set_description
        (
            gradeLine
            + ppLine
            + statsLine
            + "<t:" + std::to_string(score.timestamp) + ":R>"
        )
        .set_footer(
            "Mapset by " + score.beatmap.creator,
            "https://cdn.discordapp.com/emojis/1458142644768080135.png"
        )
        .set_image(
            "https://assets.ppy.sh/beatmaps/" +
            std::to_string(score.beatmap.beatmapset_id) + "/covers/cover.jpg"
        );

    return embed;
}