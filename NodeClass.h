# include <iostream>

/////////////////////// Node Class Declaration ///////////////////////////
class Node
{
    private:
        Node* next;
    public:
        Node(double element1, double element2); // constructor declaration
        Node* getnext() const; // get next declaration
        void setnext(Node* new_node); // set next declaration

        double data_val1;
        double data_val2;
};