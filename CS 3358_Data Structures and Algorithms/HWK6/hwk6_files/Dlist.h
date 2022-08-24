#ifndef __DLIST_H__
#define __DLIST_H__

/***************************************
 * Do not modify the class declarations!
 ***************************************/
class emptyList
{
};

template <typename T>
class Dlist
{
    // OVERVIEW: contains a double-ended list of Objects

public:

    // Operational methods

    bool IsEmpty() const; //1 working
    // EFFECTS: returns true if list is empty, false otherwise

    void InsertFront(const T &o);  //2 working
    // MODIFIES this
    // EFFECTS inserts o at the front of the list

    void InsertBack(const T &o); //3
    // MODIFIES this
    // EFFECTS inserts o at the back of the list

    T RemoveFront(); //4
    // MODIFIES this
    // EFFECTS removes and returns first object from non-empty list
    //         throws an instance of emptyList if empty

    T RemoveBack(); //5
    // MODIFIES this
    // EFFECTS removes and returns last object from non-empty list
    //         throws an instance of emptyList if empty

    // Maintenance methods
    Dlist();                                   // 6 ctor working
    Dlist(const Dlist &l);                     // 7 copy ctor
    Dlist &operator=(const Dlist &l);          // 8 assignment
    ~Dlist();                                  // 9 dtor working

private:
    // A private type
    struct node
    {
        node   *next;
        node   *prev;
        T      o;
    };

    node   *first; // The pointer to the first node (0 if none)
    node   *last;  // The pointer to the last node (0 if none)
    //How us this different than the doubly linked list in class?

    // Utility methods
//10
    void MakeEmpty();
    // EFFECT: called by constructors to establish empty
    // list invariant

    void RemoveAll(); //11
    // EFFECT: called by destructor and operator= to remove and destroy
    // all list nodes

    void CopyAll(const Dlist &l); //12
    // EFFECT: called by copy constructor/operator= to copy nodes
    // from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/

/***************************************
 *ADD  Member function implementations here
 ***************************************/
// START FROM HERE

/*
PSEUDOCODE
//1 method IsEmpty
  if first is not nullptr
    return 1
  else
    return 0

//2 method InsertFront (reference of a node called o)
 create new_node pointer to a new node
 set o of new_node = o
 if first is nullptr
   set first = new_node
   set last = new_node
   set next of new_node = nullptr
   set prev of new_node = nullptr
 else
   first->prev = new_node;
   new_node->next = first;
   new_node->prev = nullptr;
   first = new_node;
//3 method InsertBack(reference of a node called o)
 create a new_pointer to a new node;
 set o of the node of new_node pointer = o
 if the list is not empty
   set first = new_node;
   set last = new_node;
   set new_node->next = nullptr
   set new_node->prev = nullptr
 else
   set last->next = new_node
   set new_node->prev = last
   set new_node->next = nullptr
   set last = new_node

*/
//1
template <class T>
bool Dlist<T>::IsEmpty() const
{
    return !first?1:0;
}
//2
template <class T>
void Dlist<T>::InsertFront(const T &o)
{
    node* new_node = new node;
    new_node->o = o;
    if (!first)
    {
        first = new_node;
        last = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    }
    else
    {
        first->prev = new_node;
        new_node->next = first;
        new_node->prev = nullptr;
        first = new_node;
    }
}
//3
template <typename T>
void Dlist<T>::InsertBack(const T &o)
{
    node* new_node = new node;
    new_node->o = o;
    if (!first)
    {
        first = new_node;
        last = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    }
    else
    {
        last->next = new_node;
        new_node->prev = last;
        new_node->next = nullptr;
        last = new_node;
    }
}
//4
template <typename T>
T Dlist<T>::RemoveFront()
{
    if (IsEmpty())
    {
        emptyList empt;
        throw empt;
    }
    node *old_node = first;
    if (first == last)
    {
        first = nullptr;
        last = nullptr;
    }
    else
    {
        first = first->next;
        first->prev = nullptr;
    }
    T o = old_node->o;
    delete old_node;
    return o;
}
//5
template <typename T>
T Dlist<T>::RemoveBack()
{
    if (IsEmpty())
    {
        emptyList empt;
        throw empt;
    }
    else
    {
        node *last_node = last;
        if (last == first)
        {
            last = nullptr;
            first = nullptr;
        }
        else
        {
            last = last->prev;
            last->next = nullptr;
        }
        T o = last_node->o;
        delete last_node;
        return o;
    }
}
//6 done
template <class T>
Dlist<T>::Dlist()
{
    MakeEmpty();
}
//7 done
template <class T>
Dlist<T>::Dlist(const Dlist &l)
{
    MakeEmpty();
    CopyAll(l);
}
//8
template <class T>
Dlist<T> &Dlist<T>::operator=(const Dlist &l)
{
    if (this == &l)
        return *this;
    RemoveAll();
    CopyAll(l);
    return *this;
}
//9 done
template <class T>
Dlist<T>::~Dlist()
{
    RemoveAll();
}

//10
template <class T>
void Dlist<T>::MakeEmpty()
{
    first = nullptr;
    last = nullptr;
}
//11
template <class T>
void Dlist<T>::RemoveAll()
{
    while (first)
    {
        node *toDelete = first;
        first = first->next;
        toDelete->next = nullptr;
        delete toDelete;
    }
}
//12
template <class T>
void Dlist<T>::CopyAll(const Dlist &l)
{
    if (l.first == nullptr)
    {
        first = nullptr;
        last = nullptr;
    }
    else
    {
        node* curr = l.first;
        while (curr)
        {
            InsertBack(curr->o);
            curr = curr->next;
        }
    }
}
#endif /* __DLIST_H__ */
