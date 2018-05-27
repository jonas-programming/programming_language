#include <iostream>
#include <cstddef>
#include <vector>

/** */

using namespace std;

template <class T>
/**
	A node is part of a tree<br>
	It holds some kind of data and has a left and right child<br>
	The left child is strictly smaller than this node<br>
	The right child is strictly greater than this node
*/
class Node{
	private:
		const T data;
		Node<T>* lchild;
		Node<T>* rchild;
	public:
		
		/** Constructor for a node with data but no childs */
		Node(T datam) : data( datam ){
			this->lchild = nullptr;
			this->rchild = nullptr;
		}
		
		/** Return data of node */
		T getData(){ return (this->data); }
		
		/**
			Set child of this node<br>
			opt is weather node should be set to left or right child<br>
			opt 0 - left child : default!<br>
			opt 1 - right child
		*/
		void setChild(Node<T>& node, int opt){
			if (opt == 1) this->rchild = &node;
			else this->lchild = &node;
		}
		
		/**
			Get child of this node<br>
			opt is weather node should be set to left or right child<br>
			opt 0 - left child : default!<br>
			opt 1 - right child
		*/
		Node<T>* getChild(int opt){ return (opt == 1)? this->rchild: this->lchild; }
		
		/** Compare to nodes based on there data */
		int compareTo(Node<T>& node){
			if(this->getData() == node.getData()){
				return 0;
			} else if (this->getData() > node.getData()){
				return 1;
			} else {
				return -1;
			}
		}
		
		/**
			Pass insertion to left or right child depending on comparison of nodes data
			and itself data<br>
			To left child if smaller; to right child if greater; ignore if equal<br>
			If itself has no corresponding child given node gets inserted there
		*/
		void insert(Node<T>& node) {
			int com = this->compareTo(node);
			if(com == 0) return;
			else {
				Node<T>* child = (com > 0)?this->lchild: this->rchild; 
				if(child != nullptr) child->insert(node);
				else this->setChild(node, (com > 0)?0 : 1);
			}
		}
		
		/**
			Recursively part the problem to a smaller one<br>
			Check if left or right subtree contains search data<br>
			If any of the subtrees contains it return true
		*/
		bool search(T data) {
			if(data == this->getData()) return true;
			else return ((this->lchild == nullptr)? false: this->lchild->search(data)) || ((this->rchild == nullptr)? false: this->rchild->search(data));
		}
		
		/**
			Converts the subtree to the left and to the right of this node to a vector in
			following fashion:<br>
			opt 0 - infix : default!<br>
			opt 1 - prefix<br>
			opt 2 - postfix<br>
			Then set together with itself in same way
		*/
		vector<Node<T>*> toArray(int opt){
			vector<Node<T>*> arr, left, right;
			left = (this->lchild == nullptr)? vector<Node<T>*>(): this->lchild->toArray(opt);
			right = (this->rchild == nullptr)? vector<Node<T>*>(): this->rchild->toArray(opt);
			switch(opt) {
			case 0 :
				arr.insert(end(arr), begin(left), end(left));
				arr.push_back(this);
				arr.insert(end(arr), begin(right), end(right));
				break;
			case 1:
				arr.push_back(this);
				arr.insert(end(arr), begin(left), end(left));
				arr.insert(end(arr), begin(right), end(right));
				break;
			case 2:
			default:
				arr.insert(end(arr), begin(left), end(left));
				arr.insert(end(arr), begin(right), end(right));
				arr.push_back(this);
				break;
			}
			return arr;
		}
};

template <class T>
/**
	Tree class to represent a generic ordered tree<br>
	All elements to the left of the root are strictly smaller than the root<br>
	All elements to the right of the root are strictly greater than the root<br>
*/
class Tree{
	 
	private:
		Node<T>* root;
	public:
		
		/** Constructor for an empty tree */
		Tree(){ this->root = nullptr; }
		
		/** Insert a new node to the tree with the given data as data */
		void insert(T data) { this->insert(*(new Node<T>(data))); }
		
		/**
			Insert the given node in to the tree respectively to the data so that the
			tree remains ordered<br>
			If data of node is already contained in tree, insert is ignored
		*/	
		void insert(Node<T>& node) {
			if(this->root == nullptr) this->root = &node;
			else this->root->insert(node);
		}
		
		/**
			Search for the node in the tree or more specific check if the tree contains
			the nodes data
		*/
		bool search(Node<T>& node) { return (this->search(node.getData())); }
		
		/** Check if the tree contains the given data */
		bool search(T data) { return (this->root == nullptr)? false: this->root->search(data); }
		
		/**
			Converts the tree to an array in following fashion:<br>
			opt 0 - infix : default!<br>
			opt 1 - prefix<br>
			opt 2 - postfix
		*/
		vector<Node<T>*> toArray(int opt) { return this->root->toArray(opt); }
		
		/** Print array in infix fashion */
		void print() { for(Node<T>* e : this->toArray(0)) cout << e->getData() << endl; }
	
		/** Print array in prefix fashion */
		void prePrint() { for(Node<T>* e : this->toArray(1)) cout << e->getData() << endl; }
	
		/** Print array in postfix fashion */
		void postPrint() { for(Node<T>* e : this->toArray(2)) cout << e->getData() << endl; }
};


int main(){
	Tree<int> t = Tree<int>();
	Node<int> a = Node<int>(1);
	t.insert(a); t.insert(4); t.insert(5); t.insert(5); t.insert(-2);
	cout << "infix" << endl;
	t.print();
	cout << "prefix" << endl;
	t.prePrint();
	cout << "postfix" << endl;
	t.postPrint();
	cout << endl;
	cout << "6 in tree?" << endl;
	cout << ((t.search(6))? "true": "false") << endl;
	cout << "5 in tree?" << endl;
	cout << (t.search(5)? "true": "false");	
}
