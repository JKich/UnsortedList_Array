//  Jack Kichula
//  Lab1

#include "UnsortedListByArray.h"

//constructor
UnsortedListByArray::UnsortedListByArray()
{
  length = 0;
}

//check whether the list is full
bool UnsortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}

//check how many elements are in this list
int UnsortedListByArray::GetLength( ) const
{
  return length;
}

//check whether there is element in this list
bool UnsortedListByArray::IsEmpty() const
{
  return (length == 0);
}

//Pre: the list should not be full
// Post: item is in the list.
void UnsortedListByArray::InsertItem(ItemType item)
{
  info[length] = item;
  length++;
}

// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged.
void UnsortedListByArray::RetrieveItem(ItemType& item, bool& found) 
{
  bool moreToSearch;
  int location = 0;
  found = false;
  moreToSearch = (location < length);
  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    { case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}

// Pre: item's key has been inititalized.
//	One and only one element in the list has a key that matches item's.
// Post: No element in the list has a key that matches itemís.
void UnsortedListByArray::DeleteItem ( ItemType  item ) 
{    
  int  location  =  0 ;

  while (item.ComparedTo (info[location])  !=  EQUAL)
         location++;
  // move last element into position where item was located

  info [location] = info [length - 1 ] ;
  length-- ; //the length of the list is decreased
}

// Pre:  N/A   
// Post: the list is empty
void UnsortedListByArray::MakeEmpty()
{
   length = 0;
}


// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
void UnsortedListByArray::ResetList ( )  
{    
  currentPos  =  -1 ;
}

// Pre:  List has been initialized. Current position is 
//       defined. 
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
void UnsortedListByArray::GetNextItem ( ItemType&  item )  
{
  currentPos++  ;
  item = info [currentPos] ;
}


//START OF LAB FUNCTIONS

// Pre: Lit has been initialized and is not empty.
// 	The list has at least one copy of the item.
// Post: List does not have any copies of the item.
void UnsortedListByArray::DeleteAllItems (ItemType item)
{
  int i=0;
  
  while (info[length-1].ComparedTo(item) == EQUAL)
  {
    length--;  //makes sure that item is not at the end
  }            //of the array so the loop doesn't miss it

  for (i; i<length+1; i++)
  {

	if (info[i].ComparedTo(item) == EQUAL)
	{
	  info[i] = info[length-1];  //replaces item with the
	  length--;		     //last item in the array
	}
  }
}


// Pre: List has been initialized.
// Post: List should have at least one copy of the item.
void UnsortedListByArray::InsertItem (ItemType item, bool& done)
{
  done = true;
 
// loops through the list and if the item value already
// exists in the list, then the new item is not inserted.
// If the item value is not in the list, it is inserted
// at the end of the array. 
  for (int i=0; i<length+1; i++)
  {
	if (info[i].ComparedTo(item) == EQUAL)
	{
	  done = false;
	  break;
	}
  }
  if (done)
  {
	InsertItem(item);
  }
}


// Pre: List has been initialized and is not empty. 
// 	listOne and listTwo are initiailized but empty.
// Post: listOne contains all the items of the list whose
// 	 keys are less than or equal to item's key;
// 	 listTwo contains all items of list whose keys are
// 	 greater than itme's key.
void UnsortedListByArray::SplitList (ItemType item, UnsortedListByArray& listLess,
					UnsortedListByArray& listGreater)
{
  int i = 0;

// loops through the list and if the element is less than
// or equal to the key, then it is placed in another list, listLess.
//
// If the element is greater than the key, it is placed
// in another list, listGreater.
  for (i; i<length; i++)
  {
	if (info[i].ComparedTo(item) == LESS)
	{
	  listLess.InsertItem(info[i]);
	}
	else if (info[i].ComparedTo(item) == EQUAL)
	{
	  listLess.InsertItem(info[i]);
	}
	else if (info[i].ComparedTo(item) == GREATER)
	{
	  listGreater.InsertItem(info[i]);
	}
  }

}


// Pre: List has been intialized. 
// 	listOne and listTwo have been initialized.
// Post: List contains all items from listOne and listTwo.
// 	 If there are duplicate items, keep all of them in the list.
void UnsortedListByArray::MergeList(UnsortedListByArray& listLess,
					UnsortedListByArray& listGreater)
{

// Takes all the items from listLess and adds them to a new list.
  for (int i=0; i<listLess.length; i++)
  {
	InsertItem(listLess.info[i]);
  }
// Takes all the items from listGreater and adds them to the new list
// to make the new list a combination of the two smaller lists.
  for (int i=0; i<listGreater.length; i++)
  {
	InsertItem(listGreater.info[i]);
  }


}








