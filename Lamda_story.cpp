/*

Note: to build flag with #define is -DYourflag
lamda function story till now
Source: https://www.cppstories.com/2019/02/lambdas-story-part1/
*/
#ifdef lamda03
/*
“Lambdas” in C++03
Since the early days of STL, std::algorithms - like std::sort could take any
callable object and call it on elements of the container. However,
in C++03 it meant only function pointers and functors.

For example:
*/
#include <algorithm>
#include <iostream>
#include <vector>

struct PrintFunctor {
    void operator()(int x) const { std::cout << x << std::endl; }
};

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    std::for_each(v.begin(), v.end(), PrintFunctor());
}
// compiler :  g++ prog.cc -Wall -Wextra -std=c++98

/*
But the problem was that you had to write a separate function or a functor
in a different scope than the invocation of the algorithm.

As a potential solution, you could think about writing a local functor class -
since C++ always has support for that syntax. But that didn’t work…

See this code:

int main() {
    struct PrintFunctor {
        void operator()(int x) const {
            std::cout << x << std::endl;
        }
    };

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    std::for_each(v.begin(), v.end(), PrintFunctor());
}

Try to compile it with -std=c++98 and you’ll see the following error on GCC:

error: template argument for
'template<class _IIter, class _Funct> _Funct
std::for_each(_IIter, _IIter, _Funct)'
uses local type 'main()::PrintFunctor'

Basically, in C++98/03 you couldn’t instantiate a template with a local type
*/

#endif

#ifdef lamda11

/*
Moving to C++11
Lambdas were added into the language in a smart way I think. They use some new
syntax, but then the compiler “expands” it into a real class. This way we have
all advantages (and disadvantages sometimes) of the real strongly typed
language.

Here’s a basic code example that also shows the corresponding local functor
object:
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    struct {
        void operator()(int x) const { std::cout << x << '\n'; }
    } someInstance;

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    std::for_each(v.begin(), v.end(), someInstance);
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << '\n'; });
}

/*
The syntax of the lambda expression:

[] ()   { code; }
^  ^  ^
|  |  |
|  |  optional: mutable, exception, trailing return, ...
|  |
|  parameter list
|
lambda introducer with capture list

[&] - capture by reference, all automatic storage duration variable declared in
the reaching scope
[=] - capture by value, a value is copied
[x, &y] - capture x by value and y by a reference explicitly

Mutable
By default operator() of the closure type is const,
and you cannot modify captured variables inside the body of the lambda.

If you want to change this behaviour you need to add mutable keyword after
the parameter list:

int x = 1, y = 1;
std::cout << x << " " << y << std::endl;
auto foo = [x, y]() mutable { ++x; ++y; };
foo();
std::cout << x << " " << y << std::endl

output :
1 1
1 1
Note: without mutable its throw error as paasing as value this is const
      but pass as referance no issues.


With Global variable:

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

int global = 10;

int main()
{
    std::cout << global << std::endl;
    [] { ++global; } ();
    std::cout << global << std::endl;
    [global] { ++global; } (); // warning: capture of variable 'global'
                               //with non-automatic storage duration
    std::cout << global << std::endl;
    auto foo = [=] () mutable { ++global; };
    foo();
    std::cout << global << std::endl;

}
Note: Mutable not required in global variable
Output:
10
11
12
13

For Static variable : behaviour is same as global variable
#include <iostream>

void bar()
{
    static int static_int = 10;
    std::cout << static_int << std::endl;
    auto foo = [=] () mutable { ++static_int; };
    foo();
    std::cout << static_int << std::endl;
    [] { ++static_int; } ();
    std::cout << static_int << std::endl;
    [static_int] { ++static_int; } (); //warning: capture of variable
'static_int' with non-automatic storage duration
}

int main()
{
   bar();
}
10
11
12
*/

/*
Capturing a Class Member

#include <iostream>
#include <functional>

struct Baz
{
    std::function<void()> foo()
    {
        return [=] { std::cout << s << std::endl; };
    }

    std::string s;
};

int main()
{
   auto f1 = Baz{"ala"}.foo();  // This is temporary object
   auto f2 = Baz{"ula"}.foo();  // This is temporary object
   f1();
   f2();
}
Output:
ula
ula

- The code declares a Baz object and then invokes foo(). 
- Please note that foo() returns a lambda (stored in std::function) that captures 
  a member of the class.

- Since we use temporary objects, we cannot be sure what will happen 
- when you call f1 and f2. This is a dangling reference problem and generates 
  Undefined Behaviour.


Similarly to:

struct Bar { 
    std::string const& foo() const { return s; }; 
    std::string s; 
};
auto&& f1 = Bar{"ala"}.foo(); // dangling reference

Again, if you state the capture explicitly ([s]):

std::function<void()> foo()
{
    return [s] { std::cout << s << std::endl; };
}

The compiler will prevent you for making this mistake, by emitting errors:

In member function 'std::function<void()> Baz::foo()':
error: capture of non-variable 'Baz::s'
error: 'this' was not captured for this lambda function
*/

