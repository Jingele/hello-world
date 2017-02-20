#include "linker.h"
#include "common_io.h"

linker::linker()
{
	this->head = new node;
	this->length = 0;
	this->head->next = NULL;
}

linker::linker(linker &lnk)
{
	this->length = 0;
	this->head = new node;
	this->head->next = NULL;
	pnode p = this->head;
	pnode q = lnk.head;
	while(q->next != NULL)
	{
		q = q->next;
		pnode t = new node;
		t->data = q->data;
		t->next = NULL;
		p->next = t;
		p = p->next;
		this->length++;
	}
}

linker::linker(int *src,int len)
{
	this->head = new node;
	this->length = len;
	this->head->next = NULL;
	pnode p = this->head;
	int *q = src;
	for(int i =0; i < len; i++)
	{
		pnode t = new node;
		t->data = *(q++);
		t->next = NULL;
		p->next = t;
		p = p->next;
	}
}

linker::~linker()
{
	pnode p = head;
	pnode q = p->next;
	while(q != NULL)
	{
		delete p;
		p = q;
		q = p -> next;
	}
	delete p;
}

void linker::display()
{
	pnode p = head;
	p = p->next;
	while(p != NULL)
	{
		cout<<p->data<<"\t";
		p = p->next;
	}
	cout<<endl;
}


void linker::append(int d)
{
	pnode p = this->head;
	while(p->next != NULL)
	{
		p = p-> next;
	}
	pnode q = new node;
	q->data = d;
	q->next = NULL;
	p->next = q;
	this->length += 1;
}

void linker::del(int d)
{
	pnode p = this->head;
	while(p->next != NULL)
	{
		if(p->next->data == d)
		{
			pnode q = p->next->next;
			delete p->next;
			p->next = q;
			this->length--;
		}
		else
		{
			p = p->next;
		}
	}
}

int linker::find(int d)
{
	pnode p = this->head;// -1
	p =  p->next;
	int i = 0;
	while(p != NULL)
	{
		if(p-> data == d)
		{
			return i;
		}
		else
		{
			p = p->next;
			i++;
		}
	}
	return -1;
}

void linker::modify(int d, int v)
{
	pnode p = this->head;
	while(p->next != NULL)
	{
		p = p->next;
		if(p->data == d)
		{
			p->data = v;
		}
	}
}
