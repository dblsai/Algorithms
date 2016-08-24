struct TreeNode{
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};	
// in a struct, everything is public
// while in a class, there can be private and public members
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct MyListNode {
	bool mapped;
	int key;
    int val;
    MyListNode *next;
    MyListNode() : next(NULL), mapped(false) {}
    MyListNode(int k, int v, bool m) : key(k), val(v), next(NULL), mapped(m) {}
};

template<typename T>  //template parameter declaration

void print_vector(std::vector<T> v){
	std::cout<<"{ ";
	for(int i=0; i<v.size(); i++)
    	std::cout<<v[i]<<' ';
	std::cout<<"}"<<std::endl;
}

template<typename T> 
void print_2d_vector(std::vector<std::vector<T>> v2){
	for(int i=0; i<v2.size(); i++)
		print_vector(v2[i]);
}

template<typename T> 
std::vector<T> arrayToVector(T arr[], int size){
	std::vector<T> res(arr, arr+size);
	return res;
}

class MyHashMap{
private:
	int mapsize = 10;//INT_MAX/10;
	std::vector<MyListNode*> mymap;
	
public:
	MyHashMap(){
			std::cout<<"integer max: "<<INT_MAX<<std::endl;
		for(int i=0; i<mapsize; i++){
			MyListNode *tmp = new MyListNode();
			mymap.push_back(tmp);
		}
		std::cout<<"constructed"<<std::endl;
	}
	void insert(int k, int v){
		int i = std::hash<int>()(k);
		MyListNode *s = mymap[i%mapsize];
		std::cout<<"insert index = " << i <<std::endl;
		if(!s->mapped){
			//s = new MyListNode(k, v, true);
			s->mapped = true;
			s->key = k;
			s->val = v;
			std::cout<<"1inserted: "<<k<<" , "<<v<<std::endl;
		}else{
			while(s->next != NULL)
				s = s->next;
			s->next = new MyListNode(k, v, true);
			std::cout<<"2inserted: "<<k<<" , "<<v<<std::endl;
		}
	}
	int get(int k){
		int i = std::hash<int>()(k);
			std::cout<<"get index = " << i <<std::endl;
		MyListNode *s = mymap[i%mapsize];
		std::cout<<"mapped: "<<s->mapped<<std::endl;
		if(s->mapped && s->key == k){
			
			return s->val;
		}
		while(s->next != NULL){
			if(s->mapped && s->key == k){
				return s->val;
			}
			s = s->next;
		}
		return -1;
	}
};

//int stoi(const std::string& s) {
//    std::istringstream str(s);
//    int i;
//    str >> i;
//    return i;
//}


