#include <iostream>
#include <string.h>
using namespace std;

class Book
{
    string *book_name;
    string *book_author;
    string *book_publisher;
    float *cost;
    int *copies;
    // Private data member for updated price
    int new_price;
    // Static Data Members
    static int no_of_successful_transactions;
    static int no_of_unsuccessful_transactions;

private:
    void update_price() // Updates the price for the sales
    {
        cout << "Enter the updated price per book.\n";
        cin >> new_price;
        *cost = new_price;
        cout << "The price has been updated to " << *cost << "." << endl;
    }

public:
    // Parametrized Constructor
    Book(string name, string author, string publisher, float value, int copy)
    {
        book_name = new string(name);
        book_author = new string(author);
        book_publisher = new string(publisher);
        cost = new float(value);
        copies = new int(copy);
    }
    Book()
    {
        book_name = new string;
        book_author = new string;
        book_publisher = new string;
        cost = new float;
        copies = new int;
    }

    ~Book(){};                  // Destructor
    void check_availability();  // Checks for the copies of the available books
    void buy();                 // Provides the data about the inventory changes after the copies are sold
    void display();             // Displays the complete details about that book in inventory
    int search(string, string); // Searches for the book customer wants
    int average_sales();
    void update_cost(); // Displays the average sales after a transaction
};

int Book ::no_of_successful_transactions;
int Book ::no_of_unsuccessful_transactions;

int Book::search(string aname, string bname)
{
    if (bname == *book_name && aname == *book_author)
    {
        cout << "BOOK IS AVAILABLE\n";
        no_of_successful_transactions++;
        return 1;
    }
    else
    {
        no_of_unsuccessful_transactions++;
        return 0;
    }
}
void Book::check_availability()
{
    int no_of_copies;
    cout << "Enter number of copies required.\n";
    cin >> no_of_copies;
    if (*copies >= no_of_copies)
    {
        cout << "book is available and Your bill for " << no_of_copies << " will be " << no_of_copies * (*cost) << endl;
    }
    else if (*copies < no_of_copies && cost != 0)
    {
        cout << "Required copies not in stock. There are only " << *copies << " copies available" << endl;
    }
    else
    {
        cout << "Required copies not in stock.\n";
    }
}

void Book::buy()
{
    int no_of_copies;
    cout << "Enter no. of copies required.\n";
    cin >> no_of_copies;
    if (*copies >= no_of_copies)
    {
        cout << "Your Bill is " << min(no_of_copies, *copies) * (*cost) << endl;
        cout << "Copies available before purchase: " << *copies << endl;
        *copies -= min(no_of_copies, *copies);
        cout << "Copies available after purchase: " << *copies << endl;
    }
    else
    {
        cout << "Sorry for the inconvenience. The number of copies you have asked for is not available." << endl;
    }
}
void Book::update_cost() { update_price(); }
void Book::display()
{
    cout << "---------------------" << endl;
    cout << "BOOK NAME:" << *book_name << endl;
    cout << "AUTHOR NAME:" << *book_author << endl;
    cout << "PUBLISHER NAME:" << *book_publisher << endl;
    cout << "NO. OF COPIES:" << *copies << endl;
    cout << "PRICE OF BOOK:" << *cost << endl;
    cout << "---------------------" << endl;
}

int Book::average_sales()
{
    float value;
    value = (no_of_successful_transactions) / (no_of_successful_transactions + no_of_unsuccessful_transactions);
    return value;
}

int main()
{
    Book *array[10];
    array[0] = new Book("HARRY_POTTER", "JK_ROWLING", "HOGWARTS", 999, 3);
    array[1] = new Book("A_SCANDAL_IN_BOHEMIA", "ARTHUR_DOYLE",
                        "CAMBRIDGE", 1500, 6);
    array[2] = new Book("THE_ALCHEMIST", "PAULO_COELHO", "HOWARTZ", 699,
                        1);
    array[3] = new Book("HUCKLE_BERRY", "ANDREW_HOFFMAN", "PENGUIN", 1599,
                        4);
    array[4] = new Book("INCEPTION", "CHRISTOPHER_NOLAN", "HOWARTS", 299,
                        8);
    array[5] = new Book("NEW_INDIA", "BIBEK_DEBRIK", "MACMILLAN", 180, 5);
    array[6] = new Book("MY_JOURNEY", "ASHISH_RAY", "MACMILLAN", 199, 5);
    array[7] = new Book("PRIDE_AND_PREJUDICE", "JANE_AUSTEN",
                        "HARPER_COLLINS", 160, 9);
    array[8] = new Book("2_STATES", "CHETAN_BHAGAT", "PENGUIN", 499, 6);
    array[9] = new Book("TO_KILL_A_MOCKINGBIRD", "HARPER_LEE",
                        "HARPER_COLLINS", 799, 5);
    string aname;
    string bname;
    cout << "ENTER BOOK NAME IN UPPERCASE AND USE UNDERSCORES FOR SPACES.\n";
    cin >> bname;
    cout << "ENTER BOOK AUTHOR IN UPPERCASE AND USE UNDERSCORES FOR SPACES.\n";
    cin >> aname;
    int t;
    for (t = 0; t < 10; t++)
    {
        if (array[t]->search(aname, bname))
        {
            break;
        }
        else if (t == 9)
        {
            cout << "BOOK NOT SOLD IN OUR BOOKSTORE\n";
            exit(0);
        }
    }
    int a;
    while (a != 6)
    {
        cout << "\nEnter 1 to check availability of no. of copies\n"
             << "Enter 2 to buy\n"
             << "Enter 3 to display details of the book\n"
             << "Enter 4 to get average sales\n"
             << "Enter 5 to update price\n"
             << "Enter 6 to Exit\n";
        cin >> a;
        if (a == 1)
        {
            array[t]->check_availability();
        }
        else if (a == 2)
        {
            array[t]->buy();
        }
        else if (a == 3)
        {
            array[t]->display();
        }
        else if (a == 4)
        {
            float ans = array[t]->average_sales();
            cout << "The average sales value is " << ans << "." << endl;
        }
        else if (a == 5)
        {
            array[t]->update_cost();
        }
        else if (a == 6)
        {
            break;
        }
    }
    return 0;
}
