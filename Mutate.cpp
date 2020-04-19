#include <iostream>
#include <string>
#include <set>


std::set<std::string> check_inclusion1(std::string, std::string);
void reset(int*, std::string&);
void get_input(std::string* st1, std::string* st2)
{
	std::string input;
	std::cout << "##################################################################" << std::endl;
	std::cout << 
		"_____________________________________________\n" <<
		+ "     /  /|                  _____ \n"  <<
		+ "    /| / | --------- _/_ --/___ / _/_---___-  -)__ -\n"<<
		+ "   / |/  |    /   /  /    /    /  /    /___/  /   )\n"<<
		+ "  /  /   |   /   /  /    /    /  /    /      /    \n" <<
		+ " / ___   | _/___/__/_ __/___ /_ /_ __/___ _ / _____\n" ;
	std::cout << "##################################################################" << std::endl;
	std::cout << "Please enter a string of chars to which you want the permutations:" << std::endl;
	std::cout << "Or press [any key] to run built in test string." << std::endl;
	std::cin >> input;
	if (!st1->empty()) {

		*st1 = input;
		std::cout << "Please enter a string of chars to compare to:" << std::endl;
		std::cin >> *st2;
	}

	const auto comp1 = *st1;
	const auto comp2 = *st2;
	if (comp1.length() > comp2.length())
	{
		std::cout <<
			"EEEE\n" <<
			+"E\n" <<
			+"EEE  rrr rrr ooo rrr\n" <<
			+"E    r   r   o o r" <<
			+"EEEE r   r   ooo r \n";
		std::cout << "sub string must be equal to or small to qualify as a sub-string." << std::endl;
		std::cout << "Using default string." << std::endl;
		
	}
}
int main()
{
	auto index = 1;
	std::string st1 = "abbc";
	std::string st2 = "babcabbacaabcbabcacbb";
	get_input(&st1, &st2);
	std::cout << "All the permutations of: " << st1 + " that are in In string: " << st2 << std::endl;
	for(const auto& i : check_inclusion1(st1, st2))
	{
		std::cout << index + " " << +" " << i << std::endl;
	}
}

// The elements need to be reset to control 
void reset_controllers(std::string* perm_constructor, int* same_index, int* elements_found)
{
	*elements_found = 0;
	*perm_constructor = "";
	*same_index = -1;
};

std::set<std::string> check_inclusion1(std::string s1, std::string s2)
{
	std::set<std::string> pFound;
	std::string perm_constructor;

	auto elementsFound = 0;
	auto sameIndex = -1;
	const auto sub_string_size = s1.length();
	auto permutation_restore = s2;
	auto found = 0;

	while (s2.length() >= sub_string_size)
	{
		perm_constructor.push_back(s2[elementsFound]);
		found = s1.find(s2[elementsFound]);
		s2 = s2.substr(1, s2.length());

		if (s2.length() < s1.length())
		{
			permutation_restore = permutation_restore.substr(1, permutation_restore.length());
			s2 = permutation_restore;
			reset_controllers(&perm_constructor, &sameIndex, &elementsFound);
		}
		if (found == std::string::npos || found == sameIndex)
		{
			reset_controllers(&perm_constructor, &sameIndex, &elementsFound);
			continue;
		}
		sameIndex = found;
		elementsFound++;
		if (elementsFound == s1.length() && !perm_constructor.empty())
		{
			pFound.insert(perm_constructor);
			reset_controllers(&perm_constructor, &sameIndex, &elementsFound);
		}
	}

	return pFound;

}
