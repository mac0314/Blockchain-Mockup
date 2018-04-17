
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef _SERVER_HPP_
#define _SERVER_HPP_


#include <cstdlib>
#include <iostream>
#include <boost/asio.hpp>
#include <nlohmann/json.hpp>

#include "../block/block.h"
#include "../block/blockchain.h"
#include "../hash/hash.h"
#include "../constant.h"

using boost::asio::ip::udp;

class server {
public:
  server(boost::asio::io_context& io_context, short port)
    : socket_(io_context, udp::endpoint(udp::v4(), port)){
    do_receive();
  }

  void do_receive();
  void do_send(std::size_t length);

private:
  udp::socket socket_;
  udp::endpoint sender_endpoint_;
  enum { max_length = 1024 };
  char data_[max_length];
};

extern void startServer(char* port);

#endif
