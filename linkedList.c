#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk node dalam double linked list
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Fungsi untuk menambah node di tengah (push_mid)
void push_mid(struct Node **head_ref, int new_data)
{
    // Membuat node baru
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    // Jika list kosong, node baru menjadi head
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // Temukan posisi tengah
    struct Node *slow = *head_ref;
    struct Node *fast = *head_ref;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Sisipkan node baru di tengah
    new_node->next = slow->next;
    new_node->prev = slow;

    if (slow->next != NULL)
        slow->next->prev = new_node;
    slow->next = new_node;
}

// Fungsi untuk menghapus node dari depan (delete_front)
void delete_front(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List kosong!\n");
        return;
    }

    struct Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;

    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;

    free(temp);
}

// Fungsi untuk menghapus node dari belakang (delete_back)
void delete_back(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List kosong!\n");
        return;
    }

    struct Node *temp = *head_ref;

    // Traverse sampai akhir list
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
        temp->prev->next = NULL;

    free(temp);
}

// Fungsi untuk menghapus node di tengah (delete_mid)
void delete_mid(struct Node **head_ref)
{
    if (*head_ref == NULL || (*head_ref)->next == NULL)
    {
        printf("List kosong atau hanya ada satu elemen!\n");
        return;
    }

    // Temukan posisi tengah
    struct Node *slow = *head_ref;
    struct Node *fast = *head_ref;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Hapus node tengah
    if (slow->prev != NULL)
        slow->prev->next = slow->next;

    if (slow->next != NULL)
        slow->next->prev = slow->prev;

    free(slow);
}

// Fungsi untuk menampilkan list
void print_list(struct Node *node)
{
    if (node == NULL)
    {
        printf("List kosong!\n");
        return;
    }

    while (node != NULL)
    {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Fungsi utama untuk testing
int main()
{
    struct Node *head = NULL;

    // Menambah elemen di tengah
    push_mid(&head, 10);
    push_mid(&head, 20);
    push_mid(&head, 30);
    push_mid(&head, 40);
    push_mid(&head, 50);

    printf("List setelah push_mid: ");
    print_list(head);

    // Menghapus elemen dari depan
    delete_front(&head);
    printf("List setelah delete_front: ");
    print_list(head);

    // Menghapus elemen dari belakang
    delete_back(&head);
    printf("List setelah delete_back: ");
    print_list(head);

    // Menghapus elemen di tengah
    delete_mid(&head);
    printf("List setelah delete_mid: ");
    print_list(head);

    return 0;
}
