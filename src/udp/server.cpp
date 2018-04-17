
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#include "server.hpp"

void server::do_receive(){
  //std::cout << "do_receive\n";
  socket_.async_receive_from(
      boost::asio::buffer(data_, max_length), sender_endpoint_,
      [this](boost::system::error_code ec, std::size_t bytes_recvd){
        if (!ec && bytes_recvd > 0){
          //std::cout << "bytes_recvd : " << bytes_recvd << "\n";
          //std::cout << data_ << "\n";

          auto json = nlohmann::json::parse(data_);

          std::cout << std::setw(4) << json << "\n";

          //std::cout << calcHash(json.at("preHash").get<std::string>(), "", json.at("nTime").get<int64_t>(), json.at("nNonce").get<uint32_t>()) << "\n";

          //std::cout << json.at("hash").get<std::string>() << "\n\n";


          if(json.at("hash").get<std::string>().compare( calcHash(json.at("preHash").get<std::string>(), "", json.at("nTime").get<int64_t>(), json.at("nNonce").get<uint32_t>())) == 0){
            std::cout << "Hash Check true" << "\n";

            blockchain.push_back(new Block(json.at("version").get<int32_t>(), json.at("preHash").get<std::string>(), json.at("hash").get<std::string>(), json.at("nTime").get<int64_t>(), json.at("nBits").get<uint32_t>(), json.at("nNonce").get<uint32_t>()));

            std::cout << "block : " << blockchain.size() << "\n\n";

            idx++;
          }

          do_send(bytes_recvd);
        } else {
          do_receive();
        }
      });
}

void server::do_send(std::size_t length){
  //std::cout << "do_send\n";
  //std::cout << "length : " << length << "\n";
  socket_.async_send_to(
      boost::asio::buffer(data_, length), sender_endpoint_,
      [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/){
        do_receive();
      });
}

void startServer(char* port){
  try {
    //std::cout << "startServer\n";
    boost::asio::io_context io_context;

    server s(io_context, std::atoi(port));

    io_context.run();
  } catch (std::exception& e){
    std::cerr << "Exception: " << e.what() << "\n";
  }
}
