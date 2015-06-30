/* initial memory allocated for the set */
#define INITSETSIZE 64

/* size of the different types */
#define CHAR 1
#define INT sizeof(int)
#define DOUBLE sizeof(double)

typedef struct universalSet {
 void *elem;//pointer to elements of the set
 int card;//cardinal of the set
 int type;//type of elements in the set (CHAR INT or DOUBLE)
 } uset;

 /* initialize an empty set of type type (one of: CHAR INT DOUBLE)
 * allocate memory for the set: INITSETSIZE * type
 */
 void newSet(uset *set, int type);

 /* free the memory allocated by newSet */
 void deletSet(uset *set);

/* add the element pointed by elem to the end of set
* check whether the element is already in the set
* resize memory if card > allocated memory
* new allocated memory = allocated memory+64
* e.g. before: mem=128, card=128, after: men=192, card=129
*/
void addElem(void *elem, uset *set);

/* remove the element pointed by elem from the set
* do nothing if the set does not contain this element
* resize memory if "too much memory" is used
* new allocated memory = allocated memory-64
* e.g. before: mem=192, card=129, after: card=128, mem=128
*/
void remElem(void *elem, uset *set);