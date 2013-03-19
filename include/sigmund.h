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

#ifndef SIGMUND_H
#define SIGMUND_H

#define SIGMUND_VERSION_MAJOR 0
#define SIGMUND_VERSION_MINOR 2
#define SIGMUND_VERSION_PATCH 0
#define SIGMUND_MAKE_VERSION(major, minor, patch) \
  ((major) * 10000 + (minor) * 100 + (patch))
#define SIGMUND_VERSION \
  SIGMUND_MAKE_VERSION( \
      SIGMUND_VERSION_MAJOR, \
      SIGMUND_VERSION_MINOR, \
      SIGMUND_VERSION_PATCH)

#include "json.h"
#include "error.h"
#include "list.h"

#endif
