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

#include "../sigmund.h"
#include <string.h>
#include <stdlib.h>

/** 
 * JSON variable type
 *  - Primitive: number, boolean, or null
 *  - String: a string of at least 1 character
 *  - Array: a list of variables
 *  - Object: a key/value pair of variables
 */
typedef enum {
  PRIMITIVE = 0,
  STRING = 1,
  ARRAY = 2,
  OBJECT = 3
} jsontype_t;

/**
 * JSON key/value pair
 *  - (char*) key: The JSON key
 *  - (void*) value: The JSON value
 */
typedef struct {
  char *key;
  void *value;
  size_t size;
} json_keyval;

/**
 * JSON key/value pair initialization method
 * Parameters:
 *  - (json_keyval*) key_pair: The JSON key/value pair to initialize
 *
 * Returns:
 *  - Success: 0
 *  - Failure: -1
 */
int json_keyval_new(json_keyval *key_pair);

/**
 * JSON key/value pair destructor method
 * Parameters:
 *  - (json_keyval*) key_pair: The JSON key/value pair to destroy
 *
 * Returns:
 *  - Success: 0
 *  - Failure: -1
 */
int json_keyval_destroy(json_keyval *key_pair);

#endif
