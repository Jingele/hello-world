#ifndef __MATTER_H__
#define __MATTER_H__

class mat{
	
	private:
		int row;
		int col;
		int **p;
	public:
		mat();
		mat(int i, int j);
		mat(const mat &m);
		mat(int *d,int row,int col);
		~mat();

		friend mat operator+(mat &a, mat &b);
		mat operator+(int k);
		friend mat operator*(mat &a, mat &b);
		mat operator*(int k);
		void display();
	private:
		static bool add_able(mat &a, mat &b);
		static bool mul_able(mat &a, mat &b);
};
	
#endif
