#ifndef __LINKER_H__
#define __LINKER_H__


typedef struct Node{
	int data;
	struct Node *next;
}node,*pnode;


class linker{
	private:
		pnode head;
		int length;

	public:
		linker();
		linker(linker &lnk);
		linker(int *src,int len);
		~linker();
		void display();

		void append(int d);//append to the tail of the link
		void del(int d);//delete all the d in the link
		int find(int d);//print the index of first d; head is (-1) 
		void modify(int d, int v);//modify all the d to v;
};

#endif

