
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lib.cpp";

using namespace std;

int main()
{
    cout << " Hello! This program creates a perfectly balanced search tree (PBST) from a given array " << endl;
    int choice; //variable that indicates the selected action
    int n; //number of array elements
    int addel; // the item that the user wants to add
    int rm; // the item that the user wants to remove
    int findel; // the item that the user wants to find

    while(!0) //menu
    {
        cout << " Please select action: " << endl;
        cout << " 1 - Set an array and make an array of the PBST" << endl;
        cout << " 2 - Display PBST" << endl;
        cout << " 3 - Remove item from PBST" << endl;
        cout << " 4 - Remove entire PBST" << endl;
        cout << " 5 - Add item to PBST" << endl;
        cout << " 6 - Find element in PBST" << endl;
        cout << " 0 - EXIT" << endl;
        cin >> choice;
        switch(choice)
        {
            case 0://Exit
                {
                    cout << "Exit in progress..." << endl;
                    return 0;
                    break;
                }

            case 1: //Make tree
                {
                    cout << "Enter the number of elements in the array: " << endl;
                    cin >> n;
                    int *a = new int[n];
                    cout << "Enter array elements (elements need not be repeated): " << endl;
                    for(int i = 0; i < n; i++) //set an array
                    {
                        cin >> a[i];

                       // a[i] = rand();
                    }
                    cout << "Your array is: " << endl;
                    for(int i = 0; i < n; i++)
                    {
                        cout << a[i] << " ";
                    }
                    cout << endl;
                    Sort(a,n); //sort array

                    BuildTree(a,n);
                    cout << "PBST was made" << endl;
                    cout << endl;
                    break;
                }

            case 2: //display tree
                {
                    if(Tree)
                    {
                        PrintTree(Tree);//if the tree is print it
                    }else
                    {
                        cout << "No tree" << endl;
                    }
                    break;
                }

            case 3: //remove item
                {
                    cout << "Enter the item you want to delete: " << endl;
                    cin >> rm;
                    int v = SearchElement(rm, Tree); //check the element for presence in the tree
                    if(v)
                    {
                        cout << "The element is deleted." << endl;
                        RemoveElement(rm, Tree); //remove element
                    }else
                    {
                        cout << "Ops...Item not found." << endl;
                    }
                    break;
                }
            case 4: //remove tree
                {
                    DeleteTree(Tree); //remove tree
                    Tree = NULL; //initialize the tree with zero
                    cout << " Tree removed." << endl;
                    break;
                }
            case 5: //Add element
                {
                    cout << "Enter the item you want to add:" << endl;
                    cin >> addel;
                    int k;
                    k = SearchElement(addel, Tree); //check the element for uniqueness
                    if(k)
                    {
                        cout << "This element is already in the tree" << endl;

                    }else
                    {
                        AddElement(addel, Tree); //add this item
                        cout << "Item added! " << endl;
                        cout << endl;
                    }
                    break;
                }

            case 6: //find element in the tree
                {
                    cout << "Enter the item you want to find: " << endl;
                    cin >> findel;
                    int w;
                    w = SearchElement(findel, Tree); //find item
                    if(w)
                    {
                        cout << "This element is in the tree. " << endl;
                    }else
                    {
                        cout << "This element didn't find. " << endl;
                    }
                }
        }
    }
}
