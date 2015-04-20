#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
    char m_content;
    bool m_marker;
    vector<Node*> m_children;

public:
    Node() { m_content = ' '; m_marker = false; }
    ~Node() {}
    
	char content() { return m_content; }
    
	void setContent(char c) { m_content = c; }
	void setWordMarker() { m_marker = true; }
	void appendChild(Node* child) { m_children.push_back(child); }
	
    bool wordMarker() { return m_marker; }

    vector<Node*> children() { return m_children; }
    Node* findChild(char c);
};

Node* Node::findChild(char c)
{
    for ( int i = 0; i < m_children.size(); i++ )
    {
        Node* tmp = m_children.at(i);
        if ( tmp->content() == c )
        {
            return tmp;
        }
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
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
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