# Double Linked List in C

This project implements a **Double Linked List** in C with various operations such as insertion, deletion, and display.

## 📌 Features
- Insert an element in the middle (`push_mid`)
- Delete an element from the front (`delete_front`)
- Delete an element from the back (`delete_back`)
- Delete an element from the middle (`delete_mid`)
- Display the linked list (`print_list`)

## 📂 File Structure
- `main.c` → The main program file implementing the doubly linked list functions.

## 🚀 How to Compile and Run
1. **Compile the program**:
   ```bash
   gcc main.c -o linkedlist
   ```
2. **Run the program**:
   ```bash
   ./linkedlist
   ```

## 🛠 Functions Explanation

### 1. `push_mid(Node **head_ref, int new_data)`
Inserts a new node at the middle of the list.

### 2. `delete_front(Node **head_ref)`
Deletes the front node from the list.

### 3. `delete_back(Node **head_ref)`
Deletes the last node from the list.

### 4. `delete_mid(Node **head_ref)`
Deletes the middle node from the list.

### 5. `print_list(Node *node)`
Prints the elements of the linked list.

## 📌 Example Usage
```bash
Masukkan jumlah elemen dalam list: 5
Masukkan 5 elemen:
Elemen 1: 10
Elemen 2: 20
Elemen 3: 30
Elemen 4: 40
Elemen 5: 50

List awal: 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL

Pilih operasi:
1. Push Mid
2. Delete Front
3. Delete Back
4. Delete Mid
5. Tampilkan List
6. Keluar
```

## 🤝 Contributing
Feel free to contribute by opening an issue or pull request!

## 📜 License
This project is open-source and available under the MIT License.
