#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

// bool compareisbn(const class Sales_data& data1, const class Sales_data& data2);

class Sales_data{
public:
    string isbn() const {return bookNO;}
    Sales_data(string str);
private:
    string bookNO;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


bool compareisbn(const Sales_data &data1,const Sales_data &data2){
    return data1.isbn() < data2.isbn();
}

int main(){
    string str1 = "abc";
    string str2 = "def";
    Sales_data data1 = Sales_data(str1);
    Sales_data data2 = Sales_data(str2);
    vector<Sales_data> vec = {data1 ,data2};
    stable_sort(vec.begin(), vec.end(), compareisbn);
    for(auto i :vec){
        cout << i.isbn() << " ";
    }

}


Sales_data::Sales_data(string str){
    bookNO = str;
}

