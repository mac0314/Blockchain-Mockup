#ifndef _MINING_H_
#define _MINING_H_

#include <string>
#include <stddef.h>
#include <stdint.h>
#include "../block/block.h"
#include "../hash/hash.h"

extern Block* miningBlock(std::string preHash, std::string data, int64_t timestamp, uint32_t difficulty);

#endif
