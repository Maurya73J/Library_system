#include <bits/stdc++.h>
using namespace std;
class user
{
public:
    string username;
    int id;
    string password;
    int type;
};

class books
{
public:
    int isbn;
    string name;
    string author;
    string publication;
    int avail;
    int booker;
    int issuedate;
};

class booksdata
{
public:
    vector<books> booksdatabase;
    void displayall()
    {
        for (auto &x : this->booksdatabase)
        {
            if (x.booker != 0)
            {
                cout << "\nName:" << x.name;
                cout << "\nAuthor:" << x.author;
                cout << "\nISBN:" << x.isbn;
                cout << "\nPublication:" << x.publication;
                cout << "\nAvailability(0 means no/ 1 means yes):" << x.avail;
                cout << "\nBooker's ID:" << x.booker;
                cout << "\nIsuue Date:" << x.issuedate;
                cout << "\n\n";
            }
        }
    }
    void displayallavail()
    {
        for (auto &x : this->booksdatabase)
        {
            if (x.avail && x.booker != 0)
            {
                cout << "\nName:" << x.name;
                cout << "\nAuthor:" << x.author;
                cout << "\nISBN:" << x.isbn;
                cout << "\nPublication:" << x.publication;
                cout << "\n\n";
            }
        }
    }
    int checkfine(user ouruser, int dt)
    {
        int fine = 0;
        for (auto &x : this->booksdatabase)
        {
            if (x.booker == ouruser.id)
            {
                if (ouruser.type == 1)
                {
                    if ((dt - x.issuedate - 60) >= 0)
                    {
                        fine += (dt - x.issuedate - 60) * 5;
                    }
                }
                else if (ouruser.type == 2)
                {
                    if ((dt - x.issuedate - 30) >= 0)
                    {
                        fine += (dt - x.issuedate - 30) * 2;
                    }
                }
            }
        }
        return fine;
        cout << "\nInvalid user";
    }

    void add(books newbook)
    {
        cout << "\nEnter the book name:";
        cin >> newbook.name;
        cout << "\nEnter the author's name:";
        cin >> newbook.author;
        cout << "\nEnter the ISBN:";
        cin >> newbook.isbn;
        cout << "\nEnter the Publication:";
        cin >> newbook.publication;
        cout << "\nEnter the availability(1/0):";
        cin >> newbook.avail;
        if (newbook.avail == 0)
        {
            cout << "\nEnter the booker's id:";
            cin >> newbook.booker;
            cout << "\nEnter the issue date:";
            cin >> newbook.issuedate;
        }
        else
        {
            newbook.booker = 100000;
            newbook.issuedate = 100000;
        }

        this->booksdatabase.push_back(newbook);
    }
    books search(books thbook)
    {
        int f = 0;
        for (auto &x : this->booksdatabase)
        {
            if (x.name == thbook.name)
            {
                f = 1;
                return x;
            }
        }
        if (f == 0)
        {
            books zero;
            zero.isbn = 0;
            return zero;
        }
    }
    void issue(books ibook, user isuser, int dat)
    {
        for (auto &x : this->booksdatabase)
        {
            if (x.name == ibook.name && x.avail == 1)
            {
                x.booker = isuser.id;
                x.issuedate = dat;
                x.avail = 0;
                return;
            }
        }
        cout << "\nBook not available";
    }
    void listuserbook(user thuser)
    {

        for (auto &x : this->booksdatabase)
        {
            if (x.booker == thuser.id)
            {
                cout << "\nName:" << x.name;
                cout << "\nAuthor:" << x.author;
                cout << "\nISBN:" << x.isbn;
                cout << "\nPublication:" << x.publication;
                cout << "\nIssue date:" << x.issuedate;
                cout << "\n\n";
            }
        }
    }
    void delet(books ourbook)
    {
        for (auto &x : this->booksdatabase)
        {
            if (x.name == ourbook.name || x.isbn == ourbook.isbn)
            {
                x.name = "";
                x.isbn = 0;
                x.publication = "";
                x.author = "";
                x.avail = 0;
                x.booker = 0;
                x.issuedate = 100000;
                return;
            }
        }
        cout << "\nBook not found\nPlease try again";
    }
    void clearfine(user thuser, int dt)
    {
        int finety = 0;
        for (auto &x : this->booksdatabase)
        {
            if (x.booker == thuser.id)
            {
                x.issuedate = 100000;
                x.avail = 1;
                x.booker = 100000;
            }
        }
    }
    void update(books ourbook)
    {
        for (auto &x : this->booksdatabase)
        {
            if (x.name == ourbook.name)
            {
                string n, i, p, a, av, bi, d;
                cout << "\nWant to change name?(y/n):";
                cin >> n;
                if (n == "y")
                {
                    cout << "\nEnter changed name:";
                    cin >> x.name;
                }
                cout << "\nWant to change ISBN?(y/n):";
                cin >> i;
                if (i == "y")
                {
                    cout << "\nEnter changed ISBN:";
                    cin >> x.isbn;
                }
                cout << "\nWant to change author?(y/n):";
                cin >> a;
                if (a == "y")
                {
                    cout << "\nEnter changed author:";
                    cin >> x.author;
                }
                cout << "\nWant to change publication?(y/n):";
                cin >> p;
                if (p == "y")
                {
                    cout << "\nEnter changed type:";
                    cin >> x.publication;
                }
                cout << "\nWant to change availability?(y/n):";
                cin >> av;
                if (av == "y")
                {
                    cout << "\nEnter changed availability:";
                    cin >> x.avail;
                }
                cout << "\nWant to change booker's id?(y/n):";
                cin >> bi;
                if (bi == "y")
                {
                    cout << "\nEnter changed book's id:";
                    cin >> x.booker;
                }
                cout << "\nWant to change issue date?(y/n):";
                cin >> d;
                if (d == "y")
                {
                    cout << "\nEnter changed issue date:";
                    cin >> x.booker;
                }
                return;
            }
        }
        cout << "\nUser not found\nPlease try again";
    }
};

