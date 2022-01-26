// Patrick Jirele

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct  strct {
    string type;
    string status;
    int price;
};


int main() {
    ifstream garageSale("garageSale.txt");
    strct arr[100];
    string type, str, stri;
    int x, i, sizeOfArray;
    x = 0;
    sizeOfArray = 100;
    cout << "Items sold: " << endl;

    while (getline(garageSale, str))
    {
        stringstream ss(str);
        string comma = ",";
        str.find(comma);
        stri = str.substr(0, str.find(comma));
        arr[x].type = stri;

        str = str.substr(str.find(comma) + 1);
        stri = str.substr(0, str.find(comma));
        arr[x].status = stri;


        str = str.substr(str.find(comma) + 1);
        stri = str;
        istringstream(str) >> arr[x].price;

        for (i = 0; i < x; i++) {
            if (arr[i].type == arr[x].type) {
                if (arr[x].status == "wanted" && arr[i].status == "for sale" && arr[x].price >= arr[i].price) {
                    cout << arr[x].type << " " << arr[x].price << endl;
                    for (int j = x; j <= x - 2; j++) {
                        arr[j] = arr[j + 1];
                    }
                    x--;
                    x--;

                } //wanted if
                if (arr[x].status == "for sale" && arr[i].status == "wanted" && arr[x].price <= arr[i].price) {
                    cout << arr[x].type << " " << arr[x].price << endl;
                    for (int j = x; j <= x - 2; j++) {
                        arr[j] = arr[j + 1];
                    }
                    x--;
                    x--;
                } // for sale if
            }//type if
        } //for loop
        x++;
    } //end while

    cout << endl << "Items left over: " << endl;
    for (int y = 0; y < x; y++) {
        if (arr[y].status == "for sale") {
            cout << arr[y].type << ", " << "for sale" << ", " << arr[y].price << endl;
        } // end if
        if (arr[y].status == "wanted") {
            cout << arr[y].type << ", " << "wanted" << ", " << arr[y].price << endl;
        } // end if
    } // end for
    garageSale.close();
}//end main
