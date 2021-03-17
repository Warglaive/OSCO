#include<stdio.h>
#define F 3
int frames[F];
int lastFIFOindex = 0;

void toPrint(int page_in) {
	printf("|P: %d | %d | %d | %d |", page_in, frames[0], frames[1], frames[2]);
}
int getAddr(int page_in) {
	for (int i = 0; i < F; i++) {
		if (frames[i] == page_in) {
			return 1;
		}
	}
	return 0;
}
void handlePfault(int page_in) {
	if (lastFIFOindex == 3) {
		lastFIFOindex = 0;
	}
	frames[lastFIFOindex] = page_in;
	lastFIFOindex++;

}
int FIFO(int page_in) {
	if (getAddr(page_in) == 0) {
		handlePfault(page_in);
		toPrint(page_in);
		printf(" F \n");
	}
	else {
		toPrint(page_in);
		printf("\n");
	}
	return 0;
}
int main() {
	printf("FIFO memory management\n");
	printf("Frame:| 0 | 1 | 2 | PF?\n");
	FIFO(2);
	FIFO(3);
	FIFO(2);
	FIFO(1);
	FIFO(5);
	FIFO(2);
	FIFO(4);
	FIFO(5);
	FIFO(3);
	FIFO(2);
	FIFO(5);
	FIFO(2);
}