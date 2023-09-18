#include <iostream>
#include <string>
#include "ChildrensGame.h"
using namespace std;

////////////////////////// Node Class Definitions//////////////////////////

Node::Node(double element1, double element2): data_val1(element1), data_val2(element2), next(nullptr){} // constructor definition
Node* Node::getnext() const {return next;}// getnext function definition
void Node::setnext(Node* new_node) {next = new_node;} //setnext function definition

////////////////////////// Game Class Definitions /////////////////////////

Game::Game(): list_head(nullptr) //constructor definition
{
    num_players = 0;
}
Game::~Game() // destructor definition
{
    Node* current = list_head;
    list_head = nullptr;

    while(current!= nullptr)
    {
        Node* temp = current;
        current = current->getnext();
        delete temp;
    }
} 
Node* Game::get_list_head() // get_list_head function definition
{
    return list_head;
}
void Game::append(double element1, double element2) // append function definition
{   
    Node* new_node = new Node(element1, element2);

    if (list_head == nullptr)
    {
        list_head = new_node;
        num_players++;
    } 
    else 
    {
    Node* temp = list_head;
    while(temp->getnext()!= nullptr)
    {
        temp = temp->getnext();
    }
    temp->setnext(new_node);
    num_players++;
    }
}
void Game::move_closer(Node* current_node, double time)
{
    double temp_x = current_node->data_val1;
    current_node->data_val1 = current_node->data_val1 - (time * cos(atan2 (current_node->data_val2, current_node->data_val1)));
    current_node->data_val2 = current_node->data_val2 - (time * sin(atan2 (current_node->data_val2, temp_x)));
}
double Game::get_distance(Node* current_node)
{
    distance = sqrt(pow(current_node->data_val1 + current_node->data_val2, 2));
    return distance;
}
Node* Game::delete_node(Node* current_node) // delete_node function definition 
        {
            if (list_head == nullptr) // If the list head points to nothing
            {
                return nullptr;
            } 
            else if (list_head == current_node) // If the list head points to the current node
            {
                list_head = list_head->getnext(); // list head points to the next node
                delete current_node;
                num_players--;
                return list_head;
            } 
            else // If the list head does not point to the current node (node is in the middle/end of the list)
            {
                Node* prior_node = list_head;

                while(prior_node->getnext()!= current_node)
                {
                    prior_node = prior_node->getnext(); // Find the prior node to the current node
                }

                Node* hold = current_node->getnext();
                prior_node->setnext(hold); // Set the prior node to the next node
                delete current_node;
                num_players--;
                return hold;
            }
        }

// ADD CHILD CLASS WHICH WILL STORE FUNCTIONS tO PERFORM TASKS FOR CHILDREN

int main()
{
////// Class & Variable Declarations //////
Game BigBad_Wolf;

double x_coordinate;
double y_coordinate;
double time;
double distance;

//string input
string command;

while (cin >> command) 
{
    if (command == "SPAWN") //SPAWN command is entered//
    {
        //Take in the paramaters and save them to variables - can be added to a class
        cin >> x_coordinate;
        cin >> y_coordinate;

        //check if the coordinates are valid (x & y greater than 0)
        if( x_coordinate > 0 && y_coordinate > 0)
        {
            BigBad_Wolf.append(x_coordinate, y_coordinate);
            cout << "success" << endl;
        } else 
        {
            cout << "failure" << endl;
        }

        /////// End of the SPAWN command ///////

    } else if (command == "TIME") //TIME command is entered//
    { 
        Node* current_node = BigBad_Wolf.get_list_head();
        Node* temp = current_node;
        //Take in the time and save them to variables - can be added to a class
        cin >> time;

        if (time >= 0) {
            while (current_node != nullptr)
            {
                //calculate the new x and y coordinates of the node and update the node
                BigBad_Wolf.move_closer(current_node, time);

                //move to the next node in the list
                current_node = current_node->getnext();
            }
            while (temp!= nullptr) 
            {
            if (BigBad_Wolf.get_distance(temp) <= 0) 
                {
                    temp = BigBad_Wolf.delete_node(temp);
                } else 
                {
                    temp = temp->getnext();
                }
            }
            cout << "number of children still playing: " << BigBad_Wolf.num_players << endl;
        } 
        else 
        {
            while (current_node != nullptr) 
            {
                if (BigBad_Wolf.get_distance(current_node) < 1) //child is less than 1m away
                {
                    // delete the node from the list
                    current_node = BigBad_Wolf.delete_node(current_node);
                } else 
                {
                    current_node = current_node->getnext();
                }
            }
            cout << "number of children still playing: " << BigBad_Wolf.num_players << endl;
        }

        /////// End of the TIME command ///////

    } else if (command == "NUM") 
    {
        cout<< "number of children still playing: " << BigBad_Wolf.num_players << endl;

        /////// End of the NUM command ///////

    } else if (command == "PRT") //PRT command is entered//
    {
        Node* current_node = BigBad_Wolf.get_list_head();
        cin >> distance;
        
        if (distance >= 0)
        {
            while (current_node!= nullptr) 
            {
                if (BigBad_Wolf.get_distance(current_node) < distance) //child is less than D away
                {
                    cout << current_node->data_val1 << " " << current_node->data_val2 << " ";
                    current_node = current_node->getnext();
                } 
                else 
                {
                    cout << "no children within distance" << endl;
                    current_node = current_node->getnext();
                }
            }
        }

        /////// End of the PRT command ///////

    }else if (command == "OVER") //OVER command is entered//
    { 
            
        if (BigBad_Wolf.num_players < 1)
        {
            cout << "the players win" << endl;
        } 
        else
        {
            cout << "the wolf wins" << endl;
        }

        break;

        /////// End of the OVER command ///////
    }
}
return 0;
}
