//  Jack Kichula
//  Lab1

#include "ItemType.h"
#include "UnsortedListByArray.h"

void PrintList( UnsortedListByArray& list)
// Pre:  list has been initialized.         
// Post: Each component in list has been written. 
// 
{
  int length;
  ItemType item;

  list.ResetList( );
  length = list.GetLength( );
  for (int counter = 1; counter <= length; counter++)
  {
    list.GetNextItem(item);
    item.Print( );
  }
}

int main(){

    UnsortedListByArray listOne;

    UnsortedListByArray list;
    UnsortedListByArray listLess;
    UnsortedListByArray listGreater;
    UnsortedListByArray listCombine;

    ItemType a;
    a.Initialize(2);
    listOne.InsertItem(a);
    
    ItemType b;
    b.Initialize(5);
    listOne.InsertItem(b);
    
    ItemType c;
    c.Initialize(5);
    listOne.InsertItem(c);
    
    ItemType x;
    x.Initialize(5);
    listOne.InsertItem(x);

    ItemType y;
    y.Initialize(6);
    listOne.InsertItem(y);

    ItemType z;
    z.Initialize(5);
    listOne.InsertItem(z);
    
    cout << "Original List" << endl;
    PrintList(listOne);

    cout << " " << endl;

    listOne.DeleteAllItems(x);
    cout << "After DeleteAll Function" << endl;
    PrintList(listOne);

    cout << " " << endl;

    cout << "Before new insert" << endl;
    PrintList(listOne);
    
    bool done;
    listOne.InsertItem(a, done);
    
    cout << " " << endl;

    cout << "After new insert (2)" << endl;
    PrintList(listOne);

    cout << " " << endl;

    cout << "Before second insert" << endl;
    PrintList(listOne);

    ItemType i;
    i.Initialize(8);
    listOne.InsertItem(i, done);

    cout << " " << endl;

    cout << "After second insert (8)" << endl;
    PrintList(listOne);

// new list for split function

    
    ItemType aa;
    aa.Initialize(1);
    list.InsertItem(aa);
    
    ItemType ab;
    ab.Initialize(3);
    list.InsertItem(ab);

    ItemType ac;
    ac.Initialize(5);
    list.InsertItem(ac);

    ItemType ad;
    ad.Initialize(2);
    list.InsertItem(ad);

    ItemType ae;
    ae.Initialize(10);
    list.InsertItem(ae);

    ItemType af;
    af.Initialize(12);
    list.InsertItem(af);

    ItemType ag;
    ag.Initialize(0);
    list.InsertItem(ag);
    

    
    ItemType key;
    key.Initialize(4);
        
    cout << " " << endl;

    cout << "Before Split" << endl;
    PrintList(list);

    list.SplitList(key, listLess, listGreater);
    cout << " " << endl;

    cout << "After Split listLess (key = 4)" << endl;
    PrintList(listLess);
    cout << " " << endl;

    cout << "After Split listGreater (key = 4)" << endl;
    PrintList(listGreater);

    cout << " " << endl;

    listCombine.MergeList(listLess, listGreater);
    cout << "After Merge List" << endl;
    PrintList(listCombine);


/*
    listOne.MakeEmpty();
    cout<<listOne.IsEmpty()<<endl;
*/
    return 0;
}
