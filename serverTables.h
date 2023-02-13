#ifndef SERVERTABLES_H
#define SERVERTABLES_H

#pragma once
#include <algorithm>
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

#include <boost/asio.hpp>

#include "server_commands.h"
#include "gettingCommands.h"

namespace join_query
{
    namespace ba = boost::asio;

    class serverTables
    {
    public:
        serverTables(uint16_t port);

        ~serverTables() = default;

        void AcceptConnection();

    private:
        void consumer_thread();

        void producer_thread(std::shared_ptr<ba::ip::tcp::socket> sock);

        ba::io_service			service;
        ba::ip::tcp::acceptor	acc;

        abstract_command::handler_t handler;
        std::mutex					guard_mutex;
        std::condition_variable		cond_var;
        std::queue<std::pair<	std::weak_ptr<ba::ip::tcp::socket>,
                                std::unique_ptr<abstract_command>>> q;

    };
}




#endif // SERVERTABLES_H
