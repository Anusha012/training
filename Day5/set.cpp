
// Testing Standard Library class set
  #include <iostream>
  #include <set> 
  #include <algorithm>
  #include <iterator>
  using namespace std;

  // define short name for set type used in this program
  typedef std::set< int, std::less< int > > ms;        

  int main()
  {
     const int SIZE = 10;
     int a[ SIZE ] = { 7, 22, 9, 1, 15, 30, 100, 22, 85, 13 };
     ms intset; // ms is typedef for "integer set"
     std::ostream_iterator< int > output( cout, " " );

     cout << "There are currently " << intset.count( 15 )<< " values of 15 in the set\n";

     intset.insert( 15 ); // insert 15 in intset
     intset.insert( 15 ); // insert 15 in intset
     cout << "After inserts, there are " << intset.count( 15 )<< " values of 15 in the set\n\n";

     // iterator that cannot be used to change element values
     ms::const_iterator t;

     // find 15 in intset; find returns iterator
     t = intset.find( 15 );                

     if ( t != intset.end() ) // if iterator not at end
        cout << "Found value 15\n"; // found search value 15

     // find 20 in intset; find returns iterator
     t = intset.find( 20 );                

     if ( t == intset.end() ) // will be true hence
        cout << "Did not find value 20\n"; // did not find 20

     // insert elements of array a into intset
     intset.insert( a, a + SIZE );            
     cout << "\nAfter insert, intset contains:\n";
     std::copy( intset.begin(), intset.end(), output );
     cout<<endl;
     
     return 0;
  } // end main
