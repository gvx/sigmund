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

#include "../include/json.h"

json_keyval* json_keyval_new() {
	json_keyval *key_val;
	key_val = (json_keyval*) malloc(sizeof(json_keyval));

	if (key_val) {
		return key_val;
	} else {
		return NULL;
	}
}

void json_keyval_destroy(json_keyval* key_val) {
	free(key_val);
}
