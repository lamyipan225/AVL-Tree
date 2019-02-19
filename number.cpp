/*
 * number.cpp
 *
 *  Created on: 2016¦~11¤ë19¤é
 *      Author: Wind
 */

/*
 * Submit this file only. The filename has to be exactly "number.cpp".
 * Friendly reminder: submit the correct version of your file and submit early.
 */

#include "number.h"

#include <cstring>
using namespace std;

//No global variable is allowed
//No additional library can be included
//You may create additional (helper) functions in this file if needed
//Make sure your number.cpp can be compiled with the given number.h and main.cpp in our Windows Eclipse package
//(like the one used in our lab)

//In this file, implement all the functions (except printNumber, printNumberReversed, and deleteNumber) declared in number.h
//If you cannot finish implementing all the functions, please still define all of them here
//and provide a dummy implementation for each of them
//so that your number.cpp can still be compiled with our files and be graded for the parts that you could finish

/*
 * Print the represented decimal number on the console using cout, when given a linked list
 * (represented by "headNode" parameter, i.e., a pointer that points to the head node in the linked list)
 *
 * Note: its implementation is already given below and should NOT be modified
 * Note: it would only work if you use it with a correct doubly-linked list
 */
void printNumber(const DecimalNode* headNode)
{
	while (headNode != NULL)
	{
		cout << headNode->content;
		headNode = headNode->next;
	}

	cout << endl;
}

/*
 * Same as printNumber but the printing is reversed
 * So, for example, if printNumber prints 12.345, printNumberReversed prints 543.21
 *
 * Note: its implementation is already given below and should NOT be modified
 * Note: it would only work if you use it with a correct doubly-linked list
 */
void printNumberReversed(const DecimalNode* headNode)
{
	//find the tail node first
	const DecimalNode* tailNode = headNode;
	while(tailNode!= NULL && tailNode->next != NULL)
		tailNode = tailNode->next;

	while(tailNode != NULL)
	{
		cout << tailNode->content;
		tailNode = tailNode->prev;
	}

	cout << endl;
}

/*
 * Deallocate all the dynamically allocated memory for the given linked list
 * (represented by "headNode" parameter, i.e., a reference to a pointer that points to the head node in the linked list)
 * You are also required to set headNode to NULL after the memory deallocation is done
 * Do nothing if the parameter "headNode" is NULL
 *
 * Note: its implementation is already given below and should not be modified
 */
void deleteNumber(DecimalNode*& headNode)
{
	//delete everything with a loop
	const DecimalNode* current = headNode;
	while(current != NULL)
	{
		DecimalNode* next = current->next;
		delete current;
		current = next;
	}
	headNode = NULL;
}



//TODO: write your implementation of the missing functions below

