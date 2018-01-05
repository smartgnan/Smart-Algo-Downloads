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

/* Linked List Operations */
void insertAtHead(int);
void insertAtTail(int);
void insertAtPosition(int, int);
int removeFromHead();
int removeFromTail();
int removeFromPosition(int);
int search(int);
void traverse();

node *head = NULL;

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
        printf("1. Insert At Head\n");
        printf("2. Insert At Tail\n");
        printf("3. Insert At Position\n");
        printf("4. Remove From Head\n");
        printf("5. Remove From Tail\n");
        printf("6. Remove From Position\n");
        printf("7. Search\n");
        printf("8. Traverse\n");
        printf("0. Quit\n");

        if(choice < 0 || choice > 8)
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
    char enter = 0;

    switch(choice)
    {
        case 0:
            exit(0);
            break;
        case 1:
            insertAtHead(readInput("Enter new data"));
            break;
        case 2:
            insertAtTail(readInput("Enter new data"));
            break;
        case 3:
            insertAtPosition(readInput("Enter position to insert"), readInput("Enter new data"));
            break;
        case 4:
            data = removeFromHead();
            printf("Data removed from head is %d\n", data);
            break;
        case 5:
            data = removeFromTail();
            printf("Data removed from tail is %d\n", data);
            break;
        case 6:
            data = removeFromPosition(readInput("Enter position to remove from"));
            printf("Data removed is %d\n", data);
            break;
        case 7:
            index = search(readInput("Enter data to find"));
            if(index == -1)
            {
                printf("Data not found\n");
            }
            else
            {
                printf("Data is found at %d\n", index);
            }
            break;
        case 8:
            traverse();
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

void insertAtHead(int data)
{
    node* new_node = createNewNode(data);

    if(head != NULL)
    {
        new_node->next = head;
    }

    head = new_node;
}

void insertAtTail(int data)
{
    node* new_node = createNewNode(data);
    node* temp = head;

    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

}

void insertAtPosition(int position, int data)
{
    node* new_node = createNewNode(data);
    node* temp = head;
    node* prev = NULL;

    int i = 1;

    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        while(temp->next != NULL && --position != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = new_node;
        new_node->next = temp;
    }
}

int removeFromHead()
{
    int data = -1;
    node* temp;

    if(head != NULL)
    {
        data = head->data;
        temp = head;
        head = head->next;
        free(temp);
    }

    return data;
}

int removeFromTail()
{
    int data = -1;
    node* temp = head;
    node* prev;

    if(head != NULL)
    {
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        data = temp->data;
        free(temp);
    }

    return data;
}

int removeFromPosition(int position)
{
    int data;
    node* temp = head;
    node* prev = NULL;

    if(head != NULL)
    {
        while(temp->next != NULL && --position != 0)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        data = prev->data;
        free(temp);
    }

    return data;
}

int search(int toFind)
{
    int found = -1;
    node* temp = head;
    int i = 0;

    if(head != NULL)
    {
        while(temp != NULL)
        {
            i++;
            if(toFind == temp->data)
            {
                found = i;
                break;
            }
            temp = temp->next;
        }
    }

    return found;
}

void traverse()
{
    node* temp = head;

    if(head != NULL)
    {
        printf("\n");
        while(temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
