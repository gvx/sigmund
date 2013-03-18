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

#include "../include/sigmund.h"

/**
 * JSON key/value pair constructor method
 *
 * Parameters:
 *  - None 
 *
 * Returns:
 *  - Success: json_keyval pointer
 *  - Failure: NULL
 **/
json_keyval* json_keyval_new() {
	json_keyval *key_val;
	key_val = (json_keyval*) malloc(sizeof(json_keyval));

	if (key_val) {
		return key_val;
	} else {
		return NULL;
	}
}

/**
 * JSON key/value pair destructor method
 *
 * Parameters:
 *	- (json_keyval*) key_val: The key/value pair to be destroyed
 *
 * Returns:
 *	- Void
 **/
void json_keyval_destroy(json_keyval *key_val) {
	free(key_val);
}

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
json_object* json_object_new() {
	json_object *object;
	object = (json_object*) malloc(sizeof(json_object));

	if (object) {
		return object;
	}	else {
		return NULL;
	}
}

/**
 * JSON object destructor method
 *
 * Parameters:
 *	- (json_object*) object: The object to be destroyed
 *
 * Returns:
 *	- Void
 **/
void json_object_destroy(json_object *object) {
	free(object);
}
