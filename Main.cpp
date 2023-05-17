#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    string m_id;
    string m_name;
    int m_age;

public:
    Animal() {}
    Animal(string _id, string _name, int _age)
    {
        m_id = _id;
        m_name = _name;
        m_age = _age;
    }
    string get_id() const { return m_id; }
    string get_name() const { return m_name; }
    int get_age() const { return m_age; }
    void set_id(string _id) { m_id = _id; }
    void set_name(string _name) { m_name = _name; }
    void set_age(int _age) { m_age = _age; }
};

class Node
{
public:
    int value;
    Node *next;
};

class AnimalNode
{
public:
    int anInt;
    Animal *animalObj;
    AnimalNode *next;
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->value << endl;
        n = n->next;
    }
}

void printAnimalList(AnimalNode *n)
{
    cout << "\n\n";
    while (n != NULL)
    {
        cout << "\n " << n->anInt << " " << n->animalObj->get_name() << " " << n->animalObj->get_age() << " " << n->animalObj->get_id() << endl;
        n = n->next;
    }
    cout << "\n\n";
}

void appendNode(Node *&head, int data)
{
    Node *newNode = new Node();
    newNode->value = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void appendAnimalNode(AnimalNode *&head, int anInt, string id, string name, int age)
{
    AnimalNode *newNode = new AnimalNode();
    newNode->anInt = anInt;
    newNode->animalObj = new Animal(id, name, age);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        AnimalNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main()
{
    Node *head = NULL;
    for (int i = 1; i <= 13; i++)
    {
        appendNode(head, i);
    }
    printList(head);

    // Create three animals
    Animal *myAnimal01 = new Animal();
    Animal *myAnimal02 = new Animal();
    Animal *myAnimal03 = new Animal();

    myAnimal01->set_id("Hy01");
    myAnimal01->set_age(5);
    myAnimal01->set_name("Shenzi");

    myAnimal02->set_id("Hy02");
    myAnimal02->set_age(2);
    myAnimal02->set_name("Banzai");
    
    myAnimal03->set_id("Hy03");
    myAnimal03->set_age(7);
    myAnimal03->set_name("Ed");

    // Create an AnimalNode linked list with three nodes
    AnimalNode *anHead = new AnimalNode();
    anHead->anInt = 1;
    anHead->animalObj = myAnimal01;

    anHead->next = new AnimalNode();
    anHead->next->anInt = 2;
    anHead->next->animalObj = myAnimal02;

    anHead->next->next = new AnimalNode();
    anHead->next->next->anInt = 3;
    anHead->next->next->animalObj = myAnimal03;
    anHead->next->next->next = NULL;

    // Print the linked list
    printAnimalList(anHead);

    // Clean up the memory
    delete myAnimal01;
    delete myAnimal02;
    delete myAnimal03;

    AnimalNode *current = anHead;
    AnimalNode *next;

    while (current != NULL)
    {
        next = current->next;
        delete current->animalObj;
        delete current;
        current = next;
    }

    return 0;
} 
