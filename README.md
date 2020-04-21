         _   _   _   _   _   _   _   _   _   _   _  
        / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \ 
       ( P | e | r | m | u | t | a | t | i | o | n )
        \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/ 
# permutation
A functional Interview challenge problem. The problem; finding all intersects  B and A. Furthermore, all  characters in A (in size smaller or equal to B)  rearranged, form a contiguous subset in B. 

Math: Find all permutations where order counts, of intersections between A  and B such that all b_i are an element of A, and all b_i ... b_n remain contiguous, forming a unique sub-string in A.  

# Analysis 
The formula to find all the permutations of the string B is P(n,r)=n! (n−r)!; Knowing a bit of big-O an exclamation is a baaaad thing ;).
So after the first brute-forcing solution, a better approach to the problem emerged.

## Edge Cases 
In the problem set there are endge cases that added a bit of complexity 
Given Ex: a string A "ABC" which is to be found in B
- B equals "AAABC" true
- B equals "CBAAA" true
- B equals "CGAAAEB" false
In short the mutiplicity of reaquring carachters are a problem.
### The code is not yet complete the evolution is documentation for the process used for the solution.
- The first code block dirty and well works... kinda. There is one bug in it. 
- The bug, it did not account for dupplicate char's in the permutation queue. So need a better one - solution that is.
- Using this information I noticed wait the queue containing my permutations needs to have the element if not it fails.
- Check if the any of permutation queu is in equal to the top of the container queue if not pop it and move to the next.
- Now I was able to complete this portion but in the process I think I found another solution it can be done with reqersion
### I hope anyways Ill update this if it is.
# Compexity O(n^2)
The first implementation was using a queue which took then I noticed I do not need a queue or an array at all, (other than to store the result). 
```
std::set<std::string> check_inclusion1(std::string s1, std::string s2)
{
	std::set<std::string> pFound;
	std::string perm_constructor;


	auto permutation_restore = s2;
	auto permutation_sub_restore = s1;
	auto found = 0;
	// using the string length the split off the fist char
	// until the main string B is shorter than A
	while (permutation_restore.length() >   0)
	{
		//push on result
		//find element in the long string
		perm_constructor.push_back(s2[0]);
		found = s1.find(s2[0]);
		s2 = s2.substr(1, s2.length());
		// If the element is not in the purmutation set reset all indicators
		if (found == std::string::npos)
		{
			reset_controllers(&perm_constructor, &permutation_sub_restore, &s1, &found);
			continue;
		}
		// If it is the last element in the set then all ements where found and we retain the value;
		if (s1.length() == 1)
		{
			pFound.insert(perm_constructor);
			reset_controllers(&perm_constructor, &permutation_sub_restore, &s1, &found);
		}else
		{
			s1.erase(found, 1);
		}
		if(s2.length() < 1)
		{
			permutation_restore = permutation_restore.substr(1, permutation_restore.length());
			s2 = permutation_restore;
			reset_controllers(&perm_constructor, &permutation_sub_restore, &s1, &found);
		}
		if(s1.length() == permutation_sub_restore.length() && s1 == permutation_sub_restore)
		{
			pFound.insert(permutation_sub_restore);
		}
	}
	return pFound;
}
```

# Great Resource for your interview prep
### Disclosure: using this link Amazon will donate to me for my sugestion.
### - [Cracking the coding interview](https://amzn.to/2XMejh7/)
### OR maybe you dont have an Amazon account, some dont. (absolutly understandable)
## Gayle Laakmann Page
### -[Cracking the coding interview home page](http://www.crackingthecodinginterview.com/)
