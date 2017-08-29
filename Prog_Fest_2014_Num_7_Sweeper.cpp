//Authors:
//Edgar Tejada and Obed Lopez
//Revision Date: 2015-11-06
#include <iostream>
#include <string>

int main()
{
	int *ms_squared;
	unsigned int m_size;
	std::cin >> m_size;
	ms_squared = new int[(m_size + 2)*(m_size + 2)];
	unsigned int i;
	unsigned int j;
	unsigned int c = 0;
	bool *finale;
	bool lostthegame = false;
	finale = new bool[(m_size + 2)*(m_size + 2)];
	for (; c < (m_size + 2)*(m_size + 2); c++)
	{
		ms_squared[c] = 0;
		finale[c] = false;
	}
	std::string templine;

	for (i = (m_size + 3), j=0; j<m_size; i++, j++)
	{
		std::cin >> templine;
		std::cin.get();
		for (c = 0; c < templine.length(); c++)
		{
			if (templine[c] == '*')
			{
				ms_squared[i] = (-10);
				ms_squared[i - 1]++;
				ms_squared[i + 1]++;
				ms_squared[i + m_size + 1]++;
				ms_squared[i + m_size + 2]++;
				ms_squared[i + m_size + 3]++;
				ms_squared[i - m_size - 1]++;
				ms_squared[i - m_size - 2]++;
				ms_squared[i - m_size - 3]++;
			}
			
			i++;
		}
		i ++;
	}
	for (i = (m_size + 3), j = 0; i<(m_size + 2)*(m_size + 2) - (m_size + 3), j<m_size; i++, j++)
	{

		std::cin >> templine;
		std::cin.get();
		for (c = 0; c < templine.length(); c++)
		{
			if ((templine[c] == 'x' || templine[c]=='X'))
			{
				finale[i]=true;
			
			}

			i++;
		}
		i++;
	}
	
	for (i = m_size + 3; i < (m_size + 2)*(m_size + 2) - (m_size + 3); i++)
	{

		if (i % (m_size + 2) == 0)
			std::cout << '\n';
		else
			if (i % (m_size + 2) != 0 && ((i + 1) % (m_size + 2) != 0))
				if (finale[i] && ms_squared[i] >= 0)
					std::cout << ms_squared[i];
				else if ((finale[i] && ms_squared[i] < 0))
				{
					std::cout << '*';
					lostthegame = true;
				}
				else if ((lostthegame && ms_squared[i] < 0))
				{
					std::cout << '*';
				}
				else
					std::cout << '.';
	}

	std::cin.get();
	delete[] ms_squared;
	delete[] finale;
	std::cin.get();
	return 0;
}
