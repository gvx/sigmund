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

#include <stdio.h>

#include "../include/sigmund.h"
#include "../include/minunit.h"

int tests_run = 0;

char* create_list() {
	puts("Starting test: create_list");
	MU_ASSERT(list_new() != NULL, "Error in \"create_list\": Cannot create list");

	return 0;
}

static char* run_tests() {
	MU_RUN_TEST(create_list);
	
	return 0;
}

int main() {
	char *result = run_tests();

	if (result != 0) {
		printf("%s\n", result);
	} else {
		puts("Tests complete. No errors found.");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
