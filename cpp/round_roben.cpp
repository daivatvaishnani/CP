#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

typedef struct {
	int no, arr, bur;
} data;

queue<data> q1, q2;
int time_quantum;
int bur_time[100];
int wa_time[100];
int ta_time[100];
int comp_time[100];

void *create_processes(void *args) {
	int clk1 = 0, clk2 = 0, arr, bur;
	for(int i=0; i<5; ++i) {
		if(i & 1) {
			arr = clk1 + rand() % 10;
			bur = 1 + rand() % 10;
			clk1 = arr;
			data node;
			node.no = i+1;
			node.arr = arr;
			node.bur = bur;
			q2.push(node);
			bur_time[i+1] = bur;
			printf("Process %d(even) assigned to Queue 2\t%d\t\t%d\n", i + 1, arr, bur);
		}
		else {
			arr = clk2 + rand() % 10;
			bur = 1 + rand() % 10;
			clk2 = arr;
			data node;
			node.no = i+1;
			node.arr = arr;
			node.bur = bur;
			q1.push(node);
			bur_time[i+1] = bur;
			printf("Process %d(odd) assigned to Queue 1\t%d\t\t%d\n", i + 1, arr, bur);
		}
	}
	printf("\n");
	pthread_exit(0);
}

void *Scheduler1 (void *args) {
	int time = 0, wait = 0; 
	do {
		if(q1.empty()) {
			++wait;
			if(wait >= 200000000)
				pthread_exit(0); // process creation has stopped. 
		}
		else {
			wait = 0;
			if(q1.front().arr > time) {
				time += q1.front().arr;
			}
			if(q1.front().bur > time_quantum) {
				printf("Process %d is executing from Queue 1...\n", q1.front().no);
				time += time_quantum;
				data node;
				node.no = q1.front().no;
				node.arr = q1.front().arr;
				node.bur = q1.front().bur - time_quantum;
				q1.pop();
				q1.push(node);
			}
			else {
				time += q1.front().bur;
				printf("Process %d finished executing and got dequeued from Queue 1...\n", q1.front().no);
				comp_time[q1.front().no] = time;
				ta_time[q1.front().no] = comp_time[q1.front().no] - q1.front().arr;
				wa_time[q1.front().no] = ta_time[q1.front().no] - bur_time[q1.front().no];
				q1.pop();
			}
		}
	}
	while(true);
}

void *Scheduler2 (void *args) {
	int time = 0, wait = 0; 
	do {
		if(q2.empty()) {
			++wait;
			if(wait >= 200000000)
				pthread_exit(0); // process creation has stopped. 
		}
		else {
			wait = 0;
			if(q2.front().arr > time) {
				time += q2.front().arr;
			}
			if(q2.front().bur > time_quantum) {
				printf("Process %d is executing from Queue 2...\n", q2.front().no);
				time += time_quantum;
				data node;
				node.no = q2.front().no;
				node.arr = q2.front().arr;
				node.bur = q2.front().bur - time_quantum;
				q2.pop();
				q2.push(node);
			}
			else {
				time += q2.front().bur;
				printf("Process %d finished executing and got dequeued from Queue 2...\n", q2.front().no);
				comp_time[q2.front().no] = time;
				ta_time[q2.front().no] = comp_time[q2.front().no] - q2.front().arr;
				wa_time[q2.front().no] = ta_time[q2.front().no] - bur_time[q2.front().no];
				q2.pop();
			}
		}
	}
	while(true);
}

int main() {

	pthread_t tid[3];

	printf("\nDefine Time time_quantum : ");
	scanf("%d", &time_quantum);

	printf("\t\t\t\t\tArrival Time\tBurst Time\n");

	pthread_create(&tid[0], NULL, create_processes, NULL);
	pthread_create(&tid[1], NULL, Scheduler1, NULL);
	pthread_create(&tid[2], NULL, Scheduler2, NULL);

	for(int i=0; i<3; ++i) {
		pthread_join(tid[i], NULL);
	}

	printf("\n");

	printf("\nP no\tC time\tW time\tTA time\n");

	for(int i=1; i<=5; i++){
		printf("%d\t%d\t%d\t%d\n", i , comp_time[i], wa_time[i], ta_time[i]);
	}

	printf("\n");

	return 0;
}