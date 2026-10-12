#include <iostream>
#include <string>
using namespace std;

struct Donor
{
    int id;
    string name;
    int age;
    string bloodGroup;
    string phone;

    Donor* next;
    Donor* pre;
};

class DoubleLinkedList
{
private:
    Donor* head;
    Donor* tail;

public:
    DoubleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void addDonor(int id, string name, int age, string bg, string phone)
    {
        Donor* temp = new Donor();
        temp->id = id;
        temp->name = name;
        temp->age = age;
        temp->bloodGroup = bg;
        temp->phone = phone;
        temp->next = NULL;
        temp->pre = NULL;
         
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->pre = tail;
            tail = temp;
        }
    }

    void display()
    {

        for(Donor* temp = head; temp != NULL; temp = temp->next)
        {
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Blood Group: " << temp->bloodGroup << endl;
            cout << "Phone: " << temp->phone << endl;
        }
    }
};

struct Request
{
    string name;
    string bloodGroup;

    Request* next;

    Request(string n, string bg)
    {
        name = n;
        bloodGroup = bg;
        next = NULL;
    }
};

class Queue
{
public:
    Request *front;
	Request *rear;

    Queue()
    {
        front =  NULL;
        rear  =  NULL;
    }

    void enqueue(string name, string bg)
    {
        Request* temp = new Request(name, bg);

        if(front == NULL)
        {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout << "No Requests!"<<endl;
            return;
        }

        Request* temp = front;

        cout << "Processing: " << temp->name << endl;

        front = front->next;
        delete temp;

        if(front == NULL)
            rear = NULL;
    }

    void display()
    {
        Request* temp = front;

        if(front == NULL)
        {
            cout << "No Requests!"<<endl;
            return;
        }

        while(temp != NULL)
        {
            cout << "\nPatient: " << temp->name
                 << " | Blood Group: " << temp->bloodGroup<<endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

struct node
{
    int id;
    string name;

    node* left;
    node* right;
};

class tree
{
    node* root;
public:
    tree()
    {
        root = NULL;
    }

    node* insert(node* temp, int id, string n)
    {
        if(temp == NULL) {
            node* temp = new node;
            temp->id = id;
            temp->name = n;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
        
        if(id < temp->id) {
            temp->left = insert(temp->left, id, n);
        } 
        else {
            temp->right = insert(temp->right, id, n);
        }

        return temp;
    }

    node* search(node* temp, int id)
    {
        if(temp == NULL || temp->id == id)
            return temp;
        

        if(id < temp->id)
            return search(temp->left, id);

        return search(temp->right, id);
    }

    void inorder(node* temp)
    {
        if(temp != NULL)
        { 
            inorder(temp->left);
            cout << "ID: " << temp->id << " Name: " << temp->name << endl;
            inorder(temp->right);
        }
    }
    
    void insert(int id, string name)
    {
        root = insert(root, id, name);
    }

    node* search(int id)
    {
        return search(root, id);
    }

    void inorder()
    {
        inorder(root);
    }
};

int main()
{
    DoubleLinkedList donors;
    Queue q;
    tree t1;

    int choice;

    do
    {
        cout << " **BLOOD DONATION SYSTEM**"<<endl;
        cout << "1. Add Donor"<<endl;
        cout << "2. Display Donors"<<endl;
        cout << "3. Add Blood Request"<<endl;
        cout << "4. Process Request"<<endl;
        cout << "5. Display Requests"<<endl;
        cout << "6. Search Donor by ID"<<endl;
        cout << "7. Display Tree Inorder"<<endl;
        cout << "8. Exit"<<endl;

        cout << "Enter choice: "<<endl;
        cin >> choice;

        if(choice == 1)
        {
            int id, age;
            string name, bg, phone;

            cout << "Enter ID: "<<endl;
            cin >> id;

            cout << "Enter Name: "<<endl;
            cin >> name;

            cout << "Enter Age: "<<endl;
            cin >> age;

            cout << "Enter Blood Group: "<<endl;
            cin >> bg;

            cout << "Enter Phone: "<<endl;
            cin >> phone;

            donors.addDonor(id, name, age, bg, phone);
            t1.insert(id, name);

            cout << "Donor Added Successfully!"<<endl;
        }
        else if(choice == 2)
        {
            donors.display();
        }
        else if(choice == 3)
        {
            string name, bg;

            cout << "Enter Patient Name: "<<endl;
            cin >> name;

            cout << "Enter Required Blood Group: "<<endl;
            cin >> bg;

            q.enqueue(name, bg);

            cout << "Request Added!"<<endl;
        }
        else if(choice == 4)
        {
            q.dequeue();
        }
        else if(choice == 5)
        {
            q.display();
        }
        else if(choice == 6)
        {
            int id;

            cout << "Enter Donor ID: "<<endl;
            cin >> id;

            node* result = t1.search(id);

            if(result != NULL)
            {
                cout << "Donor Found"<<endl;
                cout << "ID: " << result->id << endl;
                cout << "Name: " << result->name << endl;
            }
            else
            {
                cout << "Donor Not Found!"<<endl;
            }
        }
        else if(choice == 7)
        {
            cout << "Tree"<<endl;
            t1.inorder();
        }
        else if(choice == 8)
        {
           cout << "Thank You for Using Blood Donation Management System!" << endl;
        }
        else
        {
            cout << "wrong Choice!"<<endl;
        }

    } while(choice != 8);

    return 0;
}