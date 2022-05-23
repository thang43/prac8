#ifndef NODE_H 
#define NODE_H 

class Node{ 
    private: int data; 
             Node* next; 

    public: Node(int data, Node* next); 
            int get_data(); 
            Node* get_next(); 
            void set_data(int new_data); 
            void set_next(Node* new_next); 
}; 
#endif
