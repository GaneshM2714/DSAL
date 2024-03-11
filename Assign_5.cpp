#include <iostream>
using namespace std;

class Node
{
    string word;
    string data;
    Node *next;

public:
    Node()
    {
        // this->word = " ";
        // this->data = " ";
        this->next = NULL;
    }
    Node(string word, string meaning)
    {
        this->word = word;
        this->data = meaning;
        this->next = NULL;
    }
    friend class Dictionary;
};

class Dictionary
{
    Node *table;
    int hash(string key)
    {
        char ch = toupper(key[0]);
        int h = ch - 'A';
        h = h % 26;
        return h;
    }

public:
    Dictionary()
    {
        table = new Node[26];
        for (int i = 0; i < 26; i++)
        {
            table[i] = Node();
        }
    }
    void insert(string key, string value) {
    int h = hash(key);
    key[0] = toupper(key[0]);
    Node *current = &table[h];

    while (current->next != nullptr) {
        if (current->next->word == key) {
            // If the word is found, update the meaning
            current->next->data = value;
            cout << "Changed words meaning successfully!" << endl;
            return;
        }
        current = current->next;
    }

    // If the key is not found in the linked list, add a new node
    current->next = new Node(key, value);
    cout << "Inserted new word successfully!" << endl;
}

    void search(string key)
    {
        int h = hash(key);
        key[0]=toupper(key[0]);
        Node *current = &table[h];
        while (current != NULL)
        {
            if (current->word == key)
            {
                cout << "Key : " << current->word << " Meaning : " << current->data << endl;
                return;
            }
            current = current->next;
        }
        cout << "No meaning for your word " << key << " has been found!" << endl;
    }

    void deletekey(string key)
    {
        int h = hash(key);
        key[0]=toupper(key[0]);
        Node *current = &table[h];
        Node *prev = NULL;
        while (current)
        {
            if (current->word == key)
            {
                if (prev == NULL)
                {
                    prev = current;
                    current = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete (current);
                cout << "Deleted " << key << " successfully!" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout<<key<<" wasn't present!"<<endl;
    }

    void print(){
        cout<<"******************************************************************"<<endl;
        for (int i=0;i<26;i++){
            int alpha= i + 'A';
            char alphabet=alpha;
            cout<<"For Alphabet "<<alphabet<<" : "<<endl;
            Node* current=&table[i];
            while (current){
                cout << "key : " << current->word << " meaning : " << current->data << endl;
                current=current->next;
            }
            cout<<"******************************************************************"<<endl;
        }
    }
};

int main() {
    Dictionary dictionary;

    while (true) {
        cout << "********** Dictionary Menu **********" << endl;
        cout << "1. Insert a word" << endl;
        cout << "2. Search for a word" << endl;
        cout << "3. Delete a word" << endl;
        cout << "4. Print Dictionary" << endl;
        cout << "5. Exit" << endl;
        cout << "*************************************" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.clear();
        fflush(stdin);

        switch (choice) {
            case 1: {
                string word, meaning;
                cout << "Enter the word: ";
                cin >> word;
                cout << "Enter the meaning: ";
                getline(cin>>ws,meaning);
                dictionary.insert(word, meaning);
                break;
            }
            case 2: {
                string word;
                cout << "Enter the word to search: ";
                cin >> word;
                dictionary.search(word);
                break;
            }
            case 3: {
                string word;
                cout << "Enter the word to delete: ";
                cin >> word;
                dictionary.deletekey(word);
                break;
            }
            case 4:
                dictionary.print();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
