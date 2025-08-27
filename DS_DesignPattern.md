# Sinle Link list
## In C
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Single_LL{
    int data;
    struct Single_LL* next;
    
}SLL;

// push at front
void push(SLL **hp, int __data) {
    SLL *node = (SLL*)malloc(sizeof(SLL));
    node->data = __data;
    node->next = NULL;
    
    if(*hp != NULL){
        node->next = *hp;
    }
    
    *hp = node;
}

// push at back
void push_back(SLL **hp, int __data) {
    SLL *node = (SLL*)malloc(sizeof(SLL));
    node->data = __data;
    node->next = NULL;
    
    if(*hp == NULL){
        *hp = node;
    }else{
        SLL* temp = *hp;
        
        while(temp->next != NULL) temp = temp->next;
    
        temp->next = node;
    }
}

// push at position
void push_at(SLL **hp, int __data, int pos) {
    SLL *node = (SLL*)malloc(sizeof(SLL));
    node->data = __data;
    node->next = NULL;
    
    if(pos == 0){
        *hp = node;
    }else{
        int cnt = 0;
        SLL* temp = *hp;
        while(cnt < (pos-1) && temp != NULL){
            temp = temp->next;
            cnt++;
        }
        
        if(temp == NULL){
            printf("Error: requested position is out of range.");
            free(node);
            return;
        }
        
        node->next = temp->next;
        temp->next = node;
        
    }
}

