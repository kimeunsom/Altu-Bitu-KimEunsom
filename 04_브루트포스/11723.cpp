#include <iostream>
#include <vector> 

using namespace std;

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    string cmd;
    int x;
    vector <int> s;
    int ans=0;
    
    cin >> n;
    
    while(n>0) {
        cin >> cmd ;
        if(!cmd.compare("add")) {
            cin>>x;
            ans |= (1 << x); //원소 추가
        } 
        
        else if(!cmd.compare("remove")) {
            cin>>x;
            ans &= ~(1 << x);//원소 삭제

        } 
        
        else if(!cmd.compare("check")) {
            cin>>x;
            if (ans & (1 << x))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } 
        
        else if(!cmd.compare("toggle")) {
            cin>>x;
            ans ^= (1 << x);

        } 
        
        else if(!cmd.compare("all")) {
            ans = (1 << 21) - 1;

        } 
        
        else if(!cmd.compare("empty")) {
            ans = 0;
        }
        
        n--;
    }
    
    
    
    return 0;
}