#include<iostream.h>

class Animal{
	public:
		virtual void eat(){
			cout<<"Animal eating...."<<endl;
		}
		virtual ~Animal(){
			cout<<"End of Animal class"<<endl;
		}
};

class Snake : public Animal{
	public:
		void eat(){
			cout<<"Snake eating...."<<endl;
	}
		~Snake(){
			cout<<"End of Snake class"<<endl;
		}
};

class Horse : public Animal{
	public:
		void eat(){
			cout<<"Horse eating...."<<endl;
	}
		~Horse(){
			cout<<"End of Horse class"<<endl;
		}
};

int main(){
	int choice;
	bool Quit = false;
	
	Animal *PtrAnimal;
	while(1){
		cout<<"1. Animal "<<"2. Viper "<<"3. Horse "<<endl<<"4. Exit"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				PtrAnimal = new Animal();
				break;
			case 2:
				PtrAnimal = new Snake();break;
			case 3: 
				PtrAnimal = new Horse();break;
			case 4:
				Quit = true;
				break;
			default:
				cout<<"Please try again"<<endl;
				continue;
			}
		if(Quit)
			break;
		PtrAnimal->eat();
		delete PtrAnimal;
		}
}
