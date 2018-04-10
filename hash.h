
#ifndef _HASH_H_
#define _HASH_H_

#include <stddef.h>
#include <stdint.h>
#include <string>

#include <boost/lexical_cast.hpp>

#include "crypto/sha256.h"

extern std::string calcHash(std::string preHash, std::string data, int64_t timestamp, int64_t nonce);

#endif
