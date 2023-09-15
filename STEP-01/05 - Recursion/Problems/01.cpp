
// 01: Coding Ninja -- https://www.codingninjas.com/studio/problems/-print-n-times_8380707?leftPanelTab=0



// ------------------------------------------------------------------------------------------------

// Function to generate a vector of strings containing "Coding Ninjas" repeated N times.
vector<string> printNTimes(int N) {
	
	// Create a vector for storing the answer
	vector<string> ans;
	
	// Base condition: If N is 1, return a vector containing "Coding Ninjas"
	if(N == 1) {
		ans.push_back("Coding Ninjas ");
		return ans;
	} 
	// Base condition: If N is less than 0, return an empty vector
	else if(N < 0) {
		return {};
	}

	// Recursively call printNTimes with N-1 and store the result in ans
	ans = printNTimes(N - 1);
	
	// Add "Coding Ninjas " to the end of the vector ans
	ans.push_back("Coding Ninjas ");
	
	// Return the updated vector ans
	return ans;
}

// ------------------------------------------------------------------------------------------------






// 02: GFG -- https://practice.geeksforgeeks.org/problems/print-gfg-n-times/1


// ------------------------------------------------------------------------------------------------
class Solution {
public:
    // Recursive function to print "GFG" N times
    void printGfg(int N) {
      
        // Base condition: If N is 0, return and terminate the recursion
        if (N == 0)
            return;

        // Print "GFG" followed by a space
        cout << "GFG" << " "; 
     // cout << "GFG ";  

        // Recursively call printGfg with N-1 to print "GFG" (N-1) more times
        printGfg(N - 1);
    }
};

// ------------------------------------------------------------------------------------------------
