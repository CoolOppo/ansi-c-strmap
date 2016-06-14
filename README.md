# ANSI C Hash Table ("strmap")

This is Per Ola Kristensson's implementation of a hash map in ANSI C.
The origin of the code in this repo and it's explanation can be found
[here](http://www.pokristensson.com/strmap.html).

The simple implementation is described to have the following functionality:

1. Inserting and retrieving key-value associations
2. Querying the existence of a key
3. Returning the total number of key-value associations
4. Iterating over all key-value associations

**Usage**

[example.c](example.c):
```c
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
```

**License**

> The code ("strmap") is licensed under the
[GNU Lesser General Public License](https://www.gnu.org/licenses/lgpl-3.0.txt).

The license as it was when the code was last updated
is in [LICENSE.txt](LICENSE.txt).

**Notes**

>  First, the code is not thread-safe. Use external synchronization.
>
> Second, the implementation copies values upon insertion and retrieval.
This guarantees that no internal references are exposed to the client after
the hash table has been deleted from memory. There is one exception, however.
When iterating over all key-value associations, the internal strings are
temporarily exposed as constant pointers to the internal string buffers.
This is because it is very slow and cumbersome to copy all key-value
associations to a buffer via a callback function interface. It is recommended
not to keep the pointers to the internal string buffers around out of scope of
the callback function. Otherwise, you risk having wild pointers in your code
after you have deleted the hash table.
