#include <iostream>
using namespace std;

bool matchingPair(char open, char close){
    if(open == '(' && close == ')')
    return true;
    if(open == '{' && close == '}')
    return true;
    if(open == '[' && close == ']')
    return true;
    
    return false;
}

int main(){
    char stack[100];
    int top = -1;
    string exp;
    cout<<"Enter the expression to chack: ";
    cin>>exp;
    
    for(int i=0; i<exp.length(); i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            top ++;
            stack[top] = exp[i];
        }
        else if (exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top==-1){
                cout<<"Not Balanced";
                return 0;
            }
            char ch = stack[top];
            top--;

        //ch is opening and exp[i] is closing bracket
        if(!matchingPair(ch,exp[i])){
            cout<<"Not Balanced";
            return 0;
        }
        }
        
    }

    //At the end check stack, if empty then fine otherwise not
    if(top==-1){
        cout<<"Balanced";
        return 0;
    }
    else {
        cout<<"Balabced";
        return 0;
    }

    return 0;
}

