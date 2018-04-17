
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef _CLIENT_HPP_
#define _CLIENT_HPP_


#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <boost/asio.hpp>

#include "../block/block.h"

using boost::asio::ip::udp;

enum { max_length = 1024 };

extern void startClient(Block* block, char* ip, char* port);

#endif
