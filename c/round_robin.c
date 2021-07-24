#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

struct node {
	int no, arr, bur;
	struct node *next, *prev;
};

typedef struct {
	struct node *front, *rear;
	bool empty;
} queue;

void new_queue(queue *q) {
	q->front = NULL;
	q->rear = NULL;
	q->empty = true;
	// if(q->front == NULL) printf("Init as Null\n");
}

queue q1,q2;
int quantum;
int comp_time[100], ta_time[100], wa_time[100], bur_time[100];

struct node* new_node(int no, int arr, int bur) {
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->no = no;
	temp->arr = arr;
	temp->bur = bur;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void push(queue *q, int no, int arr, int bur) {
	struct node *temp = new_node(no, arr, bur);

	if(q->front == NULL) {
		// printf("Null\n");
		q->front = temp;
		q->rear = temp;
	}
	else {
		// printf("Not null\n");
		temp->next = q->rear->next;
		temp->prev = q->rear;
		q->rear->next = temp;
		q->rear = temp;
	}

	q->empty = false;
}

void pop(queue *q) {
	if(q->front != NULL && q->front != q->rear) {
		struct node *temp = q->front;
		q->front = q->front->next;
		q->front->prev = NULL;
		free(temp);
	}
	else if(q->front == q->rear) {
		struct node *temp = q->front;
		q->front = NULL;
		q->rear = NULL;
		q->empty = true;
		free(temp);
	}
	else {
		// printf("Queue Empty pop!\n");
	}
	return ;
}

struct node* top(queue *q) {
	if(q->front != NULL && q->empty != true) {
		return q->front;
	}
	else {
		// printf("Queue Empty top!\n");
		return NULL;
	}
}

struct node* back(queue *q) {
	if(q->empty != true && q->rear != NULL) {
		return q->rear;
	}
	else {
		// printf("Queue Empty top!\n");
		return NULL;	
	}
}

int size(queue *q) {
	int ans = 0;
	if(q->front != NULL) {
		struct node *temp = q->front;
		while(temp != q->rear && temp->next != NULL) {
			++ans;
			temp = temp->next;
		}
		return ans+1;
	}
	return ans;
}

void *create_processes(void *args) {
	int clk1 = 0, clk2 = 0, arr, bur;
	for(int i=0; i<5; ++i) {
		if(i & 1) {
			arr = clk1 + rand() % 10;
			bur = 1 + rand() % 10;
			clk1 = arr;
			push(&q2, i+1, arr, bur);
			bur_time[back(&q2)->no] = bur;
			printf("Process %d(even) assigned to Queue 2\t%d\t\t%d\n", i + 1, arr, bur);
		}
		else {
			arr = clk2 + rand() % 10;
			bur = 1 + rand() % 10;
			clk2 = arr;
			push(&q1, i+1, arr, bur);
			bur_time[back(&q1)->no] = bur;
			printf("Process %d(odd) assigned to Queue 1\t%d\t\t%d\n", i + 1, arr, bur);
		}
	}
	pthread_exit(0);
}

void *Scheduler1(void *args) {
	int time = 0, wait = 0; 
	do {
		if(q1.empty == true) {
			++wait;
			if(wait >= 100000000)
				pthread_exit(0); // process creation has stopped. 
		}
		else {
			if(top(&q1)->arr > time) {
				time += top(&q1)->arr;
			}
			if(top(&q1)->bur > quantum) {
				printf("Process %d is executing from Queue 1...\n", top(&q1)->no);
				time += quantum;
				push(&q1, top(&q1)->no, top(&q1)->arr, top(&q1)->bur-quantum);
				pop(&q1);
			}
			else {
				time += top(&q1)->bur;
				printf("Process %d finished executing and got dequeued from Queue 1...\n", top(&q1)->no);
				comp_time[top(&q1)->no] = time;
				ta_time[top(&q1)->no] = comp_time[top(&q1)->no] - top(&q1)->arr;
				wa_time[top(&q1)->no] = ta_time[top(&q1)->no] - bur_time[top(&q1)->no];
				pop(&q1);
			}
		}
	}
	while(true);

}

void *Scheduler2(void *args) {
	int time = 0, wait = 0; 
	do {
		if(q2.empty == true) {
			++wait;
			if(wait >= 100000000)
				pthread_exit(0); // process creation has stopped. 
		}
		else {
			if(top(&q2)->arr > time) {
				time += top(&q2)->arr;
			}
			if(top(&q2)->bur > quantum) {
				printf("Process %d is executing from Queue 2...\n", top(&q2)->no);
				time += quantum;
				push(&q2, top(&q2)->no, top(&q2)->arr, top(&q2)->bur-quantum);
				pop(&q2);
			}
			else {
				time += top(&q2)->bur;
				printf("Process %d finished executing and got dequeued from Queue 2...\n", top(&q1)->no);
				comp_time[top(&q2)->no] = time;
				ta_time[top(&q2)->no] = comp_time[top(&q2)->no] - top(&q2)->arr;
				wa_time[top(&q2)->no] = ta_time[top(&q2)->no] - bur_time[top(&q2)->no];
				pop(&q2);
			}
		}
	}
	while(true);	
}

int main() {
	
	pthread_t tid[3]; 

	printf("\nDefine Time Quatum for Scheduler : ");
	scanf("%d", &quantum);

	printf("\t\t\t\t\tArrival Time\tBurst Time\n");

	pthread_create(&tid[0], NULL, create_processes, NULL);
	pthread_create(&tid[1], NULL, Scheduler1, NULL);
	// pthread_create(&tid[2], NULL, Scheduler2, NULL);

	for(int i=0; i<2; ++i) {
		pthread_join(tid[i], NULL);
	}

	printf("\n\n");
	
	return 0;
}
