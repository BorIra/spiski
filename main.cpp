#include <iostream>
using namespace std;

struct Node                             
 {  // узел
     int value;                             
     Node *next;                 
 };

class List
{   // список
    public:
            Node *head;
 
            List(){ this->head = NULL;}
            ~List();
            void pushFront(int value);
            void print();
            void popFront();
            bool contains(int value);
            void pushBack(int value);
            void popBack();
            void reverce();
};

List::~List()                           
 {  // деструктор для лсвобождения памяти
     Node *tmp = NULL;
     while (head)                       
     {
         tmp = head->next;
         delete head;
         head = tmp;                  
     }
     print();
 }

void List::pushFront(int value)
{ // добавление в начало
    Node *node = new Node();
    node->value = value;
    node->next = head;
    head = node;
}

void List::print()
{   // пачать списка
    Node *node = head;
    for(Node *node = head; node != NULL; node = node->next)
        cout << node->value << " ";
    cout << endl;
}

void List::popFront()
{ // удаление первого элемента
    if(head != NULL)
        head = head->next;
}

bool List::contains(int value)
{ // поиск элемента в списке
    Node *node = head;
    while(node != NULL)
    {
        if(node->value == value)
            return true;
        node = node->next;
    }
    return false;
}

void List::pushBack(int value)
{ // добавление в конец списка
    Node *node = new Node();
    node->value = value;

    if(head == NULL)
        head = node;
    else
    {
        Node *cur = head;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = node;
    }
}

void List::popBack()
{ // удаляем последний элемент
    if(head != NULL)
        if(head->next == NULL)
            head = NULL;
        else 
        {
            Node *cur = head;
            while (cur->next->next != NULL) 
            {
                cur = cur->next;
            }
            cur->next = NULL;
        }
    
}

void List::reverce()
{   // разворачиваем список
    Node *next = NULL;
    Node *cur = head;
    Node * prev = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;        
    }
    head = prev;
}

int main()
{
    List *list = new List();
    for(int i = 5; i > 0; i --)
        list->pushFront(i);
    cout << "Добавление в начало списка: ";
    list->print();

    list->popFront();
    cout << "Удаление первого элемента:";
    list->print();

    for(int i = 10; i < 16; i ++)
        list->pushBack(i);
    cout << "Добавление в конец списка: ";
    list->print();

    list->popBack();
    cout << "Удаление последнего элемента: ";
    list->print();

    list->reverce();
    cout << "Разворот списка: ";
    list->print();

    delete list;
    return 0;
}