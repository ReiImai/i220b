#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct KeyValue {
  const char *key;       
  int value;             
  struct KeyValue *succ; /** next key-value in chain */
};


static struct KeyValue *
add_key_value(struct KeyValue *keyValues, const char *k, int v)
{
  //allocate storage for new KeyValue struct
  struct KeyValue *kv = malloc(sizeof(struct KeyValue *));

  //allocate storage for string pointed to by k
  char *s = malloc((strlen(k)+1) * sizeof(char));
 

  if (kv == NULL || s == NULL) { //check if allocations succeeded
    fprintf(stderr, "malloc failure: %s\n", strerror(errno));
    exit(1);
  }
  strcpy(s, k);  //copy string k into newly allocated memory pointed to by s

  //initialize fields of *kv.
  kv->key = s; kv->value = v; kv->succ = keyValues;
 	

  return kv;
}



static void
free_key_values(struct KeyValue *keyValues)
{
  for (struct KeyValue *p = keyValues; p != NULL; p = p->succ) {
    free(p); 
  }
}




static struct KeyValue *
make_key_values(void) {
  const char *keys[] = {
    "twas", "brillig", "rei", "the", "slithy", "toves",
    "did", "gyre", "and", "gimble", "in", "the", "wabe",
    "all", "mimsy", "were", "the", "borogoves",
    "and", "the", "mome", "raths", "outgrabe",
  };
  struct KeyValue *p = NULL;
  for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
    p = add_key_value(p, keys[i], i);
  }
  return p;
}




int main() {
  struct KeyValue *keyValues = make_key_values();
  for (struct KeyValue *p = keyValues; p != NULL; p = p->succ) {
    printf("%s: %d\n", p->key, p->value);
    
 
  }
  free_key_values(keyValues);


  return 0;
}
