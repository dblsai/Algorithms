#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>
#include <climits>
#include <functional>
#include <queue>
#include <deque>

#include "utility.h"
#include "solution.h"
#include "sort.h"

using namespace std;


int main(int argc, char** argv) {
    Solution s;
    // ------------------------------------------------------------------
    // Number Tests
    // ------------------------------------------------------------------
    string to_calculate = "(1+(4+5+2)-3)+(6+8)";
    cout<<"calculator: "<<to_calculate<<" = "<<s.calculate3(to_calculate)<<endl;
    
    //std::cout << s.countBits(5)<<std::endl;
    
    //cout<<s.countPrimes(999983)<<endl;
    
    // ------------------------------------------------------------------
    // Array Tests
    // ------------------------------------------------------------------
    int array1[] = {1,3};
    int array2[] = {2};
    vector<int> nums1(array1, array1+sizeof(array1)/sizeof(int));
    vector<int> nums2(array2, array2+sizeof(array2)/sizeof(int));
    cout<<"median of two array = "<<s.findMedianSortedArrays(nums1, nums2)<<endl;
    
    // ------------------------------------------------------------------
    // String Tests
    // ------------------------------------------------------------------
    std::cout << s.reverseVowels("hello")<<std::endl;

    //string string1 = "()(";
    //string string2 = "((";
    //cout<<"string compare: "<<(string1==string2)<<endl;
   
    // ------------------------------------------------------------------
    // Sorting Tests
    // ------------------------------------------------------------------
    Sorting st;
    int array_to_sort[] = {1,9,7,6,9,7,5,5};
    vector<int> to_sort(array_to_sort, array_to_sort+sizeof(array_to_sort)/sizeof(int));
    //vector<int> sorted = st.mergesort(to_sort, 0, to_sort.size()-1);
    vector<int> sorted = st.quicksort(to_sort); 
    cout<<"after sorting: ";
    print_vector(sorted);
    
   
   
    // ------------------------------------------------------------------
    // Map Tests
    // ------------------------------------------------------------------  
    MyHashMap mm;
    mm.insert(2,100);
    mm.insert(3,800);
    mm.insert(2,101);
    cout<<"hash map value: "<<mm.get(2)<<endl;
    
    // ------------------------------------------------------------------
    // Tree Tests
    // ------------------------------------------------------------------
    std::string treeArray[] = {"5","3","6","2","4","#","#","1"};
    std::string treeArray2[] = {"37","-34","-48","#","-100","-100","48","#","#","#","#","-54","#","-72"};
    std::vector<std::string> treeVector = arrayToVector<std::string>(treeArray, sizeof(treeArray)/sizeof(string));
    std::vector<std::string> treeVector2 = arrayToVector<std::string>(treeArray2, sizeof(treeArray2)/sizeof(string));
    TreeNode *tree = s.constructTree(treeVector);
    TreeNode *tree2 = s.constructTree(treeVector2);
    print_vector<std::string>(treeVector);
    s.printTree(tree);
    TreeNode *p, *q;
    cout<<"lowestCommonAncestor: "<<s.lowestCommonAncestor(tree, new TreeNode(1), new TreeNode(4), true)->val<<endl;
    cout<<"lowestCommonAncestor: "<<s.lowestCommonAncestor(tree, new TreeNode(1), NULL, true)->val<<endl;
    print_vector<std::string>(treeVector2);
    s.printTree(tree2);
    p = s.searchTree(tree2, -100, 1);
    q = s.searchTree(tree2, -100, 2);
    cout<<"lowestCommonAncestor: "<<s.lowestCommonAncestor(tree2, p, q, false)->val<<endl;
    system("pause") ;
	return 0;
}
