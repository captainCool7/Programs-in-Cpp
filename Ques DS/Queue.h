struct Node{
	struct Node *lchild;
	int data;
	struct Node *rchild;
};
struct Queue{
	int size;
	int front;
	int rear;
	struct Node** Q;
};
void create(struct Queue *q,int s){
	q->size = s;
	q->front=q->rear=0;
	q->Q=(struct Node**)malloc(s*sizeof(struct Node*));
}
void enqueue(struct Queue *q,struct Node *n){
	if((q->rear+1)%q->size==q->front){
		printf("Queue is full");
	}else{
		q->rear = (q->rear+1)%q->size;
		q->Q[q->rear]=n;
	}
}
struct Node* dequeue(struct Queue *q){
	struct Node *x=NULL;
	if(q->front==q->rear){
		printf("Queue is Empty");
	}else{
		q->front=((q->front+1)%q->size);
		x=q->Q[q->front];
	}
	return x;
}
int isEmpty(struct Queue q){
	return q.front==q.rear;
}
