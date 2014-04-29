#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>

using namespace std;

	class RandomBitmapGenerator
	{
		public :
			RandomBitmapGenerator() {
				// Srand is suppose to be callled once.
				if(!initFlag) {
					srand(time(NULL));
					initFlag = true;
				}
				isRandomGenerated = false;
				memset(randomBitmap, 0, sizeof(randomBitmap));
				memset(randomBitShift, 0, sizeof(randomBitShift));
			}

			RandomBitmapGenerator(short percentage) {
				// Srand is suppose to be callled once.
				if(!initFlag) {
					srand(time(NULL));
					initFlag = true;
				}
				generateBitmap(percentage);
			}

			bool IsInitialized() {
					return isRandomGenerated;
			}

			bool IsIndexSet(unsigned char index) {
				//re fitting the ueIndex range from 0 to ueCount to 0-99 for randomi bit map
				index = index % 100;
				int bitmapIndex, bitNum;
				bitmapIndex = index >> 5;
				bitNum = index & 0x1F;
				return (randomBitmap[bitmapIndex] & (1 << bitNum));
			}

			void GenerateRandomBitmap(short percentage){
				generateBitmap(percentage);
			}

			void RegenerateBitMap() {
				if(isRandomGenerated) {
			/* To regenerate bitmap do cyclic shift of each bitmap with respective random shift.*/
					randomBitmap[0] = (randomBitmap[0] >> randomBitShift[0]) | (randomBitmap[0] << (32 - randomBitShift[0]));
					randomBitmap[1] = (randomBitmap[1] >> randomBitShift[1]) | (randomBitmap[1] << (32 - randomBitShift[1]));
					randomBitmap[2] = (randomBitmap[2] >> randomBitShift[2]) | (randomBitmap[2] << (32 - randomBitShift[2]));
					/*bitmap 3 is of 4 bits */
					randomBitmap[3] = ((randomBitmap[3] >> randomBitShift[3]) | (randomBitmap[3] << (4 - randomBitShift[3])) & 0xF);
				}
			}

			void print(){
				printf("Random 0x%x 0x%x 0x%x 0x%x  \n ", randomBitmap[0], randomBitmap[1], randomBitmap[2], randomBitmap[3]);
			}

		private :

			static bool initFlag;
			bool isRandomGenerated;
			/*Bit Map of 100 is distributed across 3 32bit Bitmaps and 1 4 bit bitmap. To give more randomness
			 * 4 random bit shifts are used, one per bitmap*/
			int randomBitmap[4];
			short randomBitShift[4];

			void generateBitmap(short percentage) {
				int random, bitmapIndex, bitNum, randomCount;
				isRandomGenerated = true;
				memset(randomBitmap, 0, sizeof(randomBitmap));
				if(percentage > 100 ){
					return;
				}
				/*  select random shift 0 -31 in range of 0-31 and  random Shift 1 in range of 0-3*/
				randomBitShift[0] = rand() & 0x1f;
				randomBitShift[1] = rand() & 0x1f;
				randomBitShift[2] = rand() & 0x1f;
				randomBitShift[3] = rand() & 0x3;

				/* To avoid more rand call if percentage is more than 50% then call rand 100 - percent times and
				 * do 1's complement of bitmap*/
				if(percentage > 50) {
					randomCount = 100 - percentage;
				}
				else {
					randomCount = percentage;
				}
				for(int i = 0; i< randomCount; i++) {
					do {
						random = rand() % 100;
						bitmapIndex = random >> 5;
						bitNum = random & 0x1F;
						if(!(randomBitmap[bitmapIndex] & (1 << bitNum))) {
							randomBitmap[bitmapIndex] = randomBitmap[bitmapIndex] | (1 << bitNum) ;

							break;
						}
					}while(1);
				}

				if(percentage > 50) {
					randomBitmap[0] = ~randomBitmap[0];
					randomBitmap[1] = ~randomBitmap[1];
					randomBitmap[2] = ~randomBitmap[2];
					randomBitmap[3] = (~randomBitmap[3] & 0xf);
				}
			}
	};

bool RandomBitmapGenerator::initFlag = false;

int main()
{
	RandomBitmapGenerator bitmap;
	bitmap.GenerateRandomBitmap(10);
 	return 0;
}
