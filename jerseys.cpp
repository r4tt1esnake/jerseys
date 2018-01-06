#include <iostream>
#include <vector>
#include <fstream>

int jerseyCount;
int athleteCount;
int* sizeArr;	// Takes the form of sizeArr[ size ], where the index + 1 is the jersey number.
int** prefArr; // Takes the form of prefArr[ preferred_size ][ preferred_number ], where the index + 1 is the athlete number.

void getInput();

int main() {

	getInput();

	int count = 0;

	for(int i = 0; i < athleteCount; i++) {
		if(sizeArr[prefArr[i][1] - 1] >= prefArr[i][0]) {
			count++;
			sizeArr[prefArr[i][1] - 1] = 0;
		}
	}

	std::cout << count << "\n";

}

void getInput() {

	std::ifstream file;
	file.open("s2.5.in");

	file >> jerseyCount;
	file >> athleteCount;

	sizeArr = new int[jerseyCount];
	prefArr = new int*[athleteCount];

	for(int i = 0; i < athleteCount; i++) {
		prefArr[i] = new int[2];
	}

	for(int i = 0; i < jerseyCount; i++) {

		char temp;
		file >> temp;

		if(temp == 'L') {
			sizeArr[i] = 3;
		}
		else if(temp == 'M') {
			sizeArr[i] = 2;
		}
		else if(temp == 'S') {
			sizeArr[i] = 1;
		}

	}

	for(int i = 0; i < athleteCount; i++) {

		char temp;
		file >> temp;

		if(temp == 'L') {
			prefArr[i][0] = 3;
		}
		else if(temp == 'M') {
			prefArr[i][0] = 2;
		}
		else if(temp == 'S') {
			prefArr[i][0] = 1;
		}

		file >> prefArr[i][1];

	}

}