DecimalNode* createNumber(const char* integerPart, const char* fractionalPart)
{
	int lengthOfInteger = 0;
	int lengthOfFract = 0;
	while (integerPart[lengthOfInteger]!='\0')
		lengthOfInteger++;
	while (integerPart[lengthOfFract]!='\0')
		lengthOfFract++;
	char* integerPartTemp = new char [lengthOfInteger+1];
	strcpy(integerPartTemp,integerPart);
	char* fractionalPartTemp = new char [lengthOfFract+1];
	strcpy(fractionalPartTemp,fractionalPart);
	if (integerPart==NULL||fractionalPart==NULL)
		return NULL;
	for (int i=0;i<strlen(integerPartTemp);i++)
		if (!(integerPartTemp[i]>='0'&&integerPartTemp[i]<='9'))
				return NULL;
	for (int i=0;i<strlen(fractionalPartTemp);i++)
			if (!(fractionalPartTemp[i]>='0'&&fractionalPartTemp[i]<='9'))
					return NULL;
	while (integerPartTemp[0]=='0'&&strlen(integerPartTemp)>1)
		for (int i=0;i<strlen(integerPartTemp);i++)
			integerPartTemp[i]=integerPartTemp[i+1];
	while (fractionalPartTemp[strlen(fractionalPartTemp)-1]=='0'&&strlen(fractionalPartTemp)>1)
				fractionalPartTemp[strlen(fractionalPartTemp)-1]='\0';
	DecimalNode** NodeOfInteger = new DecimalNode*[strlen(integerPartTemp)];
	NodeOfInteger[0] = new DecimalNode;
	NodeOfInteger[0]->prev=NULL;
	NodeOfInteger[0]->content=integerPartTemp[0];
	for (int i=1;i<lengthOfInteger;i++)
	{
		NodeOfInteger[i] = new DecimalNode;
		NodeOfInteger[i-1]->next=NodeOfInteger[i];
		NodeOfInteger[i]->prev=NodeOfInteger[i-1];
		NodeOfInteger[i]->content = integerPartTemp[i];
	}
	DecimalNode* NodeOfDot = new DecimalNode;
	NodeOfInteger[strlen(integerPartTemp)-1]->next=NodeOfDot;
	NodeOfDot->prev=NodeOfInteger[strlen(integerPartTemp)-1];
	NodeOfDot->content='.';
	DecimalNode** NodeOfFractional = new DecimalNode*[strlen(fractionalPartTemp)];
	NodeOfFractional[0] = new DecimalNode;
	NodeOfFractional[0]->prev=NodeOfDot;
	NodeOfDot->next=NodeOfFractional[0];
	NodeOfFractional[0]->content=fractionalPartTemp[0];
	for (int i=1;i<strlen(fractionalPartTemp)-1;i++)
	{
		NodeOfFractional[i] = new DecimalNode;
		NodeOfFractional[i]->prev=NodeOfFractional[i-1];
		NodeOfFractional[i-1]->next=NodeOfFractional[i];
		NodeOfFractional[i]->content=fractionalPartTemp[i];
	}
	NodeOfFractional[strlen(fractionalPartTemp)-1] = new DecimalNode;
	if (strlen(fractionalPartTemp)>1)
	{
		NodeOfFractional[strlen(fractionalPartTemp)-1]->prev=NodeOfFractional[strlen(fractionalPartTemp)-2];
		NodeOfFractional[strlen(fractionalPartTemp)-2]->next=NodeOfFractional[strlen(fractionalPartTemp)-1];
	}else
	{
		NodeOfFractional[strlen(fractionalPartTemp)-1]->prev=NodeOfDot;
		NodeOfDot->next=NodeOfFractional[strlen(fractionalPartTemp)-1];
	}
	NodeOfFractional[strlen(fractionalPartTemp)-1]->next=NULL;
	NodeOfFractional[strlen(fractionalPartTemp)-1]->content=fractionalPartTemp[strlen(fractionalPartTemp)-1];
	DecimalNode* head = NodeOfInteger[0];
	delete [] NodeOfInteger;
	delete [] NodeOfFractional;
	delete [] fractionalPartTemp;
	delete [] integerPartTemp;
	return head;
}

DecimalNode* search(DecimalNode* headNode, char c)
{
	if (!(c=='.'||(c>='0'&&c<='9')))
		return NULL;
	if (headNode==NULL)
		return NULL;
	if ((headNode->content)==c)
		return headNode;
	else return search(headNode->next,c);
}

int getIntegerPartLength(const DecimalNode* headNode)
{
	int length = 0;
	for (const DecimalNode* temp = headNode;temp->content!='.';temp=temp->next)
		++length;
	return length;
}

int getFractionalPartLength(const DecimalNode* headNode)
{
	int length = 0;
	for (const DecimalNode* temp = headNode;temp!=NULL;temp=temp->next)
		++length;
	return (length-1-getIntegerPartLength(headNode));
}

int compare(const DecimalNode* a, const DecimalNode* b)
{
	if (a==NULL||b==NULL)
		return 999;
	if (getIntegerPartLength(a)>getIntegerPartLength(b))
		return 1;
	if (getIntegerPartLength(a)<getIntegerPartLength(b))
		return -1;
	if (getFractionalPartLength(a)>getFractionalPartLength(b))
		return 1;
	if (getFractionalPartLength(a)<getFractionalPartLength(b))
		return -1;
	const DecimalNode* temp1=a;
	const DecimalNode* temp2=b;
	for (;temp1!=NULL;temp1=temp1->next,temp2=temp2->next)
	{
		if (temp1->content>temp2->content)
			return 1;
		if (temp1->content<temp2->content)
			return -1;
	}
	return 0;
}

