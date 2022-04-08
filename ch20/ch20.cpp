#include "std_lib_facilities.h"
// Compile: g++ ch20.cpp -o ch20

template<typename A>
void print(const A& a){
	for(auto& aut : a){
		cout << aut << " ";
	}
	cout<<"\n";
}

template<typename A>
void inc(A& a, int n){
	for(auto& aut : a){
		aut=aut+n;
	}
}

template<typename I1, typename I2>
I2 Icopy(I1 f1, I1 e1, I2 f2){
	for(I1 i=f1; i!=e1; i++){
		*f2++ = *i;
	}
	return f2;
}

int main(){

	int arrey[10]{0,1,2,3,4,5,6,7,8,9};
	cout<<"int array: ";
	print(arrey);

	vector<int> vec(10);
	copy(arrey, arrey+10, vec.begin());
	cout<<"vector: ";
	print(vec);

	list<int> l(10);
	copy(arrey, arrey+10, l.begin());
	cout<<"list: ";
	print(l);

	array<int, 10> arr;
	copy(arrey, arrey+10, arr.begin());
	cout<<"array: ";
	print(arr);

	array<int, 10> arr2=arr;
	cout<<"array2: ";
	print(arr2);
	vector<int> vec2=vec;
	cout<<"vector2: ";
	print(vec2);
	list<int> l2=l;
	cout<<"list2: ";
	print(l2);
	
	inc(arr2, 2);
	cout<<"inc. array: ";
	print(arr2);	
	inc(vec2, 3);
	cout<<"inc. vector: ";
	print(vec2);	
	inc(l2, 5);
	cout<<"inc. list: ";
	print(l2);	

	Icopy(arr2.begin(), arr2.end(), vec2.begin());
	Icopy(l2.begin(), l2.end(), arr2.begin());
	cout<<"copy array: ";
	print(arr2);
	cout<<"copy vector: ";
	print(vec2);
	cout<<"copy list: ";
	print(l2);

	vector<int>::iterator it;
	it=find(vec2.begin(),vec2.end(),3);
	if(it != vec2.end()){
		cout<<"Found at pos. "<<distance(vec2.begin(),it)<<endl;
	}
	else cout<<"Not found."<<endl;

	list<int>::iterator lit;
	lit=find(l2.begin(),l2.end(),27);
	if(lit!=l2.end()){
		cout<<"Found at pos. "<<distance(l2.begin(),lit)<<endl;
	}
	else cout<<"Not found."<<endl;

	return 0;
}