/* Copyright 2013 Zach Dziura <zcdziura@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/**
 * A linked list node, used to hold any form of information
 *
 * Variables:
 *	- (void*) data: The data being stored
 *	- (list_node*) next: The next node in the list
 **/
typedef struct list_node {
	void *data;
	struct list_node *next;
} list_node;

/**
 * List node initializer method
 *
 * Parameters:
 *	- (void*) data: The data which the node holds
 *
 * Returns:
 *	- Success: list_node pointer
 *	- Failure: NULL
 **/
list_node* list_node_new(void *data);

/**
 * List node destructor method
 *
 * Parameters:
 *	- (list_node*) node: The node to be destroyed
 *
 * Returns:
 *	- Void
 **/
void list_node_destroy(list_node *node);

/**
 * A linked list
 *
 * Variables:
 *	- (list_node*) root_node: The first node in the list
 *	- (list_node*) tail_node: The last node in the list
 **/
typedef struct list {
	list_node *root_node;
	list_node *tail_node;
} list;

/**
 * Linked list initializer method
 *
 * Parameters:
 *	- None
 *
 * Returns:
 *	- Success: list pointer
 *	- Failure: NULL
 **/
list* list_new();

/**
 * Linked list destructor method
 *
 * Parameters:
 *	- (list*) list: The list to be destroyed
 *
 * Returns:
 *	- Void
 **/
void list_destroy(list* list);

/**
 * Add a node to the list
 *
 * Parameters:
 *	- (list*) list: The list to append the node to
 *	- (list_node*) node: The node to append
 *
 * Returns:
 *	- Success: 0
 *	- Failure: -1
 **/
int list_add_node(list *list, list_node *node);

/**
 * Remove a node from the list
 *
 * Parameters:
 *	- (list*) list: The list to remove the node from
 *	- (list_node*) node: The node to remove
 *
 * Returns:
 *	- Success: (list_node*) The node that was removed
 *	- Failure: NULL
 **/
list_node* list_remove_node(list *list, list_node *node);

#endif
