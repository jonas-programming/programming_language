package blatt5;

import java.util.ArrayList;

class Task9 {

	public static void main(String[] args) {
		Tree<Integer> t = new Tree<Integer>();
		t.insert(1); t.insert(4); t.insert(5); t.insert(5); t.insert(-2);
		System.out.println("Infix");
		t.print();
		System.out.println("Prefix");
		t.prePrint();
		System.out.println("Postfix");
		t.postPrint();
		System.out.println("6 in tree?");
		System.out.println(t.search(6));
		System.out.println();
		System.out.println("5 in tree?");
		System.out.println(t.search(5));
	}

}

/**
 * Tree class to represent a generic ordered tree<br>
 * All elements to the left of the root are strictly smaller than the root<br>
 * All elements to the right of the root are strictly greater than the root<br>
 */
class Tree<T extends Comparable<T>> {

	private Node<T> root;

	/** Constructor for an empty tree */
	Tree() {
		this.root = null;
	}

	/** Insert a new node to the tree with the given data as data */
	void insert(T data) {
		this.insert(new Node<T>(data));
	}

	/**
	 * Insert the given node in to the tree respectively to the data so that the
	 * tree remains ordered<br>
	 * If data of node is already contained in tree, insert is ignored
	 */
	void insert(Node<T> node) {
		if (this.root == null)
			this.root = node;
		else
			this.root.insert(node);
	}

	/**
	 * Search for the node in the tree or more specific check if the tree contains
	 * the nodes data
	 */
	boolean search(Node<T> node) {
		return this.search(node.getData());
	};

	/** Check if the tree contains the given data */
	boolean search(T data) {
		return (this.root == null) ? false : this.root.search(data);
	}

	/**
	 * Converts the tree to an array in following fashion:<br>
	 * opt 0 - infix : default!<br>
	 * opt 1 - prefix<br>
	 * opt 2 - postfix
	 */
	ArrayList<Node<T>> toArray(int opt) {
		return this.root.toArray(opt);
	}

	/** Print array in infix fashion */
	void print() {
		
		for (Node<T> e : this.toArray(0))
			System.out.println(e.getData());
	}

	/** Print array in prefix fashion */
	void prePrint() {
		for (Node<T> e : this.toArray(1))
			System.out.println(e.getData());
	}

	/** Print array in postfix fashion */
	void postPrint() {
		for (Node<T> e : this.toArray(2))
			System.out.println(e.getData());
	}

}

/**
 * A node is part of a tree<br>
 * It holds some kind of data and has a left and right child<br>
 * The left child is strictly smaller than this node<br>
 * The right child is strictly greater than this node
 */
class Node<T extends Comparable<T>> implements Comparable<Node<T>> {

	private final T data;
	private Node<T> rchild;
	private Node<T> lchild;

	/** Constructor for a node with data but no childs */
	Node(T data) {
		this.data = data;
		this.rchild = this.lchild = null;
	}
	
	/** Return data of node */
	T getData() {
		return this.data;
	}

	/**
	 * Set child of this node<br>
	 * opt is weather node should be set to left or right child<br>
	 * opt 0 - left child : default!<br>
	 * opt 1 - right child
	 */
	void setChild(Node<T> node, int opt) {
		if (opt == 1)
			this.rchild = node;
		else
			this.lchild = node;
	}

	/**
	 * Get child of this node<br>
	 * opt is weather node should be set to left or right child<br>
	 * opt 0 - left child : default!<br>
	 * opt 1 - right child
	 */
	Node<T> getChild(int opt) {
		return (opt == 1) ? this.rchild : this.lchild;
	}

	/**
	 * Pass insertion to left or right child depending on comparison of nodes data
	 * and itself data<br>
	 * To left child if smaller; to right child if greater; ignore if equal<br>
	 * If itself has no corresponding child given node gets inserted there
	 */
	void insert(Node<T> node) {
		int com = this.compareTo(node);
		if (com == 0)
			return;
		else {
			Node<T> child = (com > 0) ? this.lchild : this.rchild;
			if (child != null)
				child.insert(node);
			else
				this.setChild(node, (com > 0) ? 0 : 1);
		}
	}

	/**
	 * Recursively part the problem to a smaller one<br>
	 * Check if left or right subtree contains search data<br>
	 * If any of the subtrees contains it return true
	 */
	boolean search(T data) {
		if (data.compareTo(this.getData()) == 0)
			return true;
		else
			return ((this.lchild == null) ? false : this.lchild.search(data))
					|| ((this.rchild == null) ? false : this.rchild.search(data));
	}

	/**
	 * Converts the subtree to the left and to the right of this node to an array in
	 * following fashion:<br>
	 * opt 0 - infix : default!<br>
	 * opt 1 - prefix<br>
	 * opt 2 - postfix<br>
	 * Then set together with itself in same way
	 */
	ArrayList<Node<T>> toArray(int opt) {
		ArrayList<Node<T>> arr = new ArrayList<Node<T>>();
		ArrayList<Node<T>> left = (this.lchild == null) ? new ArrayList<Node<T>>() : this.lchild.toArray(opt);
		ArrayList<Node<T>> right = (this.rchild == null) ? new ArrayList<Node<T>>() : this.rchild.toArray(opt);
		switch (opt) {
		default:
		case 0:
			arr.addAll(left);
			arr.add(this);
			arr.addAll(right);
			break;
		case 1:
			arr.add(this);
			arr.addAll(left);
			arr.addAll(right);
			break;
		case 2:
			arr.addAll(left);
			arr.addAll(right);
			arr.add(this);
			break;
		}
		return arr;
	}

	
	/**
	 * Implements a compareTo method to satisfy the interface Comparable<T><br>
	 * Just returns comparable of to data values which have to implement this
	 * interface
	 */
	@Override
	public int compareTo(Node<T> arg) {
		return (this.getData()).compareTo(arg.getData());
	}
}
