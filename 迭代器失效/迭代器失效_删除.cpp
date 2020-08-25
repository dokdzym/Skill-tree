#include <vector>
#include <iostream>
using namespace std;

//遍历一遍vector以删除元素3
int main()
{
	vector<int> vector_int{ 1, 4, 3, 7, 9, 3, 6, 8, 3, 3, 5, 2, 3, 7 };

	/*方案一 原理是，在vector删除导致迭代器失效时，只有当前迭代器及之后的迭代器失效，之前的不失效。因此可以利用头迭代器+偏移量的方式访问到后续的元素*/
		 //for(int i = 0; i < vector_int.size(); i++)
		 //{
		 //    if(vector_int[i] == 3)
		 //    {
		 //        vector_int.erase(vector_int.begin() + i);
		 //        i--;
		 //    }
		 //} 

	/*方案二 erase会返回下一个有效的迭代器*/
		 for(vector<int>::iterator itor = vector_int.begin(); itor != vector_int.end(); )
		 {
		     if (*itor == 3)
		     {
		         itor = vector_int.erase(itor);
			 }
			 else {
				 ++itor;
			 }

		 }

	for (vector<int>::iterator itor = vector_int.begin(); itor != vector_int.end(); itor++)
	{
		cout << *itor << "  ";
	}
	cout << endl;
	return 0;
}
