#pragma once
#include <string>
#include "json.hpp"

using namespace nlohmann;

struct Combo
{
    int max;
    int map_max;
    bool perfect;
};

inline void from_json(const json& j, Combo& c)
{
    j.at("max").get_to(c.max);
    j.at("map_max").get_to(c.map_max);
    j.at("perfect").get_to(c.perfect);
}


struct Hits
{
    int n300;
    int n100;
    int n50;
    int geki;
    int katu;
    int miss;
    int slider_breaks;
};

inline void from_json(const json& j, Hits& h)
{
    j.at("300").get_to(h.n300);
    j.at("100").get_to(h.n100);
    j.at("50").get_to(h.n50);
    j.at("geki").get_to(h.geki);
    j.at("katu").get_to(h.katu);
    j.at("miss").get_to(h.miss);
    j.at("slider_breaks").get_to(h.slider_breaks);
}


struct Score
{
    std::string grade;
    long long value;
    double pp;
    double pp_fc;
    double pp_max;
    float accuracy;
    Combo combo;
    Hits hits;
    double unstable_rate;
    double hit_error_min;
    double hit_error_max;
    bool legacy;
    bool unranked;
};

inline void from_json(const json& j, Score& s)
{
    j.at("grade").get_to(s.grade);
    j.at("value").get_to(s.value);
    j.at("pp").get_to(s.pp);
    j.at("pp_fc").get_to(s.pp_fc);
    j.at("pp_max").get_to(s.pp_max);
    j.at("accuracy").get_to(s.accuracy);
    j.at("combo").get_to(s.combo);
    j.at("hits").get_to(s.hits);
    j.at("unstable_rate").get_to(s.unstable_rate);
    j.at("hit_error").at("min").get_to(s.hit_error_min);
    j.at("hit_error").at("max").get_to(s.hit_error_max);
    j.at("legacy").get_to(s.legacy);
    j.at("unranked").get_to(s.unranked);
}


struct Mods
{
    int legacy;
    std::string string;
    std::string experimental;
};

inline void from_json(const json& j, Mods& m)
{
    j.at("legacy").get_to(m.legacy);
    j.at("string").get_to(m.string);
    j.at("experimental").get_to(m.experimental);
}

struct Difficulty
{
    double ar;
    double cs;
    double od;
    double hp;
    double stars_total;
    double stars_aim;
    double stars_speed;
    double speed_multiplier;
};

inline void from_json(const json& j, Difficulty& d)
{
    j.at("attributes").at("ar").get_to(d.ar);
    j.at("attributes").at("cs").get_to(d.cs);
    j.at("attributes").at("od").get_to(d.od);
    j.at("attributes").at("hp").get_to(d.hp);

    j.at("stars").at("total").get_to(d.stars_total);
    j.at("stars").at("aim").get_to(d.stars_aim);
    j.at("stars").at("speed").get_to(d.stars_speed);

    j.at("speed_multiplier").get_to(d.speed_multiplier);
}

struct Beatmap
{
    std::string md5;
    std::string title;
    std::string artist;
    std::string creator;
    std::string difficulty;

    int length_ms;

    int bpm_min;
    int bpm_max;
    int bpm_common;

    int objects_total;
    int objects_circles;
    int objects_sliders;
    int objects_spinners;

    int beatmap_id;
    int beatmapset_id;
};

inline void from_json(const json& j, Beatmap& b)
{
    j.at("md5").get_to(b.md5);

    j.at("title").get_to(b.title);
    j.at("artist").get_to(b.artist);
    j.at("creator").get_to(b.creator);
    j.at("difficulty").get_to(b.difficulty);

    j.at("length_ms").get_to(b.length_ms);

    j.at("bpm").at("min").get_to(b.bpm_min);
    j.at("bpm").at("max").get_to(b.bpm_max);
    j.at("bpm").at("common").get_to(b.bpm_common);

    j.at("objects").at("total").get_to(b.objects_total);
    j.at("objects").at("circles").get_to(b.objects_circles);
    j.at("objects").at("sliders").get_to(b.objects_sliders);
    j.at("objects").at("spinners").get_to(b.objects_spinners);

    j.at("ids").at("beatmap").get_to(b.beatmap_id);
    j.at("ids").at("beatmapset").get_to(b.beatmapset_id);
}

struct Player
{
    std::string name;
};

inline void from_json(const json& j, Player& p)
{
    j.at("name").get_to(p.name);
}


struct ScoreData
{
    std::string schema;
    std::string event;
    long long timestamp;

    Score score;
    Mods mods;
    Difficulty difficulty;
    Beatmap beatmap;
    Player player;
};

inline void from_json(const json& j, ScoreData& e)
{
    j.at("schema").get_to(e.schema);
    j.at("event").get_to(e.event);
    j.at("timestamp").get_to(e.timestamp);
    j.at("score").get_to(e.score);
    j.at("mods").get_to(e.mods);
    j.at("difficulty").get_to(e.difficulty);
    j.at("beatmap").get_to(e.beatmap);
    j.at("player").get_to(e.player);
}