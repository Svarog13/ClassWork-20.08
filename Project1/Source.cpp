#include <iostream>
using namespace std;


struct Node
{
    int value;
    Node* next;
    Node* prev;
    Node(int v, Node* n,Node *prev) :value(v), next(n),prev(prev) {}
};
class List
{
private:
    Node* head;
    Node* tail;
    int counter = 0;
public:
    List(initializer_list<int>l)
    {

        for (int elem:l)
        {
            AddToTail(elem);
            counter++;
        }
        return;
    }
    List()
    {
        head = tail = nullptr;
       
    }
    bool isEmpty()const
    {
        return head == nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(value,nullptr, head);

        if (isEmpty())
        {
            head =tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        } 
        counter++;
    }
    void AddToTail(int value)
    {
        Node* newNode = new Node(value,tail, nullptr);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
           /* Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;*/
            tail->next = newNode;
            tail = newNode;
        }
        counter++;
    }
    int GetElement(int pos)const
    {
        Node* current = head;
        int i = 1;
        if (pos>0 && pos <= counter)
        {
            while (current != nullptr)
            {
                if (i == pos)
                {
                    return current->value;
                }
                current = current->next;
                i++;
            }
            return 0;
        }
        
    }

    void DeleteFromTail()
    {
        if (isEmpty())
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* beforeLust = tail->prev;
        beforeLust->next = nullptr;
        delete tail;
        tail = beforeLust;
        counter--;
    }
    void DeleteFromHead()
    {
        if (isEmpty())
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (isEmpty())
        {
            tail = nullptr;
        }
        counter--;
    }
    void DeleteByValue(int value)
    {
        if (isEmpty())
        {
            return;
        }
        Node* current = head;
        while (current->value != value)
        {
            current->prev->next = current->next;
            delete current;
        }
        counter--;
    }
    void DeleteDublicate()
    {
        if (isEmpty())
        {
            return;
        }
        Node* current = head;
       
        while (current!= nullptr)
        {
            Node* currentNext = current->next;
          
            while (currentNext!=nullptr)
            {

                if (current->value == currentNext->value)
                {
                    Node* tmp = currentNext;
                    tmp->prev->next = tmp->next;
                    delete tmp;
                    counter--;
                }
            }
            current = current->next;
        }
    }
    int MaxValue() 
    { 
        if (isEmpty()) 
    { 
            return 0; 
    } 
    int maxValue = head->value; 
    for (Node* current = head; current != nullptr; current = current->next) 
    {
        maxValue = std::max(maxValue, current->value);
    } 
    return maxValue; 
    }

    int MinValue()
    {
        if (isEmpty())
        {
            return 0;
        }
        int minValue = head->value;
        for (Node* current = head; current != nullptr; current = current->next)
        {
            minValue = std::min(minValue, current->value);
        }
        return minValue;
    }
    void PrintReverse()const
    {
        if (isEmpty())
        {
            return;
        }
        Node* current = tail;
        while (current !=head)
        {
            std::cout << current << " ";
            current = current->prev;
        }
    }

    void PrintList() const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
        cout << "Size: " << counter << endl;
        cout << "Print Reverse ";
        PrintReverse();
        cout << endl;
    }
    int operator[](int pos)const
    {
        Node* current = head;
        int i = 1;
        if (pos > 0 && pos <= counter)
        {
            while (current != nullptr)
            {
                if (i == pos)
                {
                    return current->value;
                }
                current = current->next;
                i++;
            }
        }
        return 0;
    }
    int& operator[](int pos) 
    { 
        Node* current = head; 
        if (pos > 0 && pos <= counter)
        {
            for (int i = 1; i < pos; i++)
            {
                current = current->next;
            }
        }
        return current->value; 
    }

    ~List()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    List& operator=(const List& other);
};
List& List::operator=(const List& other)
{
    Node* current = other.head;
    while (current != nullptr)
    {
        AddToTail(current->value);
        current = current->next;
    }
    return *this;
}

int main()
{
    List list;
    list.AddToHead(10);
    list.AddToHead(20);
    list.AddToHead(30);
    list.PrintList();
    list.AddToTail(10);
    list.AddToTail(88);
    list.PrintList();
    cout << "Element 3 :" << list.GetElement(3) << endl;
    cout << "Element 5 :" << list.GetElement(5) << endl;
    cout << "Element 7 :" << list.GetElement(7) << endl;
    cout << "Element 9 :" << list.GetElement(9) << endl;
    std::cout << "Min Value : " << list.MinValue() << std::endl;
    std::cout << "Max Value : " << list.MaxValue() << std::endl;
    List list2;
    list2 = list;
    list2.PrintList();
    std::cout << list[3];
    list[3] = 42;
    List l = { 1, 2, 3, 13 ,6 };

}





