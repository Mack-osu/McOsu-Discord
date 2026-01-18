#include "HttpServer.h"
#include "httplib.h"

HttpServer::HttpServer(ScoreRepository& scoreRepo)
	: _scoreRepo(scoreRepo)
{

}

void HttpServer::Run(int port)
{
    httplib::Server server;
    
    server.Post("/event", [this](const httplib::Request& req,
        httplib::Response& res) 
        {
            try
            {
                auto json = nlohmann::json::parse(req.body);

                #ifdef _DEBUG
                    std::cout << json.dump(4) << "\n\n";
                #endif

                if (json.at("event") == "score_set")
                    _scoreRepo.Update(json.get<ScoreData>());

                res.status = 200;
                res.set_content("ok", "text/plain");
            }
            catch (const std::exception& e)
            {
                res.status = 400;
                res.set_content(e.what(), "text/plain");
            }
        });

    server.listen("127.0.0.1", port);
}
