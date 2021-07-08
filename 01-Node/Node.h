template <typename T>
class Node {
public :
	T data;
	Node* next;

	Node();
	Node(T val);
	~Node();
};

Node::Node() {
	next = nullptr;
}

Node::~Node() {
	delete next;
}

Node::Node(T val) {
	data = val;
	next = nullptr;
}
