
#include <iostream>
#include <thread>
#include <string>
#include <boost/lexical_cast.hpp>

#include "block/block.h"
#include "block/blockchain.h"
#include "util/utiltime.h"
#include "mining/mining.h"
#include "udp/server.hpp"
#include "udp/client.hpp"

#include "constant.h"


Blockchain blockchain;
uint32_t idx = 0;

using namespace std;


int main(int argc, char* argv[]){
	ios::sync_with_stdio(false);

	string testData[BLOCK_MAX] = {"Genesis Block"};

	char* SERVER_PORT;
	char* CLIENT_IP;
	char* CLIENT_PORT;

	if (argc != 4){
		std::cerr << "Usage: ./result <SERVER_PORT> <CLIENT_IP> <CLIENT_PORT>\n";

		return 1;
	}else{
		SERVER_PORT = argv[1];
		CLIENT_IP = argv[2];
		CLIENT_PORT = argv[3];
	}


	cout << "------------------------\n";
	cout << "Start Blockchain mockup!\n\n";


	// Setting test data
	cout << "\tData\n";
	cout << " - " << testData[0] << "\n";
	for(uint32_t i=1; i<BLOCK_MAX; i++){
		testData[i] += "Block #" + boost::lexical_cast<string>(i);
		cout << " - " << testData[i] << "\n";
	}

	cout << "\n\n";

	std::thread run_thread([&]{ startServer(SERVER_PORT); });


	// Mining until block number 10
	for(; idx<BLOCK_MAX; idx++){

		if(idx == 0){
			blockchain.push_back(miningBlock(" ", testData[idx], getTime(), DIFFICULTY));
		}else if(idx < 10){
			blockchain.push_back(miningBlock(blockchain[idx-1]->hash, testData[idx], getTime(), DIFFICULTY));

			// Client Thread
			//std::thread run_thread2([&]{ startClient(blockchain[i], CLIENT_IP, CLIENT_PORT); });
			//run_thread2.detach();

			// Client Process
			startClient(blockchain[idx], CLIENT_IP, CLIENT_PORT);

			cout << "Block #" << idx+1 << " " << blockchain[idx]->hash << " " << testData[idx] << " " << getTime() << "\n\n";
		}
	}
	run_thread.detach();

	// Print all blocks
	cout << "-----------\n";
	cout << "Mining End!\n";

	for(uint32_t i=0; i<BLOCK_MAX; i++){
		cout << " - Block #" << i+1 << " " << blockchain[i]->hash << "\n";
	}
	cout << "-----------\n\n";

	return 0;
}
