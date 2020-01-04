# Generic Dictionary

This is an implementation of a dictionary in plain C. The implementation itself is inspired by an article on [medium][1] and combines it with ideas from the following [page][2]. It uses generic skeleton that can be filled with the correct types by the preprocessor. To complete the dictionary some type specific methods have to be written (Complex structs need to be free'd somehow).

## Usage

The folder __generic_dict__ contains the generic skeleton that can be reused. The __str_int_dict__ folder contains a file called ```str-int-dict.c```. This file just plainly includes the generic methods (from source files) its header and the typed methods. The generic files will never be compiled on their own. The header will define the ```KEY_TYPE``` the ```VALUE_TYPE``` and a post_fix to make the dictionary methods unique. 

[1]: https://medium.com/@bennettbuchanan/an-introduction-to-hash-tables-in-c-b83cbf2b4cf6
[2]: https://www.cs.grinnell.edu/~rebelsky/musings/cnix-macros-generics
