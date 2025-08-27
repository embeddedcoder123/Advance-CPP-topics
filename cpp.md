# C++ concepts
- [Inline function in C++](#inline-function-in-c)
- [Function pointer and callback function](#function-pointer-and-callback-function)
- [C++ Concepts and Class creation](#c-concepts-and-class-creation)
- [Static member function and data](#static-member-function-and-data)
- [Friend function](#friend-function)
- [Inheritance](#inheritance)
- [Data abstraction](#data-abstraction)
- [Polymorphism](#polymorphism)
- [Up and Down casting](#up-and-down-casting)
- [Different Relationship between classes](#different-relationship-between-classes)
- [Deep Copy and shallow copy](#deep-copy-and-shallow-copy)
- [Template](#template)
- [Exception handling](#exception-handling)
- [Memory Management and Organization of the C Program](#memory-management-and-organization-of-the-c-program)
- [Smart Pointer](#smart-pointer)

## Inline function in C++
---
In case of function is `inline`, them while at the compiler stage function is replaced by its defination.

> Any changes made to an inline function will require the inline function to be 
recompiled again because the compiler would need to replace all the code with 
a new code; otherwise, it will execute the old functionality.

### Why do we need an inline function in C++?
-----------------------------------------
- Whenever the function is called, then it takes a lot of time to execute the tasks, such as moving to the calling function. If the length of the function is small, then the substantial amount of execution time is spent in such overheads, and
- sometimes time taken required for moving to the calling function will be greater than the time  required to execute that function.
- this is called `function call ovehead`.

### macro drawback:
---------------
- Instead of using normal funciton, we can use macros.
- The preprocessor macros are widely used in C, but the major drawback with the macros is that these are not normal functions which means the error checking process will not be done during the compilation.

- C++ has provided one solution to this problem. In the case of function calling, the time for calling such ,small functions, is huge, so to overcome such a problem,
- a new concept was introduced known as an inline function. 
- When the function is encountered inside the main() method, it is expanded with its definition thus saving time.

### We cannot provide the inlining to the functions in the following circumstances:
- If a function is recursive.
- If a function contains a loop like for, while, do-while loop.
- If a function contains static variables.
- If a function contains a switch or go to statement


### When do we require an inline function?
An inline function can be used in the following scenarios:
- An inline function can be used when the performance is required.
- It can be used over the macros.
- We can use the inline function outside the class so that we can hide the internal implementation of the function.

### Advantages of inline function
------------------------------
- In the inline function, we do not need to call a function, so it does not cause any overhead.
- It also saves the overhead of the return statement from a function.
- It does not require any stack on which we can push or pop the variables as it does not perform any function calling.
- An inline function is mainly beneficial for the embedded systems as it yields less code than a normal function.

### Disadvantages of inline function
---
The following are the disadvantages of an inline function:
- The variables that are created inside the inline function will consume additional registers. 
- If the variables increase, then the use of registers also increases, which may increase the overhead on register variable resource utilization.**This causes an overhead on resource utilization**.
- The binary executable file becomes large.
- The use of so many inline functions can reduce the instruction cache hit rate, reducing the speed of instruction fetch from the cache memory to that of the primary memory.
- t also increases the compile-time overhead because whenever the changes are made inside the inline function, then the code needs to be recompiled again to reflect the changes otherwise, it will execute the old functionality.
- Sometimes inline functions are not useful for many embedded systems because, in some cases, the size of the embedded is considered more important than the speed.
- It can also cause thrashing due to the increase in the size of the binary executable file. If the thrashing occurs in the memory, then it leads to the degradation in the performance of the computer.

```c
#include <iostream>
using namespace std;
inline int add(int a,int b){
    int c=a*b;
    return c;
}
int main()
{
    cout<<"Sum="<<add(13,5)<<endl;
    cout<<"sum ="<<add(10,12);
//If make a function as inline, then the compiler replaces the function calling
//location with the definition of the inline function at compile time.
    return 0;
}
```
```cpp
#include <iostream>
using namespace std;
int main()
{
    int *p;
    p=new int;  //inline,new, reference,fun oveloading
    //p= (int*)malloc(10*sizeof(int));
    *p=8;
  cout<<*p;
  delete p;
  return 0;
}
```
---
## Function pointer and callback function

Function pointer is the pointer that points to the function.

`int(*p)(int,int):` means funtion pointer `p` takes two integer agguments and return integer. 
```cpp
#include <iostream>
using namespace std;
void fun(int a){
    cout<<"square:"<<a<<endl;
}
int main()
{
    void (*p)(int );
    p=fun;
    p(2);
    fun(2);
    return 0;
}

```
### Callback function 
Function in that function pointer passed as arguments is called calllback function.
```cpp
#include <iostream>

int sum(int a, int b){ return (a+b);}
int sub(int a, int b){ return (a-b);}
int mul(int a, int b){ return (a*b);}
int division (int a, int b){ return (a/b);}

int callback(int (*p)(int,int),int a ,int b){
    return p(a,b);
}
int main()
{
    int i = 100 , j = 10;
    std::cout<< "sum: " << callback(sum,i,j) << std::endl;
    std::cout<< "sub: " << callback(sub,i,j) << std::endl;
    std::cout<< "mul: " << callback(mul,i,j) << std::endl;
    std::cout<< "div: " << callback(division,i,j) << std::endl;

    return 0;
}
/* Output
sum: 110
sub: 90
mul: 1000
div: 10
/*
```
---
## C++ Concepts and Class creation
In object-oriented programming, we use 4 main concepts:
- Data abstraction 
- Encapsulation,
- Inheritance, 
- Polymorphism.

### Encapsulation
Bind data member with member function is called encapsulation

```cpp
#include <iostream>
using namespace std;
class Employee {
   public:
       int id;//data member (also instance variable)    
       string name;//data member(also instance variable)
       float salary;
        Employee()    
        {    
            cout<<"Default Constructor Invoked"<<endl;    
        }    

       Employee(int id, string name, float salary)  
        {  
            cout<<"Parameterized  Constructor Invoked"<<endl;
            this->id = id;  
            this->name = name;  
            this->salary = salary;
        }
       void display()  
        {  
            cout<<id<<"  "<<name<<"  "<<salary<<endl;  
        }  
};
int main(void) {
    Employee e1(101, "Sonoo", 890000); //creating an object of Employee
    Employee e2(102, "Nakul", 59000);
    Employee e3;
    e1.display();  
    e2.display();  
    return 0;
}
/*
Parameterized  Constructor Invoked
Parameterized  Constructor Invoked
Default Constructor Invoked
101  Sonoo  890000
102  Nakul  59000
*/
```
---
```cpp
#include <iostream>  
using namespace std;  
class Point // create point class  
{  
       private:
        int x, y; // data members of the class  
       public:
        Point(int x1, int y1)  
        {  
            x = x1;  
            y = y1;  
        } // parameterised constructor
       
        Point(Point &p){
            x=p.x;     //x means p2.x ,  p.x means p1.x from main
            y=p.y;
        }
        int getX()
        {
            return x;
        } // return value of x  
       
        int getY() { return y; } // return valur of y  
       
};
int main()  
{  
    Point p1(10, 15); // call parameterised constructor
    Point p2=p1;
    cout<<"p1.x="<<p1.getX()<<" p1.y="<<p1.getY()<<endl;
    cout<<"p2.x="<<p2.getX()<<" p2.y="<<p2.getY()<<endl;
}
/*
p1.x=10 p1.y=15
p2.x=10 p2.y=15
*/
```
----
```cpp
#include <iostream>
using namespace std;
class Employee {
   public:
       int id;
        Employee()    
        {    
            cout<<"Constructor Invoked"<<endl;    
        }
        ~Employee()    
        {    
            cout<<"Destructor Invoked"<<endl;    
        }
};
int main(void) {
    Employee *e=new Employee;
    cout<<"hai"<<endl;
    delete e;  
    return 0;
}
/* Output
Constructor Invoked
hai
Destructor Invoked
*/
```
---
```cpp
#include<iostream>
using namespace std;

class Test
{
    private:
        int x;
        int y;
    public:
        Test(int x = 0, int y = 0)
        {   this->x = x;
            this->y = y;
        }
        
        Test* setX(int a){
            x=a;
            return this;
        }
        
        Test setY(int a){
            y=a;
            return *this;
        }
        
        void print() {
            cout << "x = " << x << " y = " << y << endl;
        }
};
int main()
{
    Test obj1(5, 5),*obj2, obj3;
    obj1.print();
    
    obj2=obj1.setX(10);
    obj2->print();
    
    obj3=obj1.setY(20);
    obj3.print();
    
    return 0;
}
/* Output:
x = 5 y = 5
x = 10 y = 5
x = 10 y = 20
*/
```
---
```cpp
#include<iostream>
using namespace std;
class Test
{
    private:
        int x;
        int y;
    public:
    Test(int x = 0, int y = 0) {
            this->x = x;
            this->y = y; }
    Test& setX(int a) {
            x = a;
            return *this;
    }
    Test& setY(int b) {
             y = b;
             return *this;
    }
    void print() { cout << "x = " << x << " y = " << y << endl; }
};
int main()
{
    Test t1(5, 5);
    t1.setX(10).setY(20);
    t1.print();
    return 0;
}
/* Output:
x = 10 y = 20
*/
```
---
### use of scope resolution operator
```cpp
#include <iostream>
using namespace std;  
int a = 50;  
int main ()  
{
    int a = 100;  
    cout << " The value of the local variable num: " << a;  
    cout << "\n The value of the global variable num: " << ::a;  
return 0;  
}
/* Output:
 The value of the local variable num: 100
 The value of the global variable num: 50
 */
```
---
## Static member function and data
- A field which is declared as `static` is called static field.
- Unlike instance field which gets memory each time whenever you create object,
there is only one copy of static field created in the memory. 
It is shared to all the objects
```cpp
#include <iostream>  
using namespace std;  
class Account {  
   public:  
       int accno; //data member (also instance variable)      
       string name;  
       static int count;    
       Account(int accno, string name){    
            this->accno = accno;    
            this->name = name;    
            count++;  
       }    
       void display(){    
            cout<<accno<<" "<<name<<endl;  
       }
        
       static void sfunc(){
            cout << "static function called!" << endl;
        }
};  
int Account::count=0;  
int main(void) {  
    Account a1(201, "sachin"); //creating an object of Account  
    Account a2(202, "rohit");  
    Account a3(203, "kohli");  
    a1.display();    
    a2.display();    
    a3.display();    
    cout<<"Total accounts created: "<<Account::count << endl;
    Account::sfunc();
    return 0;  
}
/* Output:
201 sachin
202 rohit
203 kohli
Total accounts created: 3
static function called!
```
---
## Friend function
`friend` function is not member function of the class but it defined in the class as friend, It can access private and protected member of the class.

By using the keyword friend compiler knows the given function is a friend function.

For accessing the data, the declaration of a friend function should be done inside the body of a class starting with the keyword friend.

**Characteristics of a Friend function:**
- The function is not in the scope of the class to which it has been declared as a friend.
- It cannot be called using the object as it is not in the scope of that class.
- It can be invoked like a normal function without using the object.
- It cannot access the member names directly and has to use an object name and dot membership operator with the member name.
- It can be declared either in the private or the public part.
---
```cpp
#include <iostream>
using namespace std;
class sample{
   int x;
   public:
    sample(int a){
    x=a; 
    }
    friend void fun(sample );
};
void fun(sample s){
    cout<<s.x;
}
int main()
{
    sample s(10);
    // cout<<s.x<<endl;
    fun(s);
    return 0;
}
// Output : 10 
```
### friend function in class
```cpp
#include <iostream> 
using namespace std;
class B;  //forward declaration
class A  
{   int x;
    public:
    void setdata(int i)  
    {  
        x=i;  
    } 
    friend void minimum(A,B);
};
class B  
{   int y;
    public:
    void setdata(int i)  
    {  
        y=i;  
    }
     friend void minimum(A,B);
};
void minimum(A a,B b){
    if(a.x<b.y)
      cout<<"smallest no is "<<a.x;
    else
      cout<<"smallest no is "<<b.y;
}
   int main()  
{  
   A a;  
   B b;  
   a.setdata(100);  
   b.setdata(20);  
   minimum(a,b);
   return 0;
}
// smallest no is 20
```
---
### Friend class
```cpp
//friend class
#include <iostream>
using namespace std;
class A  
{  
    int x =5;  
    friend class B;
};  
class B  
{  
  public:  
    void display(A a)  
    {  
        cout<<"value of x is : "<<a.x;  
    }  
};  
int main()  
{  
    A a;  
    B b;  
    b.display(a);  
    return 0;  
} 
// value of x is : 5
```
## Inheritance
| Inheritance Type | Description                    |
| ---------------- | ------------------------------ |
| Single           | One base → one derived         |
| Multiple         | Multiple bases → one derived   |
| Multilevel       | Chain of inheritance           |
| Hierarchical     | One base → multiple derived    |
| Hybrid           | Combination of the above types |
---
C++ supports **five main types of inheritance**. Each type helps structure classes differently based on the problem requirements.

---

### 1. Single Inheritance

A derived class inherits from only one base class.

```cpp
class A {
    // Base class
};

class B : public A {
    // Derived class
};
```
### 2. Multiple Inheritance
A derived class inherits from more than one base class.
```cpp
class A {
    // Base class 1
};

class B {
    // Base class 2
};

class C : public A, public B {
    // Derived from A and B
};
```
### 3. Multilevel Inheritance
A class is derived from a class which is already derived from another class.
```cpp
class A {
    // Base class
};

class B : public A {
    // Derived from A
};

class C : public B {
    // Derived from B (which is derived from A)
};
```
###  4. Hierarchical Inheritance
Multiple classes are derived from a single base class.
```cpp
class A {
    // Base class
};

class B : public A {
    // Derived class 1
};

class C : public A {
    // Derived class 2
};
```
### 5. Hybrid Inheritance
A combination of two or more types of inheritance.
```cpp
// For example: Combining Multiple and Hierarchical inheritance
class A { };
class B : public A { };
class C : public A { };
class D : public B, public C { }; // Hybrid (can cause Diamond Problem)
```
---

## Data abstraction 
- Data Abstraction is a process of providing only the essential details to the outside world and hiding the internal details, i.e., representing only the essential details in the program.
- Data Abstraction is a programming technique that depends on the seperation of the interface and implementation details of the program.

Abstraction using classes: 
- An abstraction can be achieved using classes. A class is used to group all the data members and member functions into a single unit by using the access specifiers. 
- A class has the responsibility to determine which data member is to be visible outside and which is not.

Abstraction in header files: 
- An another type of abstraction is header file. For example, pow() function available is used to calculate the power of a number without actually knowing which algorithm function uses to calculate the power. Thus, we can 
say that header files hides all the implementation details from the user.

Access Specifiers Implement Abstraction:
- Public specifier: When the members are declared as public, members can be accessed anywhere from the program.
- Private specifier: When the members are declared as private, members can only be accessed only by the member functions of the class.
Let's see a simple example of abstraction in header files.
```cpp
#include <iostream>  
#include<math.h>  
using namespace std;  
int main()  
{    
 int n = 4;  
   int power = 3;  
   int result = pow(n,power);         // pow(n,power) is the  power function  
   std::cout << "Cube of n is : " <<result<< std::endl;  
   return 0;  
}  
```
---
```cpp
#include <iostream>
using namespace std;
class base
{
    private:
      int x=10;
    protected:
      int y=20;
    public:
      int z=30;
};
int main()
{
    base b;
    //cout<<b.x;  error:y’ is private within this context
   // cout<<b.y;  error:y’ is protected within this context
   cout<<b.z;
    return 0;
}
```
---
```cpp
#include <iostream>
using namespace std;
class base
{
    private:
      int x=10;
    protected:
      int y=20;
    public:
      int z=30;
};
class child: private base{
    public:
   //...........  here y and z are private members for this class so not accessible for child2 class
   
};

class child2: public child{
    public:
    void display(){
       // cout<<"x:"<<x<<endl; here x is private
        cout<<"y:"<<y<<endl;  
        cout<<"z:"<<z<<endl;  
      }
   
};
int main()
{
    child2 c;
    c.display();
   // cout<<c.z;
    return 0;
}
```
### C++ Inheritance Access Table

This table shows how the **visibility (access specifier)** of members in a **base class** is affected in the **derived class**, depending on the type of inheritance used (`public`, `protected`, `private`).

| Base Class Visibility | Derived Class with `public` Inheritance | Derived Class with `private` Inheritance | Derived Class with `protected` Inheritance |
|-----------------------|-----------------------------------------|------------------------------------------|---------------------------------------------|
| `private`             | Not Inherited                           | Not Inherited                            | Not Inherited                               |
| `protected`           | `protected`                             | `private`                                | `protected`                                 |
| `public`              | `public`                                | `private`                                | `protected`                                 |

### Death of diamond problem
```cpp
//death of diamond problem
#include <iostream>
using namespace std;
class A{
    public:
    void display(){
        cout<<"class A display fun"<<endl;
    }
};
class B {
    public:
    void display(){
        cout<<"class B display fun"<<endl;
    }
};
class C:public A,public B{
   //...............
};
int main()
{
    C c;
    // c.display();// error: request for member ‘display’ is ambiguous
    c.B::display();
    return 0;
}
// Output: class B display fun
```
---
```cpp
#include<iostream>

class Person{
    public:
        Person() {
            std::cout<<"Person called."<<std::endl;
        }
};

class Father : public Person{
    public:
        Father():Person() {
            std::cout<<"Father called."<<std::endl;
        }   
};

class Mother : public Person{
    public:
        Mother():Person() {
            std::cout<<"Mother called."<<std::endl;
        }      
};

class Child : public Mother,public Father{
    public:
         Child():Father(),Mother() {
            std::cout<<"Child called."<<std::endl;
        }     

};

int main(){
    Child child;
    return 0;
}
/*
Output: 
Person called.
Mother called.
Person called.
Father called.
Child called.

Note: see two times person is called
 */
```
Soluton : Inherit as virual

```cpp

#include<iostream>

class Person{
    public:
        Person() {
            std::cout<<"Person called."<<std::endl;
        }
};

class Father :virtual public Person{
    public:
        Father():Person() {
            std::cout<<"Father called."<<std::endl;
        }   
};

class Mother :virtual public Person{
    public:
        Mother():Person() {
            std::cout<<"Mother called."<<std::endl;
        }      
};

class Child : public Mother,public Father{
    public:
         Child():Father(),Mother() {
            std::cout<<"Child called."<<std::endl;
        }     

};

int main(){
    Child child;
    return 0;
}
/*
output:
Person called.
Mother called.
Father called.
Child called.
*/
```
- `virtual` can be written before or after the public. 
- Now only one copy of data/function member will be copied to class child and class Father, class Mother and class Personal becomes the virtual base class. 
- Virtual base classes offer a way to save space and avoid ambiguities in class hierarchies that use multiple inheritances. When a base class is specified as a virtual base, it can act as an indirect base more than once without duplication of its data members. 
- A single copy of its data members is shared by all the classes that use virtual base.

### Constructor called sequence
```cpp

#include <iostream>
using namespace std;
class base{
    public:
    base(){
        cout<<"base class constructor"<<endl;
    }
};
class derived:public base {
    public:
    derived(){
        cout<<"derived class constructor"<<endl;
    }
   
};

int main()
{
    derived d;
    return 0;
}
/*
output:
base class constructor
derived class constructor
*/
```
---
```cpp
#include <iostream>
using namespace std;
class Base1
{
	public:
		Base1()
		{
			cout << "Inside first base class" << endl;
		}
};
class Base2
{
	public:
		Base2()
		{
			cout << "Inside second base class" << endl;
		}
};
class Derived : public Base2, public Base1
{
	public:
		Derived()
		{
			cout << "Inside child class" << endl;
		}
};
int main() {
Derived obj1;
return 0;
}
/*
Output:
Inside second base class
Inside first base class
Inside child class
*/
```
---
```cpp
#include <iostream>
using namespace std;
class base{
    public:
    base(){
        cout<<"base class constructor"<<endl;
    }
    ~base(){
        cout<<"base class destructor"<<endl;
    }
   
};
class derived:public base {
    public:
    derived(){
        cout<<"derived class constructor"<<endl;
    }
    ~derived(){
        cout<<"derived class destructor"<<endl;
    }
};

int main()
{
    derived d;
    return 0;
}
/*
Output:
base class constructor
derived class constructor
derived class destructor
base class destructor
*/
```
---
```cpp
#include <iostream>
using namespace std;
class base{
    public:
    base(){
        cout<<"base class constructor"<<endl;
    }
    ~base(){
        cout<<"base class destructor"<<endl;
    }
   
};
class derived:public base {
    public:
    derived(){
        cout<<"derived class constructor"<<endl;
    }
    ~derived(){
        cout<<"derived class destructor"<<endl;
    }
};

int main()
{
    derived *d=new derived;
    delete d;
    return 0;
}
/*
Output:
base class constructor
derived class constructor
derived class destructor
base class destructor
*/
```
---
## Polymorphism
The term "Polymorphism" is the combination of "poly" + "morphs" which means many forms. 
It is a greek word.

**Real Life Example Of Polymorphism:***
> Let's consider a real-life example of polymorphism.A lady behaves like a teacher in a classroom, mother or daughter in a home and customer in a market.Here a single person is behaving differently according to
the situations.


### Types of Polumorphism:
- Compile time Polymirphism:
	- Function Overloading
	- Operator Overloading

- Runtime Polymorphism:
	- Virtual Function

### Function Overloading
```cpp
#include <iostream>
using namespace std;    
class Cal {    
    public:    
    int add(int a,int b){      
        return a + b;      
    }      
    int add(int a, int b, int c)      
    {      
        return a + b + c;      
    }      
};     
int main(void) {    
    Cal C;                                        
    cout<<C.add(10, 20)<<endl;      
    cout<<C.add(12, 20, 23);     
   return 0;    
} 
```
**Causes of ambiguity in Function Overloading:**
- Type Conversion.
- Function with default arguments.
- Function with pass by reference.

**Ambiguity error due to Type Conversion.**
```cpp
#include <iostream>
using namespace std;

class A {
public:
    operator int() { return 1; }
    operator double() { return 1.1; }
};

void show(int)    { cout << "int\n"; }
void show(double) { cout << "double\n"; }

int main() {
    A obj;
    show(obj); // Error: ambiguous

    show(static_cast<int>(obj));    // Calls show(int)
    show(static_cast<double>(obj)); // Calls show(double)

}

```
**Function with default arguments**
```cpp
#include<iostream>  
using namespace std;  
void fun(int);  
void fun(int,int);  

void fun(int i)  
{  
    cout << "Value of i is : " <<i<< endl;  
}  
void fun(int a,int b=9)  
{  
    cout << "Value of a is : " <<a<< endl;  
    cout << "Value of b is : " <<b<< endl;  
}  
int main()  
{  
    //fun(12);  // error: call of overloaded ‘fun(int)’ is ambiguou
    fun(12,13); 
   
    return 0;  
}
/*
Value of a is : 12
Value of b is : 13
*/
```

**Function with pass by reference**
```cpp
#include <iostream>  
using namespace std;  

void fun(int x){ cout << "Value of x is : " <<x<< endl;}  
void fun(int &b){ cout << "Value of b is : " <<b<< endl;}

int main()  {  
    int a=10;  
    fun(a); // error, which f()?  
    return 0;  
}
```
### Operator Overloading
Operator overloading is a compile-time polymorphism in which the operator is overloaded to provide
 the special meaning to the user-defined data type. Operator overloading is used to overload or
 redefines most of the operators available in C++. It is used to perform the operation on the 
user-defined data type. For example, C++ provides the ability to add the variables of the user-defined
 data type that is applied to the built-in data types.
=====================
The advantage of Operators overloading is to perform different operations on the same operand.

Operator that cannot be overloaded are as follows:
- Scope operator `::`
- `Sizeof`
- member selector `.`
- member pointer selector `*`
- ternary operator `? :`

**Rules for Operator Overloading**
- Existing operators can only be overloaded, but the new operators cannot be overloaded.
- The overloaded operator contains atleast one operand of the user-defined data type.
- We cannot use friend function to overload certain operators. However, the member function 
can be used to overload those operators.
- When unary operators are overloaded through a member function take no explicit arguments, 
but, if they are overloaded by a friend function, takes one argument.
- When binary operators are overloaded through a member function takes one explicit argument,and if they are overloaded through a friend function takes two explicit arguments.

#### `Prefix increament ++x` Opearator oveloading 
```cpp
#include <iostream>    
using namespace std;    
class Test{
    int n=10;
    public:
    void operator ++(){
        n=n+1;
        cout<<n;
    }
};    
int main(void) {    
   Test t;
   ++t;
  
   return 0;    
} 
```
---
#### `Postfix increament ++x` Opearator oveloading
```cpp
#include <iostream>    
using namespace std;    
class Test{
    int n=10;
    public:
    void operator ++(int){
        n=n+1;
        cout << n;
    }
};    
int main(void) {    
   Test t;
   t++;   //post incrmnt op
   return 0;    
} 
```
### Binary operator overloading
```cpp
#include <iostream>  //binary op overloading  
using namespace std;    
class Test { 
    int n;
    public:    
    Test(int i){
        n=i;
    }      
    void operator +(Test t) {
       cout<<"binary op overloading"<<n<<" "<<t.n; //  n means t1.n, t.n means t2.n   bcoz of t1+t2 in main
    }   
};     
int main(void) {    
    Test t1(10),t2(20);
    t1+t2;
   return 0;    
}
```
---
```cpp
#include <iostream>    
using namespace std;    
class A{
    int n;
    public:
       //A(){n=0;}
       A(int x){
           n=x;
       }
       A operator +(A &a){
          // A a3;
           A a3(0);
           a3.n= n +a.n;
           return a3;
       }
       void display(){
           cout<<"n:"<<n<<endl;
       }
};
int main()  
{  
    A a1(5);  
    A a2(4);  
    A a3 = a1 + a2;
    a3.display();
    a1.display();
    a2.display();
    return 0;  
}
```
----
### Overloading Overloading Subscript or array index operator `[]`
```cpp
#include <iostream>
using namespace std;

class Array {
    int *ptr, size;
public:
    Array(int* p, int s) {
        size = s;
        if (s != 0) {
            ptr = new int[s];
            for (int i = 0; i < s; i++)
                ptr[i] = p[i];
        } else {
            ptr = nullptr;
        }
    }

    // Destructor to free memory
    ~Array() {
        delete[] ptr;
    }

    // Non-const version (read/write)
    int& operator[](int index) {
        if (index >= size || index < 0) {
            cout << "Array index out of bound, exiting...\n";
            exit(0);
        }
        return ptr[index];
    }

    // Const version (read-only)  this is optional
    const int& operator[](int index) const {
        if (index >= size || index < 0) {
            cout << "Array index out of bound, exiting...\n";
            exit(0);
        }
        return ptr[index];
    }
};
int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    Array arr(numbers, 5);

    cout << arr[2] << endl; // read → prints 3

    arr[2] = 10;            // write
    cout << arr[2] << endl; // now prints 10
}
```
---
### Stream insertion/extraction `std::cout << ...` and `std::cin >> ...`

stream insertion operator '<<' is used for output and extraction operator '>>' is used for input. 
important points to remember:
1) `std::cout` is an object of `ostream` class and `std:::cin` is an object of `istream` class. 
2) These operators must be overloaded as a global function. And if we want to allow them to access private data members of the class, we must make them `friend`. 

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int roll;
    float marks;

public:
    Student(string n = "", int r = 0, float m = 0.0f)
        : name(n), roll(r), marks(m) {}

    // Overload >> for input
    friend istream& operator>>(istream& in, Student& s) {
        cout << "Enter Name: ";
        getline(in >> ws, s.name); // ws removes leftover newlines

        cout << "Enter Roll No: ";
        in >> s.roll;

        cout << "Enter Marks: ";
        in >> s.marks;

        return in;
    }

    // Overload << for output
    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "Name: " << s.name
            << ", Roll No: " << s.roll
            << ", Marks: " << s.marks;
        return out;
    }
};

int main() {
    Student s1, s2;

    cout << "Enter details for Student 1:\n";
    cin >> s1;

    cout << "\nEnter details for Student 2:\n";
    cin >> s2;

    cout << "\n--- Student Records ---\n";
    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}
/***********
Enter details for Student 1:
Enter Name: Alice
Enter Roll No: 101
Enter Marks: 88.5

Enter details for Student 2:
Enter Name: Bob
Enter Roll No: 102
Enter Marks: 92.0

--- Student Records ---
Name: Alice, Roll No: 101, Marks: 88.5
Name: Bob, Roll No: 102, Marks: 92

***********/
```
---
###  `new` and `delete` operator overloading 
```cpp
#include <iostream>
#include <cstdlib> // for malloc, free
using namespace std;

class MyClass {
    int data;

public:
    MyClass(int val = 0) : data(val) {
        cout << "Constructor called, data = " << data << "\n";
    }
    ~MyClass() {
        cout << "Destructor called, data = " << data << "\n";
    }

    // Overload operator new
    void* operator new(size_t size) {
        cout << "[Custom new] Allocating " << size << " bytes\n";
        void* p = malloc(size); // allocate raw memory
        if (!p) throw bad_alloc();
        return p;
    }

    // Overload operator delete
    void operator delete(void* p) {
        cout << "[Custom delete] Freeing memory\n";
        free(p); // release raw memory
    }
};

int main() {
    MyClass* obj = new MyClass(42); // Calls custom new + constructor
    delete obj;                     // Calls destructor + custom delete
}
```

### Function Overriding
**What is Function Overriding?**
> if virtual function present in base class and it is re-defined in child class with same signature then it called function overrriding.

**It’s a key feature of runtime polymorphism in C++**
Rules for Function Overriding
- The base class function must be marked as virtual (unless it overrides an already virtual function).
- The function signature (name, parameters, and const-qualification) must match exactly.
- The return type must be the same, or covariant (a pointer or reference to a derived type).
- The base function and derived function must be in different classes related by inheritance.


#### C++ virtual function
- A C++ virtual function is a member function in the base class that you redefine
 in a derived class. It is declared using the 'virtual' keyword.
- It is used to tell the compiler to perform dynamic linkage or late binding on the function.
- There is a necessity to use the single pointer to refer to all the objects of the different.But, when base class pointer contains the address of the derived class object, always executes the base class function. This issue can only be resolved by using the 'virtual' function.
- **Note:** Base class pointer can points to its ascendence class object.So, we create the pointer to the base class that refers to all the derived objects.

- A 'virtual' is a keyword preceding the normal declaration of a function.
- When the function is made virtual, C++ determines which function is to be invoked at the runtime based on the type of the object pointed by the base class pointer.


**Rules of Virtual Function**
- Virtual functions must be members of some class.
- Virtual functions cannot be static members.
- They are accessed through object pointers.
- They can be a friend of another class.
- A virtual function must be defined in the base class, even though it is not used.
- The prototypes of a virtual function of the base class and all the derived classes
 must be identical. If the two functions with the same name but different prototypes, C++ will consider them as the overloaded functions.
- We cannot have a virtual constructor, but we can have a virtual destructor


#### Important points:
- `vtable`: is the array of function pointer where virtual function is stored, this is created for every class.
- A `vptr` is created as a hidden data member within each object of a class that has atlist one virtual function. This means that if you create multiple objects of such a class, each object will have its own vptr.

- The `vptr` is initialized during the object's construction. Specifically, the compiler inserts code into the constructor of the class (and any derived classes) to set the `vptr` to point to the vtable corresponding to the object's actual type. This ensures that when a `virtual` function is called through a base class pointer or reference, the correct function implementation (based on the object's dynamic type) is invoked.

- In case of function overloading, early binding happened and based on pointer class type, function of that class called.
- in Vtable only virtual function will filled and vPtr points to that function only.

- In case of function hiding Error will generated


> Base class pointer points to base class object
![Points to base object](/virtal_func_1.png) 

> Base class pointer points to derived class object
![Points to derived object](/virtal_func_2.png)
---
```cpp
class A
{
    *vptr // Hidden pointer in every object of a class with virtual functions.
           // Points to the virtual table (vtable) for the class.

public:
    void f1() { ... }             // Non-virtual → early binding
    virtual void f2() { ... }     // Virtual → entry in vtable
    virtual void f3() { ... }     // Virtual → entry in vtable
    virtual void f4() { ... }     // Virtual → entry in vtable
};

class B : public A
{
public:
    void f1() { ... }             // Hides A::f1 (same name, non-virtual)
    void f2() { ... }             // Overrides A::f2 (virtual override)
    void f4(int x) { ... }        // Function hiding, A::f4(int x) not present 
    };

// ------------------------------------------------------------
// Vtables show which function each virtual call resolves to
// ------------------------------------------------------------

/* -------- vtables -------- */

 A's vtable:               B's vtable:
+------+ +------+ +------+   +------+ +------+ +------+
| f2() | | f3() | | f4() |   | f2() | | f3() | | f4() |
| A::  | | A::  | | A::  |   | B::  | | A::  | | A::  |
+------+ +------+ +------+   +------+ +------+ +------+

// Index mapping (example):
// [0] → f2()
// [1] → f3()
// [2] → f4()

// A's vtable entries all point to its own methods.
// B's vtable replaces only f2() entry with B::f2.
// f3() and f4() still point to A's versions since they're not overridden.

// ------------------------------------------------------------
// vptr linkage in object memory layout
// ------------------------------------------------------------

    ^                         ^
    |                         |
    +-----------+-------------+
                |
            vptr in object o1
                |
                v
        +-----------------+
        |    [ vptr ] ----+---->  B's vtable  // Points to Derived's vtable
        +-----------------+
        |  A's data ...   |                  // Base class subobject
        +-----------------+
        |  B's data ...   |                  // Derived class fields
        +-----------------+

// ------------------------------------------------------------
// Function call resolution in main()
// ------------------------------------------------------------

main()
{
    A *p, 
    B o1;    // p is Base pointer, o1 is Derived object
    p = &o1; // Base* points to Derived object so *vptr points to derived class vtable

    p->f1(); // EB → A::f1 (non-virtual, resolved at compile-time)
    p->f2(); // LB → B::f2 (virtual, overridden, resolved via vtable)
    p->f3(); // LB → A::f3 (virtual, not overridden)
    p->f4(); // LB → A::f4 (virtual, not overridden; B has f4(int) instead)
    p->f4(5); // EB → Compile-time error: A has no f4(int) in its interface
}

// EB = Early Binding (Compile-time)
// LB = Late Binding (Run-time, via vtable lookup)

```
---

#### Pure Virtual Function
- A pure virtual function is not used for performing any task. It only serves as a placeholder.
- When the function has no definition, such function is known as "do-nothing" function.
- The "do-nothing" function is known as a `pure virtual function`. A pure virtual function is a 
function declared in the base class that has no definition relative to the base class.
- A class has atleast one `pure virtual function` that class called as `abstract class`.
- We can not create object of `abstract class`.
- The main objective of the base class is to provide the traits to the derived classes and to create 
the base pointer used for achieving the runtime polymorphism.

**Characteristics of a pure virtual function**
- A pure virtual function is a "do nothing" function. Here "do nothing" means that it just provides the 
	template, and derived class implements the function.
- It can be considered as an empty function means that the pure virtual function does not have any definition
	relative to the base class.
- Programmers need to redefine the pure virtual function in the derived class as it has no definition in the base class.
- A class having pure virtual function cannot be used to create direct objects of its own. It means that the class is containing any pure virtual function then we cannot create the object of that class. This type of class is known as an abstract class.

- Syntax:	
```cpp 
virtual void display() = 0;
``` 
---
```cpp

#include <iostream>  
using namespace std;  
class A    //abstract class
{  
    int x=5;  
    public:  
    	virtual void display()=0; //pure virtual function  or 'do nothing ' function
   
};  
class B: public A  
{  
    int y = 10;  
    public:  
    void display()   
    {  
        std::cout << "class B fun called" << std::endl;  
    }  
}; 
int main(){
    A *a;
   // A a1;  // error because we can't able create object for abstract class
   // a=&a1;
   // a->display();
       
    B b;
    a=&b;
    a->display();
    return 0;
}
```
----
```cpp
#include <iostream>  
using namespace std;  
class A    //abstract class
{  public:
    int x=5;  
    public:  
   virtual void display()=0;
   
};  
class B: public A {  
}; 
int main(){
    A *a;
    // B b; cannot declare variable ‘b’ to be of abstract type ‘B’
    return 0;
}
```
---
Perfect usecase 
```cpp
#include <iostream>  
using namespace std;  
 class Shape    
{    
    public:   
    virtual void draw()=0;    
};    
 class Rectangle : Shape    
{    
    public:  
     void draw()    
    {    
        cout <<"drawing rectangle..." <<endl;    
    }    
};    
class Circle : Shape    
{    
    public:  
     void draw()    
    {    
        cout <<"drawing circle..." <<endl;    
    }    
};    
int main( ) {  
    Rectangle rec;  
    Circle cir;  
    rec.draw();    
    cir.draw();   
    return 0;  
}
/*
drawing rectangle...
drawing circle...
```
---- 
## Up and Down casting

### Up casting
**Upcasting in C++** means converting a pointer or reference of a derived class to a base class type.
It’s usually done **implicitly** (no cast operator needed) and is safe, because a derived class object is a base class object at its core.
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark!" << endl;
    }
};

int main() {
    Dog d;
    // Upcasting: Dog* → Animal*
    Animal* a = &d;
    // Call virtual function through base pointer
    a->sound();  // Output: Bark! (runtime polymorphism)

    return 0;
}
```
### Downcasting 
in C++ is the process of converting a base class pointer or reference back to a derived class type.

Unlike upcasting, downcasting is not always safe — the base pointer might not actually point to a derived object.
To safely downcast, we usually use dynamic_cast with polymorphic classes (i.e., classes with at least one virtual function).

Example: Safe Downcasting
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { // virtual = makes the class polymorphic
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark!" << endl;
    }
    void fetch() {
        cout << "Dog is fetching!" << endl;
    }
};

int main() {
    Animal* a = new Dog(); // Upcasting (safe)

    // Downcasting (safe with dynamic_cast)
    Dog* d = dynamic_cast<Dog*>(a);
    if (d) {
        d->sound(); // Bark!
        d->fetch(); // Dog is fetching!
    } else {
        cout << "Downcast failed" << endl;
    }

    delete a;
}
```
Key Points

- Upcasting is always safe, but downcasting needs checking.
- Use dynamic_cast to ensure safe downcasting at runtime.
- dynamic_cast only works with polymorphic classes.

- If the cast fails:
    - For pointers → returns nullptr.
    - For references → throws std::bad_cast.
----
## Different Relationship between classes
- Inheritance (IS-A)
- composition (HAS-A)
- Aggregation (HAS-A but separate life)
- Association (KNOWS-A)
- Dependency (USES-A)

### Inheritance
**A MathTeacher IS-A Teacher.**
Rule: Child is a special type of parent.
```cpp
class Teacher {
public:
    void teach() { cout << "Teaching..." << endl; }
};

class MathTeacher : public Teacher {
public:
    void solveMath() { cout << "Solving math problems" << endl; }
};

int main() {
    MathTeacher m;
    m.teach();      // from Teacher
    m.solveMath();  // from MathTeacher
}
/*p
Teaching...
Solving math problems
```

---
### Composition (HAS-A)
**A School HAS-A Library (Library is part of School).**
Rule: The contained object cannot exist without the main object.
```cpp
class Library {
public:
    void open() { cout << "Library is open" << endl; }
};

class School {
    Library lib; // strong ownership
public:
    void startDay() {
        lib.open();
        cout << "Classes have started" << endl;
    }
};

int main() {
    School s;
    s.startDay();
}
/*
Library is open
Classes have started
*/
```
### Aggregation (HAS-A but separate life)
**A Teacher HAS-A Department, but the department can exist without the teacher.**

Rule: Related, but can live separately.
```cpp
class Department {
public:
    void info() { cout << "Science Department" << endl; }
};

class Teacher {
    Department* dept;
public:
    Teacher(Department* d) : dept(d) {}
    void showDept() { dept->info(); }
};

int main() {
    Department d;
    Teacher t(&d); // department created outside
    t.showDept();
}
```
### Association (KNOWS-A)
**Teacher KNOWS-A Student (they interact).**
Rule: They just work together.
```cpp
#include <iostream>
using namespace std;
class Student {
public:
    void learn() { cout << "Learning..." << endl; }
};

class Teacher {
public:
    void teach(Student& s) {
        cout << "Teaching student..." << endl;
        s.learn();
    }
};

int main() {
    Teacher t;
    Student s;
    t.teach(s);
}
/*
Teaching student...
Learning...
*/
```
### Dependency (USES-A)
**A School USES-A Printer to print notices.**
Rule: Only temporary help, no permanent link.
```cpp
#include <iostream>
using namespace std;
class Printer {
public:
    void printNotice() { cout << "Printing notice..." << endl; }
};

class School {
public:
    void sendNotice(Printer& p) {
        cout << "Preparing notice..." << endl;
        p.printNotice();
    }
};

int main() {
    Printer p;
    School s;
    s.sendNotice(p);
}
/*
Preparing notice...
Printing notice...
*/
```
---
## Deep Copy and shallow copy
| Feature               | Shallow Copy 🟢                        | Deep Copy 🔵                            |
| --------------------- | -------------------------------------- | --------------------------------------- |
| **Memory**            | Shares the same memory                 | Creates a new separate memory           |
| **Data copied**       | Only references (addresses)            | Actual data values                      |
| **Effect of changes** | Change in one affects the other        | Change in one does not affect the other |
| **Speed**             | Faster (just copies address)           | Slower (copies all data)                |
| **Safety**            | Risky (double free, dangling pointers) | Safe and independent                    |
| **Use case**          | When sharing is okay                   | When independent copies are needed      |

```cpp
#include <iostream>
using namespace std;\
int My_strlen(char* s){
	int i = 0;
    while(s[i++]);
	cout<<"size of  "<<i<<endl;
	return i;
}

void my_strcpy(char* src,char* des){
	int i = 0;
    while(src[i]){
		des[i] = src[i]; i++;
	}
	des[i] = 0;
}

class A{
	char* str;
	public:
        A(char* ptr){
            str = new char[My_strlen(ptr)];
            my_strcpy(ptr,str);
        }

        /*Deep copy Example*/
        explicit A (const A& obj){
            str = new char[My_strlen(obj.str)];
            my_strcpy(obj.str,str);
        }

        void modify(void) { str[0] = 'P'; }
        
        void print(void){ cout << str << endl; }
        
        ~A() { cout << "destructor called" << endl; delete [] str; }
	
};
int main()
{
	A obj1("Haresh");
	A obj2(obj1);
	obj1.modify(); //modified first charecter with 'P'
	
	obj1.print(); // Paresh
	obj2.print(); // In shallow copy (Paresh) :In Deep copy (Haresh)
   return 0;
}
```
----
## Template
- A template in C++ is a way to write generic code that works with any data type.

**Function Template**
It is used when we want one function to work for different data types.
```cpp
#include <iostream>
using namespace std;

// Function Template
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add<int>(5, 10) << endl;      // Works with int
    cout << add<double>(5.5, 2.3) << endl; // Works with double
    cout << add<string>("Hello ", "World") << endl; // Works with string
}
```
**Class Template**
A class template allows a class to handle any data type.
```cpp
#include <iostream>
using namespace std;

// Class Template
template <class T>
class Box {
    T value;
public:
    Box(T v) { value = v; }
    void show() { cout << "Value = " << value << endl; }
};

int main() {
    Box<int> b1(100);       // int type object
    Box<double> b2(99.99);  // double type object
    Box<string> b3("Hello"); // string type object

    b1.show();
    b2.show();
    b3.show();
}
```
----
## Exception handling
```cpp
#include <iostream>
#include <stdexcept>   // For standard exception classes
using namespace std;

// 🔹 User-defined exception class
class MyException {
    string msg;
public:
    MyException(string m) : msg(m) {}
    string what() { return msg; }
};

// 🔹 Function with noexcept (will not throw)
void safeFunction() noexcept {
    cout << "This function is safe and will not throw exceptions.\n";
}

// 🔹 Function that may throw and rethrow
void riskyFunction() {
    try {
        throw runtime_error("Runtime error inside riskyFunction");
    }
    catch (runtime_error &e) {
        cout << "Caught inside riskyFunction: " << e.what() << endl;
        throw;  // Rethrow exception to caller
    }
}

// 🔹 Demonstrating stack unwinding
class Resource {
public:
    Resource() { cout << "Resource acquired (Constructor)\n"; }
    ~Resource() { cout << "Resource released (Destructor)\n"; }
};

int main() {
    // Example 1: Standard exception class
    try {
        throw runtime_error("Standard runtime_error example");
    }
    catch (runtime_error &e) {
        cout << "Caught standard exception: " << e.what() << endl;
    }

    // Example 2: User-defined exception
    try {
        throw MyException("Custom user-defined exception");
    }
    catch (MyException &e) {
        cout << "Caught custom exception: " << e.what() << endl;
    }

    // Example 3: Rethrowing exceptions
    try {
        riskyFunction();
    }
    catch (runtime_error &e) {
        cout << "Caught again in main: " << e.what() << endl;
    }

    // Example 4: Stack unwinding demonstration
    try {
        Resource r;  // Constructor runs
        throw "Some error";  // Throw exception
    }
    catch (const char* msg) {
        cout << "Caught string exception: " << msg << endl;
    }
    // Destructor of Resource is called automatically here (stack unwinding)

    // Example 5: Nested try-catch
    try {
        try {
            throw 42;
        }
        catch (int x) {
            cout << "Inner catch caught: " << x << endl;
            throw; // rethrow to outer catch
        }
    }
    catch (int x) {
        cout << "Outer catch caught again: " << x << endl;
    }

    // Example 6: noexcept function
    safeFunction();

    cout << "\nProgram completed successfully!" << endl;
    return 0;
}
```
Explanation of Use Cases:
- Standard Exception Class → runtime_error caught.
- User-Defined Exception → custom exception class with what() message.
- Rethrowing Exception → handled inside riskyFunction, then rethrown to main.
- Stack Unwinding → constructor/destructor shows that cleanup happens automatically.
- Nested try-catch → inner catch rethrows, outer catch handles again.
- noexcept → function guaranteed not to throw.

## Memory Management and Organization of the C Program

- Text / Code section
- Data section
	- Initialized data fragment
	- Uninitialized data fragment (bss: block started by symbol)
- Heap section
- Stack section

 
### Text section: 
	- It contains the machine code of the compiled program. 
	It is also called code area. 
	- It is only readable, preventing machine instructions from getting modified accidentally. 
	- The text area is sharable among all the functions in a program. 
	- The existence of this area is till the exi of main().

### Data section:
	- The memory for global C variables and static variables are maintained in this area. 
	- This area is readable and writable both. 
	- It is also sharable among all the functions in a program. 
	- Its lifetime is also till the termination of the program. 
	- It is further classified into two fragments:

> **i. Initialized data fragment:**
    All the global and static variables that are initialized with some value get 
allocated memory in this area.

> **ii. Uninitialized data fragment:**
All the global and static variables that are not initialized lie in this area 
get allocated memory in this area. 
This area is also called block start by symbol (bss).

### Heap section: 
- The dynamic memory allocation takes place in this area. 
- The size for this area is not fixed, it grows till the largest available address is present. 
-In C, it is managed by malloc, calloc ,realloc and free, 
- library function which uses the brk and sbrk system calls to regulate the size. 
- This area is also shared by all the functions in a program. 
- Its existence is till the termination of the program.

### Stack section: 
- It is next to the heap area, the memory addresses for stack area and heap area are not fixed while data and text area are fixed. 
- The heap and stack area grow towards each other. 
- All the local variables (automatic) get stored in the stack area. 
- When a program start execution, first the main() get pushed into the stack and then other functions get pushed when they get called. 
- There are lots of changes that occur in the machine state when any function is called. The program counter gets updated with a new address; 
CPU executes instruction of a new function. 
The return address of the caller’s, machine register, etc. gets saved onto the stack. 
- The concept stack area is the foundation of recursion in C. 
- The space allocated to any function call gets free after the execution of a function and the space is reusable for other function calls.

## Copy/Move Constructor and Operator
```cpp
#include<iostream>
#include<cstring>

class my_string {
	char* str = NULL;
	public:
		// default constructor
		my_string(){ std::cout << "default Constructor" << std::endl; }
		
		// parameterize constructor
		my_string(const char* s){
			str = new char[strlen(s)+1];
			strcpy(str,s);
			std::cout << "Parameterize Constructor: " << str << std::endl;
        }

		// copy constructor
		my_string(const my_string& src){
			str = new char[strlen(src.str)+1];
			strcpy(str,src.str);
			std::cout << "Copy Constructor: " << str << std::endl;
		}

		//copy assignment operator
		my_string& operator = (const my_string& obj ){
			if(this != &obj){ // this means pointer and *this means objest itself points to
				delete [] str; // memory cleanup
				str = new char[strlen(obj.str)+1]; // aloocation memory
				strcpy(str,obj.str); 
				std::cout << "assignment operator: " << str << std::endl;
			}
			return *this;
		}

		// move constructor
		my_string(my_string&& src){
			str = src.str;
			src.str = NULL;
			std::cout << "move Constructor:  " << str << std::endl;
		}

		/*Move Assignment Operator*/
		void operator= (my_string&& obj) {
			if (str != nullptr) delete str;
			str = obj.str;
			obj.str = nullptr;
			std::cout << "Move assignment operator: " << str << std::endl;
		}

		~my_string() { std::cout << "destructor is called" << std::endl; }

		// Ovrerloading + operator

		my_string operator +(my_string& obj) {
			int len = strlen(str) + strlen(obj.str);
			char* buff = new char[len + 1];

			strcpy(buff,str);
			strcat(buff,obj.str);

			my_string temp(buff);

			delete [] buff;
			return temp;
		}
		
		// Overloading the stream (insertion operator)
		
        friend std::ostream& operator<<(std::ostream& os, const my_string& obj){
		   
		   if(obj.str != nullptr) os << obj.str << std::endl;
		   
		   return os;
		}

		// Overloading the stream (extraction operator)
		friend std::istream& operator >> (std::istream& in, my_string& obj){
			 char buffer[1000];  // temporary buffer (size limit)
            in >> buffer;

            delete[] obj.str;   // free old memory if any

            obj.str = new char[strlen(buffer) + 1];
            strcpy(obj.str, buffer);

            std::cout << obj.str << " : data successfully inserted!!" << std::endl;
            return in;
		}
	 
};
int main()
{
	my_string obj,obj3,obj5,obj7; // 4 times : default Constructor
	
	my_string obj1("Para"); // parameterize constructor
    /* Parameterize Constructor: Para */

	my_string obj2(obj1); // copy constructor
    /*Copy Constructor: Para */
	
	std::cout << "obj1: " << obj1 << "obj2: " << obj2 << std::endl;
    /* obj1: Para obj2: Para */
    
	obj3 = obj2; //  copy assignment operator
	/* assignment operator: Para */
	
	std::cout << "obj2: " << obj2 << "obj3: " << obj3 << std::endl;
    /* obj2: Para obj3: Para */
    
	my_string obj4{std::move(obj1)}; // Move Constructor
    /* move Constructor:  Para */
    
	std::cout << "obj1: " << obj1 << "obj4: " << obj4 << std::endl;
    /* obj1: obj4: Para */
    
	my_string obj6{std::move(my_string("Move"))}; // Move Constructor
	/*	Parameterize Constructor: Move
        move Constructor:  Move
        destructor is called    */
        
	std::cout << "obj6: " << obj6 << std::endl;
    /* obj6: Move */
    
	obj5 = std::move(obj3); // move assignment operator
	/* Move assignment operator: Para */
	
	std::cout << "obj3: " << obj3 << "obj5: " << obj5 << std::endl;
    /* obj3: obj5: Para */
    
	obj7 = my_string{"Move Assignment Operator!!"}; // move assignment operator this is lvalue so 
	/*  Parameterize Constructor: Move Assignment Operator!!
        Move assignment operator: Move Assignment Operator!!
        destructor is called    */
        
	std::cout << "obj7: " << obj7 << std::endl;
	/* obj7: Move Assignment Operator!! */
	
	my_string obj8("Hello"), obj9(" world!");
	/*  Parameterize Constructor: Hello
        Parameterize Constructor:  world!   */
        
	// std::cout << "resrult of a1+a2: " << obj8 + obj10 << std::endl;
   /* resrult of obj8 + obj10: Parameterize Constructor: Hello world! */
   
	my_string obj10;
	/* default Constructor */
	std::cout << "insert data" << std::endl;
	std::cin >> obj10;
	std::cout << "insterted data is: " << obj10;
	/* Haresh : data successfully inserted!! */
	/* destructor is called
	   destructor is called
	   destructor is called
	   destructor is called
	   destructor is called
	   destructor is called
	   destructor is called
	   destructor is called
	   destructor is called
	   destructor is called
	   destructor is called */
	
	return 0;
}
```
## Smart Pointer
### What is RAII?
RAII stands for Resource Acquisition Is Initialization.

It’s a C++ programming principle that ensures resources (like memory, files, sockets, locks, etc.) are properly acquired and released automatically using object lifetime.

#### Real-World Uses of RAII

- Smart Pointers (std::unique_ptr, std::shared_ptr) → manage memory safely.
- File Streams (fstream) → close file automatically.
- Locks (std::lock_guard) → release lock automatically.

**Shortcut to Remember**

- RAII = Resource tied to Object lifetime.
- Constructor = acquire resource.
- Destructor = release resource.

### Basic Smart Pointer 
```cpp
#include <iostream>
using namespace std;

class smart_ptr
{
private:
    int* act_ptr; // acual pointer
public:
    explicit smart_ptr(int *p  = NULL) // avoid implicit conversion for making reinitialization
    {
       act_ptr = p;
    }
    ~ smart_ptr() // destructure delete actual pointer
    {
        delete (act_ptr);
    }
    
    //Operator overloading for set and get value
    int& operator *() // by using & referance return, set and get possible
    {
        return *act_ptr;
    }
};
int main() {
    // Write C++ code here
   smart_ptr obj(new int());
 
    *obj = 500;
    cout<<*obj<<endl;
    return 0;
}
```
Same thing using template
```cpp
#include <iostream>
using namespace std;
template <class T>
class sp{
    T *data;
    public:
        sp(T*p) { data=p; }

        ~sp(){ delete data; }

        T& operator *(){ return *data; }
};
int main()
{
    int *p=new int(10);
    char *c=new char('A');
    sp<int>in(p);
    cout<<*in<<endl;
    sp<char> ch(c);
    cout<<*c<<endl;
    return 0;
}
```
### auto_ptr
auto_ptr is a smart pointer that manages an object obtained via a `new` expression and
deletes that object when `auto_ptr` itself is destroyed.

C++ program to illustrate the use of auto_ptr 
```cpp
#include <iostream> 
#include <memory> 
using namespace std; 

class A { 
    public: 
	    void show() { cout << "A::show()" << endl; } 
}; 

int main() 
{ 
	// p1 is an auto_ptr of type A 
	auto_ptr<A> p1(new A); 
	p1->show(); 

	// returns the memory address of p1 
	cout << p1.get() << endl; 

	// copy constructor called, this makes p1 empty. 
	auto_ptr<A> p2(p1); 
	p2->show(); 

	// p1 is empty now 
	cout << p1.get() << endl; 

	// p1 gets copied in p2 
	cout << p2.get() << endl; 

	return 0; 
}
/*
A::show()
0x1b42c20
A::show()
0          
0x1b42c20
*/
```
- When you copy or assign an auto_ptr, it does not make a real copy of the pointer.

- Instead, it transfers ownership of the pointer to the new object, and the old auto_ptr becomes empty (null).

- This ensures that only one auto_ptr owns a pointer at a time.

- But because of this, auto_ptr cannot be used in places where copies are required (like containers).

**Note :**  auto_ptr is not used anymore.

------
### unique_ptr
- std::unique_ptr was developed in C++11 as a replacement for std::auto_ptr. 
- unique_ptr is a new facility with similar functionality, but with improved security  (no fake copy assignments), added features (deleters), and support for arrays.

- It is a container for raw pointers. 

- It explicitly prevents copying of its contained pointer as would happen with a normal assignment

- i.e. it allows exactly one owner of the underlying pointer. 
```cpp
unique_ptr<A> ptr1 (new A);

 // Error: can't copy unique_ptr
unique_ptr<A> ptr2 = ptr1;    
 
 // Works, resource now stored in ptr2
unique_ptr<A> ptr2 = move(ptr1); 
```

C++ program to illustrate the use of unique_ptr 
```cpp
#include <iostream> 
#include <memory> 
using namespace std; 

class A { 
public: 
	void show() { cout << "A::show()" << endl; } 
}; 

int main() 
{ 
	unique_ptr<A> p1(new A); 
	p1->show();  // A::show()

	// returns the memory address of p1 
	cout << p1.get() << endl;  

	// transfers ownership to p2 
	unique_ptr<A> p2 = move(p1); 
	p2->show();  // 
	cout << p1.get() << endl;  // 0
	cout << p2.get() << endl; // 0xcebeb0

	// transfers ownership to p3 
	unique_ptr<A> p3 = move(p2); 
	p3->show();  // A::show()
	cout << p1.get() << endl;  // 0
	cout << p2.get() << endl;  // 0
	cout << p3.get() << endl;  // 0xcebeb0

	return 0; 
}
/*
A::show()
0xcebeb0
A::show()
0
0xcebeb0
A::show()
0
0
0xcebeb0
*/
```
**When to use unique_ptr?(()) 
- Use unique_ptr when you want to have single ownership(Exclusive) of the resource. 
- Only one unique_ptr can point to one resource. Since there can be one unique_ptr for a single resource it’s not possible to copy one unique_ptr to another.

#### my_unique_ptr
```cpp
// my_unique_ptr.cpp
template <class T>
class my_unique_ptr {
private:
	T * ptr = nullptr;

	void __cleanup__(){
		if (ptr != nullptr) delete ptr;
	}

public:
	
	my_unique_ptr() : ptr(nullptr) {}

	my_unique_ptr(T * ptr) : ptr(ptr) {}
	
	// copy constructor is deleted
	my_unique_ptr (const my_unique_ptr & obj) = delete;
	
	// copy assignment is deleted
	my_unique_ptr& operator= (const my_unique_ptr & obj) = delete; 

	// move constructor
	my_unique_ptr (my_unique_ptr && dyingObj) {
		// Transfer ownership of the memory pointed by dyingObj to this object
		this->ptr = dyingObj.ptr;
		dyingObj.ptr = nullptr; 
	}

	// move assignment
	void operator= (my_unique_ptr && dyingObj) {
		__cleanup__(); // cleanup any existing data

		// Transfer ownership of the memory pointed by dyingObj to this object
		this->ptr = dyingObj.ptr;
		dyingObj.ptr = nullptr;
	}

	// deferencing arrow operator
	T* operator->() { return this->ptr; }

	T& operator*() { return *(this->ptr); }

	~my_unique_ptr() {	__cleanup__();	}
};
```
-----
### shared_ptr

- shared_ptr is a smart pointer (from <memory>) that manages a resource with reference counting.

- Internally, it has:
    - a raw pointer to the resource,
    - a control block that stores reference count, weak count, and deleter.

- Reference Counting:
    - Increases when a shared_ptr is copied/assigned.
    - Decreases when a shared_ptr is destroyed/reset.

- The resource is automatically deleted when the reference count reaches zero (all owners released).

- A custom deleter can be provided for special cleanup.

- Works safely with multiple owners → ideal when resource ownership must be shared.

- ⚠️ Overhead: control block management + danger of cyclic references (solved with weak_ptr).

```cpp
#include <iostream> 
#include <memory> 
using namespace std; 

class A { 
public: 
	void show() { cout << "A::show()" << endl; } 
}; 

int main() 
{ 
	shared_ptr<A> p1(new A);
	cout << p1.get() << endl;  // 0x625010 
	p1->show();                // A::show()
	shared_ptr<A> p2(p1); 
	p2->show();                // A::show()
	cout << p1.get() << endl;  // 0x625010
	cout << p2.get() << endl;  // 0x625010

	// Returns the number of shared_ptr objects 
	// referring to the same managed object. 
	cout << p1.use_count() << endl; // 2
	cout << p2.use_count() << endl; // 2

	// Relinquishes ownership of p1 on the object 
	// and pointer becomes NULL 
	p1.reset(); 
	cout << p1.get() << endl; // 
	cout << p2.use_count() << endl; // 1
	cout << p2.get() << endl;  // 0x625010

	return 0; 
}
```
#### my_shared_ptr
```cpp
// my_shared_ptr.cpp
typedef unsigned int uint;
template<class T>
class my_shared_ptr
{
	private:
		T * ptr = nullptr;
		uint * refCount = nullptr;
		
		void __cleanup__(){
			(*refCount)--;
			if (*refCount == 0) {
				if (nullptr != ptr) delete ptr;
				
				delete refCount;
			}
		}

	public:
		my_shared_ptr() : ptr(nullptr), refCount(new uint(0)) {} // default constructor

		my_shared_ptr(T * ptr) : ptr(ptr), refCount(new uint(1)) {} // constructor
	

		/*** Copy Semantics ***/
		 // copy constructor
		my_shared_ptr(const my_shared_ptr & obj) {
			this->ptr = obj.ptr; // share the underlying pointer
			this->refCount = obj.refCount;
			if (nullptr != obj.ptr) {
				(*this->refCount)++; // if the pointer is not null, increment the refCount
			}
		}

		 // copy assignment
		my_shared_ptr& operator=(const my_shared_ptr & obj) {
			__cleanup__(); // cleanup any existing data
			
			// Assign incoming object's data to this object
			this->ptr = obj.ptr; // share the underlying pointer
			this->refCount = obj.refCount;
			if (nullptr != obj.ptr) {
				(*this->refCount)++; // if the pointer is not null, increment the refCount
			}
		}

		/*** Move Semantics ***/
		// move constructor
		my_shared_ptr(my_shared_ptr && dyingObj) {
			this->ptr = dyingObj.ptr; // share the underlying pointer
			this->refCount = dyingObj.refCount;

			dyingObj.ptr = dyingObj.refCount = nullptr; // clean the dying object
		}

		// move assignment
		my_shared_ptr& operator=(my_shared_ptr && dyingObj) {
			__cleanup__(); // cleanup any existing data
			
			this->ptr = dyingObj.ptr; // share the underlying pointer
			this->refCount = dyingObj.refCount;

			dyingObj.ptr = dyingObj.refCount = nullptr; // clean the dying object
		}

		uint get_count() const { return *refCount; /* *this->refCount */ }

		T* get() const { return this->ptr; }

		T* operator->() const{ return this->ptr;}

		T& operator*() const { return this->ptr; }

		~my_shared_ptr() { __cleanup__(); }
};
```
-----
### weak_ptr
- A weak_ptr is created as a copy of shared_ptr. 
- It provides access to an object that is owned by one or more shared_ptr instances but does not participate in reference counting. 
- The existence or destruction of weak_ptr has no effect on the shared_ptr or its other copies. 

- It is required in some cases to break circular references between shared_ptr instances.

**Cyclic Dependency (Problems with shared_ptr):** 
> Let’s consider a scenario where we have two classes A and B, and both have pointers to other classes. 
So, it’s always like A is pointing to B and B is pointing to A. Hence, use_count will never reach zero and they never get deleted 

```cpp
#include <iostream>
#include <memory> // for std::shared_ptr and std::weak_ptr
#include <string>

class Person {
	std::string m_name;
public:
    std::shared_ptr<Person> m_partner; 

	Person(const std::string &name): m_name(name) {
		std::cout << m_name << " created\n";
	}
	~Person(){
		std::cout << m_name << " destroyed\n";
	}
};

int main(){
	auto lucy { std::make_shared<Person>("Lucy") };
	auto ricky { std::make_shared<Person>("Ricky") };
    lucy->m_partner = ricky;
    ricky->m_partner = lucy;
	
	return 0;
}
/*
Lucy created
Ricky created
*/
```
- std::weak_ptr was designed to solve the “cyclical ownership” problem described above. 
- A std::weak_ptr is an observer -- it can observe and access the same object as a std::shared_ptr (or other std::weak_ptrs) but it is not considered an owner. Remember, when a std::shared pointer goes out of scope, it only considers whether other std::shared_ptr are co-owning the object.
- std::weak_ptr does not count!

```cpp
#include <iostream>
#include <memory> // for std::shared_ptr and std::weak_ptr
#include <string>

class Person {
	std::string m_name;
public:
    std::weak_ptr<Person> m_partner; 
	Person(const std::string &name): m_name(name) { std::cout << m_name << " created\n"; }

	~Person() { std::cout << m_name << " destroyed\n"; }
};

int main()
{
	auto lucy { std::make_shared<Person>("Lucy") };
	auto ricky { std::make_shared<Person>("Ricky") };
    lucy->m_partner = ricky;
    ricky->m_partner = lucy;
	return 0;
}
/*
Lucy created
Ricky created
Ricky destroyed
Lucy destroyed
*/
```
- One downside of std::weak_ptr is that std::weak_ptr are not directly usable (they have no operator->). 
- To use a std::weak_ptr, you must first convert it into a std::shared_ptr. 
- Then you can use the std::shared_ptr. To convert a std::weak_ptr into a std::shared_ptr, 
- you can use the lock() member function. Here’s the above example, updated to show this off:

```cpp
#include <iostream>
#include <memory> // for std::shared_ptr and std::weak_ptr
#include <string>

class Person
{
	std::string m_name;
	

public:
    std::weak_ptr<Person> m_partner; // note: This is now a std::weak_ptr
	Person(const std::string &name) : m_name(name) { std::cout << m_name << " created\n";	}

	~Person() { std::cout << m_name << " destroyed\n"; }

	const std::string& getName() const { return m_name; }
};

int main()
{
	auto lucy { std::make_shared<Person>("Lucy") };
	auto ricky { std::make_shared<Person>("Ricky") };
    lucy->m_partner = ricky;
    ricky->m_partner = lucy;

	//std::cout << ricky->m_partner->getName();//error: base operand of '->' has non-pointer type 'std::weak_ptr<Person>'
	
	auto partner = ricky->m_partner.lock(); // use lock() to convert weak_ptr to shared_ptr
	std::cout << ricky->getName() << "'s partner is: " << partner->getName();

	return 0;
}
/*
Lucy created
Ricky created
Ricky's partner is: Lucy
Ricky destroyed
Lucy destroyed
*/
```
#### my_weak_ptr
```cpp
// my_weak_ptr.cpp
#pragma once

#include <algorithm>
#include "cblock.h"

struct cblock {
    int shared_count = 1;
    int weak_count = 0;
};

template <class T>
class weak_ptr {
private:
    T* data_ = nullptr;
    cblock* cblock_ = nullptr;

    template<class Y> friend class shared_ptr;
    void dec_weak_count() {
        if (!cblock_) return;

        --cblock_->weak_count;

        if (cblock_->shared_count <= 0 && cblock_->weak_count <= 0) {
            delete cblock_;
            cblock_ = nullptr;
        }
    }

    void swap(weak_ptr& wp) noexcept {
        using std::swap;
        swap(data_, wp.data_);
        swap(cblock_, wp.cblock_);
    }

public:
    bool expired() const noexcept {
        return !cblock_ || cblock_->shared_count <= 0;
    }

    void reset() noexcept {
        dec_weak_count();
        data_ = nullptr;
        cblock_ = nullptr;
    }

    shared_ptr<T> lock() const {
        return expired() ? shared_ptr<T>(nullptr) : shared_ptr<T>(*this);
    }
    // Default Constructor
    weak_ptr() noexcept = default;

    //Copy Assignment Operator
    weak_ptr(const weak_ptr& wp) noexcept
        : data_(wp.data_)
        , cblock_(wp.cblock_) {
        if (cblock_) {
            ++cblock_->weak_count;
        }
    }

    //Copy Constructor
    weak_ptr(const shared_ptr<T>& sp) noexcept
        : data_(sp.data_)
        , cblock_(sp.cblock_) {
        if (cblock_) {
            ++cblock_->weak_count;
        }
    }
    //Copy Assignment Operator
    weak_ptr& operator=(const weak_ptr& wp) noexcept {
        weak_ptr tmp(wp);
        swap(tmp);
        return *this;
    }

    //Move Constructor
    weak_ptr(weak_ptr&& wp) noexcept {
        swap(wp);
        wp.reset();
    }

    //Move Assignment Operator
    weak_ptr& operator=(weak_ptr&& wp) noexcept {
        swap(wp);
        wp.reset();
        return *this;
    }
	
	int use_count() const noexcept{
		return (cblock_) ? cblock_->weak_count: 0;
	}

    ~weak_ptr() {
        dec_weak_count();
    }
};
```
-----
## Cast type
- Static Cast
- Dynamic Cast
- Const Cast
- Reinterpret Cast

### static_cast
- This is the simplest type of cast that can be used. 
- It is a compile-time cast. 
- It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions.

#### static_cast for primitive data type pointers:
```cpp
#include <iostream>
using namespace std;

// Driver code
int main()
{
	float f = 3.5;

	// Implicit type case
	// float to int
	int a = f;
	cout << "The Value of a: " << a;

	// using static_cast for float to int
	int b = static_cast<int>(f);
	cout << "\nThe Value of b: " << b;
}, 
// The Value of a: 3
// The Value of b: 3
```
#### static_cast for converting void* to any pointer typer

Note: pointer to pointer conversation is not allowed, only void* to any pointer conversion is allowed

```cpp
#include <iostream>

int main()
{
    int a = 0x1234;
    char c = 'a';
    int* q = (int*)&c; // Pass at compile time,  may fail at run time
    
    // int* p = static_cast<int*>(&c); // error: invalid ‘static_cast’ from type ‘char*’ to type ‘int*’
    
    // convert void* into char*
    void* vptr = &a;
    char* cptr = static_cast<char*>(vptr);
    std::cout << "*cptr: " << *cptr;  // *cptr: 4
    return 0;
}
```

#### static_cast for updating and downcasting in inheritance

**Note :** inherit as **`public`** is mandatory here.
```cpp
#include <iostream>
using namespace std;
class Base 
{};
class Derived : public Base   // Public is mandatory
{};

// Driver code
int main()
{
Derived d1;
Base b;
// Implicit cast allowed
Base* b1 = (Base*)(&d1);

// upcasting using static_cast
Base* b2 = static_cast<Base*>(&d1);

// Downcasting using static_cast
Derived* d2 = static_cast<Derived*>(&b);
return 0;
}
```

### dynami_cast
- Dynamic casting is mainly used for safe downcasting at `run time`. 
- To work on dynamic_cast **there must be one `virtual` function in the base class**. 
- A `dynamic_cast` works only polymorphic base class because it uses this information to decide safe downcasting.

**Where it is used:**
1. Downcasting (Base → Derived)
Safely convert a base class pointer/reference to a derived class.
Example: Base* → Derived*

2. Cross casting
Converting within a hierarchy between related classes.


- It checks at runtime whether the cast is valid.
- If it is valid, it returns the proper pointer/reference.        
- If it is invalid:
    - For pointers → it returns nullptr.
    - For references → it throws a std::bad_cast exception.

both pointer and reference examples in one program
```cpp
#include <iostream>
#include <typeinfo>   // for bad_cast
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class\n"; }  // needs at least 1 virtual function
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class\n"; }
    void derivedFunction() { cout << "Specific to Derived\n"; }
};

int main() {
    cout << "--- Pointer Example ---" << endl;
    Base* b = new Derived();   // upcasting (safe, implicit)

    // Downcasting (valid case)
    Derived* d = dynamic_cast<Derived*>(b);
    if (d) {
        d->show();
        d->derivedFunction();
    } else {
        cout << "Pointer cast failed!\n";
    }

    Base* b2 = new Base();  // pure base object
    Derived* d2 = dynamic_cast<Derived*>(b2); // invalid downcast
    if (d2)
        cout << "Pointer downcast success!\n";
    else
        cout << "Pointer downcast failed!\n";

    cout << "\n--- Reference Example ---" << endl;
    try {
        Derived d3;
        Base& bref = d3;   // upcasting

        // Valid downcast
        Derived& dref = dynamic_cast<Derived&>(bref);
        dref.show();
        dref.derivedFunction();

        Base b4;   // pure base object
        Base& bref2 = b4;

        // Invalid downcast -> throws bad_cast
        Derived& wrongRef = dynamic_cast<Derived&>(bref2);
        wrongRef.show();
    }
    catch (const bad_cast& e) {
        cout << "Reference cast failed with exception: " << e.what() << endl;
    }

    return 0;
}
/*
--- Pointer Example ---
Derived class
Specific to Derived
Pointer downcast failed!

--- Reference Example ---
Derived class
Specific to Derived
Reference cast failed with exception: std::bad_cast
*/
```
**Key Points**

1. Requires at least one `virtual` function in base class (because it relies on RTTI — Run Time Type Information).

2. Safe compared to `static_cast` (which does no runtime check).

3. Works only within inheritance hierarchies.

4. For pointers → returns `nullptr` on failure.
For references → throws `bad_cast`.

### const_cast
`const_cast` is a type cast operator in C++ used to **add** or **remove** the `const` (or `volatile`) qualifier from a variable.

**Where is it used?**

1. To remove const from a pointer or reference.

2. To add const (rare, usually not needed since compiler does it automatically).

3. Sometimes needed when dealing with legacy APIs that don’t accept const arguments.

Example 1: Removing const
```cpp
#include <iostream>
using namespace std;

int main() {
    const int x = 10;
    const int* p = &x;

    // Remove const
    int* q = const_cast<int*>(p);

    *q = 20;   // ❌ undefined behavior (modifying const object!)
    cout << *q << endl;

    return 0;
}
```
Example 2: Safe usage
```cpp
#include <iostream>
using namespace std;

void printValue(int* p) {
    *p = *p + 5;  // modify value
    cout << "Value: " << *p << endl;
}

int main() {
    int y = 100;
    const int* ptr = &y;

    // Cast away const to call function
    printValue(const_cast<int*>(ptr));

    return 0;
}

```
**Key Points**

- Use const_cast only when you are sure the underlying object is not actually const.

- Modifying a truly const object after casting → undefined behavior.

- Often used with APIs that don’t accept const even if they don’t modify the data.

### reinterpret_cast
This is used to convert pointer to any data type and data type to pointer or pointer to pointer.

- It doesn’t check safety at compile-time or runtime → you must use it carefully.

- It is the most dangerous of all casts (`static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`).

**When is it used?**

- Casting between unrelated pointer types
Example: casting an `int*` to a `char*`.
- Casting integer ↔ pointer (on many platforms).
- Low-level operations like working with memory,hardware registers, or serialization.

Example 1: Pointer reinterpretation
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 65;        // ASCII for 'A'
    int* p = &x;

    // Reinterpret as char pointer
    char* c = reinterpret_cast<char*>(p);

    cout << "Integer: " << *p << endl;   // 65
    cout << "Char: " << *c << endl;      // 'A'

    return 0;
}
```

Example 2: Integer ↔ Pointer
```cpp
#include <iostream>
#include <cstdint>   // for uintptr_t
using namespace std;

int main() {
    int x = 100;
    int* p = &x;

    // Pointer → Integer
    uintptr_t addr = reinterpret_cast<uintptr_t>(p);
    cout << "Pointer as integer: " << addr << endl;

    // Integer → Pointer
    int* p2 = reinterpret_cast<int*>(addr);
    cout << "Value via p2: " << *p2 << endl;

    return 0;
}
```
## Threads
```cpp
// @file thread1.cpp
#include <iostream>
#include <thread>

void normal_func(int x){ std::cout << "normal_func: " << x << std::endl; }

class MyClass {
public:
    // Non-static member function
    void f1(int num) { std::cout << "f1: " << num << std::endl; }
    
    // Static member function that takes one parameter
    static void f2(int num) { std::cout << "f2: "<< num << std::endl; }
};

int main(){

    std::thread fun_thread , lamda_thread, ns_thread, s_thread ;
    fun_thread = std::thread(&normal_func, 100);
    fun_thread.join();
    
    auto myLamda = [](int x){ std::cout << "lamda: " << x << std::endl;};
    
    lamda_thread = std::thread(myLamda,110);
    lamda_thread.join();
    
    MyClass obj;
    ns_thread = std::thread(&MyClass::f1, &obj, 200);
    ns_thread.join();
    
    s_thread = std::thread(&MyClass::f2,210);
    s_thread.join();
    
    
    return 0;
}
```
while working with array of threads
```cpp
#include <iostream>
#include <thread>
#include <vector>
#define NUM_TH 5

int main(){
    auto print_num = [](int a) { std::cout << "print_num: " << a << std::endl;};
    
    std::vector<std::thread>threads;   
    
    for(int i = 0;i<NUM_TH; i++) threads.push_back(std::thread(print_num,i));
    
    for(int i = 0;i< NUM_TH; i++) threads[i].join();
}
/*
print_num: 0
print_num: 1
print_num: 3
print_num: 2
print_num: 4
*/
```

`std::jthread`: In C++20, this is introduced

Same program with jthread, this is introduce in c++20
Diiferent between 
| Feature                  | `std::thread` (C++11)                       | `std::jthread` (C++20)                     |
| ------------------------ | ------------------------------------------- | ------------------------------------------ |
| Auto-join in destructor  | ❌ No (must call `.join()` or `.detach()`)   | ✅ Yes (joins automatically)                |
| Stop mechanism           | ❌ Manual (atomic flag, condition var, etc.) | ✅ Built-in `stop_token` + `request_stop()` |
| Safety if forgotten join | ❌ Program `std::terminate()`                | ✅ Safe, auto-joined                        |

1. Auto-join in destructor
std::thread (❌ must join manually)
```cpp
#include <thread>
#include <iostream>

void task() { std::cout << "Hello from thread\n"; }

int main() {
    std::thread t(task);
    // ❌ If we forget t.join(), program calls std::terminate()
    t.join(); // must be called
}
```
std::jthread (✅ joins automatically)
```cpp
#include <thread>
#include <iostream>

void task() { std::cout << "Hello from jthread\n"; }

int main() {
    std::jthread t(task);
    // ✅ No join needed, destructor auto-joins
}
```

2. Stop mechanism
std::thread (❌ manual stop flag needed)
```cpp
#include <thread>
#include <iostream>
#include <chrono>
#include <atomic>

std::atomic<bool> stopFlag{false};

void worker() {
    while (!stopFlag) {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::thread t(worker);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    stopFlag = true;   // request stop manually
    t.join();
}
```
std::jthread (✅ built-in stop_token)
```cpp
#include <thread>
#include <iostream>
#include <chrono>

void worker(std::stop_token st) {
    while (!st.stop_requested()) {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::jthread t(worker);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    t.request_stop();  // built-in stop request
} // auto-joined
```