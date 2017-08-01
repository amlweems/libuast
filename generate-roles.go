package main

import "github.com/bblfsh/sdk/uast"
import "fmt"

func main() {
	lastRole := uast.Whitespace + 1
	fmt.Println(
		`////////////////////////////////////////////////////
// Automatically generated by "generate-roles.go" //
////////////////////////////////////////////////////

#include "roles.h"

static const char *no_rule = "role.empty";
static const char *unknown_rule = "role.unknown";
static const char *id_to_roles[] = {`)

	for i := 0; i < int(lastRole); i++ {
		roleID := uast.Role(i)
		name := "role" + roleID.String()
		fmt.Printf("    \"%s\",\n", name)
	}
	fmt.Println("};")

	fmt.Println("#define TOTAL_ROLES ", int(lastRole))

	fmt.Println(`
const char *role_name_for_id(uint16_t id) {
	if(id == 0) {
		return no_rule;
	}
	if(id >= TOTAL_ROLES) {
		return unknown_rule;
	}
	return id_to_roles[id];
}
`)
}
