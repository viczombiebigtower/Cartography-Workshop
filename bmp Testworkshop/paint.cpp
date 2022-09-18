#include <math.h>

#define width 1920
#define height 1080
#define unit 120

double f[100];

//automatically corresponds to pixels and paints black
void black(char* cache, double y, int i)
{
	int j = y * unit;  //default type conversion
	int pos = j * width + i;
	//cache[pos * 3] = 0;
	//cache[pos * 3 + 1] = 0;
	//cache[pos * 3 + 2] = 0;

	//bold the target pixels...
	for (int k = -3; k <= 5; k++)
	{
		cache[pos * 3 + k] = 0;
		cache[(pos + width) * 3 + k] = 0;
		cache[(pos - width) * 3 + k] = 0;
	}

}

//automatically corresponds to pixels but paints without bolding
void orange(char* cache, int pos)
{
	cache[pos * 3] = 0;
	cache[pos * 3 + 1] = 128;
	cache[pos * 3 + 2] = 255;
}

void pink(char* cache, int pos)
{
	cache[pos * 3] = 203;
	cache[pos * 3 + 1] = 192;
	cache[pos * 3 + 2] = 255;
}
void purple(char* cache, int pos)
{
	cache[pos * 3] = 128;
	cache[pos * 3 + 1] = 0;
	cache[pos * 3 + 2] = 128;
}
void cyan(char* cache, int pos)
{
	cache[pos * 3] = 255;
	cache[pos * 3 + 1] = 255;
	cache[pos * 3 + 2] = 0;
}
void blue(char* cache, int pos)
{
	cache[pos * 3] = 255;
	cache[pos * 3 + 1] = 0;
	cache[pos * 3 + 2] = 0;
}
void midnightblue(char* cache, int pos)
{
	cache[pos * 3] = 112;
	cache[pos * 3 + 1] = 25;
	cache[pos * 3 + 2] = 25;
}
void crimson(char* cache, int pos)
{
	cache[pos * 3] = 60;
	cache[pos * 3 + 1] = 20;
	cache[pos * 3 + 2] = 220;
}
void darkred(char* cache, int pos)
{
	cache[pos * 3] = 0;
	cache[pos * 3 + 1] = 0;
	cache[pos * 3 + 2] = 139;
}
//Guess why I define this function. [doge]
bool isblack(char* cache, int pos)
{
	if (cache[pos * 3] == 0 && cache[pos * 3 + 1] == 0 && cache[pos * 3 + 2] == 0)
		return true;
	else
		return false;
}

