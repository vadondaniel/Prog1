#include "std_lib_facilities.h"
// Compile: g++ ch21.cpp -o ch21

struct Item {
    string name;
    int iid;
    double value;
};
bool CompareName(Item a, Item b){
    if(a.name < b.name)
		return 1;
	else 
	    return 0;
}
bool CompareIid(Item a, Item b){
    if(a.iid < b.iid)
		return 1;
	else 
	    return 0;
}
bool CompareValueDesc(Item a, Item b){
    if(a.value > b.value)
		return 1;
	else 
	    return 0;
}
void itemvec_push(vector<Item>& vec, string name, int iid, double value){
    Item asd;
    asd.name = name;
    asd.iid = iid;
    asd.value = value;
    vec.push_back(asd);
}

int main(){
    struct vector<Item> vi;
    ifstream i_s("file.txt");
    string name;
    int iid;
    double value;
    while(!i_s.eof())
    {
        Item asd;
        i_s >> asd.name >> asd.iid >> asd.value;
        vi.push_back(asd);
    }
    sort(vi.begin(), vi.end(), CompareName);
    for (size_t i = 0; i < vi.size(); i++)
    {
        //if (i == 0)cout << "  sorted by name\n";
        //cout << vi[i].name << "\t" << vi[i].iid << "\t" <<  vi[i].value << endl;
    }
    sort(vi.begin(), vi.end(), CompareIid);
    
    for (size_t i = 0; i < vi.size(); i++)
    {
        //if (i == 0)cout << "  sorted by iid\n";
        //cout << vi[i].name << "\t" << vi[i].iid << "\t" <<  vi[i].value << endl;
    }
    sort(vi.begin(), vi.end(), CompareValueDesc);
    for (size_t i = 0; i < vi.size(); i++)
    {
        //if (i == 0)cout << "  sorted by descending value\n";
        //cout << vi[i].name << "\t" << vi[i].iid << "\t" <<  vi[i].value << endl;
    }
    itemvec_push(vi, "horse shoe", 99, 12.34);
    itemvec_push(vi, "Canon S400", 9988, 499.95);
    sort(vi.begin(), vi.end(), CompareValueDesc);
    for (size_t i = 0; i < vi.size(); i++)
    {
        cout << vi[i].name << "\t" << vi[i].iid << "\t" <<  vi[i].value << endl;
    }
    for (size_t i = 0; i < vi.size(); i++)
    {
        if (vi[i].name == "GT-S5230") vi.erase(vi.begin() + i);
    }
    for (size_t i = 0; i < vi.size(); i++)
    {
        if (vi[i].name == "Galaxy-A3") vi.erase(vi.begin() + i);
    }
    for (size_t i = 0; i < vi.size(); i++)
    {
        if (vi[i].iid == 1) vi.erase(vi.begin() + i);
    }
    for (size_t i = 0; i < vi.size(); i++)
    {
        if (vi[i].iid == 5) vi.erase(vi.begin() + i);
    }
    for (size_t i = 0; i < vi.size(); i++)
    {
        cout << vi[i].name << "\t" << vi[i].iid << "\t" <<  vi[i].value << endl;
    }
    
    

    return 0;
}