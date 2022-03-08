#include "std_lib_facilities.h"

// Compile: g++ ch15_2.cpp -o ch15_2

struct Person{
private:
	string pfname;
    string plname;
	int page;
public:
	Person(){}
	Person(string fn, string ln, int aa);	
	
	string fname() const {return pfname;}
    string lname() const {return plname;}
	int age() const {return page;}
};

Person::Person(string fn, string ln, int aa):pfname(fn),plname(ln),page(aa){
	if(aa<0 || aa>150){
        error("Invalid Age.");
        }
	for(char c:fn){
		if(c==';' || c==':' || c=='"' || c=='[' || c==']' || c=='*' || c=='&' || c=='^' || c=='%' || c=='$' || c=='#' || c=='@' || c=='!'){
			error("Invalid name.");
		}
	}
    if (stoi(ln) > 0)
    {
        error("Last name not provided");
    }
}

ostream& operator<<(ostream& os, Person p){
	os << "Name: " << p.fname() << " " << p.lname() << " age: " << p.age() << endl;
	return os;
}

istream& operator>>(istream& is, Person& p){
	string fn;
    string ln;
	int aa;
	is >> fn >> ln >> aa;
	p = Person(fn, ln, aa);
	return is;
}

int main() {

    Person initial("Goofy", "", 63);
	cout << initial;

    Person a_person;
	cin >> a_person;
	cout << a_person;

    vector<Person> vector;
	for(Person p; cin >> p;){
		if(p.fname() == "end"){
            break;
            }
		vector.push_back(p);
	}
	for(Person p:vector){
		cout << p;
	}

    return 0;
}