void paint(char* cache)
{
	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
		{
			int xe = i % unit;
			int ye = j % unit;
			int pos = j * width + i;

			//coordinate system

			if (xe >= 118 || xe <= 2 || ye >= 118 || ye <= 2)
			{
				cache[pos * 3] = 216;
				cache[pos * 3 + 1] = 216;
				cache[pos * 3 + 2] = 216;
			}
			else
			{
				cache[pos * 3] = 200;
				cache[pos * 3 + 1] = 255;
				cache[pos * 3 + 2] = 200;
			}

		}

	for (int i = 0; i < width; i++)
	{
		double x = 1.0 * i / unit;

		f[0] = 2 * x - 2.0;
		f[1] = -2 * x + 6.8;
		f[2] = 2 * x - 2.8;
		f[3] = -2 * x + 18.0;
		f[4] = 2 * x - 4.0;
		f[5] = -2 * x + 19.2;
		f[6] = 2.0;
		f[7] = 8.0;
		f[8] = 5.0;
		f[9] = 5.4;
		f[10] = -2 * x + 14.4;
		f[11] = 4.4;
		f[12] = 2 * x - 7.6;
		f[13] = -2 * x + 14.0;
		f[14] = 2 * x - 8.0;
		f[15] = -2 * x + 12.8;
		f[16] = 2 * x - 9.2;
		f[17] = 8.4;
		f[18] = 2 * x - 3.2;
		f[19] = 2 * x - 8.8;
		f[20] = -2 * x + 23.6;
		f[21] = -2 * x + 24.8;
		f[22] = -2 * x + 25.6;
		f[23] = 2 * x - 20.8;
		f[24] = -2 * x + 20.0;
		f[25] = 2 * x - 14.4;
		f[26] = 2 * x - 15.6;
		f[27] = 2 * x - 15.2;
		f[28] = 2 * x - 13.6;
		f[29] = 2 * x - 13.2;
		f[30] = 2 * x - 16.0;
		f[31] = 2 * x - 16.8;
		f[32] = 1.8;
		f[33] = -2 * x + 17.2;
		f[34] = -2 * x + 19.6;

		for (int j = 0; j < height; j++)
		{
			double y = 1.0 * j / unit;
			int pos = j * width + i;
			//color inside (to be continued)
			if (y < f[0] && y < f[3] && y > f[1] && y > f[2]  && !isblack(cache, pos))
			{
				purple(cache, pos);
			}
			if ((y < f[18] && y < f[24] && y > f[5] && y > f[27]
				|| y < f[19] && y < f[22] && y > f[21] && y > f[23])
				&& !isblack(cache, pos))
			{
				midnightblue(cache, pos);
			}
			if ((y < f[2] && y < f[3] && y > f[4] && y > f[6]
				|| y < f[14] && y < f[20] && y > f[15] && y > f[16]
				|| y < f[11] && y < f[28] && y > f[25] && y > f[32]
				|| y < f[20] && y < f[30] && y > f[31] && y > f[32])
				&& !isblack(cache, pos))
			{
				pink(cache, pos);
			}
			if ((y < f[5] && y < f[7] && y > f[3] && y > f[6]
				|| y < f[7] && y < f[21] && y > f[6] && y > f[20])
				&& !isblack(cache, pos))
			{
				cyan(cache, pos);
			}
			if ((y < f[13] && y < f[4] && y > f[15] && y > f[12]
				|| y < f[12] && y < f[11] && y > f[15] && y > f[14])
				&& !isblack(cache, pos))
			{
				crimson(cache, pos);
			}
			//if ((y < ))
			//{
			//	darkred(cache, pos);
			//}
		}

		//outline

		if (x >= 2.2 && x <= 5.2)
		{
			black(cache, f[0], i);
		}
		if (x >= 2.2 && x <= 2.4)
		{

			black(cache, f[1], i);
		}

		if (x >= 2.4 && x <= 5.2)
		{
			black(cache, f[2], i);
		}
		if (x >= 5.0 && x <= 8.0)
		{
			black(cache, f[3], i);
		}
		if (x >= 3.0 && x <= 5.5)
		{
			black(cache, f[4], i);
		}
		if (x >= 5.6 && x <= 8.6)
		{
			black(cache, f[5], i);
		}
		if (x >= 2.4 && x <= 3.0 || x >= 8.0 && x <= 8.6 || x >= 10.8 && x <= 11.4)
		{
			black(cache, f[6], i);
		}
		if (x >= 5.0 && x <= 5.6 || x >= 7.8 && x <= 8.4)
		{
			black(cache, f[7], i);
		}
		if (x >= 4.7 && x <= 6.5 || x >= 7.1 && x <= 9.3)
		{
			black(cache, f[8], i);
		}
		if (x >= 4.7 && x <= 6.3 || x >= 7.3 && x <= 9.1)
		{
			black(cache, f[9], i);
		}
		if (x >= 4.7 && x <= 5.5)
		{
			black(cache, f[10], i);
		}
		if (x >= 5.0 && x <= 6.2 || x >= 7.4 && x <= 9.4)
		{
			black(cache, f[11], i);
		}
		if (x >= 5.4 && x <= 6.0 || x >= 6.7 && x <= 8.0)
		{
			black(cache, f[12], i);
		}
		if (x >= 4.5 && x <= 5.4)
		{
			black(cache, f[13], i);
		}
		if (x >= 5.2 && x <= 6.2 || x >= 6.8 && x <= 7.9)
		{
			black(cache, f[14], i);
		}
		if (x >= 4.2 && x <= 5.5)
		{
			black(cache, f[15], i);
		}
		if (x >= 5.5 && x <= 6.8 || x >= 7.1 && x <= 8.2)
		{
			black(cache, f[16], i);
		}
		if (x >= 5.2 && x <= 5.8 || x >= 8.0 && x <= 8.6)
		{
			black(cache, f[17], i);
		}
		if (x >= 5.6 && x <= 5.8)
		{
			black(cache, f[18], i);
		}
		if (x >= 8.4 && x <= 8.6)
		{
			black(cache, f[19], i);
		}
		if (x >= 7.8 && x <= 10.8)
		{
			black(cache, f[20], i);
		}
		if (x >= 8.4 && x <= 11.4)
		{
			black(cache, f[21], i);
		}
		if (x >= 8.6 && x <= 11.6)
		{
			black(cache, f[22], i);
		}
		if (x >= 11.4 && x <= 11.6)
		{
			black(cache, f[23], i);
		}
		if (x >= 5.8 && x <= 6.9 || x >= 7.8 && x <= 8.3 || x >= 8.6 && x <= 8.8)
		{
			black(cache, f[24], i);
		}
		if (x >= 8.1 && x <= 8.2 || x >= 8.4 && x <= 9.4)
		{
			black(cache, f[25], i);
		}
		if (x >= 8.8 && x <= 9.8)
		{
			black(cache, f[26], i);
		}
		if (x >= 8.6 && x <= 8.8)
		{
			black(cache, f[27], i);
		}
		if (x >= 7.7 && x <= 7.9 || x >= 8.2 && x <= 9.0)
		{
			black(cache, f[28], i);
		}
		if (x >= 7.6 && x <= 7.8 || x >= 8.1 && x <= 8.8)
		{
			black(cache, f[29], i);
		}
		if (x >= 8.9 && x <= 9.9)
		{
			black(cache, f[30], i);
		}
		if (x >= 9.3 && x <= 10.1)
		{
			black(cache, f[31], i);
		}
		if (x >= 7.7 && x <= 8.1 || x >= 8.9 && x <= 9.3)
		{
			black(cache, f[32], i);
		}
		if (x >= 7.6 && x <= 7.7)
		{
			black(cache, f[33], i);
		}
		if (x >= 8.8 && x <= 8.9)
		{
			black(cache, f[34], i);
		}
	}

}

