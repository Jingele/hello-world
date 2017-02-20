#ifndef __SORTER_H__
#define __SORTER_H__

/*
class sorting{
pubic:
	virtual void sort()=0;
};
*/


class sorter{
	private:
		int *src;
		int *dst;
		int length;
	public:
		sorter();
		sorter(sorter &ter);
		~sorter();
		//add,delete,and modify data;
		static void swap(int *a, int *b);	
		static void swap(int *s, int i, int j);
		//display *src
		void display();
		void display(int *s, int len);	
		//sort 
		void bub();
		void insert();
		void select();
		void shell();

		void quick();
		void partition(int *s, int lf, int rt);
		
		void merge();
		void merg(int *s, int lf,int mid,int rt);
};

#endif
