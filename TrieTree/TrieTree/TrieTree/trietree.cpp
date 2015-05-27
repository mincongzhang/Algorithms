#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node;
typedef std::map<char,Node*> node_map;
typedef node_map::value_type node_value;


/////////////////////Node///////////////////////////////

class Node {
private:
	char m_content;
	bool m_marker;
	node_map m_children; //use hashmap or map to save children for efficient search

public:
	Node() { m_content = ' '; m_marker = false; }
	~Node() {}

	char content() { return m_content; }
	void setContent(const char c) { m_content = c; }
	void setWordMarker() { m_marker = true; }
	bool wordMarker() { return m_marker; }

	node_map children() { return m_children; }
	Node* findChild(const char c);
	Node* appendChild(char c);
};

Node* Node::findChild(const char c)
{
	node_map::const_iterator iter = m_children.find(c);
	if(iter != m_children.end()){
		return iter->second;
	}

	return NULL;
}

Node* Node::appendChild(const char c)
{
	Node* child = new Node();
	child->setContent(c);
	m_children.insert(node_value(c,child)); 
	return child;
}
//////////////////////////////////////////////////////////


class Trie {
private:
	Node* root;


public:
	Trie(){ root = new Node(); };
	~Trie(){ delete this; }; //TODO: not sure if I should recursively delete?

	void addWord(std::string s);
	void deleteWord(std::string s);
	bool searchWord(std::string s);
	void printAllWords(); //traverse tree
	std::vector<std::string> getAllWords(); //traverse tree
};

void Trie::printAllWords()
{
	Node* current = root;

	//std::string tmp;
	//tmp+=node.content();
	//if(	node->wordMarker()) cout<<tmp
	//if reach end
	//tmp("")
}

void Trie::addWord(std::string s)
{
	Node* current = root;

	for ( int i = 0; i < s.length(); ++i )
	{        
		Node* child = current->findChild(s[i]);
		if ( child != NULL )
			current = child;
		else
			current = current->appendChild(s[i]);
	}

	current->setWordMarker();
}

bool Trie::searchWord(std::string s)
{
	Node* current = root;

	if ( current != NULL )
	{
		for ( int i = 0; i < s.length(); i++ )
		{
			current = current->findChild(s[i]);
			if ( current == NULL )	return false;
		}

		return current->wordMarker();
	}

	return false;
}


// Test program
int main()
{
	Trie* trie = new Trie();
	trie->addWord("Hello");
	trie->addWord("Helloo");
	trie->addWord("Balloon");
	trie->addWord("Ball");
	trie->addWord("");

	if ( trie->searchWord("Hell") )
		cout << "Found Hell" << endl;

	if ( trie->searchWord("Hello") )
		cout << "Found Hello" << endl;

	if ( trie->searchWord("Helloo") )
		cout << "Found Helloo" << endl;

	if ( trie->searchWord("Ball") )
		cout << "Found Ball" << endl;

	if ( trie->searchWord("Balloon") )
		cout << "Found Balloon" << endl;

	if(trie->searchWord(""))
		cout<<"Found ''"<<endl;

	system("pause");
}