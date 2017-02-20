#ifndef __MATTER_H__
#define __MATTER_H__

class mat{
	
	private:
		int row;
		int column;
		int *m;
	public:
		mat();
		mat(int i, int j);
		mat(mat &t);

		~mat();

		display();

	
#endif