class userdata
{
public:
    vector<user> userdatabase;
    void displayall()
    {
        for (auto &x : this->userdatabase)
        {
            if(x.id!=0){
            cout << "\nName:" << x.username;
            cout << "\nid:" << x.id;
            cout << "\nUsertype:" << x.type;
            cout << "\nPassword:" << x.password << "\n\n";
        }}
    }
    void add(user newuser)
    {
        cout << "\nEnter the username:";
        cin >> newuser.username;
        cout << "\nEnter the id:";
        cin >> newuser.id;
        cout << "\nEnter the user type:";
        cin >> newuser.type;
        cout << "\nEnter the password:";
        cin >> newuser.password;
        this->userdatabase.push_back(newuser);
    }
    user search(user ouruser, int t)
    {
        int f = 0;
        for (auto &x : this->userdatabase)
        {
            if (x.username == ouruser.username && (t + (x.password == ouruser.password)) && x.id!=0)
            {
                f = 1;
                return x;
            }
        }
        if (f == 0)
        {
            user zero;
            zero.type = 0;
            return zero;
        }
    }
    void delet(user ouruser)
    {
        for (auto &x : this->userdatabase)
        {
            if (x.username == ouruser.username && x.id != 0)
            {
                x.username = "";
                x.id = 0;
                x.type = 0;
                x.password = "";
                return;
            }
        }
        cout << "\nUser not found\nPlease try again";
    }
    void update(user ouruser)
    {
        for (auto &x : this->userdatabase)
        {
            if (x.username == ouruser.username)
            {
                string u, i, p, t;
                cout << "\nWant to change username?(y/n):";
                cin >> u;
                if (u == "y")
                {
                    cout << "\nEnter changed username:";
                    cin >> x.username;
                }
                cout << "\nWant to change id?(y/n):";
                cin >> i;
                if (i == "y")
                {
                    cout << "\nEnter changed id:";
                    cin >> x.id;
                }
                cout << "\nWant to change password?(y/n):";
                cin >> p;
                if (p == "y")
                {
                    cout << "\nEnter changed password:";
                    cin >> x.password;
                }
                cout << "\nWant to change type?(y/n):";
                cin >> t;
                if (t == "y")
                {
                    cout << "\nEnter changed type:";
                    cin >> x.type;
                }
                return;
            }
        }
        cout << "\nUser not found\nPlease try again";
    }
};

class professor : public user, public userdata
{
public:
    double fine_amount;
    vector<books> list_of_books;
    double checkpfine(user thuser, booksdata data, int dt)
    {
        double fine = 0;
        for (auto &x : data.booksdatabase)
        {
            if (x.booker == thuser.id)
            {
                if (dt - x.issuedate - 60 > 0)
                {
                    fine += (dt - x.issuedate - 60) * 5;
                }
            }
        }
        return fine;
    }
};

class student : public user, public userdata
{
public:
    double fine_amount;
    vector<books> list_of_books;
    double checksfine(user thuser, booksdata data, int dt)
    {
        double fine = 0;
        for (auto &x : data.booksdatabase)
        {
            if (x.booker == thuser.id)
            {
                if (dt - x.issuedate - 30 > 0)
                {
                    fine += (dt - x.issuedate - 30) * 2;
                }
            }
        }
        return fine;
    }
};

class librarian : public user, public userdata
{
};