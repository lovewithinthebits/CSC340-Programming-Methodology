I will not be attempting extra credit for milestone 2


# UML sequence diagram
It wasn't clear in the assignment description what the required scope of the sequence diagram was. I emailed you and established your expectations, but I'm including this section in the readme to elaborate on what exactly I attempted to include in my sequence diagram. 

In our email correspondence you said "It should show an overall flow of the program, it could be a happy path the program goes through, or some test case."

So i decided to attempt to model the interactions between the program's components while processing the major operations in the most rigorous test case. From inspecting the test conditions it seemd like test case 5 was the most rigorous, so I decided to include all of the details behind the operations involved in that test case.

# AI attribution section

## Prompt 1

I'm doing a project for school where I'm implementing a hash table. Can you output just the declarations (not implementation) of these member functions from this header file with the appropriate doxygen style comments? I just want a skeleton for me to actually implement the functions. 

Format the comments for each of them like this  

/**
*
* reversePrintList 
*
* prints all the values of the nodes in the list in reverse
*
* TESTED, WORKING
*
* @param    none 
*
* @return   none
*
*/

### Response 1
Yep. Based strictly on the `hash_node.h` you uploaded, there are **two member functions** declared in `HashNode`: the constructor and `printNode(bool verbose)`. 

Here they are as a skeleton, using your exact comment style:

```cpp
/**
*
* HashNode
*
* constructs a new HashNode with the given data
*
* @param    val             key value
* @param    myFullName      full name associated with the key
* @param    myAddress       address
* @param    myCity          city
* @param    myState         state
* @param    myZip           zip code
*
* @return   none
*
*/
HashNode(int val, std::string myFullName, std::string myAddress,
         std::string myCity, std::string myState, std::string myZip);


/**
*
* printNode
*
* prints the information stored in the node
*
* @param    verbose     determines whether the node information is printed
*                       in verbose format
*
* @return   none
*
*/
void printNode(bool verbose);
```

I left out `TESTED, WORKING` since you haven't implemented or tested these yet.

## Prompt 2
sorry I sent the wrong header file I meant this

### Response 2
Yep — if these are going into your **`hash_table.cpp` implementation file**, the declarations/signatures should be scoped with `HashTable::` like this:

```cpp
/**
*
* HashTable
*
* constructs a new hash table with the specified number of buckets
*
* @param    hashTableSize   number of buckets in the hash table
*
* @return   none
*
*/
HashTable::HashTable(int hashTableSize);


/**
*
* ~HashTable
*
* destroys the hash table and releases dynamically allocated memory
*
* @param    none
*
* @return   none
*
*/
HashTable::~HashTable();


/**
*
* getTable
*
* gets the internal array of bucket pointers
*
* @param    none
*
* @return   pointer to the array of HashNode pointers
*
*/
HashNode** HashTable::getTable();


/**
*
* getSize
*
* gets the number of buckets in the hash table
*
* @param    none
*
* @return   number of buckets in the hash table
*
*/
int HashTable::getSize();


/**
*
* calculateHashCode
*
* calculates the hash code for a given key
*
* @param    currentKey   key used to calculate the hash code
*
* @return   calculated bucket index
*
*/
int HashTable::calculateHashCode(int currentKey);


/**
*
* isEmpty
*
* determines whether the hash table is empty
*
* @param    none
*
* @return   true if the hash table is empty, false otherwise
*
*/
bool HashTable::isEmpty();


/**
*
* getNumberOfItems
*
* gets the number of items currently stored in the hash table
*
* @param    none
*
* @return   number of items currently stored in the hash table
*
*/
int HashTable::getNumberOfItems();


/**
*
* add
*
* adds a new node to the hash table
*
* @param    curKey   key associated with the node
* @param    myNode   pointer to the node to be added
*
* @return   true if the node was successfully added, false otherwise
*
*/
bool HashTable::add(int curKey, HashNode* myNode);


/**
*
* remove
*
* removes the node associated with the specified key from the hash table
*
* @param    curKey   key of the node to remove
*
* @return   true if the node was successfully removed, false if not found
*
*/
bool HashTable::remove(int curKey);


/**
*
* clear
*
* clears the entire hash table by deleting all entries
*
* @param    none
*
* @return   none
*
*/
void HashTable::clear();


/**
*
* getItem
*
* retrieves the node associated with the specified key
*
* @param    curKey   key of the node to retrieve
*
* @return   pointer to the corresponding HashNode, or nullptr if not found
*
*/
HashNode* HashTable::getItem(int curKey);


/**
*
* contains
*
* determines whether a node with the specified key exists in the hash table
*
* @param    curKey   key to search for
*
* @return   true if the key is found, false otherwise
*
*/
bool HashTable::contains(int curKey);


/**
*
* printTable
*
* prints the contents of the hash table
*
* @param    none
*
* @return   none
*
*/
void HashTable::printTable();
```

One important distinction: **don't add `HashTable::` to the declarations inside `hash_table.h`**. The prefix is used when defining the functions outside the class, normally in `hash_table.cpp`. The signatures themselves come from your uploaded header.


