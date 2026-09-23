/**
 * @file hash_table.cpp
 * @brief Implementation of the member functions for the HashTable class
 *
 * @date 09-21-2026 Initial creation and comments, implementation of getTable
 * @date 09-22-2026 Implementation of most member functions
 * @date 09-23-2026 Implementation of the last three member functions, getItem, contains, and printTable
 * 
 * @author Alexander Rieke
 * @email riekealexander@gmail.com
 * @studentID 926617494
 */

#include "hash_table.h"
#include "milestone2.h"

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
* @status COMPLETED, TESTED
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
* @status COMPLETED, TESTED
*
*/
int HashTable::getSize() {
        return numberOfBuckets;
    }


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
* @status COMPLETED, TESTED
*
*/
int HashTable::calculateHashCode(int currentKey) {
        return (currentKey % numberOfBuckets);
    }


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
* @status COMPLETED, TESTED
*
*/
bool HashTable::isEmpty() {
        return (numberOfItems == 0);
    }


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
* @status COMPLETED, TESTED
*
*/
int HashTable::getNumberOfItems() {
        return numberOfItems;
    }


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
* @status COMPLETED, TESTED
*
*/
bool HashTable::add(int curKey, HashNode* myNode) {
        // check for failures
        if (myNode == nullptr) {return false;} 
        if (contains(curKey)) {return false;}

        int bucket_index = calculateHashCode(curKey);

        myNode->key = curKey;
        myNode->hashCode = bucket_index;

        // insert node at the head
        myNode->prev = nullptr;
        myNode-> next = table[bucket_index];

        // if bucket isn't empty, makes the old_head->prev point to the new node
        if (table[bucket_index] != nullptr) {
            table[bucket_index]->prev = myNode; 
            }

        // make the beginning of the bucket point to the new node
        table[bucket_index] = myNode;

        ++numberOfItems;

        return true;
    }


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
* @status COMPLETED, TESTED
*
*/
bool HashTable::remove(int curKey) {
        int bucket_index = calculateHashCode(curKey);

        HashNode* current_node = table[bucket_index];

        while (current_node != nullptr) {
            if (current_node->key == curKey) {
                
                // accounting for the previous node
                if (current_node->prev != nullptr) {
                    current_node->prev->next = current_node->next;
                } else {
                    // the case where the the current is the head
                    table[bucket_index] = current_node->next;
                    }
                // accounting for the next node
                if (current_node->next != nullptr) {
                    current_node->next->prev = current_node->prev;
                    }

                current_node->prev = nullptr;
                current_node->next = nullptr;

                --numberOfItems;

                return true;

                }
            current_node = current_node->next;
            }
        // the case where no matching key is found
        return false;
    }


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
* @status COMPLETED, TESTED
*
*/
void HashTable::clear() {
    for (int i = 0; i < numberOfBuckets; ++i) {
        HashNode* current_node = table[i];

        // delete all the nodes from the current bucket
        while (current_node != nullptr) {
            HashNode* temp_node = current_node;
            current_node = current_node->next;
            delete temp_node; 
            } 
        table[i] = nullptr;
        }
    numberOfItems = 0;
    }


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
* @status COMPLETED, TESTED
*
*/
HashNode* HashTable::getItem(int curKey) {
        int bucket_index = calculateHashCode(curKey);
        HashNode* current_node = table[bucket_index];

        // search through every node in each bucket starting from the head
        while (current_node !=nullptr) {
            if (current_node->key == curKey) {
                return current_node;
                }
            current_node = current_node->next;
            }
        return nullptr;
    }


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
* @status COMPLETED, TESTED
*
*/
bool HashTable::contains(int curKey) {
        return (getItem(curKey) != nullptr);
    }


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
* @status COMPLETED, TESTED
*
*/
void HashTable::printTable() {
        logToFileAndConsole(
            "\nHere are the Hash Table contents (" +
            std::to_string(numberOfItems) + 
            " entries):"
        );

        for (int i = 0; i < numberOfBuckets; ++i) {
            if (table[i] == nullptr) {
                logToFileAndConsole (
                    "Bucket " + std::to_string(i) + ": Empty"
                    );
                } 
            else {
                logToFileAndConsole (
                    "Bucket " + std::to_string(i) + ": "
                    );

                HashNode* current_node = table[i];

                while (current_node != nullptr) {
                    current_node->printNode(true);
                    current_node = current_node->next;
                    }
                }
            }
        logToFileAndConsole("End of table");
    }
