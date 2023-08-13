#include<iostream>
using namespace std;
# define MAX 5
class Reverse{
    private :
    int stk[MAX]; 
    int top = -1;
    public :
    void push(int value){
        if (top<MAX-1){
            stk[++top]=value;
        }
    }

    int pop() {
        if(top>=0){
            return stk[top--];
        }
        return -1;
    }
};
    void reverseArrayUsingStack (int stk[]) {
        Reverse s;
        for(int i =0;i<MAX-1;i++){
           s.push (stk[i]);
        }

        for(int i=0;i<MAX-1;i++){
            stk[i]=s.pop();
        }
    }

int main(){
    int array[] = {1,2,3,4,5};
    cout<<"ORIGINAL ARRAY : "<<endl;
    for(int i=0;i<MAX-1;i++){
        cout<<array[i]<<" "<<endl;
    }
    // cout<<endl;
   
    reverseArrayUsingStack(array);
    cout<<"REVERSE ARRAY :"<<endl;
    for(int i=0;i<MAX-1;i++){
        cout<<array[i]<<" "<<endl;
    }
   return 0;
}    