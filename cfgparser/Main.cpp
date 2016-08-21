#include "Main.h"


int main()
{



	{
		cConfig mycfg("test.cfg", CONFIG_WRITE);
		
		mycfg.Write<int>("TestOption", 5);
		
	}
	{
		cConfig mycfg("test.cfg", CONFIG_READ);

		std::cout << mycfg.Read<int>("TestOption") << std::endl;

	}

	system("pause");
	return EXIT_SUCCESS;
}