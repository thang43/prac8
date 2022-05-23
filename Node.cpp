#include "Node.h" 


Node::Node(int data, Node* next){ 
    this->data = data; 
    this->next = next; 
}
 
int Node::get_data(){
    return this->data; 
}
 
Node* Node::get_next(){
    return this->next; 
}

void Node::set_data(int new_data){
    this->data = new_data; 
}
 
void Node::set_next(Node* new_next){
    this->next = new_next; 
}
