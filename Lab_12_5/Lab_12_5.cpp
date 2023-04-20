#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info info;
};

void push(Elem*& top, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = top;
    top = tmp;
}

Info pop(Elem*& top)
{
    Elem* tmp = top->link;
    Info value = top->info;
    delete top;
    top = tmp;
    return value;
}

void print(Elem* top)
{
    while (top != NULL)
    {
        cout << top->info << " ";
        top = top->link;
    }
}

Info eval(Elem* stack, string exprsn, Info a, Info b, Info c, Info d)
{
    for (int j = exprsn.size() - 1; j >= 0; j--) 
    {
        if (exprsn[j] == 'a' || exprsn[j] == 'b' || exprsn[j] == 'c' || exprsn[j] == 'd') //1
            switch (exprsn[j])
            {
            case 'a':
                push(stack, a);
                break;
            case 'b':
                push(stack, b);
                break;
            case 'c':
                push(stack, c);
                break;
            case 'd':
                push(stack, d);
                break;
            }
        else 
        {
            Info o1 = pop(stack); //2
            Info o2 = pop(stack); //3
            switch (exprsn[j])  //4
            {
            case '+':
                push(stack, o1 + o2);
                break;
            case '-':
                push(stack, o1 - o2);
                break;
            case '*':
                push(stack, o1 * o2);
                break;
            case '/':
                push(stack, o1 / o2);
                break;
            }
        }
        print(stack); cout << " (" << exprsn[j] << ")" << endl;
    }
    return stack->info;
}

int main()
{
    Elem* top = NULL;
    Info a, b, c, d;
    ifstream fin("file.txt");
    string expresn;
    if (fin.is_open())
    {
        string line;
        while (getline(fin, line))
            expresn += line;
        fin.close();
    }
    else
    {
        cout << "Can't open the file" << endl;
        return 0;
    }   
    cout << expresn << endl; 
    cout << "a = "; cin >> a; cout << "b = "; cin >> b; cout << "c = "; cin >> c; cout << "d = "; cin >> d;
    cout << "Result = " << eval(top, expresn, a, b, c, d) << endl;
    return 0;
}