#include<stdio.h>
#define F 3
int frames[F];
int ages[F]; //age of frames
int lastFIFOindex = 0;

int getAddr(int page_in) {
	for (int i = 0; i < F; i++) {
		if (frames[i] == page_in) {
			return 1;
		}
	}
}

void updateAges(int page_in) { //the LEAST recent used - smaller age
								//MOSTrecent used - bigger age
	int n;
	for (int i = 0; i < F; i++) {
		if (frames[i] == page_in) {
			n = i;
		}
		ages[i]++;
	}
	ages[n] = 0;
}

void handlePfault(int page_in) {
	frames[lastFIFOindex] = page_in;
	printf("|P: %d | %d | %d | %d | F \n", page_in, frames[0], frames[1], frames[2]);

	if (lastFIFOindex == 2) { lastFIFOindex = 0; }
	else { lastFIFOindex++; }
}

int LRU(page_in) {
	if (getAddr(page_in) == 1) {
		printf("|P: %d | %d | %d | %d | \n", page_in, frames[0], frames[1], frames[2]);
		updateAges(page_in);
	}
	else {
		int oi, o = -1;
		for (int i = 0; i < F; i++) {
			if (ages[i] > o) {
				o = ages[i];
				oi = i;
			}
		}
		frames[oi] = page_in;
		printf("|P: %d | %d | %d | %d | F \n", page_in, frames[0], frames[1], frames[2]);
		updateAges(page_in);
	}
}

int main(int argc, char** argv) {
	printf("LRU memory management\n");
	printf(" Frame:| 0 | 1 | 2 | PF? \n\n");
	LRU(2);
	LRU(3);
	LRU(2);
	LRU(1);
	LRU(5);
	LRU(2);
	LRU(4);
	LRU(5);
	LRU(3);
	LRU(2);
	LRU(5);
	LRU(2);
	return 0;
}