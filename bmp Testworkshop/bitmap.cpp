//msvc is a little trouble
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#pragma pack(1)

#include <iostream>
#include <fstream>

#define width 1920
#define height 1080

//In vs, if I include paint.cpp here and do not declare the functions, 
//it will report an error, but in linux (to be exact, g++) things will be different.
//~~QAQ~~
//Maybe because the function name is the same as the source file?
//That's not important.

void paint(char* cache);


typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int LONG;

typedef struct tagBITMAPFILEHEADER
{
	WORD  bfType;
	DWORD bfSize;
	WORD  bfReserved1;
	WORD  bfReserved2;
	DWORD bfOffBits;
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
	DWORD        biSize;
	LONG         biWidth;
	LONG         biHeight;
	WORD         biPlanes;
	WORD         biBitCount;
	DWORD        biCompression;
	DWORD        biSizeImage;
	LONG         biXPelsPerMeter;
	LONG         biYPelsPerMeter;
	DWORD        biClrUsed;
	DWORD        biClrImportant;
} BITMAPINFOHEADER;

int main(int argc, char* argv[])
{
	std::ofstream outFile("test.bmp", std::ios::binary);
	BITMAPFILEHEADER bmpFileHeader;
	BITMAPINFOHEADER bmpInfoHeader;
	bmpInfoHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmpInfoHeader.biWidth = width;
	bmpInfoHeader.biHeight = height;
	bmpInfoHeader.biPlanes = 1;
	bmpInfoHeader.biBitCount = 24;
	bmpInfoHeader.biCompression = 0;
	bmpInfoHeader.biSizeImage = width * height * 3;
	bmpInfoHeader.biXPelsPerMeter = 2834;
	bmpInfoHeader.biYPelsPerMeter = 2834;
	bmpInfoHeader.biClrUsed = 0;
	bmpInfoHeader.biClrImportant = 0;

	((char*)(&bmpFileHeader.bfType))[0] = 'B';
	((char*)(&bmpFileHeader.bfType))[1] = 'M';
	bmpFileHeader.bfReserved1 = 0;
	bmpFileHeader.bfReserved2 = 0;
	bmpFileHeader.bfOffBits = bmpInfoHeader.biSize + sizeof(BITMAPFILEHEADER);
	bmpFileHeader.bfSize = bmpFileHeader.bfOffBits + bmpInfoHeader.biSizeImage;

	outFile.write(reinterpret_cast<char*>(&bmpFileHeader), sizeof(BITMAPFILEHEADER));
	outFile.write(reinterpret_cast<char*>(&bmpInfoHeader), sizeof(BITMAPINFOHEADER));

	char* cache = new char[bmpInfoHeader.biSizeImage];

	//for (int j = 0; j < height; j++)
	//	for (int i = 0; i < width; i++)
	//	{
	//		int pos = j * width + i;
	//		cache[pos * 3] = 50;
	//		cache[pos * 3 + 1] = 255;
	//		cache[pos * 3 + 2] = 122;
	//	}

	paint(cache);

	outFile.write(cache, bmpInfoHeader.biSizeImage);
	delete[] cache;
	outFile.close();
};

