#include <iostream>
using namespace std;
#include <vector>

int main() {
    int num;

    vector<int>numeroPares = {2,4,6,8,10};
    vector<int>numeroImpares = {1,3,5,7,9,11,13};
    vector<int>todosNumeros;
    
    numeroPares.push_back(12);
    numeroImpares.pop_back();
    
    
    // for(int i = 0; i< numeroPares.size();i++)
    // {
    //     cout<<numeroPares[i]<<",";
    // }
    
    for (int num : numeroPares) {
        todosNumeros.push_back(num);
    }
    for (int num : numeroImpares) {
        todosNumeros.push_back(num);
    }
    
    
    cout<<endl; 
    cout <<numeroPares.size()<<endl;
    cout <<numeroImpares.empty()<<endl;
    
    return 0;
}