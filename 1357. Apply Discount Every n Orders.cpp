// Problem 1357. Apply Discount Every n Orders
// https://leetcode.com/problems/apply-discount-every-n-orders

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Cashier {
public:
    int n;
    int discount;
    int count;
    unordered_map<int,int>tags;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        this -> count = 0;

        for(int i = 0;i<products.size();i++){
            tags[products[i]] = prices[i];
        }
    }

    bool isEligibleForDiscount(){
        return count%n == 0;
    }
    
    void applyDiscount(double &subTotal){
        subTotal = subTotal *((100.0-discount)/100);
    }
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double subTotal = 0.0;
        for(int i = 0;i<product.size();i++){
            int productId = product[i];
            subTotal += amount[i]*tags[productId];
        }

        if(isEligibleForDiscount()){
            applyDiscount(subTotal);
        }

        return subTotal;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */

int main(){
    int n = 3;
    int discount = 50;
    vector<int>products = {1,2,3,4,5,6,7};
    vector<int>prices = {100,200,300,400,300,200,100};

    vector<vector<vector<int>>>customers = {
        {{1,2},{1,2}},
        {{3,7},{10,10}},
        {{1,2,3,4,5,6,7},{1,1,1,1,1,1,1}},
        {{4},{10}},{{7,3},{10,10}},
        {{7,5,3,1,6,4,2},{10,10,10,9,9,9,7}},
        {{2,3,5},{5,3,2}}
    };
    // {{productId},{quantity}}

    Cashier* obj = new Cashier(n,discount,products,prices);
    for(int i = 0;i<customers.size();i++){
        double bill = obj->getBill(customers[i][0],customers[i][1]);
        cout<<bill<<endl;
    }

    return 0;

}
