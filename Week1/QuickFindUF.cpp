#include <iostream>

class QuickFindUF
{
private:
	int* id; //array of ints.
	int size;
public:
	QuickFindUF(int n)
	{
		id = new int[n];
		size = n;
		for(int i=0; i<n;i++)
			id[i] = i;
	}
	
	//Utility function to vizualize changes
	void printArray()
	{
		for(int i=0; i<size; i++)
			std::cout << id[i] << "\t" ;
		std::cout << std::endl;
	}
	
	bool connected(int p, int q)
	{
		if( p>=size || q >=size)
			return false;
		else
			return (id[p] == id[q]);
	}

	//False means error
	bool Union(int p, int q)
	{
		if(p>=size || q>=size)
			return false;
		
		int pId = id[p];
		int qId = id[q];
		for(int i=0; i<size; i++)
		{
			if(id[i] == pId)
				id[i] = qId;
		}
		printArray();
		return true;
		
	}
};


int main()
{
	QuickFindUF obj(10);
	obj.Union(4,3);
	obj.Union(3,8);
	obj.Union(6,5);
	obj.Union(9,4);
	obj.Union(2,1);
	std::cout << obj.connected(8,9) << std::endl;
	std::cout << obj.connected(5,0) << std::endl;
	obj.Union(5,0);
	obj.Union(7,2);
	obj.Union(6,1);
	std::cout << obj.connected(1,5) << std::endl;
	return 0;
}