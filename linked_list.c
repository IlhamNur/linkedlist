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

// Fungsi untuk menambah elemen di akhir (push_back)
void push_back(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    // Jika list kosong, node baru menjadi head
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    // Traverse ke node terakhir
    while (last->next != NULL)
        last = last->next;

    // Masukkan node baru setelah node terakhir
    last->next = new_node;
    new_node->prev = last;
}

// Fungsi utama untuk testing
int main()
{
    struct Node *head = NULL;
    int n, value, operation;

    // Input jumlah elemen yang ingin dimasukkan
    printf("Masukkan jumlah elemen dalam list: ");
    scanf("%d", &n);

    // Input elemen-elemen awal
    printf("Masukkan %d elemen:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Elemen %d: ", i + 1);
        scanf("%d", &value);
        push_back(&head, value);
    }

    // Menampilkan list awal
    printf("List awal: ");
    print_list(head);

    // Menu operasi
    do
    {
        printf("\nPilih operasi:\n");
        printf("1. Push Mid\n");
        printf("2. Delete Front\n");
        printf("3. Delete Back\n");
        printf("4. Delete Mid\n");
        printf("5. Tampilkan List\n");
        printf("6. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            // Input data untuk push_mid
            printf("Masukkan nilai untuk Push Mid: ");
            scanf("%d", &value);
            push_mid(&head, value);
            break;
        case 2:
            delete_front(&head);
            break;
        case 3:
            delete_back(&head);
            break;
        case 4:
            delete_mid(&head);
            break;
        case 5:
            printf("List terkini: ");
            print_list(head);
            break;
        case 6:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Pilihan tidak valid! Coba lagi.\n");
        }
    } while (operation != 6);

    return 0;
}
