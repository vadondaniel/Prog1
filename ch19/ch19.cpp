#include "std_lib_facilities.h"

// Compile: g++ ch19.cpp -o ch19

template<typename T>
struct S {
private:

	T val;

public:

	explicit S(T v = 0) : val{v} {}

	S& operator = (const T&);
	T& get();
	const T& get() const;
	void set(T value){val=value;}
};

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const {
	return val;
}

//"bonus thing"
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		os<<vec[i]<<" ";
	}
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& vec){
	char ch = 0;
	is>>ch;
	if(ch!='{'){
		error("Vector format invalid");
		return is;
	}
	for(T val; is>>val;){
		vec.push_back(val);
		is>>ch;
		if(ch=='}'){break;}
	}
	return is;
}

template<typename T>
void read_val(T& v){
	cin>>v;
}

int main(){

//initial values
    S<int> s_int {0};
    cout<<s_int.get()<<endl;

	S<char> s_char {'a'};
	cout<<s_char.get()<<endl;

	S<double> s_double {6.9};
	cout<<s_double.get()<<endl;

	S<string> s_string {"a string"};
	cout<<s_string.get()<<endl;

	S<vector<int>> s_vector {vector<int>{4,2,0}};
	cout<<s_vector.get()<<endl;

//custom set values
	int in;
	cout<<"Intiger: ";
	read_val(in);
	s_int.set(in);
	cout<<s_int.get()<<endl;

	char ch;
	cout<<"Caracter: ";
	read_val(ch);
	s_char.set(ch);
	cout<<s_char.get()<<endl;

	double du;
	cout<<"Double: ";
	read_val(du);
	s_double.set(du);
	cout<<s_double.get()<<endl;

	string st;
	cout<<"String: ";
	read_val(st);
	s_string.set(st);
	cout<<s_string.get()<<endl;

	vector<int> ve;
	cout<<"Vector (format: {number,number,...}): ";
	read_val(ve);
	s_vector.set(ve);
	cout<<s_vector.get()<<endl;

    return 0;
}