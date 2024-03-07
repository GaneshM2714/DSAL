#include <iostream>
using namespace std;

#define size 5

class contact
{
    string name;
    string number;

public:
    contact()
    {
        name = " ";
        number = " ";
    }
    contact(string name, string number)
    {
        this->name = name;
        this->number = number;
    }
    bool empty()
    {
        if (name == " " && number == " ")
        {
            return true;
        }
        return false;
    }
    friend class Hashtable;
};

class Hashtable
{
private:
    contact *o;

public:
    Hashtable()
    {
        o = new contact[size];
        for (int i = 0; i < size; i++)
        {
            o[i] = contact();
        }
    }
    int hash(string key)
    {
        int h = 0;
        for (char ch : key)
        {
            h += (int)ch;
        }

        return h % size;
    }

    void insert(string key, string num)
{
    int h = hash(key);
    cout << key << ": " << h << endl;
    int cpy = h;
    if (o[h].name == " ")
    {
        o[h].name = key;
        o[h].number = num;
    }
    else
    {
        bool found = false;
        while (h != cpy - 1 && o[h].name != " ")
        {
            h = (h + 1) % size;
            if (o[h].name == " ")
            {
                o[h].name = key;
                o[h].number = num;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "The Table is Full." << endl;
        }
    }
}


    void print()
    {
        for (int i = 0; i < size; i++)
        {
            if (!o[i].empty())
            {
                cout << "Name: " << o[i].name << " - Number: " << o[i].number << endl;
            }
        }
    }
    void search(string key)
    {
        int h = hash(key);
        int cpy = h;
        while (o[h].name != key && h != cpy - 1)
        {
            h = (h + 1) % size;
        }
        if (h == cpy - 1)
        {
            if (o[h].name == key)
            {
                cout << "Name: " << o[h].name << " - Number: " << o[h].number << endl;
            }
            else
            {
                cout << "Key is not present in the Table. " << endl;
            }
        }
        else
        {
            cout << "Name: " << o[h].name << " - Number: " << o[h].number << endl;
        }
    }
    void delete_key(string key)
{
    int h = hash(key);
    int cpy = h;
    while (o[h].name != key && o[h].name != " " && h != cpy - 1)
    {
        h = (h + 1) % size;
    }
    if (o[h].name == key)
    {
        o[h].name = " ";
        o[h].number = " ";
        cout << "Deleted Successfully!" << endl;
    }
    else
    {
        cout << "Key is not present in the Table to delete. " << endl;
    }
}

};

int main()
{
    Hashtable hashTable;
    int choice;

    while (true)
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Insert contact" << endl;
        cout << "2. Search contact" << endl;
        cout << "3. Delete contact" << endl;
        cout << "4. Print contacts" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, number;
            cout << "Enter contact name: ";
            cin >> name;
            cout << "Enter contact number: ";
            cin >> number;
            hashTable.insert(name, number);
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter contact name to search: ";
            cin >> name;
            hashTable.search(name);
            break;
        }
        case 3:
        {
            string name;
            cout << "Enter contact name to delete: ";
            cin >> name;
            hashTable.delete_key(name);
            break;
        }
        case 4:
            hashTable.print();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
