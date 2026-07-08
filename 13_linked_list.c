#include <stdio.h>
#include <stdlib.h>   

typedef struct node 
    {
        int data;
        struct node *next;
    }node_t;
    
    //bellekten yer ayır
node_t *node_create(int data){
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if(new_node == NULL){
        printf("Bellek hatasi!\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//Listenin sonuna ekle
void list_append(node_t **head, int data) {
    node_t *new_node = node_create(data);
    if (new_node == NULL) return;

    /* Liste boşsa */
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    /* Sonuna kadar git */
    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}
//Baştan sona yazdır
void list_print(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//Tüm belleği free et
void list_destroy(node_t **head) {
    node_t *current = *head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}



int main(){

 node_t *head = NULL;
 list_append(&head,121);
 list_append(&head,122);
 list_append(&head,123);

 list_print(head);

 
list_destroy(&head);
list_print(head);








    return 0;
}