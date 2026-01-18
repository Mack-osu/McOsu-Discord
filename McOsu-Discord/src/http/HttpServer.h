#pragma once
#include "domain/scores/ScoreRepository.h"

class HttpServer
{
	public:
		HttpServer() = delete;
		~HttpServer() = default;
		HttpServer(ScoreRepository& scoreRepo);

		void Run(int port);

	private:
		ScoreRepository& _scoreRepo;
};