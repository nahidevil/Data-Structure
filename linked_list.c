#include<stdio.h>

struct listnode
{
    int data;
    struct listnode *next;
};
struct listnode *head;
void insert_position(int value,int index)
{
    int i=1;
    struct listnode*temp1,*newnode=(struct listnode*)malloc(sizeof(struct listnode));
    newnode->data=value;
    temp1=head;

    for(i=1; i<index-1; i++)
    {
        temp1=temp1->next;
    }
    newnode->next=temp1->next;
    temp1->next=newnode;
}

void insert_begining(int value)
{
    struct listnode* newnode;
    newnode=(struct listnode*)malloc(sizeof(struct listnode));
    newnode->data=value;

    newnode->next=head;
    head=newnode;

}
void insert_end(int value)
{
    struct listnode*temp,*newnode;
    newnode=(struct listnode*)malloc(sizeof(struct listnode));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL)
    {
        head->next=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void del(int index)
{
    if(index==1)
    {
        struct listnode* temp;
        temp=head;
        head=head->next;
        free(temp);
    }
    else
    {
        struct listnode *temp;
        temp=head;
        for(int i=1; i<index-1; i++)
        {
            temp=temp->next;
        }
        struct listnode *temp2;
        temp2=temp->next;
        temp->next=temp2->next;
        free(temp2);
    }

}

void reverse()
{
    printf("\nReversed Linked list: ");
    struct listnode *prevnode,*restnode,*currnode=head;
    prevnode=NULL;
    restnode=NULL;
    while(currnode!=NULL)
    {
        restnode=currnode->next;
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=restnode;
    }

    while(prevnode!=NULL)
    {
        printf("%d ",prevnode->data);
        prevnode=prevnode->next;
    }
    printf("\n\n");

}
void print()
{
    struct listnode *display=head;
    printf("\Output:\n");
    while(display!=NULL)
    {
        printf("%d ",display->data);
        display=display->next;
    }
    printf("\n\n");
}
int main()
{
    head=NULL;
    while(1)
    {
        printf("MENU:\n\t1. insert new node\t\t2. insert node at begining\n\t3. insert node at index\t\t4. insert at end\n");
        printf("\t5. print\t\t\t6.reverse\n\t7. delete\n\t0. Exit\n");
        int n,v,p;
        scanf("%d",&n);
        if(n==1)
        {
            head=(struct listnode*)malloc(sizeof(struct listnode));
            head->data=1;
            head->next=NULL;
        }
        else if(n==2)
        {
            printf("\nEnter value: ");
            scanf("%d",&v);
            insert_begining(v);
        }
        else if(n==3)
        {
            printf("\nEnter value and position: ");
            scanf("%d%d",&v,&p);
            insert_position(v,p);
        }
        else if(n==4)
        {
            printf("\nEnter value: ");
            scanf("%d",&v);
            insert_end(v);

        }
        else if(n==5)
        {
            print();
        }
        else if(n==6)
        {
            reverse();
        }
        else if(n==7)
        {
            printf("\nEnter Index of node: ");
            scanf("%d",&p);
            del(p);
        }
        else
            break;
    }
}
