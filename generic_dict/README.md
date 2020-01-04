# Generic Dictionary

This is an implementation of a dictionary in plain C. The implementation itself is inspired by an article on [medium][1] and combines it with ideas from the following [page][2]. It uses generic skeleton that can be filled with the correct types by the preprocessor. To complete the dictionary some type specific methods have to be written (Complex structs need to be free'd somehow). Note that I did not implement a remove function, because I did not need it.

## Usage

The __str_int_dict__ folder contains the complete implementation of a dictionary from string to keys to int values. The folder __generic__ contains the generic skeleton that can be reused. ```str-int-dict.c``` plainly includes the generic methods (from source files) its header and the typed methods. The generic files will never be compiled on their own. The header will define the ```KEY_TYPE``` the ```VALUE_TYPE``` and a post_fix to make the dictionary methods unique. As mentioned already the typed methods are necessary to make this specific dictionary work. If you want to use other types of keys you will need to write another hash method and another free method and so on.

[1]: https://medium.com/@bennettbuchanan/an-introduction-to-hash-tables-in-c-b83cbf2b4cf6
[2]: https://www.cs.grinnell.edu/~rebelsky/musings/cnix-macros-generics