void print(SLL* hp){
    if(hp == NULL){
        printf("Error: Link list is empty!\n"); return;
    }
    SLL* temp = hp;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sort_LL(SLL** hp){
    SLL* cur = *hp;
    SLL* cur_next;
    printf("before sorted...\n");
    print(*hp);
    while(cur != NULL){
        cur_next = cur->next;
        while(cur_next != NULL){
            if(cur->data > cur_next->data){
                cur->data = cur_next->data + cur->data - (cur_next->data = cur->data); 
            }
            cur_next = cur_next->next;
        }
        cur = cur->next;
    }
    printf("After sorted...\n");
    print(*hp);
}

void del_by_key(SLL** hp, int key){
    SLL* temp = *hp, *prev;

    if(temp == NULL){
        printf("Error: Link list is empty!"); return;
    }
    // if head itself hold key
    if(temp != NULL && temp->data == key){
        *hp = temp->next;
        free(temp);
        return;
    }

    // now serch node has exact key
    while(temp != 0) {
        if(temp->data == key ) break;
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Error: requested node is not present");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void del_by_pos(SLL** hp, int pos){
    SLL* temp = *hp, *prev;
    
    // if LL is empty;

    if(temp == NULL){
        printf("Error: Link list is empty!\n"); return;
    }
    // if head itself hold key
    if(pos == 0){
        *hp = temp->next;
        free(temp);
        return;
    }

    // now serch node has exact key
    int cnt = 0;
    while((cnt < pos) && temp != 0) {
        prev = temp;
        temp = temp->next; cnt++;
    }

    if(temp == NULL) {
        printf("Error: requested node is not present\n");
        return;
    }
    prev->next = temp->next;
    free(temp); 
}

void del_SLL(SLL **hp){
    SLL* temp = *hp;
    while(*hp != NULL) {
        temp = (*hp)->next;
        free(*hp);
        *hp = temp;
    }
}

int main()
{
    SLL *hp = NULL;
    push(&hp,10);
    push(&hp,20);
    push(&hp,30);
    push(&hp,40);
    push_back(&hp,50);
    push_back(&hp,60);
    push_back(&hp,70);
    push_at(&hp,100,2);
    sort_LL(&hp);
    del_by_pos(&hp,2); 
    print(hp);
    del_SLL(&hp);
    print(hp);
    return 0;
}
```

### Remove loop
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct single_LL {
    int data;
    struct single_LL *next;
} SLL;

void push_front(SLL **hp, int __data){
    
    SLL* node = (SLL*)malloc(sizeof(SLL));
    node->next = NULL;
    node->data = __data;
    
    if(*hp != NULL){
        node->next = *hp;
    }
   
   *hp = node;
}

void print(SLL* hp){
    SLL* temp = hp;
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    
    printf("\n");
}

void remove_loop(SLL **hp){
    SLL* fast = *hp;
    SLL* slow = *hp;
    int flag = 0;
    while(slow != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            flag = 1;
            break;
        }
    }
    
    if(flag){
        fast = *hp;
        while(slow->next != fast->next){
            slow = slow->next; fast = fast->next;
        }
        slow->next = NULL;
    }
    else{
        printf("data structure is not looped!");
    }
}
int main(){ 
    SLL *A, *B,*C,*D,*E,*F;
    A = (SLL*)malloc(sizeof(SLL));
    B = (SLL*)malloc(sizeof(SLL));
    C = (SLL*)malloc(sizeof(SLL));
    D = (SLL*)malloc(sizeof(SLL));
    E = (SLL*)malloc(sizeof(SLL));
    F = (SLL*)malloc(sizeof(SLL));
    
    A->data = 10; A->next = B;B->data = 20; B->next = C;
    C->data = 30; C->next = D;D->data = 40; D->next = E;
    E->data = 50; E->next = F;F->data = 60; F->next = C;
    remove_loop(&A);
    print(A);
    return 0;
}
```

---

## In C++

```cpp
#include<iostream>

class node {
    public:
        int data;
        node * next = nullptr;
        node (int udata):data (udata){};
};

class SLinkedList {
    node* hp = nullptr;
    public:
		
        SLinkedList() noexcept = default;
        
		void add_front (int udata){  // push
           node *ptr = new node(udata);
            
			if (hp == nullptr){
            	hp = ptr;
            }
            else{
                ptr->next = hp;
                hp = ptr;
            }
        }

        void add_end (int udata){ // push_back
            node *ptr = new node(udata);
            if(hp == nullptr){
               hp = ptr;
            }
            else{
                node *temp = hp;
                while(temp->next != nullptr){ 
                    temp = temp->next;
                }
                temp->next = ptr; 
            }
        
        }
    
        void add_middle (int udata,int pos){ /// push_at
            if(pos == 0){
                node *ptr = new node(udata);
                ptr->next = hp;
                hp = ptr;
                return;
            }
            else{
                node *temp = hp;
                int cur_pos =0;
                while(cur_pos < (pos-1) && temp != nullptr){
                    temp = temp->next;
                    cur_pos++;
                }
                if(temp == nullptr){
                    std::cout<<"Requested position is out of range\n";
                    return;
                }
                else{
                    node* ptr = new node(udata);
                    ptr->next = temp->next;
                    temp->next = ptr;
                }
            }
        }
        
        void delete_by_pos(int pos){
            
            node *temp = hp;
            node * prev = hp;
            if(hp == nullptr) {
                std::cout << "Error: Link list is empty!" << std::endl;
            }
            https://www.onlinegdb.com/online_c++_compiler#tab-stdin
            if(pos == 0){
                hp = hp->next;
                delete temp;
                return ;
            }else{
                // find the pos
                int cnt = 0;
                while(cnt < pos && temp != nullptr){
                    prev = temp; temp = temp->next; cnt++;
                }
                
                // if pos out of range
                if(temp == nullptr){
                    std::cout << "Error: position is out of range!" << std::endl; return;
                }
                
                prev->next = temp->next;
                delete temp;
            } 
            
        }
        
        void delete_by_key(int key){

            node *temp = hp;
            node * prev = hp;
            if(hp == nullptr) {
                std::cout << "Error: Link list is empty!" << std::endl;
            }
            
            if(hp->data == key){
                std::cout << "Error: Link list is empty!12" << std::endl;
                hp = hp->next;
                delete temp;
                return ;
            }else{
                // find the pos
                if(temp == nullptr){
                    std::cout<< "temp is nulptr" << std::endl;
                }
                while(temp != nullptr){
                    
                    if(temp->data == key) break;
                    
                    prev = temp;
                    temp = temp->next;
                }
                // if pos out of range
                if(temp  == nullptr){
                    std::cout << "Error: position is out of range!" << std::endl; 
                    return;
                }else{
                    prev->next = temp->next;
                    delete temp;
                }
                
                
            } 
        }
        void sort_list(){
            
            std::cout<<"sort_list is called..."<<std::endl;
            node *cur_ptr = hp;
            node *next_ptr = cur_ptr->next;
            while(cur_ptr != nullptr){
                next_ptr = cur_ptr->next;
                while(next_ptr != nullptr){
                    if(cur_ptr->data > next_ptr->data){
                        cur_ptr->data = (next_ptr->data + cur_ptr->data) - (next_ptr->data = cur_ptr->data); 
                    }
                    next_ptr = next_ptr->next;
                }
                cur_ptr = cur_ptr->next;
            }
        }
        void printList (){
        node *temp = hp;
            while(temp != nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
        std::cout<<std::endl;
        }
};

int main (){
  SLinkedList SL;
  SL.add_front(10);
  SL.add_front(20);
  SL.add_front(30);
  SL.add_end(40);
  SL.add_end(50);
  SL.add_middle(100,3);
  //SL.printList();
  
  SL.sort_list();
  SL.printList();
  
  SL.delete_by_key(20);
  SL.printList();
  
  
  std::cout << "End of main..." << std::endl;
  return 0;
}

```
---

# Double Link List

# In C
```
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} SLL;

void print(SLL* hp){
    SLL* temp = hp , * last;
    if(hp == NULL) {
        printf("Error: List is empty!\n");
        return;
    }
    printf("forward printing...\n");
    while(temp != NULL) {
        printf("%d ",temp->data);
        last = temp;
        temp = temp->next;
    }
    printf("\n");
    printf("reverse printing...\n");
    // temp = temp->prev;
    
    while(last != NULL) {
        printf("%d ",last->data);
        last = last->prev;
    }
    
    printf("\n");
}

void push_front(SLL **hp, int __data){
    
    SLL* node = (SLL*)malloc(sizeof(SLL));
    node->next = NULL; node->prev = NULL;
    node->data = __data;
    
    if(*hp == NULL){
        *hp = node;
    }
    else{
        (*hp)->prev = node;
        node->next = *hp;
        *hp = node;
    }


}


void push_back(SLL **hp,int __data){
    SLL* node = (SLL*)malloc(sizeof(SLL));
    node->next = NULL; node->prev = NULL;
    node->data = __data;
    
    if(*hp == NULL){
        *hp = node;
    }else{
        SLL *temp = *hp;
        while(temp->next != NULL) temp = temp->next;
        
        temp->next = node;
        node->prev = temp;
    }
}

void push_at(SLL** hp, int pos, int __data){
    SLL* node = (SLL*)malloc(sizeof(SLL));
    node->next = NULL; node->prev = NULL;
    node->data = __data;
    
    if(*hp == NULL ){
        *hp = node;
    }else{
        if(pos == 0){
            node->next = *hp; 
            (*hp)->prev = node; 
            *hp = node;
            
        } else {
            SLL *temp = *hp; int cnt = 0;
            while(cnt < (pos-1)){
                if(temp == NULL) break;
                temp = temp->next; cnt++;
            }
            
            // if pos is out of range
            
            if(temp == NULL){
                printf("Error: Requested postion is out of range!\n");
                return;
            }
            node ->prev = temp; node->next = temp->next;
            temp->next->prev = node; temp->next = node;
        }
    }    
}

void del_by_pos(SLL *hp, int pos){
    SLL *temp = hp;
    if (pos == 0){
        temp->next->prev = NULL;
        hp = temp->next;
    } else {
        int cnt = 0;

        while(cnt < (pos-1)){
            
            temp = temp->next;
            if(temp == NULL) {
                printf("Error: del pos out of range!");
                return;
            }
            cnt++;
        }
        if(temp->next != NULL) temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    }
    print(hp);
}

void del_by_key(SLL *hp, int key){
    SLL *temp = hp;
    if (temp->data == key){
        temp->next->prev = NULL;
        hp = temp->next;
    } else {
        int cnt = 0;
        while(temp->data != key){
            
            temp = temp->next;
            if(temp == NULL) {
                printf("Error: del pos out of range!");
                return;
            }
            cnt++;
        }
        if(temp->next != NULL) temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        free(temp);
    }
    print(hp);
}

void del_LL(SLL** hp){
    SLL* temp = *hp;

    while(temp != 0){
        SLL* next = temp->next; 
        free(temp);
        temp = next;
    }
    *hp = NULL; // this is important
}

int main(){ 
    SLL *hp = NULL;
    push_front(&hp,10); push_front(&hp,20); 
    push_front(&hp,30); push_front(&hp,40);
    //print(hp);
    
     push_back(&hp, 5); push_back(&hp,15); 
     push_back(&hp, 25); push_back(&hp,35); 
     //print(hp);
    
     push_at(&hp, 7, 45);
     print(hp);

     del_by_key(hp,40);
     del_LL(&hp);
     print(hp); 
}

```
---

# Circular buffer

## in C 
```
#include <stdio.h>
#include <stdlib.h>

enum {N = 10;};
int writeIndex = 0, readIndex = 0;
int buff[N] ;
int put(int data){

    // check if buffer is full
    if((writeIndex +1) % N == readIndex){
        printf("buffer is full\n"); 
        return 0;
    }

    buff[writeIndex] = data;
    writeIndex = (writeIndex + 1) % N;
    return 1;
}

int get(int *retriveData) {

    // check if buffer is empty;
    if(writeIndex == readIndex){
        printf("buffer is empty\n");
        return 0;
    }

    *retriveData = buff[readIndex];
    readIndex = (readIndex + 1) % N; 
    return 1;
}
int main() {
    int val = 100;
    while(put(val)){
        printf("added value: %d\n",val++);
    }
    int get_val;
    while(get(&get_val)){
        printf("read value: %d\n", get_val);
    }
}
```

## in C++
```
#include <iostream>
#include <vector>

template <class T>
class circularbuffer{
    std::vector<T> buff;
    int capacity;
    int head, tail;

    bool is_full(){
        return ((head+1) % capacity == tail);
    }

    bool is_empty(){
        return (head == tail);
    }

    public:
        circularbuffer(int cap){
            head = tail = 0;
            capacity = cap;
            buff.resize(capacity);
        }

        void push_back(T data){
            // check if buff is full
            if(is_full()) { throw("buffer is full!"); }

            // std::cout << __func__ << std::endl;
            buff[head] = data;
            head = (head + 1) % capacity;
        }

        T pop_front(){
            // check is buff empty
            if(is_empty()){ throw ("buffer is empty!"); }

            // std::cout << __func__ << std::endl;
            T data = buff[tail];
            tail = (tail+1) % capacity;
            return data;
        }
};
int main(){
    circularbuffer<int> cb(11);
    try{
        for(int i=0;i<100;i++){
            cb.push_back(i*10);
            // std::cout << cb.pop_front() <<"\n";
        }
        cb.pop_front();
    }
    catch(char const *e){
        std::cout << e << std::endl;
    }
    
    return 0;
}
```

---
 
 # Stack

 ```c
 #include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int* arr;
    unsigned int capacity;
}stack;

stack* create_stack(unsigned int cap){
    stack* s =  (stack*)malloc(sizeof(stack));
    s->top = -1;
    s->capacity = cap;
    s->arr = (int*)malloc(cap * sizeof(int));
    return s;
}

int is_full(stack* s){
    return (s->top == (s->capacity-1));
}

int is_empty(stack* s){
    return (s->top == -1);
}

void push(stack* s, int data){

    // check if stack full
    if(is_full(s)){
        printf("stack is full!\n"); return;
    }

    s->arr[++s->top] = data;
    printf("pushed data: %d at: %d\n",data, s->top);
}

void pop(stack* s, int *retdata){

    // check if stack is empty
    if(is_empty(s)){ printf("stack is empty!\n"); return ; }

    *retdata = s->arr[s->top--];
    printf("retrived data: %d at: %d\n", *retdata, s->top+1);
}

int peek(stack* s){ // just return top not decrement top

    // check if stack is empty
    if(is_empty(s)){ printf("stack is empty!"); return 0 ; }

    return  s->arr[s->top];

}

int main(){
    stack *sk = create_stack(10);
    int data = 100 , index = 0;
    while(index++ < 11){
        push(sk, data); data += 100;
    }
    printf("retrived data st top %d\n", peek(sk));
    index = 0; 
    while(index++ < 12){
        pop(sk, &data);
    }
    return 0;
}
 ```