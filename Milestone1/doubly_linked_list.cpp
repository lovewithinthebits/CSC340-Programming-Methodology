/**
 * @file doubly_linked_list.h
 * @brief Implementation of the DoublyLinkedList class and its member functions
 *
 * This file implements a basic doubly linked list and common operations like
 * insertion, deletion, and movement of nodes.
 *
 * @date 08-28-2026 - Initial creation and comments, implementation of isEmpty function
 * @date 08-29-2026 - Implementation of insertAtHead, insertAtTail, and removeHeaderNode 
 * functions
 * @date 09-08-2026 - Implementation of remove, removeTailNode, moveNodeToHead, moveNodeToTail,
 * clear, printList, and reversePrintList functions. Also updated styling and added last touches and fixes
 * 
 * @author Alexander Rieke
 * @email riekealexander@gmail.com
 * @studentID 926617494
 */

#include "doubly_linked_list.h"
#include "milestone1.h"

/**
*
* DoublyLinkedList
*
* constructor
*
* TESTED, WORKING
*
* @param    none
*
* @return   none 
*
*/
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    }

/**
*
* ~DoublyLinkedList
*
* destructor
*
* TESTED, WORKING
*
* @param    none
*
* @return   none       
*
*/

DoublyLinkedList::~DoublyLinkedList() {
    clear();
    }

/**
*
* isEmpty
*
* checks to see if list is empty
*
* TESTED, WORKING
*
* @param key    none
*
* @return       bool value pertaining to empty status
*
*/
///< Checks if the list is empty.
bool DoublyLinkedList::isEmpty() {
    return head == nullptr;
    }

/**
*
* insertAtHead
*
* inserts a node at the head of the list
*
* TESTED, WORKING
*
* @param key    key value of the added node
*
* @return       none
*
*/
void DoublyLinkedList::insertAtHead(int key) {
    DllNode* new_node = new DllNode(key);
    if (isEmpty()) {
        head = new_node;
        tail = new_node;
    } else {
        head->prev = new_node; 
        new_node->next = head;
        head = new_node; 
        }
    } 

/**
*
* insertAtTail 
*
* inserts a node at the tail end of the list
*
* TESTED, WORKING
*
* @param key    key value of the added node
*
* @return       none
*
*/
void DoublyLinkedList::insertAtTail(int key) {
    DllNode* new_node = new DllNode(key);
    if (isEmpty()) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node; 
        }
    }

/**
*
* remove
*
* removes a node with a specific key.
* 
*
* TESTED, WORKING
*
* @param key    key value of the added node
*
* @return       none
*
*/
void DoublyLinkedList::remove(int key) {
    /*
    // old version, has problems with edge cases of search_node
    // being head or tail
    DllNode* search_node = head;
    while (search_node != nullptr) {
        if (search_node->key == key) {
            search_node->next->prev = search_node->prev;
            search_node->prev->next = search_node->next;
            delete search_node;
        }
        search_node = search_node->next;
    }
    */
    
    DllNode* search_node = head;
    while (search_node != nullptr) {
        if (search_node->key == key) {

            if (search_node->prev == nullptr) {
                head = search_node->next;
                } else {
                search_node->prev->next = search_node->next;
                }

            if (search_node->next == nullptr) {
                tail = search_node->prev;
                } else {
                search_node->next->prev = search_node->prev;
                }

            delete search_node;
            return;
            }
        search_node = search_node->next;
        }
    }

/**
*
* removeHeaderNode
*
* removes the head node.
*
* TESTED, WORKING
*
* @param    none
*
* @return   none
*
*/
void DoublyLinkedList::removeHeaderNode() {
    if (!isEmpty()) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            }
        }
    }


/**
*
* removeTailNode
*
* removes the tail node
*
* TESTED, WORKING
*
* @param    none
*
* @return   none
*
*/
void DoublyLinkedList::removeTailNode() {
    if (!isEmpty()) {
        if (tail->prev == nullptr) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
            }
        }
    }

/**
*
* moveNodeToHead
*
* moves a node to the head
*
* TESTED, WORKING
*
* @param key    the key value of the node to move
*
* @return   none
*
*/
void DoublyLinkedList::moveNodeToHead(int key) {
    DllNode* search_node = head;
    while (search_node != nullptr) {
        if (search_node->key == key) {

            if (search_node->prev == nullptr) {
                return;
                } else {
                search_node->prev->next = search_node->next;
                }

            if (search_node->next == nullptr) {
                tail = search_node->prev;
                } else {
                search_node->next->prev = search_node->prev;
                }

            search_node->next = head;
            head->prev = search_node;
            search_node->prev = nullptr;
            head = search_node;
            return;
            }
        search_node = search_node->next;
        }        
    }

/**
*
* moveNodeToTail
*
* moves a node to the tail
*
* TESTED, WORKING
*
* @param key    the key value of the node to move
*
* @return   none
*
*/
void DoublyLinkedList::moveNodeToTail(int key) {
    DllNode* search_node = head;
    while (search_node != nullptr) {
        if (search_node->key == key) {

            if (search_node->next == nullptr) {
                return;
                } else {
                search_node->next->prev = search_node->prev;
                }

            if (search_node->prev == nullptr) {
                head = search_node->next;
                } else {
                search_node->prev->next = search_node->next;
                }

            search_node->prev = tail;
            tail->next = search_node;
            search_node->next = nullptr;
            tail = search_node;
            return;
            }
        search_node = search_node->next;
        }        
    }

/**
*
* clear
*
* clears the list
*
* TESTED, WORKING
*
* @param    none 
*
* @return   none
*
*/
void DoublyLinkedList::clear() {

    /*
    // old version
    while (!isEmpty()) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            }    
        }
    */

    // new better way
    while(head != nullptr) {
        DllNode* old_head = head;
        head = head->next;
        delete old_head;
        }
            
    tail = nullptr;

    }

/**
*
* printList
*
* prints all the values of the nodes in the list
*
* TESTED, WORKING
*
* @param    none 
*
* @return   none
*
*/

void DoublyLinkedList::printList() {
    logToFileAndConsole("\nHere are the List contents: ");
    DllNode* index_node = head;
    while (index_node != nullptr) {
        index_node->printNode();
        index_node = index_node->next;
        }
    logToFileAndConsole("End of List");
    }

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

void DoublyLinkedList::reversePrintList() {
    logToFileAndConsole("\nHere are the List contents reversed: ");
    DllNode* index_node = tail;
    while (index_node != nullptr) {
        index_node->printNode();
        index_node = index_node->prev;
        }
    logToFileAndConsole("End of List");
    }
