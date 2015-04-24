#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node;
typedef std::map<char,Node*> node_map;
typedef node_map::value_type node_value;

class Node {
private:
    char m_content;
    bool m_marker;
    node_map m_children;		 //use hashmap or map here

public:
    Node() { m_content = ' '; m_marker = false; }
    ~Node() {}
    
	char content() { return m_content; }
    
	void setContent(const char c) { m_content = c; }
	void setWordMarker() { m_marker = true; }
	void appendChild(char c,Node* child) { m_children.insert(node_value(c,child)); }
	//void appendChild(Node* child) {} //TODO:overload to insert multiple children at one time

	
    bool wordMarker() { return m_marker; }

    node_map children() { return m_children; }
    Node* findChild(const char c);
};

Node* Node::findChild(const char c)
{
	node_map::const_iterator iter = m_children.find(c);
	if(iter != m_children.end()){
		Node* tmp = iter->second;
		return tmp;
	}

    return NULL;
}

class Trie {
private:
    Node* root;
	
public:
    Trie(){ root = new Node(); };
    ~Trie(){ /*Free memory*/ };
	
    void addWord(string s);
	void deleteWord(string s);
    bool searchWord(string s);
};

void Trie::addWord(string s)
{
    Node* current = root;

    if ( s.length() == 0 )
    {
        current->setWordMarker(); // an empty word
        return;
    }

    for ( int i = 0; i < s.length(); i++ )
    {        
        Node* child = current->findChild(s[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            //TODO:Look into simplize this part
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(s[i],tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 )
            current->setWordMarker();
    }
}

bool Trie::searchWord(string s)
{
    Node* current = root;

    if ( current != NULL )
    {
        for ( int i = 0; i < s.length(); i++ )
        {
            Node* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return false;
            current = tmp;
        }

        if ( current->wordMarker() )
            return true;
        else
            return false;
    }

    return false;
}


// Test program
int main()
{
    Trie* trie = new Trie();
    trie->addWord("Hello");
    trie->addWord("Balloon");
    trie->addWord("Ball");

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

    delete trie;

	system("pause");
}
