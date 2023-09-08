#include "MyBinTree.h"
using std::cout;



MyBinTree::MyBinTree() : root{ nullptr }, count{ 0 } {}

void MyBinTree::add(Node*& node, const int& data)
{
	if (node == nullptr) node = new Node(data);
	else if (data < node->data) add(node->left, data);
	else add(node->right, data);
}

void MyBinTree::delete_sub_my_tree(Node* node)
{
	if (node != nullptr)
	{
		delete_sub_my_tree(node->left);
		delete_sub_my_tree(node->right);

		delete node;
		node = nullptr;
		count--;
	}
}

void MyBinTree::show(Node* node) const
{
	if (node == nullptr) return;
	show(node->left);
	cout << node->data << "  ";
	show(node->right);
}

MyBinTree::Node* MyBinTree::search(Node* node, const int& data) const
{
	if (node == nullptr) return nullptr;
	if (node->data == data) return node;
	if (node->data <= data) return search(node->right, data);
	else return search(node->left, data);
}

void MyBinTree::save_to_txt(Node* node, FILE* file) const
{
	if (node != nullptr)
	{
		save_to_txt(node->left, file);
		fprintf(file, "%d ", node->data);
		save_to_txt(node->right, file);
	}
}

void MyBinTree::save_to_bin(Node* node, FILE* file) const
{
	if (node != nullptr)
	{
		save_to_bin(node->left, file);
		save_to_bin(node->right, file);
		fwrite(&node->data, sizeof(int), 1, file);
	}
}

void MyBinTree::add(const int& val)
{
	add(root, val);
	count++;
}

void MyBinTree::show() const
{
	if (count) show(root);
	else
	{
		cout << "\n Дерево пусто ";
		return;
	}
}

void MyBinTree::save_to_txt(FILE* file) const
{
	if (count) save_to_txt(root, file);
	else return;
}

void MyBinTree::save_to_bin(FILE* file)
{
	if (count)
	{
		fwrite(&count, sizeof(int), 1, file);
		save_to_bin(root, file);
	}
	else return;
}

void MyBinTree::read_from_bin(FILE* file)
{
	if (count) delete_sub_my_tree(root);
	int cnt = 0;
	fread_s(&cnt, sizeof(int), sizeof(int), 1, file);

	for (int i = 0; i < cnt; i++)
	{
		int src = 0;
		fread_s(&src, sizeof(int), sizeof(int), 1, file);
		add(src);
	}

}

bool MyBinTree::search(const int& data) const
{
	return search(root, data);
}

MyBinTree::~MyBinTree()
{
	delete_sub_my_tree(root);
}



