
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#include "client.hpp"

void startClient(Block* block, char* ip, char* port){
  //std::cout << "startClient\n";
  try {
    boost::asio::io_context io_context;

    udp::socket s(io_context, udp::endpoint(udp::v4(), 0));

    udp::resolver resolver(io_context);
    udp::resolver::results_type endpoints =
      resolver.resolve(udp::v4(), ip, port);

    // Request
    char data[max_length];

    strcpy(data, block->toString().c_str());
    s.send_to(boost::asio::buffer(data, max_length), *endpoints.begin());

    //std::cout << "send_to: " << data << "\n";

    /*
    // Response
    char reply[max_length];

    udp::endpoint sender_endpoint;
    size_t reply_length = s.receive_from(
        boost::asio::buffer(reply, max_length), sender_endpoint);

    //std::cout << "Reply is: " << reply << '\n';
    */
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }
}
