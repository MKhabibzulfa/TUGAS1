
#include <iostream>
#include <string>

#define MAX 20
using namespace std;

void push(char);
char pop();
string in2prefix(string);
int priority (char);
char stk[MAX];
int top = -1;
bool isFull();
bool isEmpty();
void cetak();

bool isFull(){
    if(top == MAX -1)
        return true;
    else
        return false;
}

bool isEmpty(){
    if(top== -1)
        return true;
    else
        return false;

}

void push(char oper){
    if(isFull()){
        cout<<"Stack Penuh";
    }else{
        top++;
        stk[top] = oper;
    }
}

char pop(){
    char ch;
    if(isEmpty()){
        cout<< "Stack Kosong ";
    }else{
        ch = stk[top];
        stk[top]= '\0';
        top--;
        return ch;
        }
    return 0;
}

string in2prefix(string infix){
    int i = 0;
    string pst = "";

    while(infix[i]!='\0'){

        if(infix[i]>='a' && infix[i]<='z'){
            pst.insert(pst.end(),infix[i]);
            i++;
        }
        else if(infix[i] == '(' || infix[i] == '{' || infix[i] == '['){
            push(infix[i]);
            i++;
        }
        else if(infix[i] == ')' || infix[i] == '}' || infix[i] == ']'){
            if(infix[i]== ')'){
                while(stk[top] != '('){
                        pst.insert(pst.begin(),pop());
                      }
                pop();
                i++;
               }
            if(infix[i]== '}'){
                while(stk[top] != '{'){
                       pst.insert(pst.begin(),pop());
                      }
                pop();
                i++;
            }
            if(infix[i]== ']'){
                while(stk[top] != '['){
                       pst.insert(pst.begin(),pop());
                      }
                pop();
                i++;
            }
        }
        else{
            if(top == -1){
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) <= priority(stk[top])){
                pst.insert(pst.begin(),pop());

                while(priority(infix[i]) == priority(stk[top])){
                   pst.insert(pst.begin(),pop());
                   if(top < 0){
                    break;
                   }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])){
            push(infix[i]);
            i++;
        }
    }
}
    while(top != -1){
        pst.insert(pst.begin(),pop());
    }

    cout<<"Hasil Konversi ke Prefix: " << pst;
    return pst;
}

    int priority(char alpha){
        if(alpha == '+' || alpha == '-'){
            return 1;
        }
        if(alpha == '*' || alpha == '/'){
            return 2;
        }
        if(alpha == '$'){
            return 3;
        }
    return 0;
}
void cetak(){
    for(int i =0 ; i<=top ; i++){
        cout<<stk[i]<<" ";
    }
}

int main(){
    string infix,prefix;
    cin>>infix;
    prefix = in2prefix(infix);
    cetak();
    return 0;
}