void multiply(DecimalNode* headNode, int n)
{
	if (headNode==NULL)
		return;
	if (n==0)
		return;
	int numOfNode = getIntegerPartLength(headNode)+getFractionalPartLength(headNode)+1;
	DecimalNode** currentNode = new DecimalNode*[numOfNode+n];
	DecimalNode* temp = headNode;
	int dotPos=0;
	for (int i=0;temp!=NULL;i++)
	{
		currentNode[i]=temp;
		if (currentNode[i]->content=='.')
			dotPos=i;
		temp=temp->next;
	}
	if (n>=getFractionalPartLength(headNode))
	{
		for (int i=numOfNode;i<numOfNode+n;i++)
		{
			currentNode[i] = new DecimalNode;
			currentNode[i-1]->next=currentNode[i];
			currentNode[i]->prev=currentNode[i-1];
			currentNode[i]->content='0';
		}
		currentNode[numOfNode+n-1]->next=NULL;;
		currentNode[dotPos-1]->next=currentNode[dotPos+1];
		currentNode[dotPos+1]->prev=currentNode[dotPos-1];
		currentNode[dotPos+n]->next=currentNode[dotPos];
		currentNode[dotPos]->prev=currentNode[dotPos+n];
		currentNode[dotPos+n+1]->prev=currentNode[dotPos];
		currentNode[dotPos]->next=currentNode[dotPos+n+1];
		DecimalNode* lastNode = currentNode[numOfNode+n-1];
		temp = NULL;
		while (lastNode->content=='0'&&lastNode->prev->content!='.')
		{
			temp = lastNode;
			lastNode=lastNode->prev;
			delete temp;
		}
		lastNode->next=NULL;
	}
	else {
		currentNode[dotPos-1]->next=currentNode[dotPos+1];
		currentNode[dotPos+1]->prev=currentNode[dotPos-1];
		currentNode[dotPos+n]->next=currentNode[dotPos];
		currentNode[dotPos]->prev=currentNode[dotPos+n];
		currentNode[dotPos+n+1]->prev=currentNode[dotPos];
		currentNode[dotPos]->next=currentNode[dotPos+n+1];
	}
	if ((headNode->content=='0'&&headNode->next->content!='.'))
	{
		DecimalNode* temp1 = headNode->next;
		temp = headNode;
		while (temp1->content=='0'&&temp1->next->content!='.')
		{
			temp = temp1;
			temp1=temp1->next;
			delete temp;
		}
		headNode->content=temp1->content;
		headNode->next=temp1->next;
		headNode->next->prev=headNode;
		delete temp1;

	}
	delete [] currentNode;
	currentNode=NULL;
}
void reverseNode(DecimalNode*& headNode)
{
	while (headNode!=NULL)
	{
		DecimalNode* temp=headNode->prev;
		headNode->prev=headNode->next;
		headNode->next=temp;
		if (headNode->prev!=NULL)
			headNode=headNode->prev;
		else break;
	}
}

void divide(DecimalNode*& headNode, int n)
{
	if (headNode==NULL)
		return;
	if (n==0)
		return;
	reverseNode(headNode);

	int numOfNode = getIntegerPartLength(headNode)+getFractionalPartLength(headNode)+1;
	DecimalNode** currentNode = new DecimalNode*[numOfNode+n];
	DecimalNode* temp = headNode;
	int dotPos=0;
	for (int i=0;temp!=NULL;i++)
	{
		currentNode[i]=temp;
		if (currentNode[i]->content=='.')
			dotPos=i;
		temp=temp->next;
	}
	if (n>=getFractionalPartLength(headNode))
	{
		for (int i=numOfNode;i<numOfNode+n;i++)
		{
			currentNode[i] = new DecimalNode;
			currentNode[i-1]->next=currentNode[i];
			currentNode[i]->prev=currentNode[i-1];
			currentNode[i]->content='0';
		}
		currentNode[numOfNode+n-1]->next=NULL;;
		currentNode[dotPos-1]->next=currentNode[dotPos+1];
		currentNode[dotPos+1]->prev=currentNode[dotPos-1];
		currentNode[dotPos+n]->next=currentNode[dotPos];
		currentNode[dotPos]->prev=currentNode[dotPos+n];
		currentNode[dotPos+n+1]->prev=currentNode[dotPos];
		currentNode[dotPos]->next=currentNode[dotPos+n+1];
		DecimalNode* lastNode = currentNode[numOfNode+n-1];
		while (lastNode->content=='0'&&lastNode->prev->content!='.')
			lastNode=lastNode->prev;
		lastNode->next=NULL;
		}
	else {
		currentNode[dotPos-1]->next=currentNode[dotPos+1];
		currentNode[dotPos+1]->prev=currentNode[dotPos-1];
		currentNode[dotPos+n]->next=currentNode[dotPos];
		currentNode[dotPos]->prev=currentNode[dotPos+n];
		currentNode[dotPos+n+1]->prev=currentNode[dotPos];
		currentNode[dotPos]->next=currentNode[dotPos+n+1];
	}
	while (headNode->content=='0'&&headNode->next->content!='.')
		headNode=headNode->next;
	headNode->prev=NULL;
	delete [] currentNode;
	reverseNode(headNode);

}

