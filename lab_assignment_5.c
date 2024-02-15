#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
  char letter;
  struct node* next;
} node;



int length(node* head)
{
  int len = 0;
  node* temp = head;
  while(temp != NULL)
  {
    len ++;
    temp = temp -> next;
  }
  return len;
}



char* toCString(node* head)
{
  int i = 0;
  char* str = (char*)malloc(sizeof(char) * length(head));
  while(head != NULL)
    {
      str[i] = head -> letter;
      head = head -> next;
      i++;
    }
  return str;
}


void insertChar(node** pHead, char c)
{
  node* temp;
  node* newNode = (node*)malloc(sizeof(node));
  newNode -> letter = c;
  newNode -> next = NULL;
  if(*pHead == NULL)
    *pHead = newNode;
  else
  {
    temp = *pHead;
    while(temp -> next != NULL)
      temp = temp -> next;
    temp -> next = newNode;
  }
}


void deleteList(node** pHead)
{
  node* temp = *pHead;
  while(temp != NULL)
    {
      *pHead = temp -> next;
      free(temp);
      temp = *pHead;
    }
  *pHead = NULL;
}


int main(void)
{
  int i, strLen, numInputs;
  node* head = NULL;
  char* str;
  char c;
  FILE* inFile = fopen("input.txt","r");
  fscanf(inFile, " %d\n", &numInputs);
  while (numInputs-- > 0)
  {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++)
    {
      fscanf(inFile," %c", &c);
      insertChar(&head, c);
    }
    str = toCString(head);
    printf("String is : %s\n", str);
    free(str);
    deleteList(&head);
    if (head != NULL)
    {
      printf("deleteList is not correct!");
      break;
    }
  }  
  fclose(inFile);
}
