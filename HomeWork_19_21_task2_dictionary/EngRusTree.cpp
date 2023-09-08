#include "EngRusTree.h"
#include "MyString.h"
using std::cout;



EngRusTree::EngRusTree() : root{ nullptr }, count{ 0 } {}

void EngRusTree::add(Node*& node, Translation& data)
{
	if (node == nullptr) node = new Node(data);
	else if (data.english < node->data.english) add(node->left, data);
	else add(node->right, data);
}

void EngRusTree::delete_sub_my_tree(Node* node)
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

void EngRusTree::show(Node* node) const
{
	if (node == nullptr) return;
	show(node->left);
	cout << node->data.english << " - " << node->data.russian << endl;
	show(node->right);
}

EngRusTree::Node* EngRusTree::search(Node* node,const MyString& data) const
{
	if (node == nullptr) return nullptr;
	if (node->data.english == data) return node;
	if (node->data.english < data) return search(node->right, data);
	else return search(node->left, data);
}

void EngRusTree::save_to_txt(Node* node, FILE* file) const
{
	if (node != nullptr)
	{
		save_to_txt(node->left, file);
		fprintf(file, "%s - %s\n", (char*)node->data.english, (char*)node->data.russian);
		save_to_txt(node->right, file);
	}
}

void EngRusTree::save_to_bin(Node* node, FILE* file) const
{
	if (node != nullptr)
	{
		save_to_bin(node->left, file);
		save_to_bin(node->right, file);
		node->data.english.save_to_bin_file(file);
		node->data.russian.save_to_bin_file(file);
	}
}

MyString EngRusTree::get_data(Node* node, MyString data) const
{
	if (node == nullptr) return "не существут.";
	if (node->data.english == data) return node->data.russian;
	if (node->data.english < data) return get_data(node->right, data);
	else return get_data(node->left, data);
}

bool EngRusTree::add(Translation& data)
{
	if (!search(data.english))
	{
		add(root, data);
		count++;
		return true;
	}
	return false;
}

void EngRusTree::show() const
{
	if (count) show(root);
	else
	{
		cout << "\n Словарь пуст ";
		return;
	}
}

bool EngRusTree::save_to_txt(FILE* file) const
{
	if (count)
	{
		save_to_txt(root, file);
		return true;
	}
	else return false;
}

bool EngRusTree::save_to_bin(FILE* file)
{
	bool succes = false;
	if (count)
	{
		
		fwrite(&count, sizeof(int), 1, file);
		save_to_bin(root, file);
		succes = true;
		
	}
	else succes = false;
	return succes;
}

bool EngRusTree::read_from_bin(FILE* file)
{
	
	if (count) delete_sub_my_tree(root);
	int cnt = 0;
	fread_s(&cnt, sizeof(int), sizeof(int), 1, file);
	
	Translation temp;

	for (int i = 0; i < cnt; i++)
	{
		temp.english.read_from_bin_file(file);
		temp.russian.read_from_bin_file(file);
		add(temp);
	}

	return true;
}

bool EngRusTree::search(const MyString& data) const
{
	return search(root, data);
}

MyString EngRusTree::get_translation(const MyString& str_eng)const
{

	if (count) return get_data(root,str_eng);
	return "";
}



EngRusTree::~EngRusTree()
{
	delete_sub_my_tree(root);
}



