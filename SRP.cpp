#include<iostream>
#include<vector>
using namespace std;

class Product{
    public:
    string name;
    double price;
    Product(string name,double price) {
        this->price=price;
        this->name=name;
    }
};


class ShopingCart{

    private:
    vector<Product*>products;

    public:
    void add_to_cart(Product* item){
       products.push_back(item);
    }

    vector<Product*>get_products(){
        return products;
    }
   

};

class Cart_invoice{

    private:
    ShopingCart* sc;
    public:
    Cart_invoice( ShopingCart* sc){
       this->sc=sc;
    }
    void print_invoice(){
      for(auto it: sc->get_products()){
        cout<<it->name<<" rs "<<it->price<<endl;
      }
    }

};

int main(){

    ShopingCart* shoping_cart=new ShopingCart();

    shoping_cart->add_to_cart(new Product("shoes" , 4000));
    shoping_cart->add_to_cart(new Product("bag" , 1000));

    Cart_invoice* invoice = new Cart_invoice(shoping_cart);
    invoice->print_invoice();


    return 0;
}