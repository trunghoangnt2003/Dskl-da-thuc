//
//  main.c
//  dslk
//
//  Created by Nguyễn Trung on 13/12/2022.
//

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct node
{
    int bac;
    int heso;
    struct node *next;
};
typedef struct node node;
node *makeNode(int heso,int bac)
{
    node *newNode=(node*)malloc(sizeof(node));
    newNode->bac=bac;
    newNode->heso=heso;
    newNode->next=NULL;
    return newNode;
}
void pushBack(node **head,int heso,int bac)
{
    node*newNode=makeNode(heso, bac);
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }
    node *temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}
void duyet(node *head)
{
    while(head!=NULL)
    {
        printf("%dx^%d ",head->heso,head->bac);
        if(head->next!=NULL) printf("+ ");
        head=head->next;
    }
}
void sort(node **head)
{
    for(node *temp=*head;temp!=NULL;temp=temp->next)
    {
        for(node *j=temp->next;j!=NULL;j=j->next)
        {
            if(temp->bac<j->bac)
            {
                int k1=temp->heso;
                int k2=temp->bac;
                temp->heso=j->heso;
                temp->bac=j->bac;
                j->heso=k1;
                j->bac=k2;
            }
        }
    }
}

int main()
{
    char s[1000];
    
    int cnt=1;
    int heso=(s[0]-'0');
    node *head=NULL;
    for(int i=0;i<2;i++)
    {
        fgets(s,1000,stdin);
        s[strlen(s)-1]='\0';
    
    for(int i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
            if(cnt==1)
            {
                heso=(s[i]-'0');
                cnt++;
                continue;
            }
            else if(cnt==2)
            {
                node *temp=head;
                int check=1;
                int bac=s[i]-'0';
                while(temp!=NULL)
                {
                    if(temp->bac==bac)
                    {
                        temp->heso=temp->heso+heso;
                        check=0;
                        break;
                    }
                    temp=temp->next;
                }
                if(check==1)
                {
                    pushBack(&head, heso, bac);
                }
                cnt=1;
            }
            
        }
    }
    }
    sort(&head);
    duyet(head);
    
}