/*
Move-able-only Objects   
If you have an object that is movable only (for example unique_ptr), then you cannot move it to lambda as a captured variable. Capturing by value does not work, so you can only capture by reference… however this won’t transfer the ownership, and it’s probably not what you wanted.

std::unique_ptr<int> p(new int{10});
auto foo = [p] () {}; // does not compile....


Preserving Const   
If you capture a const variable, then the constness is preserved:

int const x = 10;
auto foo = [x] () mutable { 
    std::cout << std::is_const<decltype(x)>::value << std::endl;
    x = 11;
};
foo();
*/


/*
Return Type   
- In C++11 you could skip the trailing return type of the lambda and then 
- the compiler would deduce the type for you.

- Initially, return type deduction was restricted to lambdas with bodies 
  containing a single return statement, but this restriction was quickly 
  lifted as there were no issues with implementing a more convenient version.

*/

#endif

#ifdef lamdas14
/************************
mprovements in C++14   
The standard N4140 and lambdas: [expr.prim.lambda].

C++14 added two significant enhancements to lambda expressions:

Captures with an initialiser
Generic lambdas
The features can solve several issues that were visible in C++11.


Return Type   
- Lambda return type deduction was updated to conform to the rules of 
  auto deduction rules for functions.

Captures With an Initializer   
- In short, we can create a new member variable of the closure type and 
  then use it inside the lambda.

For example:

int main() {
    int x = 10;
    int y = 11;
    auto foo = [z = x+y]() { std::cout << z << '\n'; };
    foo();
}
It can solve a few problems, for example with movable only types.

Move
Now, we can move an object into a member of the closure type:

#include <memory>

int main()
{
    std::unique_ptr<int> p(new int{10});
    auto foo = [x=10] () mutable { ++x; };
    auto bar = [ptr=std::move(p)] {};
    auto baz = [p=std::move(p)] {};
}  

Capturing a Member Variable   
- Initialiser can also be used to capture a member variable. 
- We can then capture a copy of a member variable and don’t bother with 
  dangling references.

For example

struct Baz
{
    auto foo()
    {
        return [s=s] { std::cout << s << std::endl; };
    }

    std::string s;
};

int main()
{
   auto f1 = Baz{"ala"}.foo();
   auto f2 = Baz{"ula"}.foo(); 
   f1();
   f2();
}

Generic Lambdas   
Another significant improvement to Lambdas is a generic lambda.

Since C++14 you can now write:

auto foo = [](auto x) { std::cout << x << '\n'; };
foo(10);
foo(10.1234);
foo("hello world");

*************************/
#endif

//Source : https://www.cppstories.com/2019/03/lambdas-story-part2/

#ifdef lamdas17
/*******************************
Improvements in C++17   
- C++17 added two significant enhancements to lambda expressions:
    - constexpr lambdas
    - Capture of *this


constexpr function rules:
    In C++11:
        - Must contain only a single return statement.
        - No loops, conditionals, or local variables.
        - Very restrictive.

    In C++14:
        - Loops (for, while) allowed.
        - Conditionals (if, switch) allowed.
        - Local variables allowed (must be of literal types).
        - Functions can be more complex.

    In C++20:
        - Almost all limitations are lifted.
        - try/catch blocks (with limitations), dynamic memory (with constexpr allocators), 
          and more complex expressions are allowed.

*/
#include <array>
#include <iostream>
#ifdef lamdas17p1
template<typename Range, typename Func, typename T>
constexpr T SimpleAccumulate(const Range& range, Func func, T init) {
    for (auto &&elem: range) {
        init += func(elem);
    }
    return init;
}

int main() {
    constexpr std::array arr{ 1, 2, 3 };

    static_assert(SimpleAccumulate(arr, [](int i) { 
            return i * i; 
        }, 0) == 14);
    return 0;    
}
#endif

/*
Capture of *this   
Do you remember our issue when we wanted to capture a class member?

By default, we capture this (as a pointer!), and that’s why we might get into troubles when temporary objects go out of scope… We can fix this by using capture with initialiser (see in the first part of the series).

But now, in C++17 we have another way. We can wrap a copy of *this:
*******************/
#ifdef lamdas17p2
#include <iostream>

struct Baz {
    auto foo() {
        return [*this] { std::cout << s << std::endl; };
    }

    std::string s;
};

int main() {
   auto f1 = Baz{"ala"}.foo();
   auto f2 = Baz{"ula"}.foo(); 
   f1();
   f2();
}
#endif
/**************
In C++14 the only way to make the code safer 
is init capture this:

auto foo() {
    return [self=*this] { self.print(); };
}

But in C++17 it’s cleaner, as you can write:

auto foo() {
    return [*this] { print(); };
}
********************************/
#endif

#ifdef lamdas20
/******************************
- Lambdas Can Be constexpr by Default
    - If a lambda satisfies constexpr constraints, 
      it becomes a constexpr function automatically.

    auto square = [](int x) { return x * x; };
    constexpr int val = square(5); 

- Lambdas Can Be templates (Generic Lambdas Improved)
    - This is a huge enhancement: lambdas can now be template lambdas with template parameter 
      lists (i.e., explicit template syntax like in regular functions).


    auto add = []<typename T>(T a, T b) {
        return a + b;
    };

    int x = add(1, 2);          // OK
    double y = add(1.5, 2.5);   // OK

******************************/
#endif
