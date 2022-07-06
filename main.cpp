#include <bits/stdc++.h>
using namespace std;

#include "classes.cpp"

int main()
{
    system("clear");
    int currentdate = 0;
    user ouruser;
    userdata userbase;
    user xu, yu, zu, au, bu;
    xu.username = "admin";
    xu.password = "admin";
    xu.id = 1;
    xu.type = 3;
    userbase.userdatabase.push_back(xu);
    yu.username = "1234";
    yu.password = "1234";
    yu.id = 2;
    yu.type = 3;
    userbase.userdatabase.push_back(yu);
    zu.username = "prof";
    zu.password = "prof";
    zu.id = 3;
    zu.type = 1;
    userbase.userdatabase.push_back(zu);
    au.username = "stud";
    au.password = "stud";
    au.id = 4;
    au.type = 2;
    userbase.userdatabase.push_back(au);
    bu.username = "lib";
    bu.password = "lib";
    bu.id = 5;
    bu.type = 3;
    userbase.userdatabase.push_back(bu);

    books tbook;
    booksdata bookbase;

    books x, y, z, a, b;
    x.name = "Harrypotter";
    x.author = "JK Rowling";
    x.avail = 1;
    x.isbn = 1;
    x.booker = 100000;
    x.publication = "penguin";
    x.issuedate = 100000;
    bookbase.booksdatabase.push_back(x);
    y.name = "Peak";
    y.author = "Thomas";
    y.avail = 0;
    y.isbn = 2;
    y.booker = 3;
    y.publication = "galaxy books";
    y.issuedate = 10;
    bookbase.booksdatabase.push_back(y);
    z.name = "Theriver";
    z.author = "Sim Johns";
    z.avail = 1;
    z.isbn = 3;
    z.booker = 100000;
    z.issuedate = 100000;
    z.publication = "Hill books";
    bookbase.booksdatabase.push_back(z);
    a.name = "Planetearth";
    a.author = "RD Downey";
    a.avail = 0;
    a.isbn = 4;
    a.booker = 4;
    a.publication = "Rock water firm";
    a.issuedate = 10;
    bookbase.booksdatabase.push_back(a);
    b.name = "Oceansdrives";
    b.author = "Tupic Reynolds";
    b.avail = 0;
    b.isbn = 5;
    b.booker = 3;
    b.publication = "mongovier books";
    b.issuedate = 5;
    bookbase.booksdatabase.push_back(b);

    for (;;)
    {
        cout << "LIBRARY SOFTWARE"
         << "\n\n";
        cout << "Enter username:";
        cin >> ouruser.username;
        cout << "Enter password:";
        cin >> ouruser.password;
        user userour;
        int usertype;
        userour = userbase.search(ouruser, 0);
        usertype = userour.type;
    start:
        
        cout << "Current date:" << currentdate;
        if (usertype == 0)
        {
            cout << "\n\nInvaild username or password\nPlease Try again\n\n";
            continue;
        }
        else if (usertype == 1)
        {
            professor prof;
            int command;
            cout << "\nenter 1: To see list of all books \nenter 2: To see list of your books\nenter 3: diaplay all available books\nenter 4: To check your fine\nenter 5: To search book\nenter 6: To issue the book\nenter 0: To exit\n\n";
            cin >> command;
            system("clear");
            if (command == 1)
            {
                bookbase.displayall();
                goto start;
            }
            else if (command == 2)
            {
                bookbase.listuserbook(userour);
                goto start;
            }
            else if (command == 3)
            {
                bookbase.displayallavail();
                goto start;
            }
            else if (command == 4)
            {
                int fint;
                fint = bookbase.checkfine(userour, currentdate);
                cout << "\nThe user's fine is: ₹" << fint << "\n";
                goto start;
            }
            else if (command == 5)
            {
                books ebook, r;
                cout << "Enter name of the book:";
                cin >> ebook.name;
                r = bookbase.search(ebook);
                if (r.isbn)
                {
                    cout << "\nName:";
                    cout << r.name << "\n";
                    cout << "ISBN:" << r.isbn << "\n";
                    cout << "Publication:" << r.publication << "\n";
                    cout << "Author:" << r.author << "\n";
                    cout << "Availibility:" << r.avail << "\n";
                }
                else
                {
                    cout << "\nBook not found\n";
                }
                goto start;
            }
            else if (command == 6)
            {
                books ibook, r;
                cout << "Enter name of the book:";
                cin >> ibook.name;
                r = bookbase.search(ibook);
                bookbase.issue(r, userour, currentdate);
                goto start;
            }
            else if (command == 0)
            {
                continue;
            }
            else
            {
                cout << "Invalid command entered\nPlease try again\n";
                goto start;
            }
        }
        else if (usertype == 2)
        {
            student stud;
            int command;
            cout << "\nenter 1: To see list of all books \nenter 2: To see list of your books\nenter 3: diaplay all available books\nenter 4: To check your fine\nenter 5: To search book\nenter 6: To issue the book\nenter 0: To exit\n\n";
            cin >> command;
            system("clear");
            if (command == 1)
            {
                bookbase.displayall();
                goto start;
            }
            else if (command == 2)
            {
                bookbase.listuserbook(userour);
                goto start;
            }
            else if (command == 3)
            {
                bookbase.displayallavail();
                goto start;
            }
            else if (command == 4)
            {
                int fint;
                fint = bookbase.checkfine(userour, currentdate);
                cout << "\nThe user's fine is: ₹" << fint << "\n";
                goto start;
            }
            else if (command == 5)
            {
                books ebook, r;
                cout << "Enter name of the book:";
                cin >> ebook.name;
                r = bookbase.search(ebook);
                if (r.isbn)
                {
                    cout << "\nName:";
                    cout << r.name << "\n";
                    cout << "ISBN:" << r.isbn << "\n";
                    cout << "Publication:" << r.publication << "\n";
                    cout << "Author:" << r.author << "\n";
                    cout << "Availibility:" << r.avail << "\n";
                }
                else
                {
                    cout << "\nBook not found\n";
                }
                goto start;
            }
            else if (command == 6)
            {
                books ibook, r;
                cout << "Enter name of the book:";
                cin >> ibook.name;
                r = bookbase.search(ibook);
                bookbase.issue(r, userour, currentdate);
                goto start;
            }
            else if (command == 0)
            {
                continue;
            }
            else
            {
                cout << "Invalid command entered\nPlease try again\n";
                goto start;
            }
        }
        else if (usertype == 3)
        {
            librarian libr;
            int command;
            cout << "\nenter 1: To see list of all books\nenter 2: To edit user database\nenter 3: To edit book database\nenter 4: To display all users\nenter 5: To see the list of books of a user\nenter 6: To change current date\nenter 7: To check user's fine\nenter 8: To clear user's fine\nenter 0: To exit\n\n";
            cin >> command;
            system("clear");
            if (command == 1)
            {
                bookbase.displayall();
                goto start;
            }
            else if (command == 2)
            {
            start2:
                
                cout << "\nenter 1: To add user\nenter 2: To update user\nenter 3: To delete user\nenter 4: To search the user\nenter 0: To exit\n\n";
                int comd;
                cin >> comd;
                system("clear");
                if (comd == 1)
                {
                    cout << "\nAdd User";
                    user newuse;
                    userbase.add(newuse);
                    goto start2;
                }
                else if (comd == 2)
                {
                    cout << "\nUpadate User";
                    user upuser;
                    cout << "\nEnter username of the user:";
                    cin >> upuser.username;
                    userbase.update(upuser);
                    goto start2;
                }
                else if (comd == 3)
                {
                    cout << "\nDelete User";
                    user deuser;
                    cout << "\nEnter username of the user:";
                    cin >> deuser.username;
                    userbase.delet(deuser);
                    goto start2;
                }
                else if (comd == 4)
                {
                    cout << "\nSearch User";
                    int t;
                    user seuser, r;
                    cout << "\nEnter username of the user:";
                    cin >> seuser.username;
                    r = userbase.search(seuser, 1);
                    if (r.type)
                    {
                        cout << "\nUsername:";
                        cout << r.username << "\n";
                        cout << "ID:" << r.id << "\n";
                        cout << "Password:" << r.password << "\n";
                        cout << "Type:" << r.type << "\n";
                    }
                    else
                    {
                        cout << "\nUser not found\n";
                    }
                    goto start2;
                }
                else if (comd == 0)
                {
                    goto start;
                }
                else
                {
                    cout << "Invalid command entered\nPlease try again\n";
                    goto start2;
                }
            }
            else if (command == 3)
            {
            start3:
                
                cout << "\nenter 1: To add book\nenter 2: To update book\nenter 3: To delete book\nenter 4: To search the book\nenter 0: To exit\n\n";
                int comd;
                cin >> comd;
                system("clear");
                if (comd == 1)
                {
                    cout << "\nAdd Book";
                    books newbook;
                    bookbase.add(newbook);
                    goto start3;
                }
                else if (comd == 2)
                {
                    cout << "\nUpadate Book";
                    books upbook;
                    cout << "\nEnter name of the book:";
                    cin >> upbook.name;
                    bookbase.update(upbook);
                    goto start3;
                }
                else if (comd == 3)
                {
                    cout << "\nDelete Book";
                    books debook;
                    cout << "\nEnter name of the book:";
                    cin >> debook.name;
                    bookbase.delet(debook);
                    goto start3;
                }
                else if (comd == 4)
                {
                    cout << "\nSearch Book";
                    books sebook, r;
                    cout << "\nEnter name of the book:";
                    cin >> sebook.name;
                    r = bookbase.search(sebook);
                    if (r.isbn)
                    {
                        cout << "\nName:";
                        cout << r.name << "\n";
                        cout << "ISBN:" << r.isbn << "\n";
                        cout << "Publication:" << r.publication << "\n";
                        cout << "Author:" << r.author << "\n";
                        cout << "Availibility:" << r.avail << "\n";
                        cout << "Booker's id:" << r.booker << "\n";
                        cout << "Issue date:" << r.issuedate << "\n";
                    }
                    else
                    {
                        cout << "\nBook not found\n";
                    }
                    goto start3;
                }
                else if (comd == 0)
                {
                    goto start;
                }
                else
                {
                    cout << "\nInvalid command entered\nPlease try again\n";
                    goto start3;
                }
            }
            else if (command == 4)
            {
                userbase.displayall();
                goto start;
            }
            else if (command == 5)
            {
                user luser, rs;
                cout << "\nEnter username of the user:";
                cin >> luser.username;
                rs = userbase.search(luser, 1);
                bookbase.listuserbook(rs);
                goto start;
            }
            else if (command == 6)
            {
                int dt;
                cout << "\nIncrease current date by:";
                cin >> dt;
                currentdate += dt;
                goto start;
            }
            else if (command == 7)
            {
                int fint;
                user suser, rs;
                cout << "\nEnter username of the user:";
                cin >> suser.username;
                rs = userbase.search(suser, 1);
                fint = bookbase.checkfine(rs, currentdate);
                cout << "\nThe user's fine is: ₹" << fint << "\n";
                goto start;
            }
            else if (command == 8)
            {
                user fuser, rt;
                cout << "\nEnter username of the user:";
                cin >> fuser.username;
                rt = userbase.search(fuser, 1);
                bookbase.clearfine(rt, currentdate);
                goto start;
            }
            else if (command == 0)
            {
                continue;
            }
            else
            {
                cout << "Invalid command entered\nPlease try again\n";
                goto start;
            }
        }
        return 0;
    }
}