#include <stdio.h>
#include <stdlib.h>
struct LinkedList
{
    int data;
    struct LinkedList *next;
};
typedef struct LinkedList node;

//create a new list or add a new node in the last of the list
node *addLast(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        node *last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = temp;
        last = temp;
    }
    return head;
}
void printList(node *head)
{
    if (head == NULL)
        printf("List is empty!");
    else
    {
        while (head != NULL)
        {
            printf("%d\t", head->data);
            head = head->next;
        }
    }
}

node *addFront(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

void reversePrint(node *head)
{
    if (head == NULL)
        return;
    else
    {
        reversePrint(head->next);
        printf("%d\t", head->data);
    }
}
//to count nodes in list
int counter(node *head)
{
    static int c;
    if (head == NULL)
        return 0;
    else
    {
        c++;
        counter(head->next);
    }
    return c;
}
//to count nodes in list(by using recursion)
int counter2(node *head)
{
    if (head == NULL)
        return 0;
    else
        return 1 + counter2(head->next);
}

node *destroyList(node *head)
{
    node *temp = head;
    while (head != NULL)
    {
        head = head->next;
        free(temp);
        temp = head;
    }
    return head;
}
//(by using recursion)
node *destroyListRec(node *head)
{
    if (head == NULL)
        return NULL;
    return destroyListRec(head->next);
    free(head);
}
node *deleteNode(node *head, int x)
{
    node *temp = head;
    if (head->data == x)
    {
        head = head->next;
        free(temp);
    }
    else
    {
        while (temp->next != NULL && temp->next->data != x)
            temp = temp->next;
        if (temp->next == NULL)
            return head;
        node *del = temp->next;
        temp->next = del->next;
        free(del);
    }
    return head;
}
//to subtract the minimum node from all of another nodes in the list
node *substractMin(node *head)
{
    if (head != NULL)
    {
        node *iter = head;
        int min = head->data;
        iter = iter->next;
        while (iter != NULL)
        {
            if (min > iter->data)
                min = iter->data;
            iter = iter->next;
        }
        iter = head;
        while (iter != NULL)
        {
            iter->data -= min;
            iter = iter->next;
        }
    }
    return head;
}

int main()
{
    node *head = NULL;
    head = addFront(head, 3);
    head = addLast(head, 5);
    head = addLast(head, 7);
    head = addLast(head, 2);
    head = addFront(head, 9);
    head = addFront(head, 1);
    printList(head);
    printf("\n after delete\n");
    head = deleteNode(head, 8);
    printList(head);
    printf("\n after substractMin\n");
    head = substractMin(head);
    printList(head);
    return 0;
}
