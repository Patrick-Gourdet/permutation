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

# Compexity O(n^2)
The first implementation was using a queue which took then I noticed I do not need a queue or an array at all, (other than to store the result). 
```

```

# Great Resource for prep
Disclosure: using this link Amazon will donate to me becase of my sugestion.
This site was built using [Cracking the coding interview](https://amzn.to/2XMejh7/)
OR maybe you dont have an Amazon account like most people (absolutly understandable)
This site was built using [Cracking the coding interview home page](http://www.crackingthecodinginterview.com/)
