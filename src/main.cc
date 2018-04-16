
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

#include "block.h"
#include "blockchain.h"
#include "util/utiltime.h"
#include "mining.h"
#include "udp/server.hpp"
#include "udp/client.hpp"
#include "constant.h"

#define BLOCK_MAX 10
#define DIFFICULTY 5


using namespace std;

string testData[BLOCK_MAX] = {"Genesis Block"};

Blockchain blockchain;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(false);

	char* SERVER_PORT;
	char* CLIENT_IP;
	char* CLIENT_PORT;

	if (argc != 4){
		std::cerr << "Usage: result <SERVER_PORT> <CLIENT_IP> <CLIENT_PORT>\n";

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
	for(int i=1; i<BLOCK_MAX; i++){
		testData[i] += "Block #" + boost::lexical_cast<string>(i);
		cout << " - " << testData[i] << "\n";
	}

	cout << "\n\n";

	std::thread run_thread([&]{ startServer(SERVER_PORT); });


	// Mining until block number 10
	for(int i=0; i<BLOCK_MAX; i++){

		if(i==0){
			blockchain.push_back(miningBlock(" ", testData[i], getTime(), DIFFICULTY));
		}else{
			blockchain.push_back(miningBlock(blockchain[i-1]->hash, testData[i], getTime(), DIFFICULTY));
		}

		std::thread run_thread2([&]{ startClient(CLIENT_IP, CLIENT_PORT); });
		run_thread2.detach();

		cout << "Block #" << i+1 << " " << blockchain[i]->hash << " " << testData[i] << " " << getTime() << "\n\n";
	}
	run_thread.detach();

	// Print all blocks
	cout << "-----------\n";
	cout << "Mining End!\n";

	for(int i=0; i<BLOCK_MAX; i++){
		cout << " - Block #" << i+1 << " " << blockchain[i]->hash << "\n";
	}
	cout << "-----------\n\n";

	return 0;
}
