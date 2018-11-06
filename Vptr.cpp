#include<iostream.h>
using namespace std;
class Instrument{
	public:
		//Pure virtual function
		virtual void play() const=0;
		virtual char* what() const=0;
		//Assume this will modify the object
		virtual void adjust() const=0;
};

class Wind : public Instrument {
	public:
		void play() const{
			cout<<"Wind::play"<<endl;
		}
		char* what() const{return "Wind";}
		void adjust() const{}
};

class Percussion : public Instrument {
	public:
		void play() const{
			cout<<"Persussion::play"<<endl;
		}
		char* what() const{return "Percussion";}
		void adjust() const{}
};

//Identical function from before
	void tune(Instrument& i){
		i.play();}

int main(){
	Wind flute;
	Percussion drum;
	tune(flute);
	tune(drum);
}
