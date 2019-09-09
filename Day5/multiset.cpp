// Testing Standard Library class multiset
  #include <iostream>
  #include <set> 
  #include <algorithm>
  #include <iterator>
  using namespace std;

  // define short name for multiset type used in this program
  typedef std::multiset< int, std::less< int > > ms;        

  int main()
  {
     const int SIZE = 10;
     int a[ SIZE ] = { 7, 22, 9, 1, 18, 30, 100, 22, 85, 13 };
     ms intMultiset; // ms is typedef for "integer multiset"
     std::ostream_iterator< int > output( cout, " " );

     cout << "There are currently " << intMultiset.count( 15 )<< " values of 15 in the multiset\n";

     intMultiset.insert( 15 ); // insert 15 in intMultiset
     intMultiset.insert( 15 ); // insert 15 in intMultiset
     cout << "After inserts, there are " << intMultiset.count( 15 )<< " values of 15 in the multiset\n\n";

     // iterator that cannot be used to change element values
     ms::const_iterator t;

     // find 15 in intMultiset; find returns iterator
     t = intMultiset.find( 15 );                

     if ( t != intMultiset.end() ) // if iterator not at end
        cout << "Found value 15\n"; // found search value 15

     // find 20 in intMultiset; find returns iterator
     t = intMultiset.find( 20 );                

     if ( t == intMultiset.end() ) // will be true hence
        cout << "Did not find value 20\n"; // did not find 20

     // insert elements of array a into intMultiset
     intMultiset.insert( a, a + SIZE );            
     cout << "\nAfter insert, intMultiset contains:\n";
     std::copy( intMultiset.begin(), intMultiset.end(), output );
     cout<<endl;
     
     return 0;
  } // end main
