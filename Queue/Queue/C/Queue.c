#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

void menu();
void processUserChoice(short);
int readInput(char *);
node* createNewNode();

/* Queue Operations */
void Enqueue(int);
int Dequeue();
int Peek();
char IsEmpty();
int Size();

node *head = NULL;
node *tail = NULL;
int queue_size = 0;

int main() {

    menu();

    return 0;
}

void menu()
{
    short choice  = 0;

    do
    {
        system("cls");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. IsEmpty\n");
        printf("5. Size\n");
        printf("0. Quit\n");

        if(choice < 0 || choice > 5)
        {
            printf("Invalid input\n");
        }

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        processUserChoice(choice);

        printf("Press any key to continue\n");
        getch();
    }while(choice != 0);
}

void processUserChoice(short choice)
{
    int data;
    int index;
    char isEmpty = 0;

    switch(choice)
    {
        case 0:
            exit(0);
            break;
        case 1:
            Enqueue(readInput("Enter new data"));
            break;
        case 2:
            data = Dequeue();
            printf("Front of the queue is %d\n", data);
            break;
        case 3:
            data = Peek();
            printf("Front of the queue is %d\n", data);
            break;
        case 4:
            isEmpty = IsEmpty();
            if(isEmpty == 1)
            {
                printf("queue is empty\n");
            }
            else
            {
                printf("queue is not empty\n");
            }
            break;
        case 5:
            data = Size();
            printf("Size of the queue is %d\n", data);
            break;
    }
}

int readInput(char *str)
{
    int input;
    printf("%s: ", str);
    scanf("%d", &input);
    return input;
}

node* createNewNode(int data)
{
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error creating new node\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void Enqueue(int data)
{
    node* new_node = createNewNode(data);

    if(tail != NULL)
    {
        tail->next = new_node;
    }

    tail = new_node;

    if(head == NULL)
    {
        head = tail;
    }
    ++queue_size;
}

int Dequeue()
{
    int data = -1;
    node* temp;

    if(head != NULL)
    {
        data = head->data;
        temp = head;
        head = head->next;
        free(temp);
        --queue_size;
    }

    return data;
}

int Peek()
{
    int data = -1;

    if(head != NULL)
    {
        data = head->data;
    }

    return data;
}

char IsEmpty()
{
    return queue_size == 0;
}

int Size()
{
    return queue_size;
}
