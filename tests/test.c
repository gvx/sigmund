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

	list *list = list_new();
	MU_TEST(list != NULL,
			"Error in \"create_list\": Cannot create list");
	list_destroy(list);

	return 0;
}

char* create_list_node() {
	puts("Starting test: create_list_node");

	char *hello = "Hello, world!";
	list_node *node = list_node_new((void*) hello);
	MU_TEST(node != NULL,
				"Error in \"create_list_node\": Cannot create node");
	list_node_destroy(node);

	return 0;
}

char* add_node_to_list() {
	puts("Starting test: add_node_to_list");

	char *hello = "Hello, world!";
	char *goodbye = "Goodbye, cruel world!";
	list *list = list_new();
	list_node *hello_node = list_node_new((void*) hello);
	list_node *goodbye_node = list_node_new((void*) goodbye);

	MU_TEST(list_add_node(list, hello_node) == 0,
		"Error in \"add_node_to_list\": Cannot add node to list");
	
	MU_TEST(list_add_node(list, goodbye_node) == 0,
		"Error in \"add_node_to_list\": Cannot add node to list");

	puts("  Iterating through list...");
	for (list_node *node = list->root_node; node != NULL; node = node->next) {
		printf("    %s\n", (char*) node->data);
	}

	list_destroy(list);
	list_node_destroy(hello_node);
	list_node_destroy(goodbye_node);

	return 0;
}

char* remove_node_from_list() {
	puts("Starting test: remove_node_from_list");

	char *hello = "Hello, world!";
	char *goodbye = "Goodbye, cruel world!";
	list *list = list_new();
	list_node *hello_node = list_node_new((void*) hello);
	list_node *goodbye_node = list_node_new((void*) goodbye);
	
	list_add_node(list, hello_node);
	list_add_node(list, goodbye_node);

	MU_TEST(list_remove_node(list, hello_node) != NULL,
			"Error in \"remove_node_from_list\": Cannot remove node from list");

	MU_TEST(list_remove_node(list, goodbye_node) != NULL,
			"Error in \"remove_node_from_list\": Cannot remove node from list");

	list_destroy(list);
	list_node_destroy(hello_node);
	list_node_destroy(goodbye_node);

	return 0;
}

char* create_json_object() {
	puts("Starting test: create_json_object");

	json_object *object = json_object_new();
	MU_TEST(object != NULL,
			"Error in \"create_json_object\": Cannot create object");

	json_object_destroy(object);
	return 0;
}

static char* run_tests() {
	puts("BEGINNING LIST TESTS");
	MU_RUN_TEST(create_list);
	MU_RUN_TEST(create_list_node);
	MU_RUN_TEST(add_node_to_list);
	MU_RUN_TEST(remove_node_from_list);

	printf("\n");

	puts("BEGINNING JSON TESTS");
	MU_RUN_TEST(create_json_object);
	return 0;
}

int main() {
	char *result = run_tests();

	if (result != 0) {
		printf("\n%s\n", result);
	} else {
		puts("\nTests complete. No errors found.");
	}
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
