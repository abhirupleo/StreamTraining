#include<iostream.h>
#include<iomanip.h>

class Sales{
	public:
		double computeSales(double price){
			double sales;
			sales = price;
			return sales;
		}
		double computeSales(double price,int qty){
			double sales;
			sales = price*qty;
			return sales;
		}
		double computeSales(double price,int qty, double discount){
			double sales;
			sales = price*qty - discount;
			return sales;
		}
};

int main(){
	Sales *s = new Sales();
	std::cout<<std::fixed;
	std::cout<<std::setprecision(2);
	std::cout<< s->computeSales(100)<<endl;
	std::cout<< s->computeSales(100,2)<<endl;
	std::cout<< s->computeSales(100,2,30)<<endl;
	delete s;
}
