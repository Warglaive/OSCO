/*
  FCFS Disk Scheduling Implementation

*/

#include <stdio.h>
#include <stdlib.h>
#include "fcfc.h"

#define LOW 0
#define HIGH 199

int main() {
	FcFs();
	SSTF();
	SE();
	CS();
	return 0;
}


/// <summary>
///	FirstComeFirstServed
/// </summary>
/// <returns></returns>

int FcFs()
{
	int queue[100], q_size, head, seek = 0, diff;
	float avg;

	printf("%s\n", "***FCFS Disk Scheduling Algorithm***");

	printf("%s\n", "Enter the size of the queue");
	scanf("%d", &q_size);

	printf("%s\n", "Enter queue elements");
	for (int i = 1; i <= q_size; i++) {
		scanf("%d", &queue[i]);
	}

	printf("%s\n", "Enter initial head position");
	scanf("%d", &head);

	queue[0] = head;

	for (int j = 0; j <= q_size - 1; j++) {
		diff = abs(queue[j] - queue[j + 1]);
		seek += diff;
		printf("Move from %d to %d with Seek %d\n", queue[j], queue[j + 1], diff);
	}

	printf("\nTotal seek time is %d\t", seek);
	avg = seek / (float)q_size;
	printf("\nAverage seek time is %f\t", avg);

	return 0;
}
/// <summary>
///	CircularScan
/// </summary>
/// <returns></returns>
/// 

int CS() {
	int queue[20];
	int head, max, q_size, temp, sum;
	int discLocation; //location of disk (head) arr


	printf("%s\t", "Input no of disk locations");
	scanf("%d", &q_size);

	printf("%s\t", "Enter head position");
	scanf("%d", &head);

	printf("%s\n", "Input elements into disk queue");
	for (int i = 0; i < q_size; i++) {
		scanf("%d", &queue[i]);
	}

	queue[q_size] = head; //add RW head into queue
	q_size++;

	//sort the array
	for (int i = 0; i < q_size; i++) {
		for (int j = i; j < q_size; j++) {
			if (queue[i] > queue[j]) {
				temp = queue[i];
				queue[i] = queue[j];
				queue[j] = temp;
			}
		}
	}

	max = queue[q_size - 1];

	//locate head in the queue
	for (int i = 0; i < q_size; i++) {
		if (head == queue[i]) {
			discLocation = i;
			break;
		}
	}

	if (abs(head - LOW) <= abs(head - HIGH)) {

		for (int j = discLocation; j >= 0; j--) {
			printf("%d --> ", queue[j]);
		}
		for (int j = discLocation + 1; j < q_size; j++) {
			printf("%d --> ", queue[j]);
		}

	}
	else {

		for (int j = discLocation + 1; j < q_size; j++) {
			printf("%d --> ", queue[j]);
		}
		for (int j = discLocation; j >= 0; j--) {
			printf("%d --> ", queue[j]);
		}

	}

	sum = head + max;
	printf("\nmovement of total cylinders %d", sum);

	return 0;
}
/// <summary>
///	ScanElevator
/// </summary>
/// <returns></returns>
int SE() {
	int queue[20];
	int head, max, q_size, temp, sum;
	int diskLocation; //location of disk (head) arr


	printf("%s\t", "Input no of disk locations");
	scanf("%d", &q_size);

	printf("%s\t", "Enter head position");
	scanf("%d", &head);

	printf("%s\n", "Input elements into disk queue");
	for (int i = 0; i < q_size; i++) {
		scanf("%d", &queue[i]);
	}

	queue[q_size] = head; //add RW head into queue
	q_size++;

	//sort the array
	for (int i = 0; i < q_size; i++) {
		for (int j = i; j < q_size; j++) {
			if (queue[i] > queue[j]) {
				temp = queue[i];
				queue[i] = queue[j];
				queue[j] = temp;
			}
		}
	}

	max = queue[q_size - 1];

	//locate head in the queue
	for (int i = 0; i < q_size; i++) {
		if (head == queue[i]) {
			diskLocation = i;
			break;
		}
	}

	if (abs(head - LOW) <= abs(head - HIGH)) {

		for (int j = diskLocation; j >= 0; j--) {
			printf("%d --> ", queue[j]);
		}
		for (int j = diskLocation + 1; j < q_size; j++) {
			printf("%d --> ", queue[j]);
		}

	}
	else {

		for (int j = diskLocation + 1; j < q_size; j++) {
			printf("%d --> ", queue[j]);
		}
		for (int j = diskLocation; j >= 0; j--) {
			printf("%d --> ", queue[j]);
		}

	}
	sum = head + max;
	printf("\nmovement of total cylinders %d", sum);

	return 0;

}
/// <summary>
/// ShortestServiceTimeFirst
/// </summary>
/// <returns></returns>
int SSTF()
{
	int queue[100], queue2[100], q_size, head, seek = 0, temp;
	float avg;

	printf("%s\n", "-----SSTF Disk Scheduling Algorithm-----");

	printf("%s\n", "Enter the size of the queue");
	scanf("%d", &q_size);

	printf("%s\n", "Enter queue elements");
	for (int i = 0; i < q_size; i++) {
		scanf("%d", &queue[i]);
	}

	printf("%s\n", "Enter initial head position");
	scanf("%d", &head);

	//get distance from head of elems in queue
	for (int i = 0; i < q_size; i++) {
		queue2[i] = abs(head - queue[i]);
	}

	//swap elems based on their distance from each other
	for (int i = 0; i < q_size; i++) {
		for (int j = i + 1; j < q_size; j++) {

			if (queue2[i] > queue2[j]) {
				temp = queue2[i];
				queue2[i] = queue[j];
				queue2[j] = temp;

				temp = queue[i];
				queue[i] = queue[j];
				queue[j] = temp;
			}
		}

	}

	for (int i = 1; i < q_size; i++) {
		seek = seek + abs(head - queue[i]);
		head = queue[i];
	}

	printf("\nTotal seek time is %d\t", seek);
	avg = seek / (float)q_size;
	printf("\nAverage seek time is %f\t", avg);

	return 0;
}
