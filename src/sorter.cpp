#include "sorter.h"

#include <iostream>

using namespace std;

const int data[] ={2,4,1,0,5,3,9,8,3,6};
const int len = 10;

sorter::sorter()
{
	this->length = len;
	this->src = new int[this->length];
	this->dst = new int[this->length];
	int *p = this->src;
	for(int i =0; i < this->length; i++)
	{
		*(p++) = data[i];
	}
	p = NULL;
}

sorter::sorter(sorter &ter)
{
	this->length = ter.length;
	this->src = new int[this->length];
	this->dst = new int[this->length];
	int *p = this->src;
	int *q = ter.src;
	for(int i =0; i < this->length; i++)
	{
		*(p++) = *(q++);
	}
	p = NULL;
}

sorter::~sorter()
{
	if(this->src != NULL)
	{
		delete[] this->src;
	}
	if(this->dst != NULL)
	{
		delete[] this->dst;
	}
}

void sorter::display(int *s, int len)
{
	int *p = s;
	for(int i =0; i < len; i++)
	{
		cout<<*(p++)<<"\t";
	}
	cout << endl;
	p = NULL;
}

void sorter::display()
{
	display(this->src,this->length);
}

void sorter::sorter::swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void sorter::sorter::swap(int *s, int i, int j)
{
	int t = *(s+i);
	*(s+i) = *(s+j);
	*(s+j) = t;
}

void sorter::bub()
{
	for(int i = length-1; i >0; i--)
	{
		for(int j =0; j < i; j++)
		{
			if(*(src+j) > *(src+j+1))
			{
				sorter::swap(src+j,src+j+1);
			}
			else
			{
			}
		}
		cout<<i<<"-th\t";
		display();
	}
}

void sorter::insert()
{
	for(int i =1; i < length; i++)
	{
		for(int j =i; *(src+j) < *(src+j-1); j--)
		{
			sorter::swap(src+j,src+j-1);
		}
		cout<<i<<"-th:\t";
		display();
	}
}

void sorter::select()
{
	for(int i =0; i < length-1; i++)
	{
		int min = *(src+i);
		int k = i;
		for(int j =i+1; j < length; j++)
		{
			if( min > *(src+j) )
			{
				min = *(src+j);
				k = j;
			}
		}
		sorter::swap(src,k,i);
		cout<<i<<"-th\t";
		display();
	}
}

void sorter::shell()
{
	int N = length;
	int h = 1;
	while(h < N/3)
	{
		h = h*3 +1;
	}
	while(h >= 1)
	{
		for(int i = h; i < N; i++)
		{
			for(int j = i; j-h >= 0; j-=h)
			{
				if(*(src+j) < *(src+j-h))
				{
					sorter::swap(src,j,j-h);
				}
			}
		}
		cout<<h<<"--stepSize";
		display();
		h/=3;
	}
}

void sorter::partition(int *src, int lf, int rt)
{
	if(rt <= lf)
	{
		return;
	}
	int i = lf,
		j = rt;
	int key = *(src+i);
	while(i < j)
	{
		while(*(src+j) > key && (i < j))
		{
			j--;
		}
		if(j>i)
		{
			*(src+i) = *(src+j);
		}
		while(*(src+i) <= key && (i < j))
		{
			i++;
		}
		if(j>i)
		{
			*(src+j) = *(src+i);
		}
	}
	*(src+i) = key;

	cout<<lf<<"--"<<rt<<"\t";
	display();
	partition(src,lf,i-1);
	partition(src,i+1,rt);
}


void sorter::quick()
{
	partition(this->src,0,this->length-1);
}


void sorter::merg(int *s, int lf, int mid, int rt)
{
	int i = lf,
		j = mid;
	int k = lf;
	int *m = new int[rt-lf+1];
	int	*p = m;
	while( i < mid && j <= rt)
	{
		while(*(s+i) <= *(s+j) && (i < mid))
		{
			*(p++) = *(s+(i++));
		}
		while(*(s+j) <= *(s+i) && (j <= rt))
		{
			*(p++) = *(s+(j++));
		}
	}
	if(i >= mid)
	{
		while(j <= rt)
		{
			*(p++) = *(s+(j++));
		}
	}
	if(j > rt)
	{
		while(i < mid)
		{
			*(p++) = *(s+(i++));
		}
	}
	p = m;
	while(k <= rt)
	{//copy it back to s;
		*(s+(k++)) = *(p++);
	}
	p= NULL;
	delete[] m;
}

void sorter::merge()
{
	int step = 1;
	while(step <= length)
	{
		for(int i=0;i < length;i+=(2*step))
		{
			if(i+2*step < length)
			{
				merg(src,i,i+step,i+2*step-1);
			}
			else if(i+step <length)
			{
				merg(src,i,i+step,length-1);
			}
		}
		cout<<step<<"--step\t";
		display();
		step *=2;
	}
}
