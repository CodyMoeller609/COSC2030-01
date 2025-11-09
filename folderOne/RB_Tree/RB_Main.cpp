#include <iostream>
#include "RB.h"
#include "RB.cpp"

using namespace std;


int main () {
    int cmd;
    int value;
    string travOrd;

    RB* L = new RB();
    Node* p; // Node p is used for several cases. Notably to check if a returned node is a nullptr to prevent errors.

    while(cmd != 9){
        cout << "-----------------------" << endl;
        L->printTree();
		cout << "-----------------------" << endl;
        //Present Choices
		cout << "1 - Search" << endl;
        cout << "2 - Traverse" << endl;
		cout << "3 - insert" << endl;
        cout << "4 - Delete" << endl;
		cout << "5 - Print Minimum" << endl;
		cout << "6 - Print Maximum" << endl;
		cout << "7 - Print the Inorder Successor of a Value" << endl;
		cout << "8 - Print the Inorder Predecessor of a Value" << endl;
        cout << "9 - Exit the Program" << endl;
        cout << "Choice: ";
        // take input and act accordingly
        cin >> cmd;
        switch(cmd) {
            case 1: // Search
                cout << "Search for which number?" << endl;
                cin >> value;
                p = L->search(value);
                if(p == nullptr){
                    cout << p->key << " was not found!" << endl;
                }else{
                    cout << p->key << " was found at address: " << p << endl;
                }
                p = nullptr;
                break;
            case 2: // Traverse
                travOrd = ""; // Clears the variable before use
                // While loop makes sure the the user enters a valid input for the command.
                while((travOrd != "inorder") && (travOrd != "preorder") && (travOrd != "postorder")){
                    cout << "Would you like to traverse with inorder, preorder, or postorder methodology?" << endl;
                    cout << "Please choose one of the three stated options in all lowercase." << endl;
                    cin >> travOrd;
                    }

                L->traversal(travOrd);
                break;
            case 3: // Insert
                cout << "What value would you like to insert in the tree?" << endl;
                cin >> value;
                L->insert(value);
                break;
            case 4: // Delete
                cout << "What value would you like to delete from the tree?" << endl;
                cin >> value;
                L->Delete(value);
                break;
            case 5: // Print Minimum
                cout << "The minimum value in the tree is: " << L->minimum() << endl;
                break;
            case 6: // Print Maximum
                cout << "The maximum value in the tree is: " << L->maximum() << endl;
                break;
            case 7: // Print the inorder successor
                cout << "Which number would you like to find the inorder successor for?";
                cin >> value;
                p = L->inOrderSuccessor(value);
                if(p == nullptr){
                    cout << "There is no successor. " << endl;
                }else{
                    cout << "The inorder successor is: " << p->key << endl;
                }
                p = nullptr;
                break;
            case 8:  // Print the inorder predecessor
                cout << "Which number would you like to find the inorder predecessor for?";
                cin >> value;
                p = L->inOrderPredecessor(value);
                if(p == nullptr){
                    cout << "There is no predecessor. " << endl;
                }else{
                    cout << "The inorder predecessor is: " << p->key << endl;
                }
                p = nullptr;
                break;
            case 9: break; // exit the program

            // Cases 10 & 11 exist for debugging, so they are not displayed to the user
            case 10: // Rotate Right
                cout << "Which number would you like to rotate about?";
                cin >> value;
                L->rotateR(L->search(value));
                break;
            case 11: // Rotate Left
                cout << "Which number would you like to rotate about?";
                cin >> value;
                L->rotateL(L->search(value));
                break;
            default: cout << "Enter a valid choice" << endl;
				break;
        };
    }
    return 0;
}