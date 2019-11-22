#include <iostream>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node(char data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class Stack{
private:
    Node* top = nullptr;
    int size=0;
    
public:
    int getSize();
    bool isEmpty();
    void push(char data);
    char pop();
};

int Stack::getSize(){
    return size;
}

bool Stack::isEmpty(){
    return size == 0 ? true : false;
}

void Stack::push(char data){
    Node* node =  new Node(data, nullptr);
    if(isEmpty()){
        top = node;
    }
    else{
        node -> next = top;
        top = node;
    }
    size++;
}

char Stack::pop(){
    if(isEmpty()){
        return NULL;
    }
    
    char temp = top->data;
    auto fre = top;
    top = top->next;
    free(fre);
    
    size--;
    
    return temp;
}


bool isLeftBracket(char bracket){
    if(bracket == '{' || bracket == '[' || bracket == '('){
        return true;
    }
    
    
    return false;
}


bool isValid(Stack s,string check){
    for(int x = 0; x<check.length();x++){
        if(isLeftBracket(check[x])){
            s.push(check[x]);
        }
        else{
            if(s.isEmpty()){
                return false;
            }
            auto left = s.pop();
            if(left == '{' && check[x] == '}'){
                if(s.isEmpty()){
                    return true;
                }
                continue;
            }
            else if(left=='[' && check[x]==']'){
                if(s.isEmpty()){
                    return true;
                }
                continue;
            }
            else if(left=='(' && check[x]==')'){
                if(s.isEmpty()){
                    return true;
                }
                continue;
            }
            return false;
        }
    }
    return false;
}


int main(){
    Stack s;
    string temp = "({[]})";
    
    isValid(s, temp) ? cout<<"valid"<<endl : cout<<"inValid"<<endl;
    
}
