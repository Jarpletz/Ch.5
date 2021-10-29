
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class item {
public:
    string itemName;
    float price;
    string note;
    item(string, float, string);
};
item::item(string iName, float pr, string n) {
    itemName = iName;
    price = pr;
    note = n;
}
ofstream fout;
void printReceipt( string, float,float,float);

int main()
{

    fout.open("Receipt.txt");
    bool done = false;
    string house;
    float shoeSize;
    float shoePrice;
    float amoutPaid;
    float change;

    item items[] = { item("House Tie",15,""),item("Socks",5,""),item("Shoes",30," + $5/size for sizes over 9"),item("Belt",10,"")};

    cout << left << fixed << setprecision(2) << showpoint;

    

    cout << "Uniform Vending Machine" << endl << endl;


    while (!done) {
        cout << "New Vend" << endl;

        cout << "ID   Name         Price" << endl;
        for (int i = 0;i < 4;i++) {
            cout <<setfill('.')<< setw(5) << i+1 << setw(13) << items[i].itemName << "$" << items[i].price << items[i].note << endl;
        }

        MARKER1:cout << endl << "What Would you like to buy?" << endl;
        cout << "Item ID:";
        int id;
        cin >> id;

        cout<<"Vending ID "<<id<<": "+items[id-1].itemName << "--  $" << items[id - 1].price << items[id - 1].note << endl;
        switch (id)
        {
        case 1:
            cout << "House Name:";
            cin >> house;
            do {
                cout << "Amout Due: $" << items[id - 1].price << endl << "Amout Paid: $";
                cin >> amoutPaid;
                change = amoutPaid - items[id - 1].price;
                if (change < 0)
                    cout << "Not enough paid! Please Insert at least $" << items[id - 1].price << "." << endl;
            } while (change < 0);
            printReceipt( "House of " + house + " Tie", amoutPaid,change,15);
            
            break;
        case 2:
            do {
                cout << "Amout Due: $" << items[id-1].price<< endl << "Amout Paid: $";
                cin >> amoutPaid;
                change = amoutPaid - items[id - 1].price;
                if (change < 0)
                    cout << "Not enough paid! Please Insert at least $" << items[id - 1].price << "." << endl;
            } while (change < 0);
            printReceipt("Uniform Socks", amoutPaid, change,5);
            break;
        case 3:
            cout << "Shoe Size:";
            cin >> shoeSize;
            if (shoeSize > 12)shoeSize = 12;
            shoePrice = 30;
            if (shoeSize > 9) {
                shoePrice += 5 * (shoeSize - 9);
            }
            do {
                cout << "Amout Due: $"<<shoePrice << endl << "Amout Paid: $";
                cin >> amoutPaid;
                change = amoutPaid - shoePrice;
                if (change < 0)
                    cout << "Not enough paid! Please Insert at least $" << items[id - 1].price+shoePrice << "." << endl;
            } while (change < 0);
            printReceipt("Uniform Shoes", amoutPaid, change,shoePrice);
            break;
        case 4:
            do {
                cout << "Amout Due: $" << items[id - 1].price << endl << "Amout Paid: $";
                cin >> amoutPaid;
                change = amoutPaid - items[id - 1].price;
                if (change < 0)
                    cout << "Not enough paid! Please Insert at least $" << items[id - 1].price << "." << endl;
            } while (change < 0);
            printReceipt("Uniform Belt", amoutPaid, change,10);
            break;
        default:
            cout << "ERROR: INVALID VENDING ID!" << endl;
            goto MARKER1;
            break;
        }

        cout << " Would you Like to purchase another item? (Y/N):";
        char yn;
        cin >> yn;
        if (yn != 'Y' &&yn!='y') {
            done = true;
        }

    }
    cout << "Thank You for Shopping with us!" << endl;
    fout << "Thank You for Shopping with us!" << endl;
    fout.close();

    return 0;
}
void printReceipt( string itemName, float paid,float change,float cost) {
    cout <<endl<< "Receipt:" << endl;
    cout << left << fixed << setprecision(2) << showpoint;
    cout << setfill('.') << setw(20) << "Item Name:" << itemName << endl;
    cout << setfill('.') << setw(20)  << "Item Cost:" << "$"<<cost << endl;
    cout << setfill('.') << setw(20) << "Amount Recieved:"<< "$"<< paid << endl;
    cout <<setfill('.') << setw(20) << "Change Returned:" << "$" << change << endl;

    fout << endl << "Receipt:" << endl;
    fout << left << fixed << setprecision(2) << showpoint;
    fout << setfill('.') << setw(20) << "Item Name:" << itemName << endl;
    fout << setfill('.') << setw(20)  << "Item Cost:" << "$" << cost << endl;
    fout << setfill('.') << setw(20)  << "Amount Recieved:" << "$"<< paid << endl;
    fout << setfill('.') << setw(20) << "Change Returned:" << "$" << change << endl;

}
