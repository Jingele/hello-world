#include "sorter.h"

#include <iostream>

int main(void)
{
	sorter str;
	sorter st = str;
	std::cout<<"original data is:"<<std::endl;
	std::cout<<"\t";st.display();

	std::cout<<"sorting:"<<std::endl;
	st.merge();

	std::cout<<"result:"<<std::endl;
	std::cout<<"\t";st.display();
	return 0;
}
