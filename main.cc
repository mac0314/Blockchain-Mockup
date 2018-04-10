#include <iostream>
#include <string>
#include "block.h"
#include "sha256.h"

using namespace std;

Block* b[50];

int main(void){
	string data = "Test #1";
	b[0] = new Block("Test #1", "Genesis Block");

	cout << 0 << " " <<  b[0]->preHash << " " << b[0]->hash << endl;

	int i = 1;
	while(true){
		string data;
		cin >> data;

		Block* nb = new Block(data, b[i-1]->hash);

		cout << "nb " << nb->preHash << " " << nb->hash << " " << nb->getTime() << endl;

		b[i] = nb;

		cout << i << " " << b[i]->preHash << " " << b[i]->hash << " " << b[i]->getTime() << endl;

		i++;
		if(i == 50)
			break;
	}


	return 0;
}
