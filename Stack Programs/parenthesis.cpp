#include <iostream>
#include <cstring>
using namespace std;

# define MAX 10

char stk[MAX];
int flag = 1;

class Parenthesis {
    private:
    int top = -1;
    public:
    void push(char c){
    if (top == MAX - 1)
        cout<<"stack overflow"<<endl;     
    else{
        stk[++top]=c;
    }
    }
    int pop(){
         if(top == -1)
        {
            cout<<"Stack Underflow Observed";
        }
         else{
            return (stk[top--]);
        }
    }
    void checkForValidity(const char exp[]) {
    char temp;
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) {
                flag = 0;
                break; // Exit the loop immediately
            } else {
                temp = pop();
                if ((exp[i] == ')' && temp != '(') ||
                    (exp[i] == '}' && temp != '{') ||
                    (exp[i] == ']' && temp != '[')) {
                    flag = 0;
                    break; // Exit the loop immediately
                }
            }
        }
    }
    if (top >= 0)
        flag = 0;
    if (flag == 1)
        cout << "Valid Expression";
    else {
        cout << "Invalid Expression";
    }
}

};.

int main(){
    char exp[MAX];
    Parenthesis s;
    cout<<"Enter an expression";
    cin.getline(exp,MAX);
    s.checkForValidity(exp);
}