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
 */

#ifndef JSON_H
#define JSON_H

#include <string.h>
#include <stdlib.h>

#include "list.h"

/** 
 * JSON variable type
 *
 * Variables:
 *  - NULL_VALUE: Null
 *  - BOOLEAN: True or false
 *  - NUMBER: A positive or negative integer
 *  - STRING: A string of at least 1 character
 *  - ARRAY: A list of variables
 *  - OBJECT: A key/value pair of variables
 **/
typedef enum {
  NULL_VALUE = 0,
  BOOLEAN = 1,
  NUMBER = 2,
  STRING = 3,
  ARRAY = 4,
  OBJECT = 5
} json_t;

/**
 * JSON key/value pair
 *
 * Variables:
 *  - (json_t) type: The type of value being stored
 *  - (char) key: The JSON key
 *  - (void*) value: The JSON value
 **/
typedef struct {
	json_t type;
  char key;
  void *value;
} json_keyval;

/**
 * JSON key/value pair initialization method
 *
 * Parameters:
 *  - (json_t) type: The type of data the key/value pair holds
 *  - (char) key: The new key/value pair key
 *  - (void*) value: The new key/value pair value
 *
 * Returns:
 *  - Success: json_keyval pointer
 *  - Failure: NULL
 **/
json_keyval* json_keyval_new(json_t type, char key, void *value);

/**
 * JSON key/value pair destructor method
 *
 * Parameters:
 *  - (json_keyval*) key_val: The JSON key/value pair to destroy
 *
 * Returns:
 *	- Void
 **/
void json_keyval_destroy(json_keyval *key_val);

/**
 * JSON file object that holds all other key/value pairs
 * 
 * Variables:
 *	- (linked_list*) list: List of all key/value pairs
 **/
typedef struct {
	list *list;
} json_object;

/**
 * JSON object constructor method
 *
 * Parameters:
 *	- None
 * 
 * Returns:
 *	- Success: json_object pointer
 *	- Failure: NULL
 **/
json_object* json_object_new();

/**
 * JSON object destructor method
 *
 * Parameters:
 *	- (json_object*) object: The JSON object to destroy
 *
 * Returns:
 *	- Void 
 **/
void json_object_destroy(json_object *object);

#endif
