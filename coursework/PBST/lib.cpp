#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Link
{
    int x;//the number we will record
    Link *l, *r;//address fields(left and right)
};

Link *Tree=NULL;//pointer whose type is "tree link"

//The sort function of the array
void Sort(int *a, int n)
{
    int left=0;
    int right=n-1;
    int middle=a[n/2];
    while(left<=right)
    {
        while(a[left]<middle)
        {
            left++;//move the pointer to the right until it approaches the middle element
        }
        while(a[right]>middle)
        {
            right--;
        }
        if(left<=right)
        {
            swap(a[left], a[right]);//change the items in places
            left++;
            right--;
        }
    }
    if (right>0)
       Sort(a, right+1);

    if (left < n-1)
       Sort(a+left, n-left);
}

//a function that adds value to the tree
void Add(Link *Node, Link *Branch)
{
    //work with the left part of the tree
    if(Node->x<=Branch->x) //condition: the entered element is smaller than the node
    {
        if(Branch->l) //condition: there is a left tree
        Add(Node,Branch->l); //recursively write the element to the left in the free space
        else
        Branch->l=Node; //otherwise, the left subtree becomes a node
    }
    else //else a free site is not
    {
      if(Branch->r) //condition: there is a right tree
        Add(Node,Branch->r); //recursively write the element to the right in the free space
      else Branch->r=Node;//otherwise, the right subtree becomes a node
    }
}

//parent and 2 child creation function
void NewLink(int x)
{
    Link *Node = new Link;
    Node->x = x; //write data to our node
    Node->l = NULL; //create the left link and initialize to avoid errors
    Node->r = NULL; //create the left link and initialize
    if(Tree)
    {
        Add(Node, Tree); //call the add function from Node if there is a tree
    }else Tree = Node; //put in the base of out node if there is not a tree
}

//Tree building function
void BuildTree(int *a, int n){
    int middle=0; //this is a variable for the middle element
    if(n==1)
    {
        NewLink(a[0]); //create node
    }else if(n==2)
    {
        middle = n/2; //calculate middle element
        NewLink(a[n/2]); //make it a node
        BuildTree(a,1); //recursively arrange other elements
    }else
    {
        middle = n/2;
        NewLink(a[n/2]);
        BuildTree(a, n/2); //recursively work with the left part or the array; build the left subtree
        BuildTree(a+n/2+1, n-n/2-1); //recursively work with the right part or the array; build the right subtree
    }
}

//a function that counts the number of nodes in the tree
int LengthTree(Link *Derevo)
{
    if(Derevo==NULL) //if there is no tree
    {
        return (0);
    }else
    {
        return(LengthTree(Derevo->l)+1+LengthTree(Derevo->r)); //count and return the number of nodes
    }
}

//add function to add an element to an array
int *AddElToArray (int *olditem, int number, int newel)
{
    int numberTemp=number+1; // create a variable for more elements;
    int *temp = new int[numberTemp]; //create an array with a large number of elements;

    if(number==1)
    {
        temp[0]=olditem[0]; // shift the array element
        temp[number]=newel;  //add new
    }else
    {
        for(int i=0; i<number; i++)
        {
            temp[i] = olditem[i]; //shift the array elements
        }
        temp[number] = newel; // in the last place put element that you want to add
        return temp; //return new array
    }
    return temp;
}

//Writing a tree to an array
void WritingTreeToAnArray(int *arr, int b, Link *MR)
{
    if(b==1)
    {
        arr[0]=MR->x; //writing a single element to the array
    }else if(b==2)
    {
        arr[b/2]=MR->x; //write the node as the middle element of the array
        WritingTreeToAnArray(arr, 1, MR->l); //recursively insert the last element into the array
    }else
    {
        arr[b/2]=MR->x; //write the node as the middle element
        WritingTreeToAnArray(arr, b/2, MR->l); // recursively write the left subtree to the left part of the array
        WritingTreeToAnArray(arr+b/2+1, b-b/2-1, MR->r); //recursively write the right subtree to the right part of the array
    }
}

//tree delete function
void DeleteTree(Link *Emptily)
{
    if(Emptily)
    {
        if(Emptily->l)DeleteTree(Emptily->l); //recursively remove left part
        if(Emptily->r)DeleteTree(Emptily->r); //recursively remove right part
        delete Emptily; //remove last item
        Emptily==NULL;
    }
}

//a function that adds value to the ready tree
void AddElement(int element, Link *T)
{
    int m=0;//create a variable
    m=LengthTree(T);//assign the number of nodes in the tree to the element
    int *ARR=new int[m];//create new array with the number of elements equal number of node in the tree
    WritingTreeToAnArray(ARR, m, T); //write the tree to the new array
    int g = m + 1; //create a variable with the number of elements 1 more
    int *p = new int[g]; //create new array with the number of elements 1 more
    p = AddElToArray(ARR, m, element); //add a new item to array
    Sort(p, g); //sort array
    DeleteTree(Tree); //delete old tree
    Tree = NULL;
    BuildTree(p, g);
}

//remove element from array
int *RemElFromArr( int *old, int num, int E)
{
    int p = 0;
    int b = 0;
    int numTemp = num-1; //create a variable with a smaller of items 1
    int *Temp = new int[numTemp]; //create new array with a smaller of items 1

    for(int i = 0; i < num; i++)
    {
        if(old[i]!= E || p==1) //conditions: elements of the array is not equal to that which is necessary to remove or token =1
        {
            Temp[b] = old[i]; // shift the array elements
            b++;
        }
        else
        {
            p = 1;
        }
    }
    if (p == 0) return NULL;

    return Temp;

}

//function of removing an element from the tree
int RemoveElement(int element, Link *RM)
{
    int k = LengthTree(RM); //put in a new variable the number of nodes in the tree
    int N[k]; //create new array with this number of elements
    WritingTreeToAnArray(N, k, RM); //shift tree to a new array
    int s = k -1; //create a variable with a smaller of items 1
    int *L = new int[s]; //create array with this number elements

    if(!L) return 0;

    L = RemElFromArr(N, k, element); //remove an element from the array
    Sort(L, s);
    DeleteTree(Tree); //remove old tree
    Tree = NULL;
    BuildTree(L, s);
}

//tree print function
void PrintTree(Link *PR)
{
    if(PR)
    {
        cout << "Node: " << PR->x; //print Node
        if(PR->l) cout << " Left subtree: " << PR->l->x;
        if(PR->r) cout << " Right subtree: " << PR->r->x;
        cout << endl;

        PrintTree(PR->l); //recursively print left subtree
        PrintTree(PR->r); //recursively print right subtree
    }
}

//the search function for an element in the tree
int SearchElement(int item, Link *Tr)
{
    if(item<Tr->x)//condition: the sought element is smaller than the vertex
   {
       if(Tr->l)//condition: there is a left subtree
       SearchElement(item, Tr->l);//recursively looking for item the left subtree
       else return 0;//else nothing return
   }else if(item>Tr->x)//condition: the sought element is bigger than the vertex
   {
       if(Tr->r)//condition: there is a right subtree
        SearchElement(item,Tr->r);//recursively looking for item the right subtree
        else return 0;
   }else //item equal the vertex
   {
       return item;
   }
}
