#include<iostream>
#include<conio.h>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int main() 
{
    system("cls");
    bool order;
    int fl,f, b, d;
    int totalcost = 0;
    int innercost = 0;

    vector<string> selecteditems;
    vector<string> selectedf;
    vector<int> selectedprice;
    vector<int> selectedquan;
    vector<string> selectedsize;

    string food[5] = {"Burger", "Pizza", "Grilled fingerlings", "Makhni Handi", "Reshmi kabab Roll"};
    int prices[5] = {0, 0, 1699, 799, 699};
    int len = sizeof(food) / sizeof(food[0]);

    string bur[3] =  {"Chicken Burger", "Cheese Burger", "Hamburger"};
    int pr[3] = {949, 899, 799};
    int s = sizeof(bur) / sizeof(bur[0]); 

    string variety[3] =  {"Fajita", "Shawarma", "Tikka"};
    string sizes[3] = {"Small", "Medium", "Large"};
    int pri[3] = {599, 749, 899};
    int a = sizeof(sizes) / sizeof(sizes[0]); 

    string beverages[5] = {"Kashmiri Chai", "Cappuccino", "Cafe latte", "Orange Juice", "Espresso"};
    int price[5] = {90, 399, 549, 199, 499};
    int size = sizeof(beverages) / sizeof(beverages[0]);

    string dessert[6] = {"Cheese cake", "Fruit cake", "Pie", "Banana Split", "kheer", "Choco Lava"};
    int rate[6] = {899, 749, 499, 399, 299, 499};
    int n = sizeof(dessert) / sizeof(dessert[0]);

    while(true){
    cout<<"[Welcome to Hot'Grill]\n"<<endl;
    int op;
    menu:
    cout<<"- [MAIN MENU]\n";
    cout<<"- For (Food) press 1\n- For (Beverages) press 2\n- For (Dessert) press 3\n- Press 4 for your Bill "<<endl;
    cout<<"- ";
    cin>>op;
    cout<<endl;

    switch (op){
    case 1:

        for (int i = 0; i < len; i++) {
        cout<< i + 1 << ". " << food[i] << " - (" << prices[i] << ")\n";
        }

        choice:
        cout<<"\nEnter the number of Item, (Press 0 to go back to the menu) "<<endl;
        cin>>f;

        if (f == 1) { 
            system("cls");
            cout<<"What kind of burger you want\n"<<endl;
            for(int i = 0; i < s; i++){
                cout<< i + 1 << ". " <<bur[i] << " - (" <<pr[i] << ")\n";
            }
            cout<<"\nChoose: ";
            cin>>fl;
            char check;
            int quantity;
            do{
            cout<<"Quantity: ";
            cin>>quantity;
            cout<<"Confirm your order (Y|N): ";
            cin>>check;
            } while(check == 'n');
            selecteditems.push_back(food[f - 1]);
            selectedquan.push_back(quantity);
            selectedf.push_back(bur[fl - 1]);
            selectedprice.push_back(pr[fl - 1]); 
            cout<<endl;
            cout<<food[f-1]<<", flavour: "<<bur[fl-1] <<" - (" <<pr[fl-1] <<") x " <<quantity <<endl;
            totalcost += pr[fl - 1] * quantity;

        }else if(f == 2) {

            system("cls");
            cout<<"Flavours in Pizza\n"<<endl;
            for(int i = 0; i < a; i++){
                cout<< i + 1 << ". " << variety[i] << "\n";
            }
            cout<<"\nChoose the Flavour Number\n";
            cin>>fl;
            int size;
            cout<<"\nSize: "; 
            cout<<endl;
            for(int i = 0; i < a; i++){
                cout<< i + 1 << ". " << sizes[i] << " - (" << pri[i] << ")\n";
            }
            cout<<"\nChoose: ";
            cin>>size;
            char check;
            int quantity;
            do{
            cout<<"Quantity: ";
            cin>>quantity;
            cout<<"Confirm your order (Y|N): ";
            cin>>check;
            } while(check == 'n');
            selecteditems.push_back(food[f - 1]);
            selectedf.push_back(variety[fl - 1]);
            selectedsize.push_back(sizes[size - 1]);
            selectedquan.push_back(quantity);
            selectedprice.push_back(pri[fl - 1]); 
            cout<<endl;
            cout<<food[f-1]<<", flavour: "<<variety[fl-1] <<", Size: " <<sizes[size-1] <<" - (" <<pri[fl-1] <<") x " <<quantity <<endl;
            totalcost += pri[fl - 1] * quantity;

        }else if(f >= 1 && f <= len) {
            int quantity;
            cout<<"Quantity: ";
            cin>>quantity;
            cout<<endl;
            selecteditems.push_back(food[f - 1]);
            selectedquan.push_back(quantity);
            selectedf.push_back("-");
            selectedprice.push_back(prices[f - 1]);
            cout<<food[f-1] <<" - (" <<prices[f-1] <<") x " <<quantity <<endl;
            totalcost += prices[f - 1] * quantity;

        }else if (f == 0) {
            system("cls");
            goto menu;
        }else{
            cout<<"Invalid choice" <<endl;
        }

        char cr;
        cout<<"\nPress 'Y' if you want anything else in 'Food' / Press 'M' for the 'Main Menu' to checkout more items or to 'Generate Bill'"<<endl;
        cin>>cr;
        if (cr == 'y'){
            goto choice;
        }else if (cr == 'm'){
            system("cls");
            goto menu;
        }
        break;
     
    case 2:
        system("cls");
        cout<<"Here are the (Beverages)"<<endl<<endl;
        for (int j = 0; j < size; j++) {
            cout<<j + 1 <<" - " <<beverages[j] <<"- (" <<price[j] <<")\n";
        }

        in:
        cout<<"\nEnter the Item number, (Press 0 to go back to the menu) " <<endl;
        cin>>b;

        char check;
        int quantity;
        if (b >= 1 && b <= size){
            
            do{
            cout<<"Quantity: ";
            cin>>quantity;
            cout<<"Confirm your order (Y|N) ";
            cin>>check;
            } while (check == 'n');             
            cout<<endl;
            selecteditems.push_back(beverages[b - 1]);
            selectedf.push_back("-");
            selectedquan.push_back(quantity);
            selectedprice.push_back(price[b - 1]);
            cout<<beverages[b-1] <<" - (" <<price[b-1] <<") x " <<quantity <<endl;
            totalcost += price[b - 1] * quantity;

        } else if (b == 0){
            system("cls");
            goto menu;
        }else
        cout<<"Invalid choice";

        char ch;
        cout<<"\nPress 'Y' if you want anything else in 'Beverages' / Press 'M' for the 'Main Menu' to checkout more items or to 'Generate Bill'"<<endl;
        cin>>ch;

        if (ch == 'y'){
            goto in;
        }else if (ch == 'm'){
            system("cls");
            goto menu;
        }
        break;
        
    case 3:
        system("cls");
        cout<<"Here are the (Desserts)"<<endl<<endl;
        for (int k = 0; k < n; k++) {
            cout<<k + 1 <<" - " <<dessert[k] <<"- (" <<rate[k] <<")\n";
        }

        up:
        cout<<"\nEnter the Item number, (Press 0 to go back to the menu) "<<endl;
        cin>>d;

        if (d >= 1 && d <= n){
            char check;
            int quantity;
            do{
            cout<<"Quantity: ";
            cin>>quantity;
            cout<<"Confirm your order (Y|N): ";
            cin>>check;
            } while(check == 'n');
            cout<<endl;
            selecteditems.push_back(dessert[d - 1]);
            selectedf.push_back("-");
            selectedquan.push_back(quantity);
            selectedprice.push_back(rate[d - 1]);
            cout<<dessert[d-1] <<" - (" <<rate[d-1] <<") x " <<quantity <<endl;
            totalcost += rate[d - 1] * quantity;
        } else if (d == 0) {
            system("cls");
            goto menu;
        }else 
        cout<<"Invalid choice";

        char c;
        cout<<"\nPress 'Y' if you want anything else in 'Desserts' / Press 'M' for the 'Main Menu' to checkout more items or to 'Generate Bill'"<<endl;
        cin>>c;
        
        if (c == 'y'){
            goto up;
        } else if (c == 'm'){
            system("cls");
            goto menu;
        }
        break;

    case 4:
        system("cls");
        cout<<"- Your Bill for food\n"<<endl;
        cout<<"\tItem\t\t|\tFlavour\t\t|\tQuantity\t|\tPrice\n";
        for (int i = 0; i < selecteditems.size(); i++)
        {
            if (selectedf[i] == "-")
            {
                cout<<i + 1<< ". " <<selecteditems[i]<< "\t\t-\t\t\t"<<selectedquan[i] <<"\t\t\t"<<selectedprice[i] <<endl;
            }else
            cout<<i + 1<< ". " <<selecteditems[i]<< "\t\t\t"<<selectedf[i]<<"\t\t   "<<selectedquan[i]<< "\t\t\t"<< selectedprice[i] <<endl;
        }
        cout<<"\t\t\t\t\t\t\t\t\t\t_____";
        cout <<"\nTotal Cost: \t\t\t\t\t\t\t\t\t" << totalcost <<endl<<endl;
        cout<<"'Thankyou for the Purchase, You have a Good Day!'"<<endl<<endl;
        cout<<"Designed by Ayaan Qureshi.";
        getch();
        exit; 
        return 0;
    default:
        system("cls");
        cout<<"Unrecognized Number\nPress 'Enter' and Try Again"<<endl<<endl;
        getch();
        break;
    }
    }
    return 0;
}
