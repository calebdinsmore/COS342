/*
	========================================================================================
	* To run this program, compile it and type the following onto the command line:
	* ./[program name] [input BMP name] [output BMP name] ["secret message"]
	* Just like your example outlined in the problem description.
	========================================================================================
*/

#include <bitset>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>

using namespace std;

void encodeCharIntoPixels(char letter, ifstream& bmp, ofstream& out, int& byteIndex) {
	bitset<8> letterByte = letter;
	
	for ( int i = 0; i < 8; i++ ) {
		byteIndex++;
		unsigned char byte = bmp.get();
		bitset<8> tmp = byte;
		if ( byteIndex % 4 != 0 ) { //checks to see if we are on the alpha byte
			if ( letterByte[i] == 0 ) {
				if ( tmp[0] == 0 ) {
					out.put(byte);
				}
				else {
					out.put(byte & 0xFE);
				}
			}
			else {
				if ( tmp[0] == 0 ) {
					out.put(byte ^ letterByte[i]);
				}
				else {
					out.put(byte);
				}
			}
		}
		else {
			out.put(byte); //put alpha byte into outfile
			byteIndex++;
			byte = bmp.get(); //get next byte
			tmp = byte;
			if ( letterByte[i] == 0 ) {
				if ( tmp[0] == 0 ) {
					out.put(byte);
				}
				else {
					out.put(byte & 0xFE);
				}
			}
			else {
				if ( tmp[0] == 0 ) {
					out.put(byte ^ letterByte[i]);
				}
				else {
					out.put(byte);
				}
			}
		}
	}
}

string getMessageFromArgs(char* argv[]) {
	argv += 3; //increment pointer to point to first word of message
	return string(*argv) + '\n';
}

int main(int argc, char* argv[]) {
	int headerSize = 54;
	unsigned char* data = new unsigned char[headerSize];
	
	ifstream bmp(argv[1], ios::binary);
	ofstream out(argv[2], ios::binary);
	
	string strMessage = getMessageFromArgs(argv);
	
	if (!bmp.is_open()){
		cout << "File not found." << endl;
		return -1;
	}
	
	for ( int i = 0; i < headerSize; i++ ) {
		data[i] = bmp.get();
		out.put(data[i]);
	}
	
	int width = *(int*)&data[18];
	int height = *(int*)&data[22];
	int byteIndex = 0; //used to determine whether we are messing with the alpha byte
	
	for ( int i = 0; i < strlen(strMessage.c_str()); i++ ) {
		encodeCharIntoPixels(strMessage.c_str()[i], bmp, out, byteIndex);
	}
	
	while (!bmp.eof()) {
		out.put(bmp.get());
	}
	
	cout << "Pixels start at: " << headerSize << endl;
	cout << "Width of image: " << width << endl;
	cout << "Height of image: " << height << endl;
	
	bmp.close();
	out.close();
	return 0;
}