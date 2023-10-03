#include <set>
#include <iostream>
using namespace std;

void print(std::set<float> arbolRN){
    for(float a: arbolRN){
        cout << a << "\t";
    }
    cout<<endl;
}
int main(){

    std::set<float> arbolRN;
    float nums [] = {11,6,2,4,5,12,14,17};

    for(float a: nums){
        arbolRN.insert(a);
    }

    float i = 11;
    arbolRN.erase(i);
    print(arbolRN);

    i = 17;
    arbolRN.erase(i);
    print(arbolRN);

    i = 2;
    arbolRN.erase(i);
    print(arbolRN);

    i = 19;
    arbolRN.insert(i);
    print(arbolRN);

    i = 18;
    arbolRN.insert(i);
    print(arbolRN);

    i = 19;
    arbolRN.erase(i);
    print(arbolRN);

    cout << "\nARBOL FINAL------------------------------------" << endl;
    for(float a: arbolRN){
        cout << a << "\t";
    }

}