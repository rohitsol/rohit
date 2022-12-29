#include <iostream>
#include <string.h>
using namespace std;

struct node{
    char data;
    node *next;
}*top = NULL;


void push(int x){
    node *t;
    t = new node;
    t->data = x;
    t->next = top;
    top = t;
}

char pop(){
    char x = -1;

    if(top == NULL){
        cout<<"Stack is empty"<<endl;
    }
    else{
        node *t;
        t = top;
        top = top->next;

        x = t->data;
        delete t;
    }
    return x;
}

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    return 0;
}

void display(){
    node *t;
    t = top;

    cout<<"Elements are : ";
    while(t!= NULL){
        cout<<t->data<<"  ";
        t = t->next;
    }
    cout<<endl;
}

int isoperand(char x){
    if(x == '*' || x == '+' || x == '-' || x == '/'){
        return 0;
    }
    else{
        return 1;
    }
}

int pre(char x){
    if(x == '*' || x == '/' ){
        return 2;
    }
    else if(x == '+' || x == '-'){
        return 1;
    }
    return 0;
}

char* infix_to_postfix(char* infix){
    push('#');

    int len = strlen(infix);
    char *postfix = new char[len+2];
    int i = 0 , j = 0;

    while(infix[i] != '\0'){

        if(isoperand( infix[i] )){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i]) > pre(top->data) ){
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }

    while(top->data != '#'){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}


char* infix_to_prefix(char *infix){
    char *reverse = strrev(infix);

    push('#');

    int len = strlen(infix);
    char *postfix = new char[len+2];
    int i = 0 , j = 0;

    while(infix[i] != '\0'){

        if(isoperand( infix[i] )){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i]) > pre(top->data) || pre(infix[i]) == pre(top->data)){        // change
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }

    while(top->data != '#'){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    reverse = strrev(postfix);
    return reverse;
}


int main(){
    char infix[] = "a+b*c-d";

    char *postfix = infix_to_postfix(infix);

    cout<<postfix<<endl;

    char *prefix = infix_to_prefix(infix);

    cout<<prefix<<endl;
    return 0;
}
