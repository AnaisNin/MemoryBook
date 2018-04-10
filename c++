Effective Moderne C++ - Scott Meyers
---------------
Introduction
---------------

# Changes introduced by c++11/14:
auto declarations, range-based for loops, dambda expressions, rvalue references, new concurrency features
0 and typedefs are out, nullptr and alias declarations are in
enums should now be scoped. Smart pointers are now preferable to built-in ones.
Moving objects in normally better than copying them.

# Different versions of c++ and terminology
There have been 4 official versions of c++, each named after the year in which the corresponding ISO standartd was adopted:
c++98, c++03, C++11, c++14.
C++98 and 03 differ only in technical details so in this book I refer to both as c++98.
when I refer to c++11 I refer to both c++11 and c++14.
When I write c++14 I mean specifically c++14.

c++11 supports lambda expressions (true for c++11 and c++14);
c++14 offers generalized function return type deduction (true for c++14 only)

# lvalues vs rvalues
c++11's most pervasive feature is probably move semantics, 
and the foundation of move semantics is distinguishing expressions that are rvalues from those that are lvalues.
That's because rvalues indicate objects eligible for move operations, while lvalues generally don't.

In concept (though not always in practice), rvalues correspond to temporary objects returned from functions, 
while lvalues correspond to objects you can refer to, either by name or by following a pointer or lvalue reference.
A useful heuristic to determine whether an expression is a lvalue is to ask if you can take its address.
If you can, then it's an lvalue. If you can't, it's ususally an rvalue. 
That is, given a type T, you can have lvalues of type T as well as rvalues of type T. 
It's especially important to remember this when dealing with a parameter of rvalue reference type, because the parameter itself is an lvalue.
class Widget{
public:
  Widget(Widget&& rhs); //Widget's move constructor
};
Here, it'd be perfectly valid to take rhs's address inside Widgets move constructor, so rhs is an lvalue 
(by similar reasoning all parameters are lvalues) even though its type is an rvalue reference.

move operations, i.e. move constructor, move assignment operator
copy operations, i.e. copy constructor, copy assignment operator


