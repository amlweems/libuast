#ifndef LIBUAST_ROLES_TEST_H_
#define LIBUAST_ROLES_TEST_H_

#include <cstdio>
#include <cstring>

extern "C" {
#include <CUnit/Basic.h>
}

#include "roles.h"
#include "uast.h"

static void TestRoleNameForId(void) {
  // Test two first roles names
  CU_ASSERT_FATAL(strcmp(RoleNameForId(0), "roleInvalid") == 0);
  CU_ASSERT_FATAL(strcmp(RoleNameForId(1), "roleIdentifier") == 0);

  // Automatically test the rest of names
  uint16_t nu_roles = 118;
  for (uint16_t i = 0; i < nu_roles; i++) {
    const char *role = RoleNameForId(i);
    CU_ASSERT_FATAL(strlen(role) > 4);
    CU_ASSERT_FATAL(strncmp(role, "role", 4) == 0);
  }

  // Test out of bounds roles
  for (uint16_t i = nu_roles; i < nu_roles + 10; i++) {
    const char *role = RoleNameForId(i);
    CU_ASSERT_FATAL(role == NULL);
  }
}

#endif  // LIBUAST_ROLES_TEST_H_
