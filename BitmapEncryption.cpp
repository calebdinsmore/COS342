#include <bitset>
#include <iostream>
#pragma pack(1)

#include <fstream>
#include <vector>
#include <stdlib.h>
#include "BitmapEncryption.h"

using namespace std;

vector<char> buffer;
PBITMAPFILEHEADER file_header;
PBITMAPINFOHEADER info_header;

int main(int argc, char* argv[]) {
	
	ifstream file("sheldon.bmp");
	
	file.seekg(0,ios::end);
    streampos length = file.tellg();
    file.seekg(0,ios::beg);
	
	
	buffer.resize(length);
    file.read(&buffer[0],length);
	
	file_header = (PBITMAPFILEHEADER)(&buffer[0]);
    info_header = (PBITMAPINFOHEADER)(&buffer[0] + sizeof(BITMAPFILEHEADER));
	
	cout << info_header->biWidth << endl;
	
	// unsigned char BMPheader[54]; //Header size is 54
	// int width = *(int*)&BMPheader[18];
	// int height = *(int*)&BMPheader[22];
	// int row_padded = (width*3 + 3) & (~3);
	
	// unsigned char* data = new unsigned char[row_padded];
	
	// for ( int i = 0; i < height; i++ ) {
	// 	for ( int j = 0; j < width * 3; j += 3 ) {
	// 		cout << "B: " << data[j] << endl;
	// 	}
	// }
	// fclose(bmp);
}