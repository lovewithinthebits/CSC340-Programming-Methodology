/**
 * @file hash_table.h
 * @brief Implementation of the member functions for the HashTable class
 *
 * @date 09-21-2026 Initial creation and comments
 * 
 * @author Alexander Rieke
 * @email riekealexander@gmail.com
 * @studentID 926617494
 */

#include "hash_table.h"

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
HashNode** HashTable::getTable() {
        return table;
    }


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
