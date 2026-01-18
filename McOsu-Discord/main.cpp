#include "bot/bot.h"
#include "http/HttpServer.h"

std::string LoadToken();

int main() 
{
    std::string token = LoadToken();

    if (token.empty())
        return 1;

    ScoreRepository repo;

    HttpServer http(repo);
    std::thread([&] { http.Run(3000); }).detach();

    Bot bot(token, repo);
    bot.Start();
    return 0;
}

std::string LoadToken() 
{
    std::ifstream file("config.txt");

    if (!file.is_open()) 
    {
        std::cerr << "Could not open config.txt" << std::endl;
        return {};
    }

    std::string line;

    while (std::getline(file, line)) 
    {
        const std::string key = "token=";
        if (line.rfind("token=", 0) == 0)
        {
            std::cout << "Token found" << std::endl;
            return line.substr(key.size());
        }
    }

    std::cerr << "Token not found in config.txt" << std::endl;
    return {};
}