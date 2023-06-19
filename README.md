# Data-Structures-CPP
<center>

![WIP_STATUS](https://img.shields.io/badge/STATUS-WIP-RED?style=for-the-badge&color=red)
![REPO_STARS](https://img.shields.io/github/stars/SleepiCaffeine/Data-Structures-CPP?style=for-the-badge&label=stars&color=ffc336)
![FORK_STATS](https://img.shields.io/github/forks/SleepiCaffeine/Data-Structures-CPP?style=for-the-badge&color=white)
  
</center>

<center>

![FOLLOW .-.](https://img.shields.io/github/followers/SleepiCaffeine?style=social&labelColor=purple&color=purple)
  
</center>


A header-only, STL-like library for node-type data structures that are not natively supported by **STL**. All headers are documented using Doxygen comments. <br>
Currently - all supported data structures and class are [here](https://github.com/SleepiCaffeine/Data-Structures-CPP/blob/main/Data%20Structures/currentVersion.md).

## How to use
Simply include `data_structues.hpp` or any individual header, and start using it. If you are unsure how to clone a repository - [read here](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository).

## Example of use
All classes and types will have their own users-guide, and hopefully a Doxygen generated documentation PDF.
```
#include "Data Structures\node.h"
#include <iostream>

int main() {
  node<int>* my_node = new node<int>(10);   // Creates a node with value 10, and points to nothing
  auto my_other_node  = new node<int>(20);  // Creates a node with value 20, and points to nothing
  
  my_node->set_next(my_other_node);                         // Now `my_node` points to `my_other_node`
  std::cout << my_node->get_next()->get_data() << "\n";     // Output is 20

  auto copy_node = node<int>(*my_node);
  my_node->set_data(35);
  
  std::cout << my_node->get_data() << "\n";     // Output is 35
  std::cout << copy_node.get_data() << "\n";    // Output is 10
  
  return 0;
}
```

## Issues and Pull Requests
Currently there is no template for providing issues, so anything is appreciated! 

## Authors
I am the only developer working on this

## License
This project is protected by the MIT license.