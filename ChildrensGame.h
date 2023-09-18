# include <iostream>

/////////////////////// Node Class Declaration ///////////////////////////
class Node
{
    private:
        Node *next;
    public:
        Node(double element1, double element2); // constructor declaration
        Node* getnext() const; // get next declaration
        void setnext(Node* new_node); // set next declaration

        double data_val1;
        double data_val2;
};


/////////////////////// Game Class Declaration ///////////////////////////
class Game
{
    private:
        Node *list_head;

    public:
        Game(); // constructor declaration
        ~Game(); // destructor declaration
        Node* get_list_head(); //get_list_head function declaration
        void append(double element1, double element2); // append function declaration
        void move_closer(Node* current_node, double time);
        double get_distance(Node* current_node);
        Node* delete_node(Node* current_node); // delete_node function declaration


        int num_players;
        double distance;
};
