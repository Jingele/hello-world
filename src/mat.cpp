#include "mat.h"
#include "common_io.h"

mat::mat()
{
	this-> row = 0;
	this-> col = 0;
	this-> p = NULL;
}

mat::mat(int i, int j)
{
	this-> row = i;
	this-> col = j;
	this-> p = new int*[this->row];
	for(int k=0; k < this->row; k++)
	{
		p[k] = new int[this->col];
	}
}

mat::mat(const mat &t)
{
	this->row = t.row;
	this->col = t.col;
	this->p = new int*[this->row];
	for(int i = 0; i < this->row; i++)
	{
		this->p[i] = new int[this->col];
		for(int j =0; j < this->col; j++)
		{
			this->p[i][j] = t.p[i][j];
		}
	}
}

mat::mat(int *d, int row, int col)
{
	this->col = col;
	this->row = row;
	this->p = new int*[col];
	for(int i = 0;i < row; i++)
	{
		this->p[i] = new int[col];
		for(int j = 0;j < col; j++)
		{
			this->p[i][j] = d[i*col+j];
		}
	}
}

mat::~mat()
{
	int **q = this->p;
	for(int i =0; i < this->row; i++)
	{
		delete[] q[i];
	}
	delete[] q;
}

/*-----------------------------------------------------------*/
void mat::display()
{
	for(int i =0; i < this->row; i++)
	{
		int *q = this->p[i];
		for(int j = 0; j < this->col; j++)
		{
			cout << *(q++)<<"\t";
		}
		cout<<endl;
	}
}

mat operator+(mat &a, mat &b)
{
	mat r(a.row,a.col);
	for (int i =0; i < r.row; i++)
	{
		for(int j = 0; j < r.col; j++)
		{
			r.p[i][j] = a.p[i][j]+b.p[i][j];
		}
	}
	return r;
}


mat mat::operator+(int k)
{
	mat q(this->row,this->col);
	for(int i =0; i < this->row; i++)
	{
		for(int j = 0; j < this->col; j++)
		{
			q.p[i][j] = this->p[i][j] + k;
		}
	}
	return q;
}


mat mat::operator*(int k)
{
	mat q(this->row,this->col);
	for(int i =0; i < this-> row; i++)
	{
		for(int j = 0; j < this->col; j++)
		{
			q.p[i][j] = this->p[i][j] * k;
		}
	}
	return q;
}


mat operator*(mat &a, mat &b)
{
	mat r(a.row,b.col);
	for(int i = 0; i < a.row; i++)
	{
		for(int j =0;j < b.col; j++)
		{
			int t =0;
			for(int k = 0; k < a.col; k++)
			{
				t+= (a.p[i][k] * b.p[k][j]);
			}
			r.p[i][j] = t;
		}
	}
	return r;
}

bool mat::add_able(mat &a, mat &b)
{
	if(a.row == b.row && a.col == b.col)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool mat::mul_able(mat &a, mat &b)
{
	if(a.col == b.row)
	{
		return true;
	}
	else
	{
		return false;
	}
}


