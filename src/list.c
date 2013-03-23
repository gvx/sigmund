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

list_node* list_node_new(void *data) {
  list_node *node = (list_node*) malloc(sizeof(list_node));

  if (node) {
    node->data = data;
    node->next = NULL;
    return node;
  } else {
    return NULL;
  }
}

void list_node_destroy(list_node *node) {
  free(node);
}

list* list_new() {
  list *new_list = (list*) malloc(sizeof(list));

  if (new_list) {
    new_list->root_node = NULL;
    new_list->tail_node = NULL;
    return new_list;
  } else {
    return NULL;
  }
}

void list_destroy(list *list) {
  free(list);
}

void list_add_node(list *list, list_node *node) {
  if (list->root_node == NULL && list->tail_node == NULL) {
    list->root_node = node;
    list->tail_node = node;
  } else {
    list_node *previous_tail = list->tail_node;
    previous_tail->next = node;
    list->tail_node = node;
  }
}

list_node* list_remove_node(list *list, list_node *node) {
  list_node *current_node = list->root_node;
  list_node *previous_node = list->root_node;
  list_node *next_node = current_node->next;

  while (current_node != NULL) {
    if (current_node == node) {
      previous_node->next = next_node;

      return current_node;
    } else {
      previous_node = current_node;
      current_node = current_node->next;
      if (next_node != NULL) {
        next_node = current_node->next;
      }
    }
  }

  // The culprit was not found
  return NULL;
}
