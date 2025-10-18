#include <iostream>
#include "BST.h"
#include "BST.cpp"

using namespace std;


int main () {
    int cmd;
    int value;
    string travOrd;

    BST* L = new BST();

    while(cmd != 9){
        cout << "-----------------------" << endl;
		//L->traversal("inorder");
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
        cin >> cmd;
        switch(cmd) {
            case 1:
                cout << "Search para que?" << endl;
                cin >> value;
                L->search(value);
                break;
            case 2:
                travOrd = ""; // Clears the variable before use
                // While loop makes sure the the user enters a valid input for the command.
                while((travOrd != "inorder") && (travOrd != "preorder") && (travOrd != "postorder")){
                    cout << "Would you like to traverse with inorder, preorder, or postorder methodology?" << endl;
                    cout << "Please choose one of the three stated options in all lowercase." << endl;
                    cin >> travOrd;
                    }

                L->traversal(travOrd);
                break;
            case 3:
                cout << "What value would you like to insert in the tree?" << endl;
                cin >> value;
                L->insert(value);
                break;
            case 4:
            cout << "What value would you like to delete from the tree?" << endl;
                cin >> value;
                L->Delete(value);
                break;
            case 5: 
                L->maximum();
                break;
            case 6: 
                L->minimum();
                break;
            case 7: 
                cout << "Which number would you like to find the inorder successor for?";
                cin >> value;
                cout << "The inorder successor is: " << L->inOrderSuccessor(value) << endl;
                break;
            case 8: 
                cout << "Which number would you like to find the inorder successor for?";
                cin >> value;
                cout << "The inorder predecessor is: " << L->inOrderPredecessor(value) << endl;
                break;
            case 9: break;
            default: cout << "Enter a valid choice" << endl;
				break;
        };
    }



    //cout << L->locateNewLeaf(L->root, 5) << endl;
    return 0;
}