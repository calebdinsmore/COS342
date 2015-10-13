#pragma pack(1)
#pragma once

typedef struct tagBITMAPFILEHEADER {
  unsigned short  bfType;
  unsigned int bfSize;
  unsigned short  bfReserved1;
  unsigned short  bfReserved2;
  unsigned int bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
  unsigned int biSize;
  int  biWidth;
  int  biHeight;
  unsigned short  biPlanes;
  unsigned short  biBitCount;
  unsigned int biCompression;
  unsigned int biSizeImage;
  int  biXPelsPerMeter;
  int  biYPelsPerMeter;
  unsigned int biClrUsed;
  unsigned int biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;