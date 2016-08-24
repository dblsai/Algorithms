

class Solution {
private:
 	bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
           return true;
        else
           return false;
    }
    
	int numOfOnes(int number){
        int count = 0;
        while(number > 0){
            count += number & 1;
            number = number >> 1;
        }
        return count;
    }
public:

    std::string reverseVowels(std::string s) {
        std::string v = s;
        for (int i=0; i<s.size(); i++)
        {
          if(isVowel(s[i]))
            v[i] = 'y';
          else
            v[i] = 'n';
        }
        int i = 0;
        int j = s.size() - 1;
        char tmp;
        while( i < s.size() && j >= 0)
        {
          if(v[i] == 'y' && v[j] == 'y')
          {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            v[i] = 'n';
            v[j] = 'n';
          }
          if(v[i] != 'y')
            i++;
              
          if(v[j] != 'y')
            j++;
        }
        return s;
    }
    

    std::vector<int> countBits(int num) {
        std::vector<int> res;
        for(int i=0; i<= num; i++){
            res.push_back(numOfOnes(i));
        }
        return res;
    }
    
     double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> nums3;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] >= nums2[j]){
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size() ){
        	nums3.push_back(nums1[i]);
            i++;
		}
		while(j < nums2.size()){
			nums3.push_back(nums2[j]);
            j++;
		}
        int s = nums3.size();
        if(s%2 == 0)
            return (double)(nums3[s/2] + nums3[s/2 - 1])/2;
        else
            return nums3[(s-1)/2];
    }
    
     int calculate(std::string s) {
        int res = 0;
        bool push = false;
        bool cal = false;
        std::string operand;
        std::stack<std::string> calculator;
        for(int i=0; i<s.size(); i++){
        	push = false;
        	cal = false;
            if(s[i] == '('){
                calculator.push("(");
                std::cout<<"push: "<<calculator.top()<<std::endl;
                push = true;
            }
            else if(s[i] == '+' || s[i] == '-')
            	push = true;
            else if(s[i] >= '0' && s[i] <= '9')
                operand.push_back(s[i]);
            else if(s[i] == ')')
                push = true;
            if(i == s.size()-1)
            	push = true;
            std::cout<<"operand: "<<operand<<std::endl;
            if(push){
            	if(operand.size()>0 && stoi(operand) != 0 ){
            		std::cout<<"push: "<<operand<<std::endl;
            		calculator.push(operand);
				}
				if(operand != "-")
                	operand = "";
                if(s[i] == '+' || s[i] == '-')
                	operand.push_back(s[i]);
			}
			if(s[i] == ')'){
				res = 0;
				while(!calculator.empty() && calculator.top()!="("){
                    res += stoi(calculator.top());
                    std::cout<<"0pop: "<<calculator.top()<<std::endl;
                    std::cout<<"0is this (: "<<(calculator.top() == "(")<<std::endl;
                    calculator.pop();
                    cal = true;
                }
                if(cal){
                	calculator.pop();
                	calculator.push(std::to_string(res));
                	std::cout<<"push: "<<std::to_string(res)<<std::endl;
                }
            }
        }
        res = 0;
        std::cout<<"size: "<<calculator.size()<<std::endl;
    	while(!calculator.empty() && calculator.top() != "("){
    		std::cout<<"1pop: "<<calculator.top()<<std::endl;
    		std::cout<<"1is this (: "<<(calculator.top() == "(")<<std::endl;
            res += stoi(calculator.top());
            calculator.pop();
        }
        return res;
    }
    
    int calculate2(std::string s) {
        int res = 0;
        bool cal = false;
        std::string op;
        std::stack<std::string> calculator;
        for(int i=0; i<s.size(); i++){
        	cal = false;
            if(s[i] >= '0' && s[i] <= '9'){
                op.push_back(s[i]);
                if(i == s.size() - 1 && !op.empty()){
            		res += stoi(op);
            		if(!calculator.empty() && res != 0)
            			calculator.push(std::to_string(res));
            	}
            }
            else if(s[i] == '+' || s[i] == '-' ){
        		if(!op.empty()){
        			res += stoi(op);
        			op.clear();
				}
        		op.push_back(s[i]);
        	}
            else if(s[i] == '('){
        		if(res != 0){
        			calculator.push(std::to_string(res));
        			std::cout<<"push: "<<calculator.top()<<std::endl;
        			res = 0;
        		}
            	calculator.push("(");
            	std::cout<<"push: "<<calculator.top()<<std::endl;
        	}
            else if(s[i] == ')'){
            	if(!op.empty()){
        			res += stoi(op);
        			op.clear();
				}
				if(res != 0){
        			calculator.push(std::to_string(res));
        			std::cout<<"push: "<<calculator.top()<<std::endl;
        			res = 0;
        		}
        		while(!calculator.empty() && calculator.top()!="("){
                	res += stoi(calculator.top());
                	std::cout<<"0pop: "<<calculator.top()<<std::endl;
                	calculator.pop();
                	cal = true;
            	}
            	if(cal){
            		calculator.pop();
            		calculator.push(std::to_string(res));
            		std::cout<<"push: "<<std::to_string(res)<<std::endl;
            		res = 0;
        		}
			}
            std::cout<<"op = "<<op<<std::endl;  
            std::cout<<"res = "<<res<<std::endl;

        }
        if(!calculator.empty() ){
		
        	res = 0;
        	std::cout<<"size: "<<calculator.size()<<std::endl;
    		while(!calculator.empty() && calculator.top() != "("){
    			std::cout<<"1pop: "<<calculator.top()<<std::endl;
            	res += stoi(calculator.top());
            	calculator.pop();
        	}
    	}
        return res;
    }
    
    char invert_sign(char s){
    	if (s == '+') return '-';
    	if (s == '-') return '+';
    	return s;
	}
	
    int calculate3(std::string s) {
        int res = 0, count = 0;
        std::string op;
        std::stack<std::string> bracket;
        for(int i=0; i<s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9')
                op.push_back(s[i]);
            else if(s[i] == '+' || s[i] == '-' ){
        		if(!op.empty()){
        			res += stoi(op);
        			op.clear();
				}
				if(count % 2 == 0)
        			op.push_back(s[i]);
        		else
        			op.push_back(invert_sign(s[i]));
        	}
            else if(s[i] == '(' && !op.empty()){
            	if(op == "-" && count %2 == 0 || op == "+" && count%2 == 1){
					count ++;
					bracket.push("-(");
				}
				else if(op == "+" && count %2 == 0 || op == "-" && count%2 == 1)
					bracket.push("+(");
        	}
            else if(s[i] == ')' && !bracket.empty()){
            	if(bracket.top() == "-(")
            		count --;
            	bracket.pop();
			}
			if(i == s.size() - 1 && !op.empty())
            	res += stoi(op);
        }
		return res;
    }
    
    
    bool isPrime(int n){
        if (n<2) return false;
        for(int i=2; i*i<=n; i++){   //qsrt() function is expensive, avoid calling it repeatedly
            if(n % i == 0) {
                std::cout<<n<<'%'<<i<<std::endl;
                return false;
            }
        }
        return true;
    }
    int countPrimes(int n) {
        if(n<2) return 0;
        std::vector<int> dp(n+1);
        for(int i=3; i <= n; i++){
        	int count = isPrime(i-1) ? 1 : 0;
        	dp[i] = dp[i-1] + count;
		}
		return dp[n];
    }
	

    //The Sieve of Eratosthenes is one of the most efficient ways to find all prime numbers up to n.
    int countPrimes2(int n) {
    	std::vector<bool> isPrime(n);
		for (int i = 2; i < n; i++) {
      		isPrime[i] = true;
  		}
		// Loop's ending condition is i * i < n instead of i < sqrt(n)
   		// to avoid repeatedly calling an expensive function sqrt().
   		for (int i = 2; i * i < n; i++) {
      		if (!isPrime[i]) continue;
      		for (int j = i * i; j < n; j += i) {
         		isPrime[j] = false;
      		}
   		}
   		int count = 0;
   		for (int i = 2; i < n; i++) {
      		if (isPrime[i]) count++;
   		}
   		return count;
    }
    
    //------------------------------------------------
    // Tree
    //------------------------------------------------
    TreeNode* constructTree(std::vector<std::string> input){
		if (input.size() < 1 || input[0] == "#") return NULL;
		TreeNode * root = new TreeNode(stoi(input[0]));
		std::queue<TreeNode*> q;
	    //std::deque<TreeNode*> qq;
		q.push(root);
		bool leftfillwithNull = false;
		for (int i = 1; i < input.size(); i++){
			TreeNode *cur = q.front();
			if (input[i] == "#"){   //empty node
				if (cur->left == NULL && !leftfillwithNull)   // fill left with Null
					leftfillwithNull = true;
				else if(cur->right == NULL){                  // fill right with Null
					q.pop();                                  // cur node left & right filled
					leftfillwithNull = false;
				}
			}
			else{                   //non-empty node
				int val = stoi(input[i]);
				if (cur->left == NULL && !leftfillwithNull){   // fill left
					cur->left = new TreeNode(val);
					q.push(cur->left);
				}
				else if (cur->right == NULL){                 // fill right
					cur->right = new TreeNode(val);
					q.push(cur->right);
					q.pop();
					leftfillwithNull = false;
				}
			}
		}
		return root;
	}
  
    std::vector<std::vector<int> > levelOrder(TreeNode *root) {
		std::queue<TreeNode*> q, q2;
		q.push(root);
		TreeNode* cur;
		std::vector<int> row;
		std::vector<std::vector<int>> result;
		if (root == NULL) return result;
		while (!q.empty()){
			cur = q.front();
			q.pop();
			row.push_back(cur->val);
			if (cur->left != NULL)  q2.push(cur->left);
			if (cur->right != NULL) q2.push(cur->right);
			if (q.empty()){
				result.push_back(row);
				row.clear();
				swap(q, q2);
			}
		}
		return result;
	}
	
	void printTree(TreeNode * t){
		printf("print value of tree in level order: \n");
		std::vector<std::vector<int>> vt = levelOrder(t);
		print_2d_vector(vt);
	}
	
	// search the non-BST tree for the Nth(targetCnt) occurrence 
	TreeNode* searchTreeHelp(TreeNode *root, int target, int targetCnt, int& cnt){
		if(root == NULL) return NULL;
		if(target == root->val){
			cnt ++;
			if(cnt == targetCnt ) return root;
		}
		TreeNode *left = NULL, *right = NULL;
		if(root->left != NULL)
			left = searchTreeHelp(root->left, target, targetCnt, cnt);
		if(root->right != NULL)
			right = searchTreeHelp(root->right, target, targetCnt, cnt);
		return (left == NULL) ? right : left;
	}
	
	TreeNode* searchTree(TreeNode *root, int target, int targetCnt){   // targetCnt = 1,2,3...
		int cnt = 0;
		return searchTreeHelp(root, target, targetCnt, cnt);
	}

	
	void LCA(TreeNode* root, int low, int high, TreeNode*& res)
	{
        if(root == NULL || (root->left == NULL && root->right == NULL)) {printf("haha1\n");return;}
        printf("LCA: root = %d \n", root->val);
        if(root->left == NULL && (root->right->val != high || root->val != low)){printf("haha2.1\n");return;}
         if(root->right == NULL && (root->left->val != low || root->val != high)) {printf("haha2.2\n");return;}
        if((root->val == low && root->right != NULL && root->right->val == high) || 
           (root->val == high && root->left != NULL && root->left->val == low)) 
        {
            res = root;
            printf("haha_yeah1! res = %d\n", res->val);
            return;
        }
        if(root->left->val <= low || root->right->val >= high) {res = root; printf("haha_yeah1! res = %d\n", res->val);}
        if(root->left->val >= low &&  root->left->val <= high)
          LCA(root->left, low, high, res);
        if(root->right->val >= low &&  root->right->val <= high)
          LCA(root->right, low, high, res);
    }
    
    bool inRightTree(TreeNode* root, TreeNode* target)
    {
    	if(target == NULL || root == NULL || root->right == NULL) return false;
		if(target->val >= root->right->val)   // target >= right
			return true;
		else if (target->val < root->right->val && target->val > root->val)   // root < target < right
			return inLeftTree(root->right, target);
		else return false;
	}
	
    bool inLeftTree(TreeNode* root, TreeNode* target)
	{
		if(target == NULL || root == NULL || root->left == NULL) return false;
		if(target->val <= root->left->val)   //target <= left
			return true;
		else if (target->val > root->left->val && target->val < root->val)   // left < target < root
			return inRightTree(root->left, target);
		else return false;
	}
	
	
	TreeNode* LCA2(TreeNode* root, TreeNode* low, TreeNode* high)
	{
		if(root == NULL) return root;
		if(root->val == high->val && inLeftTree(root, low)) return root;
		if(root->val == low->val && inRightTree(root, high)) return root;
		if(inLeftTree(root, low) && inLeftTree(root, high))            // both low & high are in left sub tree
			return LCA2(root->left, low, high);
		else if (inRightTree(root, low) && inRightTree(root, high))    // both low & high are in right sub tree
			return LCA2(root->right, low, high);
		else
			return root;
	}
	
	
	bool inTree(TreeNode* root, TreeNode* target)
	{
		if(target == NULL || root == NULL) return false;
		if(target == root) return true;
		return inTree(root->left, target) || inTree(root->right, target);
	}
	
	TreeNode* LCA3(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if(root == NULL) return root;
		if(root == q && inTree(root->left, p)) return root;
		if(root == p && inTree(root->right, q)) return root;
		if(inTree(root->left, p) && inTree(root->left, q))            // both low & high are in left sub tree
			return LCA3(root->left, p, q);
		else if(inTree(root->right, p) && inTree(root->right, q))     // both low & high are in right sub tree
			return LCA3(root->right, p, q);
		else
			return root;
	}
	
	TreeNode* LCA4(TreeNode* root, TreeNode* p, TreeNode* q){
        // If p or q has been found, then return itself directly. If not, return NULL. 
        if (root == p || root == q || !root) {
            return root;
        }
        
        TreeNode* fromLeft = LCA4(root -> left, p, q);
        TreeNode* fromRight = LCA4(root -> right, p, q);
        
        if (!fromLeft) {
            return fromRight;
        }
        if (fromRight) {
            return root;
        }
        return fromLeft;
    }
	
	//LeetCode 235. Lowest Common Ancestor of a Binary Search Tree
	//LeetCode 236. Lowest Common Ancestor of a Binary Tree
	//For BST, Assume p,q must be in the tree
	//For non-BST, there can be duplicates!
	//a node can be a ancestor/child of itself
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, bool isBST) 
	{
        if(p == NULL || q == NULL) return (p == NULL && q == NULL) ? root : ((p == NULL)? q : p);
    
        //int low = ( p->val < q->val) ? p->val : q->val;
        //int high = ( p->val > q->val) ? p->val : q->val;
        //LCA(root, low, high, res);
        if(isBST){
	        if(p->val == q->val) 
				return p;
	        else if (p->val < q->val)
	        	return LCA2(root, p, q);
	        else
	        	return LCA2(root, q, p);
	    }
	    else{
	        //return LCA3(root, p, q);
	        return LCA4(root, p, q);
		}

    }
    

};
