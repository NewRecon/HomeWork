#include <iostream>
#include "LinkedList.cpp"
using namespace std;

class Man
{
private:
    int id;
    string name;
    int age;
public:
    Man(int id, string name, int age)
    {
        this->id = id;
        this->name = name;
        this->age = age;
    }
    int getId()
    {
        return id;
    }
    void setId(int id)
    {
        this->id = id;
    }
    friend ostream& operator <<(ostream& out, Man& man)
    {
        out << man.id << " " << man.name << " " << man.age << endl;
        return out;
    }
};

int main()
{
    Man man1(1121 ,"Max", 24);
    Man man2(1232, "Jhon", 39);
    Man man3(11243, "Phill", 28);
    Man man4(11244, "Leon", 40);
    Man man5(19, "Elena", 27);

    LinkedList<Man> list(man1);
    list.addToHead(man2);
    list.addToHead(man3);
    list.addToTail(man4);
    list.addToPosition(man5,3);
    list.addToHead(man3);
    list.addToTail(man3);
    list.show();
    cout << endl;
    cout << list.searchAndSwap(man5, 1) << endl;
    list.show();
    //cout << endl;
}