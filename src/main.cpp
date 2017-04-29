#include "sorter.h"
#include "linker.h"
#include "mat.h"

#include "common_io.h"

/*
int main(void)
{
	sorter str;
	sorter st = str;
	std::cout<<"original data is:"<<std::endl;
	std::cout<<"\t";st.display();

	std::cout<<"sorting:"<<std::endl;
	st.insert();

	std::cout<<"result:"<<std::endl;
	std::cout<<"\t";st.display();
	return 0;
}
*/


int src[] = {1,5,2,4,3,8,7,6,9,0};
int len  = 9;
/*
int main(void)
{
	cout<<"Original data:"<<endl;
	linker lnk(src,len);
	linker lk=lnk;
	lk.display();

	cout<<"operating..."<<endl;
	lk.append(5);
	lk.display();
	lk.modify(5,100);
	lk.display();
	return 0;
}
*/
int col = 3;
int row = 3;
int main(void)
{
	mat m(src,col,row);
	mat y = m;
	mat x = (y*88888888);
	x.display();
	return 0;
}
