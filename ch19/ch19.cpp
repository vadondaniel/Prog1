#include "std_lib_facilities.h"

// Compile: g++ ch19.cpp -o ch19

template<typename T>
struct S {
private:

	T val;

public:

	explicit S(T vv = 0) : val{vv} {}

	S& operator = (const T&);
	T& get();
	const T& get() const;
	void set(T x){val=x;}
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
ostream& operator<<(ostream& os, vector<T>& v){
	for(int i=0;i<v.size();i++){
		os<<v[i]<<" ";
	}
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char c = 0;
	is>>c;
	if(c!='{'){
		error("Invalid vector format");
		return is;
	}
	for(T val; is>>val;){
		v.push_back(val);
		is>>c;
		if(c=='}'){break;}
	}
	return is;
}

template<typename T>
void read_val(T& v){
	cin>>v;
}

int main(){

    S<int> s_int {69};
	S<char> s_char {'a'};
	S<double> s_double {6.9};
	S<string> s_string {"a string"};
	S<vector<int>> s_vector {vector<int>{4,2,0}};

    cout<<s_int.get()<<endl;
	cout<<s_char.get()<<endl;
	cout<<s_double.get()<<endl;
	cout<<s_string.get()<<endl;
	cout<<s_vector.get()<<endl;

	int x;
	cout<<"Intiger: ";
	read_val(x);
	s_int.set(x);

	char y;
	cout<<"Caracter: ";
	read_val(y);
	s_char.set(y);

	double d;
	cout<<"Double: ";
	read_val(d);
	s_double.set(d);

	string s;
	cout<<"String: ";
	read_val(s);
	s_string.set(s);

	vector<int> v;
	cout<<"Vector (format: {number,number,...}): ";
	read_val(v);
	s_vector.set(v);
	

	cout<<s_int.get()<<endl;
	cout<<s_char.get()<<endl;
	cout<<s_double.get()<<endl;
	cout<<s_string.get()<<endl;
	cout<<s_vector.get()<<endl;

    return 0;
}