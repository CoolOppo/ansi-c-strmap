#include <stdio.h>
#include "strmap.h"

int main() {
	// creating a new map
	StrMap *map = sm_new(4);

	// creating pairs
	sm_put(map, "tag", "Digital Cannon");
	sm_put(map, "character", "Electric Mouse");

	// getting values
	char buf[80];
	int result = sm_get(map, "character", buf, sizeof(buf));
	if (result) {
		printf("Character: %s\n", buf);
	} else {
		printf("No character\n");
	}

	// delete map when it is no longer needed
	sm_delete(map);

	return 0;
}
