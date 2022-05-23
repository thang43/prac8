#include <iostream> 
#include "LinkedList.h" 
#include <string> 
#include <limits> 

LinkedList::LinkedList(){ 
    this->head = NULL ; 
}
 
LinkedList::LinkedList(int* array_nodes, int length){ 

    if(length==0){ 
        this->head = NULL; 
    }
    else{
        this->head = new Node(array_nodes[0], NULL); 
        Node* current = this->head; 
        for (int i = 1; i < length; i++){ 
            Node* next = new Node(array_nodes[i], NULL); 
            current->set_next(next); 
            current = next; 
        }
    }
}

LinkedList::~LinkedList(){
    if(this->head == NULL) {
        return; 
    }
    Node* current = this->head; 
    current = current->get_next(); 
    this->head = NULL; 
    while(current->get_next() != NULL){
        Node* temp = current; 
        Node* next = current->get_next(); 
        current->set_next(NULL); 
        current = next; 
        temp = NULL;
        delete temp; 
    }
}

void LinkedList::printItems(){
    if(this->head == NULL){ 
        return;
    }
    std::string items = ""; 
    Node* current = this->head; 
    while (current != NULL){
        items += std::to_string(current->get_data()); 
        items += " "; 
        current = current->get_next(); 
    }
    std::cout << items << std::endl; 
}

void LinkedList::addFront(int newItem){ 
    Node* new_node = new Node(newItem, this->head); 
    this->head = new_node; 
}

void LinkedList::addEnd(int newItem){ 
    Node* current = this->head; 
    Node* new_node = new Node(newItem, NULL); 
    if(current == NULL){ 
        this->head = new_node; 
        return; 
    }
    while(current->get_next()!= NULL){
        current = current->get_next(); 
    }
    current->set_next(new_node); 
}

int LinkedList::listSize(){
    int size = 0; 
    Node* current = this->head; 
    while(current != NULL){
        size++;
        current = current->get_next(); 
    }
    return size; 
}
 
void LinkedList::addAtPosition(int position, int newItem){ 
    if(position < 1){
        this->addFront(newItem); 
        return; 
    }
    else if(position> this->listSize()){
        this->addEnd(newItem); 
        return; 
    }
    Node* current = this->head; 
    int current_position = 1; 
    if(position == 1) { 
        Node* new_node = new Node(newItem, this->head); 
        this->head = new_node; 
        return; 
    }
    while(current != NULL && current_position != position - 1){
        current = current->get_next(); 
        current_position++; 
    }
    Node* new_node = new Node(newItem, current->get_next()); 
    current->set_next(new_node); 
}

int LinkedList::search(int item){
    int current_position = 1; 
    int position_found= -1; 
    Node* current = this->head; 
    while (current != NULL && position_found == -1){ 
        if(current->get_data() == item){
            std::cout << current_position << std::endl; 
            position_found = current_position; 
        }
        current_position++; 
        current = current->get_next(); 
    }
    if(position_found == -1){
        std::cout << 0 << std::endl; 
        return 0; 
    }
    return position_found; 
}

void LinkedList::deleteFront(){ 
    Node* temp = this->head; 
    this->head = this->head->get_next(); 
    temp = NULL; 
    delete temp; 
}

void LinkedList::deleteEnd(){
    Node* current = this->head;     
    while(current->get_next() != NULL){
        current = current->get_next(); 
    }
    current = NULL; 
}

void LinkedList::deletePosition(int position){ 
    if(position < 1 || position > this->listSize()){
        std::cout << "outside range" << std::endl;
        return; 
    }
    else if(position == 1){ 
        this->deleteFront(); 
        return; 
    }
    else if (position == this->listSize()){
        this->deleteEnd(); 
        return; 
    }
    int current_position = 1; 
    Node* current = this->head; 
    while(current != NULL && current_position != position - 1){ 
        current_position++; 
        current = current->get_next(); 
    }
    Node* next = current->get_next(); 
    current->set_next(next->get_next()); 
    next = NULL; 
    delete next; 
}

int LinkedList::getItem(int position){
    if(position < 1 || position > this->listSize()){
        std::string output = std::to_string(std::numeric_limits<int>::max()); 
        output += " ";
        std::cout << output << std::endl; 
        return std::numeric_limits<int>::max(); 
    }
    Node* current = this->head; 
    int current_position = 1; 
    while(current != NULL && current_position != position){
        current = current->get_next(); 
        current_position++; 
    }
    std::string item = std::to_string(current->get_data()); 
    item += " "; 
    std::cout << item << std::endl; 
    return current->get_data(); 
}

